#include "preview.h"

#include <Wmcodecdsp.h>
#include <Mferror.h>
#include <codecapi.h>
#include <shlwapi.h>
#include <assert.h>
#include <comdef.h>

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

template <class T> void safeReleaseAllCount(T **ppT)
{
	if (ppT != NULL)
	{
		if (*ppT)
		{
			ULONG e = (*ppT)->Release();
			while (e)
			{
				e = (*ppT)->Release();
			}
			*ppT = NULL;
		}
	}
}

CPreview::CPreview(HWND hVideo, HWND hEvent) : 
	m_Ref(1),
	m_pReader(NULL),
	m_pWriter(NULL),
	m_hwndVideo(hVideo),
	m_hwndEvent(hEvent),
	m_pwszSymbolicLinkVideo(NULL),
	m_cchSymbolicLinkVideo(0),
	m_pwszSymbolicLinkAudio(NULL),
	m_cchSymbolicLinkAudio(0),
	m_bFirstSampleVideo(FALSE),
	m_llBaseTimeVideo(0)
{
	assert(hVideo != NULL);
	assert(hEvent != NULL);
	InitializeCriticalSection(&m_critsec);
}

CPreview::~CPreview()
{
	assert(m_pReader == NULL);
	assert(m_pWriter == NULL);
	DeleteCriticalSection(&m_critsec);
}

HRESULT CPreview::CloseDevice()
{
	EnterCriticalSection(&m_critsec);

	HRESULT hr = S_OK;

	if (m_pWriter)
	{
		hr = m_pWriter->Finalize();
	}

	safeRelease(&m_pWriter);
	safeRelease(&m_pReader);

	if (m_pwszSymbolicLinkVideo!=NULL)
	{
		CoTaskMemFree(m_pwszSymbolicLinkVideo);
		m_pwszSymbolicLinkVideo = NULL;
	}
	m_cchSymbolicLinkVideo = NULL;

	if (m_pwszSymbolicLinkAudio!=NULL)
	{
		CoTaskMemFree(m_pwszSymbolicLinkAudio);
		m_pwszSymbolicLinkAudio = NULL;
	}
	m_cchSymbolicLinkAudio = NULL;

	m_draw.DestroyDevice();

	LeaveCriticalSection(&m_critsec);
	return hr;
}

