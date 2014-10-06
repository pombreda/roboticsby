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

#ifndef CPREVIEW_H_
#define CPREVIEW_H_

#include <windows.h>
#include <d3d9.h>
#include <atlbase.h>

#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>

#include <Dbt.h>

#include "device.h"

const UINT WM_APP_PREVIEW_ERROR = WM_APP + 1;    // wparam = HRESULT

class CPreview : public IMFSourceReaderCallback
{
public:

	CPreview(HWND hVideo, HWND hEvent);
	
	STDMETHODIMP_ (HRESULT) QueryInterface(const IID &riid, void ** ppv)
	{
		QITAB qit[] = 
		{
			QITABENT(CPreview, IMFSourceReaderCallback),
			{ 0 },
		};
		return QISearch(this, qit, riid, ppv);
	}

	STDMETHODIMP_ (ULONG) AddRef()
	{
		return InterlockedIncrement(&m_Ref);
	}

	STDMETHODIMP_ (ULONG) Release()
	{
		ULONG ref = InterlockedDecrement(&m_Ref);

		if (ref == 0)
		{
			delete this;
		}

		return ref;
	}

    STDMETHODIMP OnReadSample(
        HRESULT hrStatus,
        DWORD dwStreamIndex,
        DWORD dwStreamFlags,
        LONGLONG llTimestamp,
        IMFSample *pSample
    );

    STDMETHODIMP OnEvent(DWORD , IMFMediaEvent*)
    {
		return S_OK;
    }

    STDMETHODIMP OnFlush(DWORD)
    {
        return S_OK;
    }

    HRESULT SetDevice(IMFActivate *pVideoActivate, IMFActivate *pAudioActivate, IMFMediaType *pTypeVideo, IMFMediaType *pTypeAudio, UINT cameraDeviceMediaTypeIndex, const WCHAR *pwszFileName);
	HRESULT SetDevicePreview(IMFActivate *pVideoActivate, IMFMediaType *pTypeVideo, UINT cameraDeviceMediaTypeIndex);
	HRESULT SetDevicePreviewAndSaveVideo(IMFActivate *pVideoActivate, IMFMediaType *pTypeVideo, UINT cameraDeviceMediaTypeIndex, const WCHAR *pwszFileName);
	HRESULT CloseDevice();
    HRESULT CheckDeviceLost(DEV_BROADCAST_HDR *pHdr, BOOL *pbDeviceLost);

private:

	~CPreview();
    HRESULT Initialize();
    HRESULT TryMediaType(IMFMediaType *pType);
	HRESULT ConfigureVideoEncoder(IMFMediaType *pType, IMFSinkWriter *pWriter, DWORD *pdwStreamIndex);
	HRESULT CopyAttribute(IMFAttributes *pSrc, IMFAttributes *pDest, const GUID& key);
	BOOL IsCapturing();
	HRESULT CreateAggregatedSource(IMFMediaSource *pSource1, IMFMediaSource *pSource2, IMFMediaSource **ppAggSource);

    volatile ULONG					m_Ref;        
    CRITICAL_SECTION				m_critsec;
    HWND							m_hwndVideo;       
    HWND							m_hwndEvent;        
	IMFSourceReader					*m_pReader;
    DrawDevice						m_draw;             
    WCHAR							*m_pwszSymbolicLinkVideo;
    UINT32							m_cchSymbolicLinkVideo;
	WCHAR							*m_pwszSymbolicLinkAudio;
	UINT32							m_cchSymbolicLinkAudio;
	BOOL							m_bFirstSampleVideo;
	LONGLONG						m_llBaseTimeVideo;
	BOOL							m_bFirstSampleAudio;
	LONGLONG						m_llBaseTimeAudio;
	IMFSinkWriter					*m_pWriter;
};

#endif //CPREVIEW_H_