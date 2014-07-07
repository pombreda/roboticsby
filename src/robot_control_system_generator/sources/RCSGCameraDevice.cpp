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

#include <QRegExp>
#include <QStringList>
#include <mfapi.h>
#include <mfidl.h>
#include <uuids.h>
#include "RCSGCameraDevice.h"
#include "RCSGUsbIds.h"

RCSGCameraDevice::RCSGCameraDevice(const UINT &cameraSlot)
{
	this->cameraSlot = cameraSlot;
	cameraVendor.clear();
	cameraDescription.clear();
	cameraMediaTypes = new QVector<IMFMediaType*>;

	if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE)))
	{
		if (SUCCEEDED(MFStartup(MF_VERSION)))
		{
			IMFAttributes *iMFAttributes = NULL;
			IMFActivate **iMFActivate = NULL;
			if (SUCCEEDED(MFCreateAttributes(&iMFAttributes, 1)))
			{
				if (SUCCEEDED(iMFAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID)))
				{
					UINT32 count=0;
					if (SUCCEEDED(MFEnumDeviceSources(iMFAttributes, &iMFActivate, &count)))
					{
						if(cameraSlot<count)
						{
							LPWSTR friendlyName = NULL;
							LPWSTR symbolicLink = NULL;
							UINT32 lenght = 0;
							if(SUCCEEDED(iMFActivate[cameraSlot]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,&friendlyName,&lenght)))
							{
								if(SUCCEEDED(iMFActivate[cameraSlot]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK,&symbolicLink,&lenght)))
								{
									cameraDescription.clear();
									cameraVendor.clear();
									RCSGUsbIds idsDataBase;
									cameraVendor.append(idsDataBase.Manufacture(extractVid(symbolicLink)));
									cameraDescription.append(idsDataBase.Product(extractVid(symbolicLink),extractPid(symbolicLink)));
									if (cameraDescription.count()==0)
									{
										cameraDescription.append(QString::fromStdWString(friendlyName));
									}

									IMFMediaSource *iMFMediaSource = NULL;
									
									if (SUCCEEDED(iMFActivate[cameraSlot]->ActivateObject(IID_PPV_ARGS(&iMFMediaSource))))
									{						
										IMFPresentationDescriptor *iMFPresentationDescriptor = NULL;
										IMFStreamDescriptor *iMFStreamDescriptor = NULL;
										IMFMediaTypeHandler *iMFMediaTypeHandler = NULL;
										IMFMediaType *iMFMediaType = NULL;
										if (SUCCEEDED(iMFMediaSource->CreatePresentationDescriptor(&iMFPresentationDescriptor)))
										{
											BOOL selectedPresentationDescriptor;
											if (SUCCEEDED(iMFPresentationDescriptor->GetStreamDescriptorByIndex(0, &selectedPresentationDescriptor, &iMFStreamDescriptor)))
											{
												if (SUCCEEDED(iMFStreamDescriptor->GetMediaTypeHandler(&iMFMediaTypeHandler)))
												{
													DWORD types = 0;
													if (SUCCEEDED(iMFMediaTypeHandler->GetMediaTypeCount(&types)))
													{
														cameraMediaTypesDeviceCapacites.clear();
														for (DWORD i = 0; i < types; i++)
														{
															if (SUCCEEDED(iMFMediaTypeHandler->GetMediaTypeByIndex(i, &iMFMediaType)))
															{
																cameraMediaTypes->append(iMFMediaType);
																QHash<QString,QString> hashTable;
																UINT32 cAttributes = 0;
																if (SUCCEEDED(iMFMediaType->GetCount(&cAttributes)))
																{					
																	for (UINT32 nIndex = 0; nIndex < cAttributes; ++nIndex)
																	{
																		GUID guid;
																		PROPVARIANT propertyVariant;
																		PropVariantInit(&propertyVariant);
																		if (SUCCEEDED(iMFMediaType->GetItemByIndex(nIndex, &guid, &propertyVariant)))
																		{																			
																			hashTable[decodeMediaTypeKey(guid)]=decodeMediaTypeValue(guid, propertyVariant);
																		}
																		PropVariantClear(&propertyVariant);
																	}
																}
																cameraMediaTypesDeviceCapacites.append(hashTable);
															}
															safeRelease(&iMFMediaType);
														}
													}
												}
											}
										}
										safeRelease(&iMFPresentationDescriptor);
										safeRelease(&iMFStreamDescriptor);
										safeRelease(&iMFMediaTypeHandler);
										safeRelease(&iMFMediaType);
									}
									safeRelease(&iMFMediaSource);
									safeRelease(&iMFActivate[cameraSlot]);
								
									CoTaskMemFree(symbolicLink);
									symbolicLink = NULL;
								}
								CoTaskMemFree(friendlyName);
								friendlyName = NULL;
							}
						}
						for(UINT32 i=0; i<count; i++)
						{
							safeRelease(&iMFActivate[i]);
						}
					}
				}
			}
			safeRelease(iMFActivate);
			safeRelease(&iMFAttributes);
			MFShutdown();
			CoUninitialize();
		}
	}
	sortMediaTypesDeviceCapacitesByFrameSize();
}

