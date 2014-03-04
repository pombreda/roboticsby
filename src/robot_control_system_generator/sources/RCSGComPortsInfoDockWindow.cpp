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

#include <QScrollBar>
#include <QtCore/QDebug>
#include <QHeaderView>
#include <windows.h>

#include "RCSGComPortsInfoDockWindow.h"
#include "RCSGComPortDevice.h"

RCSGComPortsInfoDockWindow::RCSGComPortsInfoDockWindow(QWidget *parent)
	:QTreeWidget(parent)
{
	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::black);
	p.setColor(QPalette::Text, Qt::green);
	setPalette(p);
	setColumnCount(0);
}

void RCSGComPortsInfoDockWindow::updateDevicesInformation(QHash<QString,QObject*>* communicationdevices)
{
	if (communicationdevices!=NULL)
	{
		clear();
		if (communicationdevices->size()==0)
		{
			return;
		}
		setColumnCount(2);
		QStringList ColumnNames;
		ColumnNames << QString(tr("Settings"))<<QString(tr("Values"));
		setHeaderLabels(ColumnNames);  
		QHash<QString,QObject*>::iterator iterator;
		for (iterator = communicationdevices->begin(); iterator != communicationdevices->end(); ++iterator)
		{
			RCSGComPortDevice *device = qobject_cast<RCSGComPortDevice*>(iterator.value());
			if (device!=NULL)
			{
				QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(this);
				addTopLevelItem(topLevelItem);
				topLevelItem->setText(0,device->commPortName());
				topLevelItem->setText(1,device->commPortDescription());
				QTreeWidgetItem *vendorItem=new QTreeWidgetItem(topLevelItem);
				vendorItem->setText(0,QString("Vendor"));
				vendorItem->setText(1,device->commPortVendor());
				QTreeWidgetItem *productDescriptionItem=new QTreeWidgetItem(topLevelItem);
				productDescriptionItem->setText(0,QString("Description"));
				productDescriptionItem->setText(1,device->commPortDescription());
				QTreeWidgetItem *providerSubTypeItem=new QTreeWidgetItem(topLevelItem);
				extractProviderSubType(providerSubTypeItem,device->commPortConfig());
				QTreeWidgetItem *baudRateItem=new QTreeWidgetItem(topLevelItem);
				extractBaudRate(baudRateItem,device->commPortConfig());
				QTreeWidgetItem *fBinary=new QTreeWidgetItem(topLevelItem);
				extractFBinary(fBinary,device->commPortConfig().dcb);
				QTreeWidgetItem *fParity=new QTreeWidgetItem(topLevelItem);
				extractFParity(fParity,device->commPortConfig().dcb);
				QTreeWidgetItem *fOutxCtsFlow = new QTreeWidgetItem(topLevelItem);
				extractFOutxCtsFlow(fOutxCtsFlow,device->commPortConfig().dcb);
				QTreeWidgetItem *fOutxDsrFlow = new QTreeWidgetItem(topLevelItem);
				extractFOutxDsrFlow(fOutxDsrFlow,device->commPortConfig().dcb);
				QTreeWidgetItem *fDtrControl = new QTreeWidgetItem(topLevelItem);
				extractFDtrControl(fDtrControl,device->commPortConfig().dcb);
				QTreeWidgetItem *fDsrSensitivity = new QTreeWidgetItem(topLevelItem);
				extractFDsrSensitivity(fDsrSensitivity,device->commPortConfig().dcb);
				QTreeWidgetItem *fTXContinueOnXoff = new QTreeWidgetItem(topLevelItem);
				extractFTXContinueOnXoff(fTXContinueOnXoff,device->commPortConfig().dcb);
				QTreeWidgetItem *fOutX = new QTreeWidgetItem(topLevelItem);
				extractFOutX(fOutX,device->commPortConfig().dcb);
				QTreeWidgetItem *fInX = new QTreeWidgetItem(topLevelItem);
				extractFInX(fInX,device->commPortConfig().dcb);
				QTreeWidgetItem *fErrorChar = new QTreeWidgetItem(topLevelItem);
				extractFErrorChar(fErrorChar,device->commPortConfig().dcb);
				QTreeWidgetItem *fNullByte = new QTreeWidgetItem(topLevelItem);
				extractFNullByte(fNullByte,device->commPortConfig().dcb);
				QTreeWidgetItem *fRtsControl = new QTreeWidgetItem(topLevelItem);
				extractFRtsControl(fRtsControl,device->commPortConfig().dcb);
				QTreeWidgetItem *fAbortOnError = new QTreeWidgetItem(topLevelItem);
				extractFAbortOnError(fAbortOnError,device->commPortConfig().dcb);
				QTreeWidgetItem *byteSize = new QTreeWidgetItem(topLevelItem);
				extractByteSize(byteSize,device->commPortConfig().dcb);
				QTreeWidgetItem *parity = new QTreeWidgetItem(topLevelItem);
				extractParity(parity,device->commPortConfig().dcb);
				QTreeWidgetItem *stopBits = new QTreeWidgetItem(topLevelItem);
				extractStopBits(stopBits,device->commPortConfig().dcb);
				QTreeWidgetItem *xonLim = new QTreeWidgetItem(topLevelItem);
				extractXonLim(xonLim,device->commPortConfig().dcb);
				QTreeWidgetItem *xoffLim = new QTreeWidgetItem(topLevelItem);
				extractXoffLim(xoffLim,device->commPortConfig().dcb);
				QTreeWidgetItem *xonChar = new QTreeWidgetItem(topLevelItem);
				extractXonChar(xonChar,device->commPortConfig().dcb);
				QTreeWidgetItem *xoffChar = new QTreeWidgetItem(topLevelItem);
				extractXoffChar(xoffChar,device->commPortConfig().dcb);
				QTreeWidgetItem *errorChar = new QTreeWidgetItem(topLevelItem);
				extractErrorChar(errorChar,device->commPortConfig().dcb);
				QTreeWidgetItem *eofChar = new QTreeWidgetItem(topLevelItem);
				extractEofChar(eofChar,device->commPortConfig().dcb);
				QTreeWidgetItem *evtChar = new QTreeWidgetItem(topLevelItem);
				extractEvtChar(evtChar,device->commPortConfig().dcb);
			}
		}
		header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	}	else {
		clear();
		setColumnCount(0);
	}
}

