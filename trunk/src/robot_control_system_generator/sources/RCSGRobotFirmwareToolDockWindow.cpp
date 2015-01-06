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

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

#include "RCSGRobotFirmwareToolDockWindow.h"
#include "RCSGComPortDevice.h"
#include "thirdparty/qhexedit/qhexedit.h"

QString errorDetailedInformation(LPTSTR functionName, DWORD lastError) 
{ 
	QString result;
	LPVOID messageBuffer;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		lastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &messageBuffer,
		0, NULL );

	wprintf(TEXT("[%s] failed with error %u: %s"), functionName, lastError, (LPTSTR)messageBuffer);
	result.append(QString::fromStdWString((LPTSTR)messageBuffer));
	LocalFree(messageBuffer);
	return result;
}

VOID WINAPI ThreadProcedureCOMPortRead(CommPortThreadContext* context)
{
	DWORD bytesRead;
	BYTE readBuffer[128];
	ZeroMemory(&readBuffer, ARRAYSIZE(readBuffer));

	COMSTAT comstat;
	DWORD mask=0;
	DWORD bytesInQue, numberOfBytesTransferred, error, signal;	

	ZeroMemory(&context->globalOverlapRead, sizeof(OVERLAPPED));
	context->globalOverlapRead.hEvent = CreateEvent(NULL, true, true, NULL);	
	SetCommMask(context->globalFileHandle, EV_RXCHAR);

	while(context->lastError==ERROR_SUCCESS)						
	{
		WaitCommEvent(context->globalFileHandle, &mask, &context->globalOverlapRead);              
		ZeroMemory(&readBuffer, ARRAYSIZE(readBuffer));
		if (context->globalOverlapRead.hEvent != INVALID_HANDLE_VALUE && context->globalOverlapRead.hEvent != NULL)
		{
			signal = WaitForSingleObject(context->globalOverlapRead.hEvent, INFINITE);	
			if(signal == WAIT_OBJECT_0)				        
			{
				if(GetOverlappedResult(context->globalFileHandle, &context->globalOverlapRead, &numberOfBytesTransferred, true)) 
				{
					if((mask & EV_RXCHAR)!=0)					
					{
						ClearCommError(context->globalFileHandle, &error, &comstat);		
						bytesInQue = comstat.cbInQue;                          	
						if(bytesInQue)                         			
						{
							BOOL readFileResult = ReadFile(context->globalFileHandle, readBuffer, 127, &bytesRead, &context->globalOverlapRead);
							if (readFileResult && bytesRead > 0)
							{
								QByteArray byteArray;
								byteArray.append((const char*)readBuffer, bytesRead);
								emit context->firmwareToolDockWindowThread->onIncomeCommPortDataReady(byteArray);							
							}                      		
						}
					}
				}
			}
		}
	}
}