RCSGCameraDevice::~RCSGCameraDevice()
{
	if (cameraMediaTypes != NULL)
	{
		QVector<IMFMediaType*>::iterator iterator;
		for (iterator = cameraMediaTypes->begin(); iterator != cameraMediaTypes->end(); ++iterator)
		{
			safeRelease(&(*iterator));
		}
		cameraMediaTypes->clear();
		delete cameraMediaTypes;
		cameraMediaTypes = NULL;
	}
}

template <class T> void RCSGCameraDevice::safeRelease(T **ppT)
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

QString RCSGCameraDevice::decodeMediaTypeKey( const GUID &giud )
{
	QString result("Unknown");
	if (IsEqualGUID(giud,MF_MT_MAJOR_TYPE)) return QString("MF_MT_MAJOR_TYPE");
	if (IsEqualGUID(giud,MF_MT_SUBTYPE)) return QString("MF_MT_SUBTYPE");
	if (IsEqualGUID(giud,MF_MT_FRAME_SIZE)) return QString("MF_MT_FRAME_SIZE");
	if (IsEqualGUID(giud,MF_MT_DEFAULT_STRIDE)) return QString("MF_MT_DEFAULT_STRIDE");
	if (IsEqualGUID(giud,MF_MT_FRAME_RATE)) return QString("MF_MT_FRAME_RATE");
	if (IsEqualGUID(giud,MF_MT_ALL_SAMPLES_INDEPENDENT)) return QString("MF_MT_ALL_SAMPLES_INDEPENDENT"); 
	if (IsEqualGUID(giud,MF_MT_INTERLACE_MODE)) return QString("MF_MT_INTERLACE_MODE");
	if (IsEqualGUID(giud,MF_MT_FIXED_SIZE_SAMPLES)) return QString("MF_MT_FIXED_SIZE_SAMPLES");
	if (IsEqualGUID(giud,MF_MT_SAMPLE_SIZE)) return QString("MF_MT_SAMPLE_SIZE");
	if (IsEqualGUID(giud,MF_MT_AVG_BITRATE)) return QString("MF_MT_AVG_BITRATE");
	if (IsEqualGUID(giud,MF_MT_PIXEL_ASPECT_RATIO)) return QString("MF_MT_PIXEL_ASPECT_RATIO");
	if (IsEqualGUID(giud,MF_MT_AM_FORMAT_TYPE)) return QString("MF_MT_AM_FORMAT_TYPE");
	if (IsEqualGUID(giud,MF_MT_FRAME_RATE_RANGE_MAX)) return QString("MF_MT_FRAME_RATE_RANGE_MAX");
	if (IsEqualGUID(giud,MF_MT_FRAME_RATE_RANGE_MIN)) return QString("MF_MT_FRAME_RATE_RANGE_MIN");
	if (IsEqualGUID(giud,MF_MT_VIDEO_CHROMA_SITING)) return QString("MF_MT_VIDEO_CHROMA_SITING");
	if (IsEqualGUID(giud,MF_MT_VIDEO_NOMINAL_RANGE)) return QString("MF_MT_VIDEO_NOMINAL_RANGE");
	if (IsEqualGUID(giud,MF_MT_VIDEO_LIGHTING)) return QString("MF_MT_VIDEO_LIGHTING");
	if (IsEqualGUID(giud,MF_MT_VIDEO_PRIMARIES)) return QString("MF_MT_VIDEO_PRIMARIES");
	if (IsEqualGUID(giud,MF_MT_YUV_MATRIX)) return QString("MF_MT_YUV_MATRIX");	   
	return result;
}

