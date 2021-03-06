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

#include "RCSGInputDevicesManager.h"
#include "RCSGJoystickDevice.h"

QVector<UINT> globalInputDevicesHolder;

RCSGInputDevicesManager::RCSGInputDevicesManager( RCSGMainWindow *mainWindow ): 
	mainWindow(mainWindow),inputDevices(NULL)
{
	inputDevices = new QHash<QString,QObject*>;
}

RCSGInputDevicesManager::~RCSGInputDevicesManager()
{
	if (inputDevices != NULL)
	{
		qDeleteAll(inputDevices->begin(),inputDevices->end());
		inputDevices->clear();
		delete inputDevices;
		inputDevices = NULL;
	}
}

void enumeratingInputDevices()
{
	globalInputDevicesHolder.clear();
	MMRESULT dwResult;

	UINT joyId = 0; 

	JOYINFOEX joyinfoex;
	joyinfoex.dwSize = sizeof(JOYINFOEX);
	joyinfoex.dwFlags = JOY_RETURNALL;

	while ((dwResult = joyGetPosEx(joyId++,&joyinfoex)) != JOYERR_PARMS)
	{
		if(dwResult == JOYERR_NOERROR)
		{
			globalInputDevicesHolder.append(joyId-1);
		}
	}
}

void RCSGInputDevicesManager::populateDevices()
{
	cancelPopulatingDevices();
	QObject::connect(&populatingDevicesWatcher, SIGNAL(finished()), this, SLOT(finishedPopulatingDevices()));
	populatingDevicesWatcher.setFuture(QtConcurrent::run(enumeratingInputDevices));
}

void RCSGInputDevicesManager::cancelPopulatingDevices()
{
	populatingDevicesWatcher.cancel();
	populatingDevicesWatcher.waitForFinished();
}

void RCSGInputDevicesManager::finishedPopulatingDevices()
{
	if (inputDevices != NULL)
	{
		qDeleteAll(inputDevices->begin(),inputDevices->end());
		inputDevices->clear();
	}

	{
		QVector<UINT>::iterator iterator;
		for (iterator = globalInputDevicesHolder.begin(); iterator != globalInputDevicesHolder.end(); ++iterator)
		{
			RCSGJoystickDevice *device = new RCSGJoystickDevice(*iterator);
			inputDevices->insert(QString("SLOT%1").arg(*iterator),device);
		}
	}

	QHash<QString,QObject*>::iterator iterator;
	QString message(QString("Joystick devices: %1\n").arg(inputDevices->size()));
	UINT joystickCounter = 1;
	for (iterator = inputDevices->begin(); iterator != inputDevices->end(); ++iterator)
	{
		RCSGJoystickDevice *device = qobject_cast<RCSGJoystickDevice*>(iterator.value());
		message.append(QString("%1: Slot %2 [%3] - [%4]\n").arg(QString::number(joystickCounter),QString::number(device->joystickDeviceSlot()),device->joystickDeviceVendor(),device->joystickDeviceDescription()));
		joystickCounter++;
	}
	mainWindow->showApplicationConsoleMessage(message);
	emit onInputDevicesManagerNewDevices();
}

QHash<QString,QObject*>* RCSGInputDevicesManager::getInputDevices() const
{
	return inputDevices;
}
