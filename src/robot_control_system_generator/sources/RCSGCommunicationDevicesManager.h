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

#ifndef RCSGCOMMUNICATIONDEVICESMANAGER_H_
#define RCSGCOMMUNICATIONDEVICESMANAGER_H_

#include <QObject>
#include <QMap>
#include <QString>
#include <QFutureWatcher>

#include "RCSGMainWindow.h"

class RCSGMainWindow;

class RCSGCommunicationDevicesManager : public QObject
{
	Q_OBJECT

public:
	RCSGCommunicationDevicesManager (RCSGMainWindow *mainWindow);
	~RCSGCommunicationDevicesManager();

	public slots:
		void populateDevices();
		void cancelPopulatingDevices();
		void finishedPopulatingDevices();
		QHash<QString,QObject*>* getCommunocationDevices() const;
signals:
		void onCommunicationDevicesManagerError(const QString &message);
		void onCommunicationDevicesManagerNewDevices();		

private:
	RCSGMainWindow *mainWindow;
	QHash<QString,QObject*>* devices;
	QFutureWatcher<void> populatingDeviceWatcher;
};

#endif //RCSGCOMMUNICATIONDEVICESMANAGER_H_