RCSGRobotFirmwareToolDockWindow::RCSGRobotFirmwareToolDockWindow(QWidget *parent)
	:QWidget(parent)
{
	mainUploadFirmware = new QVBoxLayout(this);

	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::black);
	p.setColor(QPalette::Text, Qt::green);
	p.setColor(QPalette::WindowText, Qt::green);

	QHBoxLayout *commPortSelectorLayout = new QHBoxLayout(this);
	commPortSelectorLayout->setObjectName("commPortSelectorLayout");

	QLabel *commPortSelectorName = new QLabel(this);
	commPortSelectorName->setObjectName("commPortSelectorName");
	commPortSelectorName->setText(QString("Communication Port"));

	commPortSelector = new QComboBox(this);
	commPortSelector->setObjectName("commPortSelector");
	commPortSelector->setToolTip(QString("Select Communication Port"));

	commPortSelectorLayout->addWidget(commPortSelectorName);
	commPortSelectorLayout->addWidget(commPortSelector);
	commPortSelectorLayout->setAlignment(Qt::AlignRight);

	QHBoxLayout *baudRateSelectorLayout = new QHBoxLayout(this);
	baudRateSelectorLayout->setObjectName("baudRateSelectorLayout");

	QLabel *baudRateSelectorName = new QLabel(this);
	baudRateSelectorName->setObjectName("baudRateSelectorName");
	baudRateSelectorName->setText(QString("Baud Rate"));

	baudRateSelector = new QComboBox(this);
	baudRateSelector->setObjectName("baudRateSelector");
	baudRateSelector->setToolTip(QString("Choose Baud Rate"));

	baudRateSelectorLayout->addWidget(baudRateSelectorName);
	baudRateSelectorLayout->addWidget(baudRateSelector);
	baudRateSelectorLayout->setAlignment(Qt::AlignRight);

	QHBoxLayout *eepFileSelectorLayout = new QHBoxLayout(this);
	eepFileSelectorLayout->setObjectName("eepFileSelectorLayout");

	eepFileSelectorName = new QLabel(this);
	eepFileSelectorName->setObjectName("eepFileSelectorName");
	eepFileSelectorName->setText(QString(""));

	viewEep = new QCheckBox(this);
	viewEep->setObjectName(QString("View *.eep"));
	viewEep->setText(tr("View"));
	viewEep->setToolTip(QString("View *.eep file"));
	connect(viewEep, SIGNAL(clicked()), this, SLOT(viewEepFile()));

	selectEep = new QPushButton(this);
	selectEep->setObjectName(QString("Select *.eep file"));
	selectEep->setText(tr("Select *.eep file"));
	selectEep->setToolTip(QString("Select *.eep file"));
	connect(selectEep, SIGNAL(clicked()), this, SLOT(selectEepFile()));

	eepFileSelectorLayout->addWidget(eepFileSelectorName);
	eepFileSelectorLayout->addWidget(viewEep);
	eepFileSelectorLayout->addWidget(selectEep);
	eepFileSelectorLayout->setAlignment(Qt::AlignRight);

	QHBoxLayout *hexFileSelectorLayout = new QHBoxLayout(this);
	hexFileSelectorLayout->setObjectName("hexFileSelectorLayout");

	hexFileSelectorName = new QLabel(this);
	hexFileSelectorName->setObjectName("hexFileSelectorName");
	hexFileSelectorName->setText(QString(""));

	viewHex = new QCheckBox(this);
	viewHex->setObjectName(QString("View *.hex"));
	viewHex->setText(tr("View"));
	viewHex->setToolTip(QString("View *.hex file"));
	connect(viewHex, SIGNAL(clicked()), this, SLOT(viewHexFile()));

	selectHex = new QPushButton(this);
	selectHex->setObjectName(QString("Select *.hex file"));
	selectHex->setText(tr("Select *.hex file"));
	selectHex->setToolTip(QString("Select *.hex file"));
	connect(selectHex, SIGNAL(clicked()), this, SLOT(selectHexFile()));

	hexFileSelectorLayout->addWidget(hexFileSelectorName);
	hexFileSelectorLayout->addWidget(viewHex);
	hexFileSelectorLayout->addWidget(selectHex);
	hexFileSelectorLayout->setAlignment(Qt::AlignRight);

	QHBoxLayout *flashFileSelectorLayout = new QHBoxLayout(this);
	flashFileSelectorLayout->setObjectName("flashFileSelectorLayout");

	flashFirmware = new QPushButton(this);
	flashFirmware->setObjectName(QString("Start flash"));
	flashFirmware->setText(tr("Start flash"));
	flashFirmware->setToolTip(QString("Start flash"));
	connect(flashFirmware, SIGNAL(clicked()), this, SLOT(flashFirmwareToRobot()));

	flashFileSelectorLayout->addWidget(flashFirmware);
	flashFileSelectorLayout->setAlignment(Qt::AlignRight);

	mainUploadFirmware->addLayout(commPortSelectorLayout);
	mainUploadFirmware->addLayout(baudRateSelectorLayout);
	mainUploadFirmware->addLayout(eepFileSelectorLayout);
	mainUploadFirmware->addLayout(hexFileSelectorLayout);
	mainUploadFirmware->addLayout(flashFileSelectorLayout);

	mainUploadFirmware->setAlignment(Qt::AlignTop);

	uploadFirmwareGroupBox = new QGroupBox(this);
	uploadFirmwareGroupBox->setTitle(tr("Upload firmware"));
	uploadFirmwareGroupBox->setLayout(mainUploadFirmware);

	QHBoxLayout *viewEepGroupBoxLayout = new QHBoxLayout(this);
	viewEepGroupBoxLayout->setObjectName("viewEepGroupBoxLayout");

	viewEepHexEdit = new QHexEdit(this);
	viewEepHexEdit->setReadOnly(true);
	viewEepHexEdit->setAddressAreaColor(QColor("black"));
	viewEepHexEdit->setPalette(p);
	viewEepGroupBoxLayout->addWidget(viewEepHexEdit);

	viewEepGroupBox = new QGroupBox(this);
	viewEepGroupBox->setTitle(tr("Viewing epp file"));
	viewEepGroupBox->setVisible(false);

	viewEepGroupBox->setLayout(viewEepGroupBoxLayout);

	QHBoxLayout *viewHexGroupBoxLayout = new QHBoxLayout(this);
	viewHexGroupBoxLayout->setObjectName("viewHexGroupBoxLayout");

	viewHexHexEdit = new QHexEdit(this);
	viewHexHexEdit->setReadOnly(true);
	viewHexHexEdit->setAddressAreaColor(QColor("black"));
	viewHexHexEdit->setPalette(p);
	viewHexGroupBoxLayout->addWidget(viewHexHexEdit);

	viewHexGroupBox = new QGroupBox(this);
	viewHexGroupBox->setTitle(tr("Viewing hex file"));
	viewHexGroupBox->setVisible(false);

	viewHexGroupBox->setLayout(viewHexGroupBoxLayout);

	QHBoxLayout *commIncomeDataGroupBoxLayout = new QHBoxLayout(this);
	commIncomeDataGroupBoxLayout->setObjectName("commIncomeDataGroupBoxLayout");

	commIncomeDataHexEdit = new QHexEdit(this);
	commIncomeDataHexEdit->setReadOnly(true);
	commIncomeDataHexEdit->setAddressAreaColor(QColor("black"));
	commIncomeDataHexEdit->setPalette(p);
	commIncomeDataGroupBoxLayout->addWidget(commIncomeDataHexEdit);

	commIncomeDataGroupBox = new QGroupBox(this);
	commIncomeDataGroupBox->setTitle(tr("Viewing communication port income data"));
	commIncomeDataGroupBox->setVisible(false);

	commIncomeDataGroupBox->setLayout(commIncomeDataGroupBoxLayout);

	QHBoxLayout *commOutcomeDataGroupBoxLayout = new QHBoxLayout(this);
	commOutcomeDataGroupBoxLayout->setObjectName("commOutcomeDataGroupBoxLayout");

	commOutcomeDataHexEdit = new QHexEdit(this);
	commOutcomeDataHexEdit->setReadOnly(true);
	commOutcomeDataHexEdit->setAddressAreaColor(QColor("black"));
	commOutcomeDataHexEdit->setPalette(p);
	commOutcomeDataGroupBoxLayout->addWidget(commOutcomeDataHexEdit);

	commOutcomeDataGroupBox = new QGroupBox(this);
	commOutcomeDataGroupBox->setTitle(tr("Viewing communication port outcome data"));
	commOutcomeDataGroupBox->setVisible(false);

	commOutcomeDataGroupBox->setLayout(commOutcomeDataGroupBoxLayout);

	QHBoxLayout *commLogGroupBoxLayout = new QHBoxLayout(this);
	commLogGroupBoxLayout->setObjectName("commLogGroupBoxLayout");

	commDataLogConsole = new RCSGConsoleDockWindow(this);
	commDataLogConsole->setReadOnly(true);
	commLogGroupBoxLayout->addWidget(commDataLogConsole);

	commLogGroupBox = new QGroupBox(this);
	commLogGroupBox->setTitle(tr("Viewing communication port process log data"));
	commLogGroupBox->setVisible(false);

	commLogGroupBox->setLayout(commLogGroupBoxLayout);

	QVBoxLayout *mainDockWindowLayout = new QVBoxLayout(this);
	mainDockWindowLayout->addWidget(uploadFirmwareGroupBox);
	mainDockWindowLayout->addWidget(viewEepGroupBox);
	mainDockWindowLayout->addWidget(viewHexGroupBox);

	mainDockWindowLayout->addWidget(commIncomeDataGroupBox);
	mainDockWindowLayout->addWidget(commOutcomeDataGroupBox);
	mainDockWindowLayout->addWidget(commLogGroupBox);

	connect(this,&RCSGRobotFirmwareToolDockWindow::onIncomeCommPortDataReady, this, &RCSGRobotFirmwareToolDockWindow::displayCommPortIncomeData);

	setLayout(mainDockWindowLayout);
}

