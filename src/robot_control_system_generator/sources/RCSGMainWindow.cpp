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

#include <QApplication>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QToolBar>
#include <QSvgRenderer>
#include <QPainter>
#include <QDockWidget>
#include <QListWidget>

#include "RCSGMainWindow.h"
#include "RCSGAboutDialog.h"
#include "RCSGConsole.h"
#include "RCSGCommunicationDevicesManager.h"


RCSGMainWindow::RCSGMainWindow(QWidget *p) : QMainWindow(p), hDevNotify(NULL), consoleMessage(""){

	createNotificationFilter();
	createActions();
	createMenus();
	createStatusBar();
	createToolBars();
	createDockWindows();
	resize(640, 480);

	communicationDevicesManager = new RCSGCommunicationDevicesManager(this);
	communicationDevicesManager->populateDevices();
}

RCSGMainWindow::~RCSGMainWindow() {
	UnregisterDeviceNotification(hDevNotify);
	if (communicationDevicesManager!=NULL)
	{		
		emit communicationDevicesManager->cancelPopulatingDevices();
		delete communicationDevicesManager;
		communicationDevicesManager = NULL;
	}
}

void RCSGMainWindow::deviceConnected()
{
	showApplicationConsoleAndStatusBarMessage(QString(tr("USB device connected\n")));
	communicationDevicesManager->populateDevices();
}

void RCSGMainWindow::deviceDisconnected()
{
	showApplicationConsoleAndStatusBarMessage(QString(tr("USB device disconnected\n")));
	communicationDevicesManager->populateDevices();
}

void RCSGMainWindow::showAboutDialog()
{
	RCSGAboutDialog aboutDialog(this);
	aboutDialog.exec();
}

void RCSGMainWindow::createActions()
{
	aboutAction = new QAction(tr("&About"), this);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));

	aboutQtAction = new QAction(tr("About &Qt"), this);
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void RCSGMainWindow::createMenus()
{
	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}

void RCSGMainWindow::createStatusBar()
{
	statusBar()->showMessage(tr("Ready to work"),0);
}

void RCSGMainWindow::createToolBars()
{
	consoleAction = new QAction(this);
	consoleAction->setEnabled(false);
	consoleAction->setObjectName(QStringLiteral("Console"));
	consoleAction->setIcon(createIconFromSVG(QString(":/icons/terminal.svg")));
	connect(consoleAction,SIGNAL(triggered()),this,SLOT(onConsoleAction()));

	startProcessAction = new QAction(this);
	startProcessAction->setEnabled(false);
	startProcessAction->setObjectName(QStringLiteral("Start simulation process"));
	startProcessAction->setIcon(createIconFromSVG(QString(":/icons/start.svg")));

	stopProcessAction = new QAction(this);
	stopProcessAction->setEnabled(false);
	stopProcessAction->setObjectName(QStringLiteral("Stop simulation process"));
	stopProcessAction->setIcon(createIconFromSVG(QString(":/icons/stop.svg")));

	generateProcessAction = new QAction(this);
	generateProcessAction->setEnabled(false);
	generateProcessAction->setObjectName(QStringLiteral("Generate custom system"));
	generateProcessAction->setIcon(createIconFromSVG(QString(":/icons/generate.svg")));

	joystickAction = new QAction(this);
	joystickAction->setEnabled(false);
	joystickAction->setObjectName(QStringLiteral("Joystick setup"));
	joystickAction->setIcon(createIconFromSVG(QString(":/icons/gamepad.svg")));

	connectionsAction = new QAction(this);
	connectionsAction->setEnabled(false);
	connectionsAction->setObjectName(QStringLiteral("Connections setup"));
	connectionsAction->setIcon(createIconFromSVG(QString(":/icons/connection.svg")));

	robotsAction = new QAction(this);
	robotsAction->setEnabled(false);
	robotsAction->setObjectName(QStringLiteral("Robots setup"));
	robotsAction->setIcon(createIconFromSVG(QString(":/icons/robot.svg")));

	toolsToolBar = new QToolBar(this);
	toolsToolBar->setObjectName(QStringLiteral("Tools"));
	toolsToolBar->setStyleSheet(QString("QToolBar{border:0px;}"));
	toolsToolBar->setToolTip(QStringLiteral("Tools"));
	toolsToolBar->setAccessibleName("Tools");
	toolsToolBar->addAction(consoleAction);
	toolsToolBar->addAction(joystickAction);
	toolsToolBar->addAction(connectionsAction);
	toolsToolBar->addAction(robotsAction);
	addToolBar(Qt::TopToolBarArea, toolsToolBar);

	simulationToolBar = new QToolBar(this);
	simulationToolBar->setObjectName(QStringLiteral("Simulation and Generation"));
	simulationToolBar->setStyleSheet(QString("QToolBar{border:0px;}"));
	simulationToolBar->setToolTip(QStringLiteral("Simulation and Generation"));
	simulationToolBar->setAccessibleName("Simulation and Generation");
	simulationToolBar->addAction(startProcessAction);
	simulationToolBar->addAction(stopProcessAction);
	simulationToolBar->addAction(generateProcessAction);
	addToolBar(Qt::TopToolBarArea, simulationToolBar);
}