HRESULT CPreview::OnReadSample(HRESULT hrStatus, DWORD dwStreamIndex, DWORD dwStreamFlags, LONGLONG	llTimeStamp, IMFSample *pSample)
{
	EnterCriticalSection(&m_critsec);

	if (dwStreamFlags & MF_SOURCE_READERF_ENDOFSTREAM)
	{
		LeaveCriticalSection(&m_critsec);
		return hrStatus;
	}
	if (dwStreamFlags & MF_SOURCE_READERF_ERROR)
	{
		LeaveCriticalSection(&m_critsec);
		return hrStatus;
	}

	HRESULT hr = hrStatus;

	if (SUCCEEDED(hr))
	{
		if (pSample!=NULL)
		{
			if (m_bFirstSampleVideo)
			{
				m_llBaseTimeVideo = llTimeStamp;
				m_bFirstSampleVideo = FALSE;
			}

			llTimeStamp -= m_llBaseTimeVideo;
			if (dwStreamIndex==0)
			{
				IMFMediaBuffer *pBuffer = NULL;
				DWORD pdwBufferCount;

				hr = pSample->SetSampleTime(llTimeStamp);		

				if (SUCCEEDED(hr)) 
				{
					if (SUCCEEDED(hr))
					{
						hr = pSample->GetBufferCount(&pdwBufferCount);
						if (SUCCEEDED(hr))
						{
							DWORD pcbTotalLength;
							hr = pSample->GetTotalLength(&pcbTotalLength);
							if (SUCCEEDED(hr))
							{
								hr = pSample->GetBufferByIndex(0, &pBuffer);
								if (SUCCEEDED(hr))
								{
									if (IsCapturing())
									{
										IMFSample *pSampleRGB32 = NULL;
										IMFMediaBuffer *pBufferRGB32 = NULL;
										hr = MFCreateSample(&pSampleRGB32);
										hr = m_draw.DrawFrame(pBuffer, &pSampleRGB32, &pBufferRGB32);
										if (pSampleRGB32!=NULL && pBufferRGB32!=NULL)
										{
											LONGLONG sampleTime;
											DWORD sampleFlags;
											LONGLONG sampleDuration;
											hr = pSample->GetSampleTime(&sampleTime);
											hr = pSample->GetSampleFlags(&sampleFlags);
											hr = pSample->GetSampleDuration(&sampleDuration);

											hr = pSampleRGB32->SetSampleTime(sampleTime);
											hr = pSampleRGB32->SetSampleFlags(sampleFlags);
											hr = pSampleRGB32->SetSampleDuration(sampleDuration);
											hr = m_pWriter->WriteSample(dwStreamIndex, pSampleRGB32);
										}
										safeRelease(&pBufferRGB32);
										safeRelease(&pSampleRGB32);
									} else {
										hr = m_draw.DrawFrame(pBuffer);
									}
								}
							}
						}		
					}
				}
				safeRelease(&pBuffer);			
			} else 
				if (dwStreamIndex==1)
				{
					if (m_bFirstSampleAudio)
					{
						m_llBaseTimeAudio = llTimeStamp;
						m_bFirstSampleAudio = FALSE;
					}

					llTimeStamp -= m_llBaseTimeAudio;
					hr = pSample->SetUINT32( MFSampleExtension_Discontinuity, FALSE );
					if (SUCCEEDED(hr)) 
					{
						hr = pSample->SetSampleTime(llTimeStamp);
						if (SUCCEEDED(hr)) 
						{
							if (IsCapturing())
							{
								hr = m_pWriter->WriteSample(dwStreamIndex, pSample);
							}
						}
					}
				}
		}
	}

	if (m_pReader!=NULL && IsCapturing())
	{	
		hr = m_pReader->ReadSample(MF_SOURCE_READER_ANY_STREAM,	0, NULL, NULL, NULL, NULL);
	} else if (m_pReader!=NULL && !IsCapturing())
	{
		hr = m_pReader->ReadSample(MF_SOURCE_READER_FIRST_VIDEO_STREAM,	0, NULL, NULL, NULL, NULL);
	}

	if (FAILED(hr))
	{
		_com_error error(hr);
		LPCTSTR errorText = error.ErrorMessage();
		MessageBox(NULL, errorText, L"Error. Failed to get the frame from the camera.", MB_ICONERROR);
	}

	LeaveCriticalSection(&m_critsec);
	return hr;
}

HRESULT CPreview::TryMediaType(IMFMediaType* pType)
{
	HRESULT hr = S_OK;
	GUID subtype = { 0 };
	hr = pType->GetGUID(MF_MT_SUBTYPE, &subtype);
	if (SUCCEEDED(hr)) 
	{ 
		if (m_draw.IsFormatSupported(subtype))
		{
			hr = m_draw.SetVideoType(pType);
		} else
		{
			hr = MF_E_TOPO_CODEC_NOT_FOUND;
		}
	}
	return hr;
}

HRESULT setDeviceFormat(IMFMediaSource *pSource, DWORD  dwFormatIndex)
{
	IMFPresentationDescriptor *pPD = NULL;
	IMFStreamDescriptor *pSD = NULL;
	IMFMediaTypeHandler *pHandler = NULL;
	IMFMediaType *pType = NULL;

	HRESULT hr = pSource->CreatePresentationDescriptor(&pPD);
	if (SUCCEEDED(hr))
	{
		BOOL fSelected;
		hr = pPD->GetStreamDescriptorByIndex(0, &fSelected, &pSD);
		if (SUCCEEDED(hr))
		{
			hr = pSD->GetMediaTypeHandler(&pHandler);
			if (SUCCEEDED(hr))
			{
				hr = pHandler->GetMediaTypeByIndex(dwFormatIndex, &pType);
				if (SUCCEEDED(hr))
				{
					hr = pHandler->SetCurrentMediaType(pType);
				}
			}
		}
	}

	safeReleaseAllCount(&pPD);
	safeRelease(&pSD);
	safeRelease(&pHandler);
	safeRelease(&pType);
	return hr;
}

