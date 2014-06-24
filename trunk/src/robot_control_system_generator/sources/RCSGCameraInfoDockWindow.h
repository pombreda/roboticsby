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

#ifndef RCSGCAMERAINFODOCKWINDOW_H
#define RCSGCAMERAINFODOCKWINDOW_H

#include <QTreeWidget>
#include <windows.h>

class RCSGCameraInfoDockWindow : public QTreeWidget
{
	Q_OBJECT

public:
	RCSGCameraInfoDockWindow(QWidget *parent = 0);

	public slots:
		void updateDevicesInformation(QHash<QString,QObject*>* cameraDevices);
	/*	void extractXaxis(QTreeWidgetItem *item, JOYCAPS caps);
		void extractYaxis(QTreeWidgetItem *item, JOYCAPS caps);
		void extractZaxis(QTreeWidgetItem *item, JOYCAPS caps);
		void extractRaxis(QTreeWidgetItem *item, JOYCAPS caps);
		void extractUaxis(QTreeWidgetItem *item, JOYCAPS caps);
		void extractVaxis(QTreeWidgetItem *item, JOYCAPS caps);
		void extractPollingFrequency(QTreeWidgetItem *item, JOYCAPS caps);
		void extractButtonsNumber(QTreeWidgetItem *item, JOYCAPS caps);
		void extractPOV(QTreeWidgetItem *item, JOYCAPS caps);
		void extractPOV4DIR(QTreeWidgetItem *item, JOYCAPS caps);
		void extractPOVCTS(QTreeWidgetItem *item, JOYCAPS caps);	
	*/
};

#endif // RCSGCAMERAINFODOCKWINDOW_H