void RCSGComPortsInfoDockWindow::extractProviderSubType( QTreeWidgetItem *item, COMMCONFIG config )
{
	item->setText(0,QString("Type"));
	QString result("");
	switch (config.dwProviderSubType)
	{
	case PST_FAX:
		result.append("FAX device");
		break;
	case PST_LAT:
		result.append("LAT protocol");
		break;
	case PST_MODEM:
		result.append("Modem device");
		break;
	case PST_NETWORK_BRIDGE:
		result.append("Unspecified network bridge");
		break;
	case PST_PARALLELPORT:
		result.append("Parallel port");
		break;
	case PST_RS232:
		result.append("RS-232 serial port");
		break;
	case PST_RS422:
		result.append("RS-422 port");
		break;
	case PST_RS423:
		result.append("RS-423 port");
		break;
	case PST_RS449:
		result.append("RS-449 port");
		break;
	case PST_SCANNER:
		result.append("Scanner device");
		break;
	case PST_TCPIP_TELNET:
		result.append("TCP/IP Telnet protocol");
		break;
	case PST_UNSPECIFIED:
		result.append("Unspecified");
		break;
	case PST_X25:
		result.append("X.25 standards");
		break;
	default:
		break;
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractBaudRate( QTreeWidgetItem *item, COMMCONFIG config )
{
	item->setText(0,QString("Baud Rate"));
	QString result("");
	switch (config.dcb.BaudRate)
	{
	case CBR_110:
		result.append("110 bps");
		break;
	case CBR_300:
		result.append("300 bps");
		break;
	case CBR_600:
		result.append("600 bps");
		break;
	case CBR_1200:
		result.append("1200 bps");
		break;
	case CBR_2400:
		result.append("2400 bps");
		break;
	case CBR_9600:
		result.append("9600 bps");
		break;
	case CBR_19200:
		result.append("19200 bps");
		break;
	case CBR_38400:
		result.append("38400 bps");
		break;
	case CBR_57600:
		result.append("57600 bps");
		break;
	case CBR_115200:
		result.append("115200 bps");
		break;
	case CBR_128000:
		result.append("128000 bps");
		break;
	case CBR_256000:
		result.append("256000 bps");
		break;
	default:
		break;
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFBinary( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FBinary"));
	QString result("");
	if (dcb.fBinary!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFParity( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FParity"));
	QString result("");
	if (dcb.fParity!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFOutxCtsFlow( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FOutxCtsFlow"));
	QString result("");
	if (dcb.fOutxCtsFlow!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFOutxDsrFlow( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FOutxDsrFlow"));
	QString result("");
	if (dcb.fOutxDsrFlow!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFDtrControl( QTreeWidgetItem *item,DCB dcb )
{
	item->setText(0,QString("FDtrControl"));
	QString result("");
	switch (dcb.fDtrControl)
	{
	case DTR_CONTROL_DISABLE:
		result.append("DTR control disable");
		break;
	case DTR_CONTROL_ENABLE:
		result.append("DTR control enable");
		break;
	case DTR_CONTROL_HANDSHAKE:
		result.append("DTR control handshake");
		break;
	default:
		break;
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFDsrSensitivity( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FDsrSensitivity"));
	QString result("");
	if (dcb.fDsrSensitivity!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFTXContinueOnXoff( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FTXContinueOnXoff"));
	QString result("");
	if (dcb.fTXContinueOnXoff!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFOutX( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FOutX"));
	QString result("");
	if (dcb.fOutX!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFInX( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FInX"));
	QString result("");
	if (dcb.fInX!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFErrorChar( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FErrorChar"));
	QString result("");
	if (dcb.fErrorChar!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFNullByte( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FNullByte"));
	QString result("");
	if (dcb.fNull!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFRtsControl( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FRtsControl"));
	QString result("");
	switch (dcb.fRtsControl)
	{
	case RTS_CONTROL_DISABLE:
		result.append("RTS control disable");
		break;
	case RTS_CONTROL_ENABLE:
		result.append("RTS control enable");
		break;
	case RTS_CONTROL_HANDSHAKE:
		result.append("RTS control handshake");
		break;
	case RTS_CONTROL_TOGGLE:
		result.append("RTS control toggle");
		break;
	default:
		break;
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractFAbortOnError( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("FAbortOnError"));
	QString result("");
	if (dcb.fAbortOnError!=FALSE)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractByteSize( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("ByteSize"));
	item->setText(1,QString::number(dcb.ByteSize));
}

void RCSGComPortsInfoDockWindow::extractParity( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("Parity"));
	QString result("");
	switch (dcb.Parity)
	{
	case EVENPARITY:
		result.append("Even parity");
		break;
	case MARKPARITY:
		result.append("Mark parity");
		break;
	case NOPARITY:
		result.append("No parity");
		break;
	case ODDPARITY:
		result.append("Odd parity");
		break;
	case SPACEPARITY:
		result.append("Space parity");
		break;
	default:
		break;
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractStopBits( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("StopBits"));
	QString result("");
	switch (dcb.StopBits)
	{
	case ONESTOPBIT:
		result.append("1 stop bit");
		break;
	case ONE5STOPBITS:
		result.append("1.5 stop bits");
		break;
	case TWOSTOPBITS:
		result.append("2 stop bits");
		break;
	default:
		break;
	}
	item->setText(1,result);
}

void RCSGComPortsInfoDockWindow::extractXonLim( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("XonLim"));
	item->setText(1,QString::number(dcb.XonLim));
}

void RCSGComPortsInfoDockWindow::extractXoffLim( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("XoffLim"));
	item->setText(1,QString::number(dcb.XoffLim));
}

void RCSGComPortsInfoDockWindow::extractXonChar( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("XonChar"));
	QString hex;
	item->setText(1,QString("'%1' - [0x%2]").arg(QString(dcb.XonChar),hex.setNum(BYTE(dcb.XonChar),16)));
}

void RCSGComPortsInfoDockWindow::extractXoffChar( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("XoffChar"));
	QString hex;
	item->setText(1,QString("'%1' - [0x%2]").arg(QString(dcb.XoffChar),hex.setNum(BYTE(dcb.XoffChar),16)));
}

void RCSGComPortsInfoDockWindow::extractErrorChar( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("ErrorChar"));
	QString hex;
	item->setText(1,QString("'%1' - [0x%2]").arg(QString(dcb.ErrorChar),hex.setNum(BYTE(dcb.ErrorChar),16)));
}

void RCSGComPortsInfoDockWindow::extractEofChar( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("EofChar"));
	QString hex;
	item->setText(1,QString("'%1' - [0x%2]").arg(QString(dcb.EofChar),hex.setNum(BYTE(dcb.EofChar),16)));
}

void RCSGComPortsInfoDockWindow::extractEvtChar( QTreeWidgetItem *item, DCB dcb )
{
	item->setText(0,QString("EvtChar"));
	QString hex;
	item->setText(1,QString("'%1' - [0x%2]").arg(QString(dcb.EvtChar),hex.setNum(BYTE(dcb.EvtChar),16)));

}