HRESULT CPreview::ConfigureVideoEncoder(IMFMediaType *pType, IMFSinkWriter *pWriter, DWORD *pdwStreamIndex)
{
	HRESULT hr = S_OK;

	IMFMediaType *pType2 = NULL;

	hr = MFCreateMediaType(&pType2);   

	if (SUCCEEDED(hr))
	{
		hr = pType2->SetGUID( MF_MT_MAJOR_TYPE, MFMediaType_Video );     
	}

	if (SUCCEEDED(hr))
	{
		hr = pType2->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_H264);
	}

	if (SUCCEEDED(hr))
	{
		hr = pType2->SetUINT32(MF_MT_MPEG2_PROFILE, eAVEncH264VProfile_Main);
	}

	if (SUCCEEDED(hr))
	{
		UINT32 width;
		UINT32 height;
		hr = MFGetAttributeSize(pType, MF_MT_FRAME_SIZE, &width, &height);
		if (SUCCEEDED(hr))
		{
			hr = pType2->SetUINT32(MF_MT_AVG_BITRATE,width*height*32);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = CopyAttribute(pType, pType2, MF_MT_FRAME_SIZE);
	}

	if (SUCCEEDED(hr))
	{
		hr = CopyAttribute(pType, pType2, MF_MT_FRAME_RATE);
	}

	if (SUCCEEDED(hr))
	{
		hr = CopyAttribute(pType, pType2, MF_MT_PIXEL_ASPECT_RATIO);
	}

	if (SUCCEEDED(hr))
	{
		hr = CopyAttribute(pType, pType2, MF_MT_INTERLACE_MODE);
	}

	if (SUCCEEDED(hr))
	{
		hr = pWriter->AddStream(pType2, pdwStreamIndex);
	}

	safeRelease(&pType2);
	return hr;
}

template <class Q>
HRESULT GetCollectionObject(IMFCollection *pCollection, DWORD dwIndex, Q **ppObject)
{
	*ppObject = NULL;   // zero output

	IUnknown *pUnk = NULL;
	HRESULT hr = pCollection->GetElement(dwIndex, &pUnk);
	if (SUCCEEDED(hr))
	{
		hr = pUnk->QueryInterface(IID_PPV_ARGS(ppObject));
		pUnk->Release();
	}
	return hr;
}

