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

#ifndef DRAWDEVICE_H_
#define DRAWDEVICE_H_

#include <windows.h>
#include <d3d9.h>
#include <atlbase.h>
#include <mfapi.h>

typedef void (*IMAGE_TRANSFORM_FN)(
    BYTE*       pDest,
    LONG        lDestStride,
    const BYTE* pSrc,
	DWORD       pSrcSize,
    LONG        lSrcStride,
    UINT       dwWidthInPixels,
    UINT       dwHeightInPixels
    );

class DrawDevice
{
private:

    HWND                    m_hwnd;

    IDirect3D9				*m_pD3D;
    IDirect3DDevice9        *m_pDevice;
    IDirect3DSwapChain9     *m_pSwapChain;

    D3DPRESENT_PARAMETERS   m_d3dpp;

    // Format information
    D3DFORMAT               m_format;
    UINT                    m_width;
    UINT                    m_height;
    LONG                    m_lDefaultStride;
    MFRatio                 m_PixelAR;
    MFVideoInterlaceMode    m_interlace;
    RECT                    m_rcDest;       // Destination rectangle

    // Drawing
    IMAGE_TRANSFORM_FN      m_convertFn;    // Function to convert the video to RGB32

private:
    
    HRESULT TestCooperativeLevel();
    HRESULT SetConversionFunction(REFGUID subtype);
    HRESULT CreateSwapChains();
	template <class T> void safeRelease(T **ppT)
	{
		if (ppT != NULL)
		{
			if (*ppT)
			{
				(*ppT)->Release();
				*ppT = NULL;
			}
		}
	}

public:

    DrawDevice();
    ~DrawDevice();

    HRESULT CreateDevice(HWND hwnd);
    HRESULT ResetDevice();
    void    DestroyDevice();

    HRESULT SetVideoType(IMFMediaType *pType);
    HRESULT DrawFrame(IMFMediaBuffer *pBuffer,IMFSample **pSampleRGB32=NULL, IMFMediaBuffer **pBufferRGB32=NULL);

    BOOL     IsFormatSupported(REFGUID subtype) const;
    HRESULT  GetFormat(DWORD index, GUID *pSubtype)  const;
};

#endif //DRAWDEVICE_H_