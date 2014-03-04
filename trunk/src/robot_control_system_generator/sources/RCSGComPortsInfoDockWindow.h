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

#ifndef RCSGCOMPORTSINFODOCKWINDOW_H
#define RCSGCOMPORTSINFODOCKWINDOW_H

#include <QTreeWidget>
#include <windows.h>

class RCSGComPortsInfoDockWindow : public QTreeWidget
{
	Q_OBJECT

public:
	RCSGComPortsInfoDockWindow(QWidget *parent = 0);

	public slots:
		void updateDevicesInformation(QHash<QString,QObject*>* communicationdevices);

private:
	void extractProviderSubType(QTreeWidgetItem *item, COMMCONFIG config);
	void extractBaudRate(QTreeWidgetItem *item, COMMCONFIG config);
	void extractFBinary(QTreeWidgetItem *item, DCB dcb);
    void extractFParity(QTreeWidgetItem *item, DCB dcb);
	void extractFOutxCtsFlow(QTreeWidgetItem *item, DCB dcb);
	void extractFOutxDsrFlow(QTreeWidgetItem *item, DCB dcb);
	void extractFDtrControl(QTreeWidgetItem *item,DCB dcb);
	void extractFDsrSensitivity(QTreeWidgetItem *item, DCB dcb);
	void extractFTXContinueOnXoff(QTreeWidgetItem *item, DCB dcb);
	void extractFOutX(QTreeWidgetItem *item, DCB dcb);
	void extractFInX(QTreeWidgetItem *item, DCB dcb);
	void extractFErrorChar(QTreeWidgetItem *item, DCB dcb);
	void extractFNullByte(QTreeWidgetItem *item, DCB dcb);
	void extractFRtsControl(QTreeWidgetItem *item, DCB dcb);
	void extractFAbortOnError(QTreeWidgetItem *item, DCB dcb);
	void extractByteSize(QTreeWidgetItem *item, DCB dcb);
	void extractParity(QTreeWidgetItem *item, DCB dcb);
	void extractStopBits(QTreeWidgetItem *item, DCB dcb);
	void extractXonLim(QTreeWidgetItem *item, DCB dcb);
	void extractXoffLim(QTreeWidgetItem *item, DCB dcb);	
	void extractXonChar(QTreeWidgetItem *item, DCB dcb);
	void extractXoffChar(QTreeWidgetItem *item, DCB dcb);
	void extractErrorChar(QTreeWidgetItem *item, DCB dcb);
	void extractEofChar(QTreeWidgetItem *item, DCB dcb);
	void extractEvtChar(QTreeWidgetItem *item, DCB dcb);

};

#endif // RCSGCOMPORTSINFODOCKWINDOW_H