HRESULT CPreview::SetDevice(IMFActivate *pVideoActivate, IMFActivate *pAudioActivate, IMFMediaType *pTypeVideo, IMFMediaType *pTypeAudio, UINT cameraDeviceMediaTypeIndex, const WCHAR *pwszFileName)
{
	EnterCriticalSection(&m_critsec);

	HRESULT hr = S_OK;

	IMFMediaSource  *pVideoSource = NULL;
	IMFAttributes   *pAttributes = NULL;
	IMFMediaSource  *pAudioSource = NULL;
	IMFAttributes   *pAudioAttributes = NULL;
	IMFMediaSource  *pSource = NULL;

	hr = CloseDevice();

	if (SUCCEEDED(hr))
	{
		m_draw.DestroyDevice();
		hr = m_draw.CreateDevice(m_hwndVideo);
	}

	if (SUCCEEDED(hr))
	{
		hr = pVideoActivate->ActivateObject(
			__uuidof(IMFMediaSource), 
			(void**)&pVideoSource
			);
	}

	if (SUCCEEDED(hr) && pAudioActivate!=NULL)
	{
		hr = pAudioActivate->ActivateObject(
			__uuidof(IMFMediaSource), 
			(void**)&pAudioSource
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = pVideoActivate->GetAllocatedString(
			MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK,
			&m_pwszSymbolicLinkVideo,
			&m_cchSymbolicLinkVideo
			);
	}

	if (SUCCEEDED(hr) && pAudioActivate!=NULL)
	{
		hr = pAudioActivate->GetAllocatedString(
			MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ENDPOINT_ID,
			&m_pwszSymbolicLinkAudio,
			&m_cchSymbolicLinkAudio
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = MFCreateAttributes(&pAttributes, 3);
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUINT32(MF_LOW_LATENCY, TRUE);
	}
	if (SUCCEEDED(hr) && pwszFileName==NULL)
	{
		hr = pAttributes->SetUINT32 (MF_READWRITE_DISABLE_CONVERTERS, TRUE); 
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUnknown(MF_SOURCE_READER_ASYNC_CALLBACK,this);
	}

	if (SUCCEEDED(hr))
	{
		hr = setDeviceFormat(pVideoSource,cameraDeviceMediaTypeIndex);
	}

	if (SUCCEEDED(hr))
	{	
		hr = TryMediaType(pTypeVideo);
	}

	if (SUCCEEDED(hr) && pAudioActivate!=NULL)
	{
		hr = CreateAggregatedSource(pVideoSource, pAudioSource, &pSource);
	}

	if (SUCCEEDED(hr) && pAudioActivate!=NULL)
	{
		hr = MFCreateSourceReaderFromMediaSource(
			pSource,
			pAttributes,
			&m_pReader
			);
	} else {
		if (SUCCEEDED(hr))
		{
			hr = MFCreateSourceReaderFromMediaSource(
				pVideoSource,
				pAttributes,
				&m_pReader
				);
		}
	}

	if (SUCCEEDED(hr) && pwszFileName!=NULL)
	{
		safeRelease(&pAttributes);
		if (SUCCEEDED(hr))
		{
			hr = MFCreateAttributes(&pAttributes, 1);
		}

		if (SUCCEEDED(hr))
		{
			hr = pAttributes->SetUINT32(MF_LOW_LATENCY, TRUE);
		}

		hr = MFCreateSinkWriterFromURL(
			pwszFileName,
			NULL,
			pAttributes,
			&m_pWriter
			);
	}    

	DWORD sinkStreamVideo = 0;
	DWORD sinkStreamAudio = 1;

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{
		hr = ConfigureVideoEncoder(pTypeVideo, m_pWriter, &sinkStreamVideo);
	}

	safeRelease(&pAttributes);
	if (SUCCEEDED(hr) && pAudioActivate!=NULL)
	{
		IMFCollection *pAvailableTypes = NULL;
		IMFMediaType *pAudioOutType = NULL;

		if (SUCCEEDED(hr)){
			hr = MFCreateAttributes(&pAttributes, 2);
		}
		if (SUCCEEDED(hr)){
			hr = pAttributes->SetUINT32(MF_LOW_LATENCY, TRUE);
		}
		if (SUCCEEDED(hr)){
			hr = pAttributes->SetUINT32(MF_TRANSFORM_ASYNC_UNLOCK, TRUE);
		}
		if (SUCCEEDED(hr)){
			hr = MFTranscodeGetAudioOutputAvailableTypes(MFAudioFormat_AAC, MFT_ENUM_FLAG_ALL | MFT_ENUM_FLAG_SORTANDFILTER,
				pAttributes, &pAvailableTypes);
		}
		if (SUCCEEDED(hr)){
			hr = GetCollectionObject(pAvailableTypes, 0, &pAudioOutType);
		}
		if (SUCCEEDED(hr)){
			hr = pAudioOutType->SetUINT32( MF_MT_AUDIO_BITS_PER_SAMPLE, 16 );
		}
		UINT32 samples;
		if (SUCCEEDED(hr)){
			hr = pTypeAudio->GetUINT32( MF_MT_AUDIO_SAMPLES_PER_SECOND, &samples );
		}
		if (SUCCEEDED(hr)){
			if (samples==44100 || samples==48000)
			{
				hr = CopyAttribute(pTypeAudio, pAudioOutType, MF_MT_AUDIO_SAMPLES_PER_SECOND);
			} else
			{
				hr = MF_E_UNSUPPORTED_RATE;
			}
		}

		if (SUCCEEDED(hr)){
			hr = CopyAttribute(pTypeAudio, pAudioOutType, MF_MT_AUDIO_NUM_CHANNELS);
		}

		if (SUCCEEDED(hr)){
			hr = pAudioOutType->SetUINT32( MF_MT_AUDIO_AVG_BYTES_PER_SECOND, 24000 );
		}

		if (SUCCEEDED(hr) && m_pWriter!=NULL){
			hr = m_pWriter->AddStream(pAudioOutType, &sinkStreamAudio);
		}

		safeRelease(&pAudioOutType);
		safeRelease(&pAvailableTypes);
	}

	if (SUCCEEDED(hr))
	{
		hr = MFTRegisterLocalByCLSID(
			__uuidof(CColorConvertDMO),
			MFT_CATEGORY_VIDEO_PROCESSOR,
			L"",
			MFT_ENUM_FLAG_SYNCMFT,
			0,
			NULL,
			0,
			NULL
			);
	}

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{
		hr = m_pWriter->SetInputMediaType(sinkStreamVideo, pTypeVideo, NULL);
	}

	if (SUCCEEDED(hr) && pAudioActivate!=NULL && m_pWriter!=NULL)
	{
		hr = m_pWriter->SetInputMediaType(sinkStreamAudio, pTypeAudio, NULL);
	}

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{		
		hr = m_pWriter->BeginWriting();
	}

	if (SUCCEEDED(hr) && m_pWriter==NULL)
	{
		m_bFirstSampleVideo = TRUE;
		m_llBaseTimeVideo = 0;
		m_bFirstSampleAudio = TRUE;
		m_llBaseTimeAudio = 0;

		hr = m_pReader->ReadSample(
			(DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM,
			0,
			NULL,
			NULL,
			NULL,
			NULL
			);
	} else {
		if (SUCCEEDED(hr) && m_pWriter!=NULL)
		{
			m_bFirstSampleVideo = TRUE;
			m_llBaseTimeVideo = 0;
			m_bFirstSampleAudio = TRUE;
			m_llBaseTimeAudio = 0;

			hr = m_pReader->ReadSample(
				(DWORD)MF_SOURCE_READER_ANY_STREAM,
				0,
				NULL,
				NULL,
				NULL,
				NULL
				);
		}
	}

	if (FAILED(hr))
	{
		if (pSource!=NULL)
		{
			pSource->Shutdown();
		}
		CloseDevice();
		m_draw.DestroyDevice();
	}

	safeRelease(&pAttributes);
	safeRelease(&pVideoSource);
	safeRelease(&pAudioAttributes);
	safeRelease(&pAudioSource);
	safeRelease(&pSource);

	LeaveCriticalSection(&m_critsec);
	return hr;
}

HRESULT  CPreview::CopyAttribute(IMFAttributes *pSrc, IMFAttributes *pDest, const GUID& key)
{
	PROPVARIANT var;
	PropVariantInit(&var);

	HRESULT hr = S_OK;

	hr = pSrc->GetItem(key, &var);
	if (SUCCEEDED(hr))
	{
		hr = pDest->SetItem(key, var);
	}

	PropVariantClear(&var);
	return hr;
}

HRESULT CPreview::CreateAggregatedSource(IMFMediaSource *videoSource, IMFMediaSource *audioSource, IMFMediaSource **aggregateSource)
{
	*aggregateSource = NULL;
	IMFCollection *pCollection = NULL;

	HRESULT hr = MFCreateCollection(&pCollection);

	if (SUCCEEDED(hr))
		hr = pCollection->AddElement(videoSource);

	if (SUCCEEDED(hr))
		hr = pCollection->AddElement(audioSource);

	if (SUCCEEDED(hr))
		hr = MFCreateAggregateSource(pCollection, aggregateSource);

	safeRelease(&pCollection);
	return hr;
}

BOOL CPreview::IsCapturing()
{
	EnterCriticalSection(&m_critsec);

	BOOL bIsCapturing = (m_pWriter != NULL);

	LeaveCriticalSection(&m_critsec);

	return bIsCapturing;
}

HRESULT CPreview::CheckDeviceLost(DEV_BROADCAST_HDR *pHdr, BOOL *pbDeviceLost)
{

	DEV_BROADCAST_DEVICEINTERFACE *pDi = NULL;

	EnterCriticalSection(&m_critsec);

	if (pbDeviceLost == NULL)
	{
		return E_POINTER;
	}

	*pbDeviceLost = FALSE;

	if (pHdr == NULL)
	{
		return S_OK;
	}

	if (pHdr->dbch_devicetype != DBT_DEVTYP_DEVICEINTERFACE)
	{
		return S_OK;
	}

	pDi = (DEV_BROADCAST_DEVICEINTERFACE*)pHdr;

	if (m_pwszSymbolicLinkVideo)
	{
		if (_wcsicmp(m_pwszSymbolicLinkVideo, pDi->dbcc_name) == 0)
		{
			*pbDeviceLost = TRUE;
		}
	}

	LeaveCriticalSection(&m_critsec);

	return S_OK;
}

HRESULT CPreview::SetDevicePreview( IMFActivate *pVideoActivate, IMFMediaType *pTypeVideo, UINT cameraDeviceMediaTypeIndex )
{
	EnterCriticalSection(&m_critsec);

	HRESULT hr = S_OK;

	IMFMediaSource  *pVideoSource = NULL;
	IMFAttributes   *pAttributes = NULL;

	hr = CloseDevice();

	if (SUCCEEDED(hr))
	{
		m_draw.DestroyDevice();
		hr = m_draw.CreateDevice(m_hwndVideo);
	}

	if (SUCCEEDED(hr))
	{
		hr = pVideoActivate->ActivateObject(
			__uuidof(IMFMediaSource), 
			(void**)&pVideoSource
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = pVideoActivate->GetAllocatedString(
			MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK,
			&m_pwszSymbolicLinkVideo,
			&m_cchSymbolicLinkVideo
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = MFCreateAttributes(&pAttributes, 3);
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUINT32(MF_LOW_LATENCY, TRUE);
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUINT32 (MF_READWRITE_DISABLE_CONVERTERS, TRUE); 
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUnknown(MF_SOURCE_READER_ASYNC_CALLBACK,this);
	}
	if (SUCCEEDED(hr))
	{
		hr = setDeviceFormat(pVideoSource,cameraDeviceMediaTypeIndex);
	}
	if (SUCCEEDED(hr))
	{	
		hr = TryMediaType(pTypeVideo);
	}
	if (SUCCEEDED(hr))
	{
		hr = MFCreateSourceReaderFromMediaSource(pVideoSource,	pAttributes, &m_pReader);
	}

	safeRelease(&pAttributes);

	if (SUCCEEDED(hr))
	{
		hr = MFTRegisterLocalByCLSID(
			__uuidof(CColorConvertDMO),
			MFT_CATEGORY_VIDEO_PROCESSOR,
			L"",
			MFT_ENUM_FLAG_SYNCMFT,
			0,
			NULL,
			0,
			NULL
			);
	}

	if (SUCCEEDED(hr) && m_pWriter==NULL)
	{
		m_bFirstSampleVideo = TRUE;
		m_llBaseTimeVideo = 0;

		hr = m_pReader->ReadSample(
			(DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM,
			0,
			NULL,
			NULL,
			NULL,
			NULL
			);
	}

	if (FAILED(hr))
	{
		if (pVideoSource!=NULL)
		{
			pVideoSource->Shutdown();
		}
		CloseDevice();
		m_draw.DestroyDevice();
	}

	safeRelease(&pVideoSource);

	LeaveCriticalSection(&m_critsec);
	return hr;
}

HRESULT CPreview::SetDevicePreviewAndSaveVideo(IMFActivate *pVideoActivate, IMFMediaType *pTypeVideo, UINT cameraDeviceMediaTypeIndex, const WCHAR *pwszFileName )
{
	EnterCriticalSection(&m_critsec);

	HRESULT hr = S_OK;

	IMFMediaSource  *pVideoSource = NULL;
	IMFAttributes   *pAttributes = NULL;

	hr = CloseDevice();

	if (SUCCEEDED(hr))
	{
		m_draw.DestroyDevice();
		hr = m_draw.CreateDevice(m_hwndVideo);
	}

	if (SUCCEEDED(hr))
	{
		hr = pVideoActivate->ActivateObject(
			__uuidof(IMFMediaSource), 
			(void**)&pVideoSource
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = pVideoActivate->GetAllocatedString(
			MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK,
			&m_pwszSymbolicLinkVideo,
			&m_cchSymbolicLinkVideo
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = MFCreateAttributes(&pAttributes, 3);
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUINT32(MF_LOW_LATENCY, TRUE);
	}
	if (SUCCEEDED(hr) && pwszFileName==NULL)
	{
		hr = pAttributes->SetUINT32 (MF_READWRITE_DISABLE_CONVERTERS, TRUE); 
	}
	if (SUCCEEDED(hr))
	{
		hr = pAttributes->SetUnknown(MF_SOURCE_READER_ASYNC_CALLBACK,this);
	}

	if (SUCCEEDED(hr))
	{
		hr = setDeviceFormat(pVideoSource,cameraDeviceMediaTypeIndex);
	}

	if (SUCCEEDED(hr))
	{	
		hr = TryMediaType(pTypeVideo);
	}

	if (SUCCEEDED(hr))
	{
		hr = MFCreateSourceReaderFromMediaSource(pVideoSource, pAttributes,	&m_pReader);
	}

	if (SUCCEEDED(hr) && pwszFileName!=NULL)
	{
		safeRelease(&pAttributes);
		if (SUCCEEDED(hr))
		{
			hr = MFCreateAttributes(&pAttributes, 1);
		}

		if (SUCCEEDED(hr))
		{
			hr = pAttributes->SetUINT32(MF_LOW_LATENCY, TRUE);
		}

		hr = MFCreateSinkWriterFromURL(
			pwszFileName,
			NULL,
			pAttributes,
			&m_pWriter
			);
	}    

	DWORD sinkStreamVideo = 0;

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{
		hr = ConfigureVideoEncoder(pTypeVideo, m_pWriter, &sinkStreamVideo);
	}

	if (SUCCEEDED(hr))
	{
		hr = MFTRegisterLocalByCLSID(
			__uuidof(CColorConvertDMO),
			MFT_CATEGORY_VIDEO_PROCESSOR,
			L"",
			MFT_ENUM_FLAG_SYNCMFT,
			0,
			NULL,
			0,
			NULL
			);
	}

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{
		hr = pTypeVideo->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_RGB32);
		if (SUCCEEDED(hr))
		{
			hr = m_pWriter->SetInputMediaType(sinkStreamVideo, pTypeVideo, NULL);
		}
	}

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{		
		hr = m_pWriter->BeginWriting();
	}

	if (SUCCEEDED(hr) && m_pWriter!=NULL)
	{
		m_bFirstSampleVideo = TRUE;
		m_llBaseTimeVideo = 0;

		hr = m_pReader->ReadSample(
			(DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM,
			0,
			NULL,
			NULL,
			NULL,
			NULL
			);
	}

	if (FAILED(hr))
	{
		if (pVideoSource!=NULL)
		{
			pVideoSource->Shutdown();
		}
		CloseDevice();
		m_draw.DestroyDevice();
	}

	safeRelease(&pAttributes);
	safeRelease(&pVideoSource);

	LeaveCriticalSection(&m_critsec);
	return hr;
}