RCSGRobotFirmwareToolDockWindow::~RCSGRobotFirmwareToolDockWindow()
{
}

void RCSGRobotFirmwareToolDockWindow::updateComPortsList( QHash<QString,QObject*>* devices )
{
	commPortDevices = devices;
	QHash<QString,QObject*>::iterator iterator;
	for (iterator = commPortDevices->begin(); iterator != commPortDevices->end(); ++iterator)
	{
		RCSGComPortDevice *device = qobject_cast<RCSGComPortDevice*>(iterator.value());
		if (device!=NULL)
		{
			commPortSelector->addItem(QString("%1 [%2]").arg(device->commPortName(),device->commPortVendor()),iterator.key());
		}
	}
	fillCurrentBaudRate();
}

void RCSGRobotFirmwareToolDockWindow::selectEepFile()
{
	QString filePath;
	filePath = QFileDialog::getOpenFileName(this, "Select *.eep file to open", "", "Eep files (*.eep)");
	if (!filePath.isEmpty())
	{
		eepFileSelectorName->setText(filePath);
		QFile file(filePath);
		if (!file.open(QFile::ReadOnly)) {
			QMessageBox::warning(this, tr("Selection of epp file"),
				tr("Cannot read file %1:\n%2.")
				.arg(filePath)
				.arg(file.errorString()));
			return;
		}
		viewEepHexEdit->setData(file.readAll());
		viewEepFile();
	}
}

