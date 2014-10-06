/*
Copyright (C) 2013-2014, Sergey Gerasuto <contacts@robotics.by>

http://www.robotics.by/

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
- Neither the name of the RCSG Developers nor the names of its
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
`AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "RCSGMediaFoundationVideoBufferLock.h"
#include "device.h"
#include "thirdparty\libyuv\libyuv.h"

#include <mferror.h>
#include <mfapi.h>
#include <mfidl.h>

void TransformImage_RGB24(
	BYTE*       pDest,
	LONG        lDestStride,
	const BYTE* pSrc,
	DWORD       ,
	LONG        lSrcStride,
	UINT		dwWidthInPixels,
	UINT		dwHeightInPixels
	)
{
	libyuv::RGB24ToARGB(pSrc,lSrcStride,pDest,lDestStride,dwWidthInPixels,dwHeightInPixels);
}

void TransformImage_RGB32(
	BYTE*       pDest,
	LONG        lDestStride,
	const BYTE* pSrc,
	DWORD		,
	LONG        lSrcStride,
	UINT		dwWidthInPixels,
	UINT		dwHeightInPixels
	)
{
	MFCopyImage(pDest, lDestStride, pSrc, lSrcStride, dwWidthInPixels * 4, dwHeightInPixels);
}

void TransformImage_YUY2(
	BYTE*       pDest,
	LONG        lDestStride,
	const BYTE* pSrc,
	DWORD       ,
	LONG        lSrcStride,
	UINT		dwWidthInPixels,
	UINT		dwHeightInPixels
	)
{
	libyuv::YUY2ToARGB(pSrc,lSrcStride,pDest,lDestStride,dwWidthInPixels,dwHeightInPixels);
}

void TransformImage_NV12(
	BYTE*		pDest, 
	LONG		dstStride, 
	const BYTE* pSrc,
	DWORD       ,
	LONG		srcStride,
	UINT		dwWidthInPixels,
	UINT		dwHeightInPixels
	)
{
	unsigned int   nbytes    = dwWidthInPixels*dwHeightInPixels; 
	const BYTE    *yplane    = pSrc;           		
	const BYTE    *uvplane    = yplane+nbytes;
	libyuv::NV12ToARGB(yplane,srcStride,uvplane,srcStride/2,pDest,dstStride,dwWidthInPixels,dwHeightInPixels);
}

void TransformImage_I420(
	BYTE*       pDest,
	LONG        dstStride,
	const BYTE* pSrc,
	DWORD       ,
	LONG        srcStride,
	UINT		dwWidthInPixels,
	UINT		dwHeightInPixels
	)
{
	unsigned int   nbytes    = dwWidthInPixels*dwHeightInPixels; 
	const BYTE    *yplane    = pSrc;           		
	const BYTE    *uplane    = yplane+nbytes;              
	const BYTE    *vplane    = uplane+(nbytes >> 2);       	
	libyuv::I420ToARGB(yplane,srcStride,uplane,srcStride/2,vplane,srcStride/2,pDest,dstStride,dwWidthInPixels,dwHeightInPixels);
}

void TransformImage_MJPG(
	BYTE*       pDest,
	LONG        lDestStride,
	const BYTE* pSrc,
	DWORD		pSrcSize,
	LONG        ,
	UINT		dwWidthInPixels,
	UINT		dwHeightInPixels
	)
{
	libyuv::MJPGToARGB(pSrc,pSrcSize,pDest,lDestStride,dwWidthInPixels,dwHeightInPixels,dwWidthInPixels,dwHeightInPixels);
}


HRESULT GetDefaultStride(IMFMediaType *pType, LONG *plStride);

inline LONG Width(const RECT& r)
{
	return r.right - r.left;
}

inline LONG Height(const RECT& r)
{
	return r.bottom - r.top;
}

struct ConversionFunction
{
	GUID               subtype;
	IMAGE_TRANSFORM_FN xform;
};

ConversionFunction   g_FormatConversions[] =
{
	{ MFVideoFormat_RGB32, TransformImage_RGB32 },
	{ MFVideoFormat_RGB24, TransformImage_RGB24 },
	{ MFVideoFormat_YUY2,  TransformImage_YUY2 },
	{ MFVideoFormat_NV12,  TransformImage_NV12},
	{ MFVideoFormat_I420, TransformImage_I420 },
	{ MFVideoFormat_MJPG, TransformImage_MJPG }
};

const DWORD g_cFormats = ARRAYSIZE(g_FormatConversions);

DrawDevice::DrawDevice() : 
	m_hwnd(NULL),
	m_pD3D(NULL),
	m_pDevice(NULL),
	m_pSwapChain(NULL),
	m_format(D3DFMT_UNKNOWN),
	m_width(0),
	m_height(0),
	m_lDefaultStride(0),
	m_interlace(MFVideoInterlace_Unknown),
	m_convertFn(NULL)
{
	m_PixelAR.Denominator = m_PixelAR.Numerator = 1; 

	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));
}

DrawDevice::~DrawDevice()
{
	DestroyDevice();
}

HRESULT DrawDevice::GetFormat(DWORD index, GUID *pSubtype) const
{
	if (index < g_cFormats)
	{
		*pSubtype = g_FormatConversions[index].subtype;
		return S_OK;
	}
	return MF_E_NO_MORE_TYPES;
}

BOOL DrawDevice::IsFormatSupported(REFGUID subtype) const
{
	for (DWORD i = 0; i < g_cFormats; i++)
	{
		if (subtype == g_FormatConversions[i].subtype)
		{
			return TRUE;
		}
	}
	return FALSE;
}

HRESULT DrawDevice::CreateDevice(HWND hwnd)
{
	DestroyDevice();

	if (m_pD3D == NULL)
	{
		m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

		if (m_pD3D == NULL)
		{
			return E_FAIL;
		}
	}

	HRESULT hr = S_OK;
	D3DPRESENT_PARAMETERS pp = { 0 };
	D3DDISPLAYMODE mode = { 0 };

	hr = m_pD3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT, 
		&mode
		);

	if (FAILED(hr)) { goto done; }

	hr = m_pD3D->CheckDeviceType(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		mode.Format,
		D3DFMT_X8R8G8B8,
		TRUE    // windowed
		);

	if (FAILED(hr)) { goto done; }

	pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_COPY;
	pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;  
	pp.Windowed = TRUE;
	pp.hDeviceWindow = hwnd;

	hr = m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_FPU_PRESERVE,
		&pp,
		&m_pDevice
		);

	if (FAILED(hr)) { goto done; }

	m_hwnd = hwnd;
	m_d3dpp = pp;

done:
	return hr;
}

HRESULT DrawDevice::SetConversionFunction(REFGUID subtype)
{
	m_convertFn = NULL;

	for (DWORD i = 0; i < g_cFormats; i++)
	{
		if (g_FormatConversions[i].subtype == subtype)
		{
			m_convertFn = g_FormatConversions[i].xform;
			return S_OK;
		}
	}

	return MF_E_INVALIDMEDIATYPE;
}

HRESULT DrawDevice::SetVideoType(IMFMediaType *pType)
{
	HRESULT hr = S_OK;
	GUID subtype = { 0 };
	MFRatio PAR = { 0 };

	// Find the video subtype.
	hr = pType->GetGUID(MF_MT_SUBTYPE, &subtype);

	if (FAILED(hr)) { goto done; }

	// Choose a conversion function.
	// (This also validates the format type.)

	hr = SetConversionFunction(subtype); 

	if (FAILED(hr)) { goto done; }

	//
	// Get some video attributes.
	//

	// Get the frame size.
	hr = MFGetAttributeSize(pType, MF_MT_FRAME_SIZE, &m_width, &m_height);

	if (FAILED(hr)) { goto done; }


	// Get the interlace mode. Default: assume progressive.
	m_interlace = (MFVideoInterlaceMode)MFGetAttributeUINT32(
		pType,
		MF_MT_INTERLACE_MODE, 
		MFVideoInterlace_Progressive
		);

	// Get the image stride.
	hr = GetDefaultStride(pType, &m_lDefaultStride);

	// Get the pixel aspect ratio. Default: Assume square pixels (1:1)
	hr = MFGetAttributeRatio(
		pType, 
		MF_MT_PIXEL_ASPECT_RATIO, 
		(UINT32*)&PAR.Numerator, 
		(UINT32*)&PAR.Denominator
		);

	if (SUCCEEDED(hr))
	{
		m_PixelAR = PAR;
	}
	else
	{
		m_PixelAR.Numerator = m_PixelAR.Denominator = 1;
	}

	m_format = (D3DFORMAT)subtype.Data1;

	// Create Direct3D swap chains.

	hr = CreateSwapChains();

	if (FAILED(hr)) { goto done; }

	// Update the destination rectangle for the correct
	// aspect ratio.

	GetClientRect(m_hwnd, &m_rcDest);

done:
	if (FAILED(hr))
	{
		m_format = D3DFMT_UNKNOWN;
		m_convertFn = NULL;
	}
	return hr;
}

HRESULT DrawDevice::CreateSwapChains()
{
	HRESULT hr = S_OK;

	D3DPRESENT_PARAMETERS pp = { 0 };

	safeRelease(&m_pSwapChain);

	pp.BackBufferWidth  = m_width;
	pp.BackBufferHeight = m_height;
	pp.Windowed = TRUE;
	pp.SwapEffect = D3DSWAPEFFECT_FLIP;
	pp.hDeviceWindow = m_hwnd;
	pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	pp.Flags = 
		D3DPRESENTFLAG_VIDEO | D3DPRESENTFLAG_DEVICECLIP |
		D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	pp.BackBufferCount = 2;

	hr = m_pDevice->CreateAdditionalSwapChain(&pp, &m_pSwapChain);

	return hr;
}

HRESULT DrawDevice::DrawFrame(IMFMediaBuffer *pBuffer, IMFSample **pSampleRGB32 , IMFMediaBuffer **pBufferRGB32 )
{
	if (m_convertFn == NULL)
	{
		return MF_E_INVALIDREQUEST;
	}

	HRESULT hr = S_OK;
	BYTE *pbScanline0 = NULL;
	LONG lStride = 0;
	D3DLOCKED_RECT lr;

	IDirect3DSurface9 *pSurf = NULL;
	IDirect3DSurface9 *pBB = NULL;

	if (m_pDevice == NULL || m_pSwapChain == NULL)
	{
		return S_OK;
	}

	RCSGMediaFoundationVideoBufferLock buffer(pBuffer);    // Helper object to lock the video buffer.

	DWORD pcbCurrentLength;

	hr = pBuffer->GetCurrentLength(&pcbCurrentLength);

	if (SUCCEEDED(hr)) 
	{ 
		hr = TestCooperativeLevel();
		if (SUCCEEDED(hr)) 
		{
			hr = buffer.LockBuffer(m_lDefaultStride, m_height, &pbScanline0, &lStride);
			if (SUCCEEDED(hr)) 
			{
				hr = m_pSwapChain->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &pSurf);
				if (SUCCEEDED(hr)) 
				{ 
					hr = pSurf->LockRect(&lr, NULL, D3DLOCK_NOSYSLOCK );
					if (SUCCEEDED(hr)) 
					{ 
						m_convertFn(
							(BYTE*)lr.pBits,
							lr.Pitch,
							pbScanline0,
							pcbCurrentLength,
							lStride,
							m_width,
							m_height
							);

						hr = pSurf->UnlockRect();

						if (SUCCEEDED(hr)) 
						{
							if (m_pDevice!=NULL) 
							{
								hr = m_pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBB);
							} 

							if (SUCCEEDED(hr)) 
							{ 
								if (pSampleRGB32!=NULL)
								{
									UINT frameBytesLength = m_width*m_height*4;
									hr = MFCreateMemoryBuffer(frameBytesLength, pBufferRGB32);
									(*pBufferRGB32)->SetCurrentLength(frameBytesLength);
									BYTE *BufferData = NULL;
									hr = (*pBufferRGB32)->Lock(&BufferData, NULL, NULL);
									libyuv::CopyRow_SSE2((BYTE*)lr.pBits,BufferData,frameBytesLength);
									(*pBufferRGB32)->Unlock();
									BufferData = NULL;
									hr = (*pBufferRGB32)->SetCurrentLength(frameBytesLength);
									(*pSampleRGB32)->AddBuffer((*pBufferRGB32));
								}
								if (m_pDevice!=NULL) 
								{
									hr = m_pDevice->StretchRect(pSurf, NULL, pBB, &m_rcDest, D3DTEXF_NONE);
								}

								if (SUCCEEDED(hr)) 
								{
									if (m_pDevice!=NULL) 
									{
										hr = m_pDevice->Present(NULL, NULL, NULL, NULL);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	safeRelease(&pBB);
	safeRelease(&pSurf);
	return hr;
}

HRESULT DrawDevice::TestCooperativeLevel()
{
	if (m_pDevice == NULL)
	{
		return E_FAIL;
	}

	HRESULT hr = S_OK;

	hr = m_pDevice->TestCooperativeLevel();

	switch (hr)
	{
	case D3D_OK:
		break;

	case D3DERR_DEVICELOST:
		{
			while (hr == D3DERR_DEVICELOST)
			{
				Sleep(100);
				hr = m_pDevice->TestCooperativeLevel();
			}
		}

	case D3DERR_DEVICENOTRESET:
		hr = ResetDevice();
		break;

	default:
		break;
	}

	return hr;
}

HRESULT DrawDevice::ResetDevice()
{
	HRESULT hr = S_OK;

	if (m_pDevice)
	{
		D3DPRESENT_PARAMETERS d3dpp = m_d3dpp;

		hr = m_pDevice->Reset(&d3dpp);

		if (FAILED(hr))
		{
			DestroyDevice();
		}
	}

	if (m_pDevice == NULL)
	{
		hr = CreateDevice(m_hwnd);

		if (FAILED(hr)) { return hr; }
	}

	if ((m_pSwapChain == NULL) && (m_format != D3DFMT_UNKNOWN))
	{
		hr = CreateSwapChains();

		if (FAILED(hr)) { return hr; }
	}

	return hr;
}

void DrawDevice::DestroyDevice()
{
	safeRelease(&m_pSwapChain);
	safeRelease(&m_pDevice);
	safeRelease(&m_pD3D);
}



HRESULT GetDefaultStride(IMFMediaType *pType, LONG *plStride)
{
	LONG lStride = 0;
	HRESULT hr = pType->GetUINT32(MF_MT_DEFAULT_STRIDE, (UINT32*)&lStride);

	if (FAILED(hr))
	{
		GUID subtype = GUID_NULL;
		UINT32 width = 0;
		UINT32 height = 0;
		hr = pType->GetGUID(MF_MT_SUBTYPE, &subtype);

		if (SUCCEEDED(hr))
		{
			hr = MFGetAttributeSize(pType, MF_MT_FRAME_SIZE, &width, &height);
			if (SUCCEEDED(hr))
			{
				hr = MFGetStrideForBitmapInfoHeader(subtype.Data1, width, &lStride);
				if (SUCCEEDED(hr))
				{
					(void)pType->SetUINT32(MF_MT_DEFAULT_STRIDE, UINT32(lStride));
				}
				
			}
		}	
	}

	if (SUCCEEDED(hr))
	{
		*plStride = lStride;
	}

	return hr;
}