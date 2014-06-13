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

#include <QThread>
#include <QDebug>
#include <QProgressDialog>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <windows.h>

#include "RCSGCommunicationDevicesManager.h"
#include "RCSGComPortDevice.h"

HANDLE globalEnumeratingCOMPortsFileHandle;
QVector<QString> globalCommunicationDevicesHolder;

RCSGCommunicationDevicesManager::RCSGCommunicationDevicesManager( RCSGMainWindow *mainWindow ) : 
	mainWindow(mainWindow),devices(NULL)
{
	devices = new QHash<QString,QObject*>;
}

RCSGCommunicationDevicesManager::~RCSGCommunicationDevicesManager()
{
	if (devices != NULL)
	{
		qDeleteAll(devices->begin(),devices->end());
		devices->clear();
		delete devices;
		devices = NULL;
	}
}

void enumeratingCommunicationDevices()
{
	globalCommunicationDevicesHolder.clear();
	for (UINT i=1; i<256; i++)
	{
		WCHAR buffer[32];
		wsprintf(buffer,TEXT("\\\\.\\COM%u"), i);

		BOOL success = FALSE;
		globalEnumeratingCOMPortsFileHandle = CreateFile(buffer, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
		if (globalEnumeratingCOMPortsFileHandle == INVALID_HANDLE_VALUE)
		{
			DWORD lastError = GetLastError();
			if (lastError == ERROR_ACCESS_DENIED || lastError == ERROR_GEN_FAILURE || lastError == ERROR_SHARING_VIOLATION || lastError == ERROR_SEM_TIMEOUT)
				success = TRUE;
		}
		else
		{
			success = TRUE;
		}

		CloseHandle(globalEnumeratingCOMPortsFileHandle);
		if (success)
		{
			globalCommunicationDevicesHolder.append(QString("COM%1").arg(i));
		}
	}
}

void RCSGCommunicationDevicesManager::populateDevices()
{
	cancelPopulatingDevices();
	QObject::connect(&populatingDeviceWatcher, SIGNAL(finished()), this, SLOT(finishedPopulatingDevices()));
	populatingDeviceWatcher.setFuture(QtConcurrent::run(enumeratingCommunicationDevices));
}

void RCSGCommunicationDevicesManager::cancelPopulatingDevices()
{
	populatingDeviceWatcher.cancel();
	populatingDeviceWatcher.waitForFinished();
}

void RCSGCommunicationDevicesManager::finishedPopulatingDevices()
{
	if (devices != NULL)
	{
		qDeleteAll(devices->begin(),devices->end());
		devices->clear();
	}
	{
		QVector<QString>::iterator iterator;
		for (iterator = globalCommunicationDevicesHolder.begin(); iterator != globalCommunicationDevicesHolder.end(); ++iterator)
		{
			WCHAR buffer[32];
			ZeroMemory(&buffer,sizeof(buffer));
			QString comPortName(*iterator);
			iterator->toWCharArray(buffer);
			RCSGComPortDevice *device = new RCSGComPortDevice(buffer);
			devices->insert(comPortName,device);
		}
	}

	QHash<QString,QObject*>::iterator iterator;
	QString message(QString("COM port devices: %1\n").arg(devices->size()));
	UINT comPortCounter = 1;
	for (iterator = devices->begin(); iterator != devices->end(); ++iterator)
	{
		RCSGComPortDevice *device = qobject_cast<RCSGComPortDevice*>(iterator.value());
		message.append(QString("%1: %2 [%3] - [%4]\n").arg(QString::number(comPortCounter),device->commPortName(),device->commPortVendor(),device->commPortDescription()));
		comPortCounter++;
	}
	mainWindow->showApplicationConsoleMessage(message);
	emit onCommunicationDevicesManagerNewDevices();
}

QHash<QString,QObject*>* RCSGCommunicationDevicesManager::getCommunocationDevices() const
{
	return devices;
}