void RCSGRobotFirmwareToolDockWindow::selectHexFile()
{
	QString filePath;
	filePath = QFileDialog::getOpenFileName(this, "Select *.hex file to open", "", "Hex files (*.hex)");
	if (!filePath.isEmpty())
	{
		hexFileSelectorName->setText(filePath);
		QFile file(filePath);
		if (!file.open(QFile::ReadOnly)) {
			QMessageBox::warning(this, tr("Selection of hex file"),
				tr("Cannot read file %1:\n%2.")
				.arg(filePath)
				.arg(file.errorString()));
			return;
		}
		viewHexHexEdit->setData(file.readAll());
		viewHexFile();
	}
}

void RCSGRobotFirmwareToolDockWindow::viewEepFile()
{
	if (!eepFileSelectorName->text().isEmpty() && viewEep->isChecked())
	{
		viewEepGroupBox->setVisible(true);
		return;
	} 
	viewEepGroupBox->setVisible(false);
}

void RCSGRobotFirmwareToolDockWindow::viewHexFile()
{
	if (!hexFileSelectorName->text().isEmpty() && viewHex->isChecked())
	{
		viewHexGroupBox->setVisible(true);
		return;
	} 
	viewHexGroupBox->setVisible(false);
}

void RCSGRobotFirmwareToolDockWindow::flashFirmwareToRobot()
{
	commIncomeDataHexEdit->setData(NULL);
	commOutcomeDataHexEdit->setData(NULL);
	commDataLogConsole->clear();

	commIncomeDataGroupBox->setVisible(true);
	commOutcomeDataGroupBox->setVisible(true);
	commLogGroupBox->setVisible(true);

	threadContext = new CommPortThreadContext;
	threadContext->firmwareToolDockWindowThread = this;
	threadContext->globalFileHandle = NULL;
	threadContext->lastError=ERROR_SUCCESS;

	RCSGComPortDevice *commPort = qobject_cast<RCSGComPortDevice*>(commPortDevices->value(commPortSelector->itemData(commPortSelector->currentIndex()).toString()));
	UINT baudRate = baudRateSelector->itemData(baudRateSelector->currentIndex()).toUInt();
	std::wstring s = commPort->commPortName().toStdWString();
	const wchar_t *commPortName = s.c_str();

	commDataLogConsole->appendPlainText(QString("Start flashing process"));
	commDataLogConsole->appendPlainText(QString("Opening comm port [%1], with baud rate [%2]").arg(commPort->commPortName(),QString::number(baudRate)));

	threadContext->globalFileHandle = CreateFile(commPortName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
	if (INVALID_HANDLE_VALUE == threadContext->globalFileHandle)
	{
		threadContext->lastError = GetLastError();
		CloseHandle(threadContext->globalFileHandle);
		commDataLogConsole->appendPlainText(QString("COM port opening issue"));
		commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("CreateFile"),threadContext->lastError));
	}

	DCB dcb;
	ZeroMemory(&dcb, sizeof(DCB));
	if (threadContext->lastError==ERROR_SUCCESS)
	{
		if (!GetCommState(threadContext->globalFileHandle, &dcb))
		{
			threadContext->lastError = GetLastError();
			CloseHandle(threadContext->globalFileHandle);
			commDataLogConsole->appendPlainText(QString("Getting comm port state"));
			commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("GetCommState"),threadContext->lastError));
		}
	}

	dcb.BaudRate = baudRate;
	dcb.ByteSize = 8; 
	dcb.StopBits = ONESTOPBIT; 
	dcb.Parity = NOPARITY; 

	if (threadContext->lastError==ERROR_SUCCESS)
	{
		if (!SetCommState(threadContext->globalFileHandle, &dcb))
		{
			threadContext->lastError = GetLastError();
			CloseHandle(threadContext->globalFileHandle);
			commDataLogConsole->appendPlainText(QString("Setting baud rate issue"));
			commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("SetCommState"),threadContext->lastError));
		}
	}

	if (threadContext->lastError==ERROR_SUCCESS)
	{
		COMMTIMEOUTS ComTimeouts;
		ZeroMemory(&ComTimeouts, sizeof(COMMTIMEOUTS));
		ComTimeouts.ReadIntervalTimeout = MAXDWORD;
		ComTimeouts.ReadTotalTimeoutConstant = 0;
		ComTimeouts.ReadTotalTimeoutMultiplier = 100;
		ComTimeouts.WriteTotalTimeoutConstant = 1;
		ComTimeouts.WriteTotalTimeoutMultiplier = 100;
		if(!SetCommTimeouts(threadContext->globalFileHandle, &ComTimeouts))
		{
			threadContext->lastError = GetLastError();
			CloseHandle(threadContext->globalFileHandle);
			commDataLogConsole->appendPlainText(QString("Setting COM Port Timeouts issue"));
			commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("SetCommTimeouts"),threadContext->lastError));
		}
	}

	if (threadContext->lastError==ERROR_SUCCESS)
	{
		if(!PurgeComm(threadContext->globalFileHandle, PURGE_RXCLEAR))
		{
			threadContext->lastError = GetLastError();
			CloseHandle(threadContext->globalFileHandle);
			commDataLogConsole->appendPlainText(QString("Purge COMM for RX issue"));
			commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("PurgeComm"),threadContext->lastError));
		}
	}

	if (threadContext->lastError==ERROR_SUCCESS)
	{
		if(!PurgeComm(threadContext->globalFileHandle, PURGE_TXCLEAR))
		{
			threadContext->lastError = GetLastError();
			CloseHandle(threadContext->globalFileHandle);
			commDataLogConsole->appendPlainText(QString("Purge COMM for TX issue"));
			commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("PurgeComm"),threadContext->lastError));
		}
	}

	if (threadContext->lastError==ERROR_SUCCESS)
	{
		globalCommPortThreadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcedureCOMPortRead, threadContext, 0, &globalCommPortThreadId);
		if (INVALID_HANDLE_VALUE == globalCommPortThreadHandle)
		{
			threadContext->lastError = GetLastError();
			CloseHandle(globalCommPortThreadHandle);
			commDataLogConsole->appendPlainText(QString("Creating comm port read thread issue"));
			commDataLogConsole->appendPlainText(errorDetailedInformation(TEXT("CreateThread"),threadContext->lastError));
		}
	}

	commDataLogConsole->appendPlainText(QString("Stop flashing process"));
}