QString RCSGCameraDevice::decodeMediaTypeValue( const GUID &giud, const PROPVARIANT &variant )
{
	QString result("Unknown");
	if (IsEqualGUID(giud,MF_MT_MAJOR_TYPE))
	{		
		if (variant.vt == VT_CLSID)
		{
			if (IsEqualGUID(MEDIATYPE_Video,*variant.puuid)) return QString("MEDIATYPE_Video");
		}
	}
	if (IsEqualGUID(giud,MF_MT_SUBTYPE))
	{		
		if (variant.vt == VT_CLSID)
		{
			if (IsEqualGUID(MFVideoFormat_RGB8,*variant.puuid)) return QString("MFVideoFormat_RGB8");
			if (IsEqualGUID(MFVideoFormat_RGB555,*variant.puuid)) return QString("MFVideoFormat_RGB555");
			if (IsEqualGUID(MFVideoFormat_RGB565,*variant.puuid)) return QString("MFVideoFormat_RGB565");
			if (IsEqualGUID(MFVideoFormat_RGB24,*variant.puuid)) return QString("MFVideoFormat_RGB24");
			if (IsEqualGUID(MFVideoFormat_RGB32,*variant.puuid)) return QString("MFVideoFormat_RGB32");
			if (IsEqualGUID(MFVideoFormat_ARGB32,*variant.puuid)) return QString("MFVideoFormat_ARGB32");

			if (IsEqualGUID(MFVideoFormat_AI44,*variant.puuid)) return QString("MFVideoFormat_AI44");
			if (IsEqualGUID(MFVideoFormat_AYUV,*variant.puuid)) return QString("MFVideoFormat_AYUV");
			if (IsEqualGUID(MFVideoFormat_I420,*variant.puuid)) return QString("MFVideoFormat_I420");
			if (IsEqualGUID(MFVideoFormat_IYUV,*variant.puuid)) return QString("MFVideoFormat_IYUV");
			if (IsEqualGUID(MFVideoFormat_NV11,*variant.puuid)) return QString("MFVideoFormat_NV11");
			if (IsEqualGUID(MFVideoFormat_NV12,*variant.puuid)) return QString("MFVideoFormat_NV12");
			if (IsEqualGUID(MFVideoFormat_UYVY,*variant.puuid)) return QString("MFVideoFormat_UYVY");
			if (IsEqualGUID(MFVideoFormat_Y41P,*variant.puuid)) return QString("MFVideoFormat_Y41P");
			if (IsEqualGUID(MFVideoFormat_Y41T,*variant.puuid)) return QString("MFVideoFormat_Y41T");
			if (IsEqualGUID(MFVideoFormat_Y42T,*variant.puuid)) return QString("MFVideoFormat_Y42T");
			if (IsEqualGUID(MFVideoFormat_YUY2,*variant.puuid)) return QString("MFVideoFormat_YUY2");
			if (IsEqualGUID(MFVideoFormat_YV12,*variant.puuid)) return QString("MFVideoFormat_YV12");

			if (IsEqualGUID(MFVideoFormat_P010,*variant.puuid)) return QString("MFVideoFormat_P010");
			if (IsEqualGUID(MFVideoFormat_P016,*variant.puuid)) return QString("MFVideoFormat_P016");
			if (IsEqualGUID(MFVideoFormat_P210,*variant.puuid)) return QString("MFVideoFormat_P210");
			if (IsEqualGUID(MFVideoFormat_P216,*variant.puuid)) return QString("MFVideoFormat_P216");
			if (IsEqualGUID(MFVideoFormat_v210,*variant.puuid)) return QString("MFVideoFormat_v210");
			if (IsEqualGUID(MFVideoFormat_v216,*variant.puuid)) return QString("MFVideoFormat_v216");
			if (IsEqualGUID(MFVideoFormat_v410,*variant.puuid)) return QString("MFVideoFormat_v410");
			if (IsEqualGUID(MFVideoFormat_Y210,*variant.puuid)) return QString("MFVideoFormat_Y210");
			if (IsEqualGUID(MFVideoFormat_Y216,*variant.puuid)) return QString("MFVideoFormat_Y216");
			if (IsEqualGUID(MFVideoFormat_Y410,*variant.puuid)) return QString("MFVideoFormat_Y410");
			if (IsEqualGUID(MFVideoFormat_Y416,*variant.puuid)) return QString("MFVideoFormat_Y416");

			if (IsEqualGUID(MFVideoFormat_DV25,*variant.puuid)) return QString("MFVideoFormat_DV25");
			if (IsEqualGUID(MFVideoFormat_DV50,*variant.puuid)) return QString("MFVideoFormat_DV50");
			if (IsEqualGUID(MFVideoFormat_DVC,*variant.puuid)) return QString("MFVideoFormat_DVC");
			if (IsEqualGUID(MFVideoFormat_DVH1,*variant.puuid)) return QString("MFVideoFormat_DVH1");
			if (IsEqualGUID(MFVideoFormat_DVHD,*variant.puuid)) return QString("MFVideoFormat_DVHD");
			if (IsEqualGUID(MFVideoFormat_DVSD,*variant.puuid)) return QString("MFVideoFormat_DVSD");
			if (IsEqualGUID(MFVideoFormat_DVSL,*variant.puuid)) return QString("MFVideoFormat_DVSL");
			if (IsEqualGUID(MFVideoFormat_H263,*variant.puuid)) return QString("MFVideoFormat_H263");
			if (IsEqualGUID(MFVideoFormat_H264,*variant.puuid)) return QString("MFVideoFormat_H264");
			if (IsEqualGUID(MFVideoFormat_H264_ES,*variant.puuid)) return QString("MFVideoFormat_H264_ES");
			if (IsEqualGUID(MFVideoFormat_M4S2,*variant.puuid)) return QString("MFVideoFormat_M4S2");
			if (IsEqualGUID(MFVideoFormat_MJPG,*variant.puuid)) return QString("MFVideoFormat_MJPG");
			if (IsEqualGUID(MFVideoFormat_MP43,*variant.puuid)) return QString("MFVideoFormat_MP43");
			if (IsEqualGUID(MFVideoFormat_MP4S,*variant.puuid)) return QString("MFVideoFormat_MP4S");
			if (IsEqualGUID(MFVideoFormat_MP4V,*variant.puuid)) return QString("MFVideoFormat_MP4V");
			if (IsEqualGUID(MFVideoFormat_MPEG2,*variant.puuid)) return QString("MFVideoFormat_MPEG2");
			if (IsEqualGUID(MFVideoFormat_MPG1,*variant.puuid)) return QString("MFVideoFormat_MPG1");
			if (IsEqualGUID(MFVideoFormat_MSS1,*variant.puuid)) return QString("MFVideoFormat_MSS1");
			if (IsEqualGUID(MFVideoFormat_MSS2,*variant.puuid)) return QString("MFVideoFormat_MSS2");
			if (IsEqualGUID(MFVideoFormat_WMV1,*variant.puuid)) return QString("MFVideoFormat_WMV1");
			if (IsEqualGUID(MFVideoFormat_WMV2,*variant.puuid)) return QString("MFVideoFormat_WMV2");
			if (IsEqualGUID(MFVideoFormat_WMV3,*variant.puuid)) return QString("MFVideoFormat_WMV3");
			if (IsEqualGUID(MFVideoFormat_WVC1,*variant.puuid)) return QString("MFVideoFormat_WVC1");
			if (IsEqualGUID(MFVideoFormat_420O,*variant.puuid)) return QString("MFVideoFormat_420O");
		}
	}
	if (IsEqualGUID(giud,MF_MT_FRAME_SIZE))
	{		
		if (variant.vt == VT_UI8)
		{
			return QString("%1x%2").arg(QString::number(variant.cyVal.Hi),QString::number(variant.cyVal.Lo));
		}
	}
	if (IsEqualGUID(giud,MF_MT_FRAME_RATE))
	{		
		if (variant.vt == VT_UI8)
		{
			return QString("%1 fps").arg(QString::number(variant.cyVal.Hi/variant.cyVal.Lo));
		}
	}
	if (IsEqualGUID(giud,MF_MT_AVG_BITRATE))
	{		
		if (variant.vt == VT_UI4)
		{
			return QString("%1 kbytes/s").arg(QString::number(variant.ulVal/8/1024));
		}
	}
	if (IsEqualGUID(giud,MF_MT_FRAME_RATE_RANGE_MIN))
	{		
		if (variant.vt == VT_UI8)
		{
			return QString("%1 fps").arg(QString::number(variant.cyVal.Hi/variant.cyVal.Lo));
		}
	}
	if (IsEqualGUID(giud,MF_MT_FRAME_RATE_RANGE_MAX))
	{		
		if (variant.vt == VT_UI8)
		{
			return QString("%1 fps").arg(QString::number(variant.cyVal.Hi/variant.cyVal.Lo));
		}
	}
	if (IsEqualGUID(giud,MF_MT_DEFAULT_STRIDE))
	{		
		if (variant.vt == VT_UI4)
		{
			return QString("%1").arg(QString::number(variant.intVal));
		}
	}
	if (IsEqualGUID(giud,MF_MT_INTERLACE_MODE))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo==MFVideoInterlace_Unknown)	return QString("MFVideoInterlace_Unknown");
			if (variant.cyVal.Lo==MFVideoInterlace_Progressive)	return QString("MFVideoInterlace_Progressive");
			if (variant.cyVal.Lo==MFVideoInterlace_FieldInterleavedUpperFirst)	return QString("MFVideoInterlace_FieldInterleavedUpperFirst");
			if (variant.cyVal.Lo==MFVideoInterlace_FieldInterleavedLowerFirst)	return QString("MFVideoInterlace_FieldInterleavedLowerFirst");
			if (variant.cyVal.Lo==MFVideoInterlace_FieldSingleUpper)	return QString("MFVideoInterlace_FieldSingleUpper");
			if (variant.cyVal.Lo==MFVideoInterlace_FieldSingleLower)	return QString("MFVideoInterlace_FieldSingleLower");
			if (variant.cyVal.Lo==MFVideoInterlace_MixedInterlaceOrProgressive)	return QString("MFVideoInterlace_MixedInterlaceOrProgressive");
		}
	}
	if (IsEqualGUID(giud,MF_MT_ALL_SAMPLES_INDEPENDENT))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo==1) return QString("True");
			if (variant.cyVal.Lo==0) return QString("False");
		}
	}
	if (IsEqualGUID(giud,MF_MT_FIXED_SIZE_SAMPLES))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo==1) return QString("True");
			if (variant.cyVal.Lo==0) return QString("False");
		}
	}
	if (IsEqualGUID(giud,MF_MT_PIXEL_ASPECT_RATIO))
	{		
		if (variant.vt == VT_UI8)
		{
			return QString("%1/%2").arg(QString::number(variant.cyVal.Hi),QString::number(variant.cyVal.Lo));
		}
	}
	if (IsEqualGUID(giud,MF_MT_SAMPLE_SIZE))
	{		
		if (variant.vt == VT_UI4)
		{
			return QString("%1 bytes").arg(QString::number(variant.cyVal.Lo));
		}
	}
	if (IsEqualGUID(giud,MF_MT_VIDEO_CHROMA_SITING))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_Unknown)	return QString("MFVideoChromaSubsampling_Unknown");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_ProgressiveChroma)	return QString("MFVideoChromaSubsampling_ProgressiveChroma");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_Horizontally_Cosited)	return QString("MFVideoChromaSubsampling_Horizontally_Cosited");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_Vertically_Cosited)	return QString("MFVideoChromaSubsampling_Vertically_Cosited");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes)	return QString("MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_MPEG2)	return QString("MFVideoChromaSubsampling_MPEG2");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_MPEG1)	return QString("MFVideoChromaSubsampling_MPEG1");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_DV_PAL)	return QString("MFVideoChromaSubsampling_DV_PAL");
			if (variant.cyVal.Lo==MFVideoChromaSubsampling_Cosited)	return QString("MFVideoChromaSubsampling_Cosited");
		}
	}
	if (IsEqualGUID(giud,MF_MT_VIDEO_NOMINAL_RANGE))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo==MFNominalRange_Unknown)	return QString("MFNominalRange_Unknown");
			if (variant.cyVal.Lo==MFNominalRange_0_255)	return QString("MFNominalRange_0_255");
			if (variant.cyVal.Lo==MFNominalRange_16_235)	return QString("MFNominalRange_16_235");
			if (variant.cyVal.Lo==MFNominalRange_48_208)	return QString("MFNominalRange_48_208");
			if (variant.cyVal.Lo==MFNominalRange_64_127)	return QString("MFNominalRange_64_127");
		}
	}
	if (IsEqualGUID(giud,MF_MT_VIDEO_PRIMARIES))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo==MFVideoPrimaries_Unknown)	return QString("MFVideoPrimaries_Unknown");
			if (variant.cyVal.Lo==MFVideoPrimaries_reserved)	return QString("MFVideoPrimaries_reserved");
			if (variant.cyVal.Lo==MFVideoPrimaries_BT709)	return QString("MFVideoPrimaries_BT709");
			if (variant.cyVal.Lo==MFVideoPrimaries_BT470_2_SysM)	return QString("MFVideoPrimaries_BT470_2_SysM");
			if (variant.cyVal.Lo==MFVideoPrimaries_BT470_2_SysBG)	return QString("MFVideoPrimaries_BT470_2_SysBG");
			if (variant.cyVal.Lo==MFVideoPrimaries_SMPTE170M)	return QString("MFVideoPrimaries_SMPTE170M");
			if (variant.cyVal.Lo==MFVideoPrimaries_SMPTE240M)	return QString("MFVideoPrimaries_SMPTE240M");
			if (variant.cyVal.Lo==MFVideoPrimaries_EBU3213)	return QString("MFVideoPrimaries_EBU3213");
			if (variant.cyVal.Lo==MFVideoPrimaries_SMPTE_C)	return QString("MFVideoPrimaries_SMPTE_C");
		}
	}
	if (IsEqualGUID(giud,MF_MT_VIDEO_LIGHTING))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo== MFVideoLighting_Unknown)	return QString(" MFVideoLighting_Unknown");
			if (variant.cyVal.Lo==MFVideoLighting_bright)	return QString("MFVideoLighting_bright");
			if (variant.cyVal.Lo==MFVideoLighting_office)	return QString("MFVideoLighting_office");
			if (variant.cyVal.Lo==MFVideoLighting_dim)	return QString("MFVideoLighting_dim");
			if (variant.cyVal.Lo==MFVideoLighting_dark)	return QString("MFVideoLighting_dark");
		}
	}
	if (IsEqualGUID(giud,MF_MT_YUV_MATRIX))
	{		
		if (variant.vt == VT_UI4)
		{
			if (variant.cyVal.Lo== MFVideoTransferMatrix_Unknown)	return QString(" MFVideoTransferMatrix_Unknown");
			if (variant.cyVal.Lo==MFVideoTransferMatrix_BT709)	return QString("MFVideoTransferMatrix_BT709");
			if (variant.cyVal.Lo==MFVideoTransferMatrix_BT601)	return QString("MFVideoTransferMatrix_BT601");
			if (variant.cyVal.Lo==MFVideoTransferMatrix_SMPTE240M)	return QString("MFVideoTransferMatrix_SMPTE240M");
		}
	}
	if (IsEqualGUID(giud,MF_MT_AM_FORMAT_TYPE))
	{		
		if (variant.vt == VT_CLSID)
		{
			if (IsEqualGUID(FORMAT_VideoInfo,*variant.puuid)) return QString("FORMAT_VideoInfo");
			if (IsEqualGUID(FORMAT_VideoInfo2,*variant.puuid)) return QString("FORMAT_VideoInfo2");
			if (IsEqualGUID(FORMAT_MPEGVideo,*variant.puuid)) return QString("FORMAT_MPEGVideo");
			if (IsEqualGUID(FORMAT_WaveFormatEx,*variant.puuid)) return QString("FORMAT_WaveFormatEx");
			if (IsEqualGUID(FORMAT_MPEG2Video,*variant.puuid)) return QString("FORMAT_MPEG2Video");
		}
	}
	return result;
}


