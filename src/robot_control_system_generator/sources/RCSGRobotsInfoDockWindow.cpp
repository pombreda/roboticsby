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

#include "RCSGRobotsInfoDockWindow.h"
#include "RCSGHockeyRobot.h"

RCSGRobotsInfoDockWindow::RCSGRobotsInfoDockWindow(QWidget *parent)
	:QTreeWidget(parent)
{
	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::black);
	p.setColor(QPalette::Text, Qt::green);
	setPalette(p);
	setColumnCount(0);
}

void RCSGRobotsInfoDockWindow::updateRobotsInformation(QHash<QUuid,QObject*>* robots)
{
	if (robots!=NULL)
	{
		clear();
		if (robots->size()==0)
		{
			return;
		}
		setColumnCount(2);
		QStringList ColumnNames;
		ColumnNames << QString(tr("Settings"))<<QString(tr("Values"));
		setHeaderLabels(ColumnNames);  
		
		QHash<QUuid,QObject*>::iterator iterator;
		
		for (iterator = robots->begin(); iterator != robots->end(); ++iterator)
		{
			RCSGHockeyRobot *robot = qobject_cast<RCSGHockeyRobot*>(iterator.value());
			if (robot!=NULL)
			{
				QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(this);
				addTopLevelItem(topLevelItem);
				topLevelItem->setText(0,robot->name());
				topLevelItem->setText(1,robot->description());
				QTreeWidgetItem *robotIdItem=new QTreeWidgetItem(topLevelItem);
				robotIdItem->setText(0,QString("id"));
				robotIdItem->setText(1,robot->id().toString());				
			}
		}	
		header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	}	else {
		clear();
		setColumnCount(0);
	}
}
