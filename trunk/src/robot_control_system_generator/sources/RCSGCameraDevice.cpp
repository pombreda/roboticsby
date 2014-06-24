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
#include "RCSGCameraDevice.h"
#include "RCSGUsbIds.h"

RCSGCameraDevice::RCSGCameraDevice(const UINT &cameraSlot)
{
	this->cameraSlot = cameraSlot;
	cameraVendor.clear();
	cameraDescription.clear();

	if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED)))
	{
		if (SUCCEEDED(MFStartup(MF_VERSION)))
		{
			IMFAttributes *pAttributes = NULL;
			IMFActivate **ppDevices = NULL;
			if (SUCCEEDED(MFCreateAttributes(&pAttributes, 1)))
			{
				if (SUCCEEDED(pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID)))
				{
					UINT32 count=0;
					if (SUCCEEDED(MFEnumDeviceSources(pAttributes, &ppDevices, &count)))
					{
						if(cameraSlot<count)
						{
							LPWSTR friendlyName = NULL;
							LPWSTR symbolicLink = NULL;
							UINT32 cchLenght = 0;
							if(SUCCEEDED(ppDevices[cameraSlot]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,&friendlyName,&cchLenght)))
							{
								if(SUCCEEDED(ppDevices[cameraSlot]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK,&symbolicLink,&cchLenght)))
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
									CoTaskMemFree(symbolicLink);
									symbolicLink = NULL;
								}
								CoTaskMemFree(friendlyName);
								friendlyName = NULL;
							}
						}
						for(UINT32 i=0; i<count; i++)
						{
							safeRelease(&ppDevices[i]);
						}
					}
				}
			}
			safeRelease(ppDevices);
			safeRelease(&pAttributes);
			MFShutdown();
			CoUninitialize();
		}
	}
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