WORD RCSGCameraDevice::extractVid( LPCWSTR symbolicLink )
{
	WORD vid = 0;
	QString data;
	data.append(QString::fromStdWString(symbolicLink));
	QRegExp regex("vid_*&p");
	regex.setPatternSyntax(QRegExp::Wildcard);
	regex.indexIn(data);
	QStringList list = regex.capturedTexts();
	if (list.count()>0)
	{
		data = list.first();
	}
	data = data.remove("vid_");
	data = data.remove("&p");
	bool ok;
	vid = data.toUShort(&ok,16);
	return vid;
}

WORD RCSGCameraDevice::extractPid( LPCWSTR symbolicLink )
{
	WORD pid = 0;
	QString data;
	data.append(QString::fromStdWString(symbolicLink));
	QRegExp regex("pid_*&m");
	regex.setPatternSyntax(QRegExp::Wildcard);
	regex.indexIn(data);
	QStringList list = regex.capturedTexts();
	if (list.count()>0)
	{
		data = list.first();
	}
	data = data.remove("pid_");
	data = data.remove("&m");
	bool ok;
	pid = data.toUShort(&ok,16);
	return pid;
}

UINT RCSGCameraDevice::cameraDeviceSlot() const
{
	return cameraSlot;
}

QString RCSGCameraDevice::cameraDeviceDescription() const
{
	return cameraDescription;
}

QString RCSGCameraDevice::cameraDeviceVendor() const
{
	return cameraVendor;
}

QVector<QHash<QString,QString>> RCSGCameraDevice::cameraDeviceCapacites() const
{
	return cameraMediaTypesDeviceCapacites;
}

bool lessThanWidth(const QHash<QString,QString> &h1, const QHash<QString,QString> &h2)
{
	QString frame_size1 = h1[QString("MF_MT_FRAME_SIZE")];
	QString frame_size2 = h2[QString("MF_MT_FRAME_SIZE")];
	UINT frameWidth1 = frame_size1.left(frame_size1.lastIndexOf("x")).toUInt();
	UINT frameWidth2 = frame_size2.left(frame_size2.lastIndexOf("x")).toUInt();
	return frameWidth1>frameWidth2;
}

void RCSGCameraDevice::sortMediaTypesDeviceCapacitesByFrameSize()
{
	qSort(cameraMediaTypesDeviceCapacites.begin(),cameraMediaTypesDeviceCapacites.end(),lessThanWidth);
}

QVector<IMFMediaType*>* RCSGCameraDevice::cameraDeviceMediaTypes() const
{
	return cameraMediaTypes;
}