void RCSGMainWindow::createNotificationFilter()
{
	GUID GUID_CLASS_USB_DEVICE = {0xA5DCBF10, 0x6530, 0x11D2,
	{0x90, 0x1F, 0x0, 0xC0, 0x4F, 0xB9, 0x51, 0xED}};

	DEV_BROADCAST_DEVICEINTERFACE notificationFilter;
	ZeroMemory( &notificationFilter, sizeof(notificationFilter) );
	notificationFilter.dbcc_size        = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	notificationFilter.dbcc_devicetype  = DBT_DEVTYP_DEVICEINTERFACE;
	notificationFilter.dbcc_reserved    = 0;
	notificationFilter.dbcc_classguid   = GUID_CLASS_USB_DEVICE;

	HDEVNOTIFY hDevNotify =
		RegisterDeviceNotification((HANDLE)winId(), &notificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE );

	if(hDevNotify == NULL)
	{
		qDebug() << tr("Error: Failed to register device notification!");
		qApp->quit();
	}
}

QIcon RCSGMainWindow::createIconFromSVG( const QString &filename )
{
	QSvgRenderer renderer(filename);
	QImage image(48, 48, QImage::Format_ARGB32);
	image.fill(0x00000000);
	QPainter painter(&image);
	renderer.render(&painter);
	return QIcon(QPixmap::fromImage(image));
}

void RCSGMainWindow::createDockWindows()
{
	createConsoleDockWindow();
}

void RCSGMainWindow::showStatusBarMessage( const QString &message )
{
	statusBar()->showMessage(message, 5000);
}

void RCSGMainWindow::showApplicationConsoleMessage( const QString &message )
{
	if (console != NULL)
	{
		if (consoleMessage.compare(message)!=0)
		{
			console->putStringData(message);
		}
		consoleMessage.clear();
		consoleMessage.append(message);
	}
}

void RCSGMainWindow::showApplicationConsoleAndStatusBarMessage( const QString &message )
{
	showStatusBarMessage(message);
	showApplicationConsoleMessage(message);
}

void RCSGMainWindow::createConsoleDockWindow()
{
	if (!consoleAction->isEnabled())
	{
		QDockWidget *dock = new QDockWidget(tr("RCSG application console"), this);
		dock->setAllowedAreas(Qt::AllDockWidgetAreas);
		console = new RCSGConsole(dock);
		dock->setWidget(console);
		addDockWidget(Qt::RightDockWidgetArea, dock);
		connect(dock, SIGNAL(visibilityChanged(bool)), this, SLOT(onConsoleAction(bool)));
	}
}

void RCSGMainWindow::onConsoleAction()
{
	consoleAction->setEnabled(!consoleAction->isEnabled());
	createConsoleDockWindow();
}

void RCSGMainWindow::onConsoleAction(bool visible)
{
	consoleAction->setEnabled(!visible);
}
