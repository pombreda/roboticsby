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

#include "windows.h"
#include "RCSGJoysticksInfoDockWindow.h"
#include "RCSGJoystickDevice.h"

RCSGJoysticksInfoDockWindow::RCSGJoysticksInfoDockWindow(QWidget *parent)
	:QTreeWidget(parent)
{
	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::black);
	p.setColor(QPalette::Text, Qt::green);
	setPalette(p);
	setColumnCount(0);
}

void RCSGJoysticksInfoDockWindow::updateDevicesInformation( QHash<QString,QObject*>* inputDevices )
{
	if (inputDevices!=NULL)
	{
		clear();
		if (inputDevices->size()==0)
		{
			return;
		}
		setColumnCount(2);
		QStringList ColumnNames;
		ColumnNames << QString(tr("Settings"))<<QString(tr("Values"));
		setHeaderLabels(ColumnNames);
		QHash<QString,QObject*>::iterator iterator;
		for (iterator = inputDevices->begin(); iterator != inputDevices->end(); ++iterator)
		{
			RCSGJoystickDevice *device = qobject_cast<RCSGJoystickDevice*>(iterator.value());
			if (device!=NULL)
			{
				QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(this);
				addTopLevelItem(topLevelItem);
				topLevelItem->setText(0,QString("Slot %1").arg(QString::number(device->joystickDeviceSlot())));
				topLevelItem->setText(1,device->joystickDeviceDescription());
				QTreeWidgetItem *vendorItem=new QTreeWidgetItem(topLevelItem);
				vendorItem->setText(0,QString("Vendor"));
				vendorItem->setText(1,device->joystickDeviceVendor());
				QTreeWidgetItem *productDescriptionItem=new QTreeWidgetItem(topLevelItem);
				productDescriptionItem->setText(0,QString("Description"));
				productDescriptionItem->setText(1,device->joystickDeviceDescription());
				QTreeWidgetItem *xAxis = new QTreeWidgetItem(topLevelItem);
				extractXaxis(xAxis,device->joystickDeviceCapacites());
				QTreeWidgetItem *yAxis = new QTreeWidgetItem(topLevelItem);
				extractYaxis(yAxis,device->joystickDeviceCapacites());
				if(device->joystickDeviceCapacites().wCaps & JOYCAPS_HASZ)
				{
					QTreeWidgetItem *zAxis = new QTreeWidgetItem(topLevelItem);
					extractZaxis(zAxis,device->joystickDeviceCapacites());
				}
				if(device->joystickDeviceCapacites().wCaps & JOYCAPS_HASR)
				{
					QTreeWidgetItem *rAxis = new QTreeWidgetItem(topLevelItem);
					extractRaxis(rAxis,device->joystickDeviceCapacites());
				}
				if(device->joystickDeviceCapacites().wCaps & JOYCAPS_HASU)
				{
					QTreeWidgetItem *uAxis = new QTreeWidgetItem(topLevelItem);
					extractUaxis(uAxis,device->joystickDeviceCapacites());
				}
				if(device->joystickDeviceCapacites().wCaps & JOYCAPS_HASV)
				{
					QTreeWidgetItem *vAxis = new QTreeWidgetItem(topLevelItem);
					extractVaxis(vAxis,device->joystickDeviceCapacites());
				}
				QTreeWidgetItem *pollingFrequency = new QTreeWidgetItem(topLevelItem);
				extractPollingFrequency(pollingFrequency,device->joystickDeviceCapacites());
				QTreeWidgetItem *buttonsNumber = new QTreeWidgetItem(topLevelItem);
				extractButtonsNumber(buttonsNumber,device->joystickDeviceCapacites());
				QTreeWidgetItem *pov = new QTreeWidgetItem(topLevelItem);
				extractPOV(pov,device->joystickDeviceCapacites());
				QTreeWidgetItem *pov4dir = new QTreeWidgetItem(topLevelItem);
				extractPOV4DIR(pov4dir,device->joystickDeviceCapacites());
				QTreeWidgetItem *povcts = new QTreeWidgetItem(topLevelItem);
				extractPOVCTS(povcts,device->joystickDeviceCapacites());
			}
		}
		header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	}	else {
		clear();
		setColumnCount(0);
	}
}

void RCSGJoysticksInfoDockWindow::extractXaxis( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("X axis"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wXmin),QString::number(caps.wXmax)));
}

void RCSGJoysticksInfoDockWindow::extractYaxis( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("Y axis"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wYmin),QString::number(caps.wYmax)));
}

void RCSGJoysticksInfoDockWindow::extractZaxis( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("Z axis"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wZmin),QString::number(caps.wZmax)));
}

void RCSGJoysticksInfoDockWindow::extractRaxis( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("R axis"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wRmin),QString::number(caps.wRmax)));
}

void RCSGJoysticksInfoDockWindow::extractUaxis( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("U axis"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wUmin),QString::number(caps.wUmax)));
}

void RCSGJoysticksInfoDockWindow::extractVaxis( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("V axis"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wVmin),QString::number(caps.wVmax)));
}

void RCSGJoysticksInfoDockWindow::extractPollingFrequency( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("Polling Frequency"));
	QString hex;
	item->setText(1,QString("[%1,%2]").arg(QString::number(caps.wPeriodMin),QString::number(caps.wPeriodMax)));
}

void RCSGJoysticksInfoDockWindow::extractButtonsNumber( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("Buttons Number"));
	QString hex;
	item->setText(1,QString("%1").arg(QString::number(caps.wNumButtons)));
}

void RCSGJoysticksInfoDockWindow::extractPOV( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("POV"));
	QString result("");
	if (caps.wCaps & JOYCAPS_HASPOV)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGJoysticksInfoDockWindow::extractPOV4DIR( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("POV4DIR"));
	QString result("");
	if (caps.wCaps & JOYCAPS_POV4DIR)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}

void RCSGJoysticksInfoDockWindow::extractPOVCTS( QTreeWidgetItem *item, JOYCAPS caps )
{
	item->setText(0,QString("POVCTS"));
	QString result("");
	if (caps.wCaps & JOYCAPS_POVCTS)
	{
		result.append("True");
	} else {
		result.append("False");
	}
	item->setText(1,result);
}