void RCSGRobotFirmwareToolDockWindow::fillCurrentBaudRate()
{
	baudRateSelector->clear();
	int index = commPortSelector->currentIndex();
	if (index != -1)
	{
		baudRateSelector->addItem("110 bps",CBR_110);
		baudRateSelector->addItem("300 bps",CBR_300);
		baudRateSelector->addItem("600 bps",CBR_600);
		baudRateSelector->addItem("1200 bps",CBR_1200);
		baudRateSelector->addItem("2400 bps",CBR_2400);
		baudRateSelector->addItem("9600 bps",CBR_9600);
		baudRateSelector->addItem("19200 bps",CBR_19200);
		baudRateSelector->addItem("38400 bps",CBR_38400);
		baudRateSelector->addItem("57600 bps",CBR_57600);
		baudRateSelector->addItem("115200 bps",CBR_115200);
		baudRateSelector->addItem("128000 bps",CBR_128000);
		baudRateSelector->addItem("256000 bps",CBR_256000);
		RCSGComPortDevice *device = qobject_cast<RCSGComPortDevice*>(commPortDevices->value(commPortSelector->itemData(index).toString()));
		if (device!=NULL)
		{
			int baudIndex = baudRateSelector->findData((UINT)device->commPortConfig().dcb.BaudRate);
			if (baudIndex != -1) 
			{ 
				baudRateSelector->setCurrentIndex(baudIndex);
			}
		}
	}
}

void RCSGRobotFirmwareToolDockWindow::displayCommPortIncomeData( const QByteArray &byteData )
{
	if (commIncomeDataHexEdit!=NULL)
	{
		QByteArray data;
		data.append(commIncomeDataHexEdit->data());
		data.append(byteData);
		emit commIncomeDataHexEdit->putData(data);
		commIncomeDataHexEdit->setCursorPosition(data.length());
	}
}

void RCSGRobotFirmwareToolDockWindow::displayCommPortOutcomeData( quint8 *data, quint32 bytesRead )
{
	if (data!=NULL)
	{
		QByteArray byteArray = commOutcomeDataHexEdit->data();
		byteArray.append(((const char*)data), bytesRead);
		emit commOutcomeDataHexEdit->putData(byteArray);
	}
}

