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

#ifndef RCSGROBOTFIRMWARETOOLDOCKWINDOW_H
#define RCSGROBOTFIRMWARETOOLDOCKWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

#include "thirdparty/qhexedit/qhexedit.h"
#include "RCSGConsoleDockWindow.h"

class RCSGRobotFirmwareToolDockWindow;

typedef struct commPortThreadContext {
	RCSGRobotFirmwareToolDockWindow *firmwareToolDockWindowThread;
	OVERLAPPED globalOverlapRead;
	HANDLE globalFileHandle;
	DWORD lastError;
} CommPortThreadContext;

class RCSGRobotFirmwareToolDockWindow : public QWidget
{
	Q_OBJECT

public:
	RCSGRobotFirmwareToolDockWindow(QWidget *parent = 0);
	~RCSGRobotFirmwareToolDockWindow();

	public slots:
		void updateComPortsList(QHash<QString,QObject*>* devices);
		void displayCommPortIncomeData(const QByteArray &byteData);
		void displayCommPortOutcomeData(quint8 *data, quint32 bytesRead);

signals:
	void onCommThreadInformation(const QString &message);
	void onIncomeCommPortDataReady(const QByteArray &byteData);

private:

	QLabel *eepFileSelectorName;
	QLabel *hexFileSelectorName;

	QCheckBox *viewHex;
	QCheckBox *viewEep;

	QPushButton *selectHex;
	QPushButton *selectEep;
	QPushButton *flashFirmware;

	QHash<QString,QObject*>* commPortDevices;

	QVBoxLayout *mainUploadFirmware;
	
	QComboBox *commPortSelector;
	QComboBox *baudRateSelector;
	
	QHexEdit *viewEepHexEdit; 
	QHexEdit *viewHexHexEdit;
	QHexEdit *commIncomeDataHexEdit; 
	QHexEdit *commOutcomeDataHexEdit;

	RCSGConsoleDockWindow *commDataLogConsole;

	QGroupBox *uploadFirmwareGroupBox;
	QGroupBox *viewEepGroupBox;
	QGroupBox *viewHexGroupBox;

	QGroupBox *commIncomeDataGroupBox;
	QGroupBox *commOutcomeDataGroupBox;
	QGroupBox *commLogGroupBox;

	HANDLE globalCommPortThreadHandle;
	DWORD globalCommPortThreadId;
	CommPortThreadContext *threadContext;

	QByteArray commIncomeData;
	QByteArray commOutcomeData;

	void fillCurrentBaudRate();
	
	private slots:
		void selectHexFile();
		void selectEepFile();
		void viewEepFile();
		void viewHexFile();
		void flashFirmwareToRobot();
};

#endif // RCSGROBOTFIRMWARETOOLDOCKWINDOW_H
