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

#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <mfapi.h>
#include <mfidl.h>

#include "RCSGCameraDevicesManager.h"
#include "RCSGCameraDevice.h"

QVector<UINT> globalCameraDevicesHolder;

RCSGCameraDevicesManager::RCSGCameraDevicesManager( RCSGMainWindow *mainWindow ): 
	mainWindow(mainWindow),cameraDevices(NULL)
{
	cameraDevices = new QHash<QString,QObject*>;
}

RCSGCameraDevicesManager::~RCSGCameraDevicesManager()
{
	if (cameraDevices != NULL)
	{
		qDeleteAll(cameraDevices->begin(),cameraDevices->end());
		cameraDevices->clear();
		delete cameraDevices;
		cameraDevices = NULL;
	}
}

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

void enumeratingCameraDevices()
{
	globalCameraDevicesHolder.clear();
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
					UINT32 deviceCount=0;
					if (SUCCEEDED(MFEnumDeviceSources(pAttributes, &ppDevices, &deviceCount)))
					{
						if(deviceCount>0)
						{
							for(UINT i=0; i<deviceCount; i++) 
							{
								globalCameraDevicesHolder.append(i);
							}
						}
						for(UINT32 i=0; i<deviceCount; i++)
						{
							safeRelease(&ppDevices[i]);
						}
					}
				}
			}
			safeRelease(ppDevices);
			safeRelease(&pAttributes);
		}
	}
	MFShutdown();
	CoUninitialize();
}

void RCSGCameraDevicesManager::populateDevices()
{
	cancelPopulatingDevices();
	QObject::connect(&populatingDevicesWatcher, SIGNAL(finished()), this, SLOT(finishedPopulatingDevices()));
	populatingDevicesWatcher.setFuture(QtConcurrent::run(enumeratingCameraDevices));
}

void RCSGCameraDevicesManager::cancelPopulatingDevices()
{
	populatingDevicesWatcher.cancel();
	populatingDevicesWatcher.waitForFinished();
}

void RCSGCameraDevicesManager::finishedPopulatingDevices()
{
	if (cameraDevices != NULL)
	{
		qDeleteAll(cameraDevices->begin(),cameraDevices->end());
		cameraDevices->clear();
	}

	{
		QVector<UINT>::iterator iterator;
		for (iterator = globalCameraDevicesHolder.begin(); iterator != globalCameraDevicesHolder.end(); ++iterator)
		{
			RCSGCameraDevice *device = new RCSGCameraDevice(*iterator);
			cameraDevices->insert(QString("SLOT%1").arg(*iterator),device);
		}
	}

	QHash<QString,QObject*>::iterator iterator;
	QString message(QString("Camera devices: %1\n").arg(cameraDevices->size()));
	UINT cameraCounter = 1;

	for (iterator = cameraDevices->begin(); iterator != cameraDevices->end(); ++iterator)
	{
		RCSGCameraDevice *device = qobject_cast<RCSGCameraDevice*>(iterator.value());
		message.append(QString("%1: Slot %2 [%3] - [%4]\n").arg(QString::number(cameraCounter),QString::number(device->cameraVideoDeviceSlot()),device->cameraDeviceVendor(),device->cameraDeviceDescription()));
		cameraCounter++;
	}
	mainWindow->showApplicationConsoleMessage(message);
	emit onCameraDevicesManagerNewDevices();
}

QHash<QString,QObject*>* RCSGCameraDevicesManager::getCameraDevices() const
{
	return cameraDevices;
}
