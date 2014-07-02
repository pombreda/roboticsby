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
#include "RCSGConsoleDockWindow.h"
#include "RCSGJoysticksInfoDockWindow.h"
#include "RCSGComPortsInfoDockWindow.h"
#include "RCSGCommunicationDevicesManager.h"
#include "RCSGInputDevicesManager.h"
#include "RCSGRobotsManager.h"
#include "RCSGCameraDevicesManager.h"

RCSGMainWindow::RCSGMainWindow(QWidget *p) : QMainWindow(p), hDevNotify(NULL),consoleMessage(""),
	communicationDevicesManager(NULL),inputDevicesManager(NULL)
{
	createNotificationFilter();
	createActions();
	createMenus();
	createStatusBar();
	createToolBars();
	createDockWindows();
	resize(640, 480);

	communicationDevicesManager = new RCSGCommunicationDevicesManager(this);
	connect(communicationDevicesManager,SIGNAL(onCommunicationDevicesManagerNewDevices()), this, SLOT(comPortDevicesAvailable()));
	communicationDevicesManager->populateDevices();

	inputDevicesManager = new RCSGInputDevicesManager(this);
	connect(inputDevicesManager,SIGNAL(onInputDevicesManagerNewDevices()), this, SLOT(joystickDevicesAvailable()));
	inputDevicesManager->populateDevices();

	cameraDevicesManager = new RCSGCameraDevicesManager(this);
	connect(cameraDevicesManager,SIGNAL(onCameraDevicesManagerNewDevices()), this, SLOT(cameraDevicesAvailable()));
	cameraDevicesManager->populateDevices();

	robotsManager = new RCSGRobotsManager(this);
	connect(robotsManager,SIGNAL(onRobotsManagerNewRobots()), this, SLOT(robotsAvailable()));
	robotsManager->populateRobots();
	
}

RCSGMainWindow::~RCSGMainWindow()
{
	if (hDevNotify!=NULL)
	{
		UnregisterDeviceNotification(hDevNotify);
		hDevNotify=NULL;
	}
	
	if (communicationDevicesManager!=NULL)
	{		
		emit communicationDevicesManager->cancelPopulatingDevices();
		delete communicationDevicesManager;
		communicationDevicesManager = NULL;
	}
	if (inputDevicesManager!=NULL)
	{		
		emit inputDevicesManager->cancelPopulatingDevices();
		delete inputDevicesManager;
		inputDevicesManager = NULL;
	}
	if (cameraDevicesManager!=NULL)
	{		
		emit cameraDevicesManager->cancelPopulatingDevices();
		delete cameraDevicesManager;
		cameraDevicesManager = NULL;
	}
	if (robotsManager!=NULL)
	{
		emit robotsManager->cancelPopulatingRobots();
		delete robotsManager;
		robotsManager = NULL;
	}
}

void RCSGMainWindow::deviceConnected()
{
	showApplicationConsoleAndStatusBarMessage(QString(tr("USB device connected\n")));
	updateDevicesInformation();
}

void RCSGMainWindow::deviceDisconnected()
{
	showApplicationConsoleAndStatusBarMessage(QString(tr("USB device disconnected\n")));
	updateDevicesInformation();
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

	toolsCameraPreviewAction = new QAction(tr("Camera &preview"), this);
	toolsCameraPreviewAction->setCheckable(true);
	toolsCameraPreviewAction->setChecked(false);
	toolsCameraPreviewAction->setObjectName(QStringLiteral("Camera preview info"));
	connect(toolsCameraPreviewAction, SIGNAL(triggered()), this, SLOT(onCameraPreviewAction()));

	toolsJoystickTestAction = new QAction(tr("Joystick &test"), this);
	toolsJoystickTestAction->setCheckable(true);
	toolsJoystickTestAction->setChecked(false);
	toolsJoystickTestAction->setObjectName(QStringLiteral("Joystick test info"));
	connect(toolsJoystickTestAction, SIGNAL(triggered()), this, SLOT(onJoystickTestAction()));

	toolsCommunicationConsoleAction = new QAction(tr("Communication &console"), this);
	toolsCommunicationConsoleAction->setCheckable(true);
	toolsCommunicationConsoleAction->setChecked(false);
	toolsCommunicationConsoleAction->setObjectName(QStringLiteral("Communication console"));
	connect(toolsCommunicationConsoleAction, SIGNAL(triggered()), this, SLOT(onCommunicationConsoleAction()));
}

void RCSGMainWindow::createMenus()
{
	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(toolsCameraPreviewAction);
	toolsMenu->addAction(toolsJoystickTestAction);
	toolsMenu->addAction(toolsCommunicationConsoleAction);

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
	consoleAction->setIconText(consoleAction->objectName());
	consoleAction->setIcon(createIconFromSVG(QString(":/icons/terminal.svg")));
	connect(consoleAction,SIGNAL(triggered()),this,SLOT(onConsoleAction()));

	startProcessAction = new QAction(this);
	startProcessAction->setEnabled(false);
	startProcessAction->setObjectName(QStringLiteral("Start control process"));
	startProcessAction->setIconText(startProcessAction->objectName());
	startProcessAction->setIcon(createIconFromSVG(QString(":/icons/start.svg")));

	stopProcessAction = new QAction(this);
	stopProcessAction->setEnabled(false);
	stopProcessAction->setObjectName(QStringLiteral("Stop control process"));
	stopProcessAction->setIconText(stopProcessAction->objectName());
	stopProcessAction->setIcon(createIconFromSVG(QString(":/icons/stop.svg")));

	controlSystemGeneratorAction = new QAction(this);
	controlSystemGeneratorAction->setEnabled(false);
	controlSystemGeneratorAction->setObjectName(QStringLiteral("Generate custom system"));
	controlSystemGeneratorAction->setIconText(controlSystemGeneratorAction->objectName());
	controlSystemGeneratorAction->setIcon(createIconFromSVG(QString(":/icons/generate.svg")));
	connect(controlSystemGeneratorAction,SIGNAL(triggered()),this,SLOT(onControlSystemGeneratorAction()));

	joystickAction = new QAction(this);
	joystickAction->setEnabled(false);
	joystickAction->setObjectName(QStringLiteral("Joysticks info"));
	joystickAction->setIconText(joystickAction->objectName());
	joystickAction->setIcon(createIconFromSVG(QString(":/icons/gamepad.svg")));
	connect(joystickAction,SIGNAL(triggered()),this,SLOT(onJoystickAction()));

	ñameraAction = new QAction(this);
	ñameraAction->setEnabled(false);
	ñameraAction->setObjectName(QStringLiteral("Web Cameras info"));
	ñameraAction->setIconText(ñameraAction->objectName());
	ñameraAction->setIcon(createIconFromSVG(QString(":/icons/camera.svg")));
	connect(ñameraAction,SIGNAL(triggered()),this,SLOT(onCameraAction()));

	connectionsAction = new QAction(this);
	connectionsAction->setEnabled(false);
	connectionsAction->setObjectName(QStringLiteral("Connections info"));
	connectionsAction->setIconText(connectionsAction->objectName());
	connectionsAction->setIcon(createIconFromSVG(QString(":/icons/connection.svg")));
	connect(connectionsAction,SIGNAL(triggered()),this,SLOT(onConnectionsAction()));

	robotsAction = new QAction(this);
	robotsAction->setEnabled(false);
	robotsAction->setObjectName(QStringLiteral("Robots info"));
	robotsAction->setIconText(robotsAction->objectName());
	robotsAction->setIcon(createIconFromSVG(QString(":/icons/robot.svg")));
	connect(robotsAction,SIGNAL(triggered()),this,SLOT(onRobotsAction()));

	toolsToolBar = new QToolBar(this);
	toolsToolBar->setObjectName(QStringLiteral("Tools"));
	toolsToolBar->setStyleSheet(QString("QToolBar{border:0px;}"));
	toolsToolBar->setToolTip(QStringLiteral("Tools"));
	toolsToolBar->setAccessibleName("Tools");
	toolsToolBar->addAction(consoleAction);
	toolsToolBar->addAction(joystickAction);
	toolsToolBar->addAction(ñameraAction);
	toolsToolBar->addAction(connectionsAction);
	toolsToolBar->addAction(robotsAction);
	addToolBar(Qt::TopToolBarArea, toolsToolBar);

	simulationToolBar = new QToolBar(this);
	simulationToolBar->setObjectName(QStringLiteral("Control and Generation"));
	simulationToolBar->setStyleSheet(QString("QToolBar{border:0px;}"));
	simulationToolBar->setToolTip(QStringLiteral("Control and Generation"));
	simulationToolBar->setAccessibleName("Control and Generation");
	simulationToolBar->addAction(controlSystemGeneratorAction);
	simulationToolBar->addAction(startProcessAction);
	simulationToolBar->addAction(stopProcessAction);
	addToolBar(Qt::TopToolBarArea, simulationToolBar);
}

void RCSGMainWindow::createNotificationFilter()
{
	GUID GUID_CLASS_USB_DEVICE = {0xA5DCBF10, 0x6530, 0x11D2,
	{0x90, 0x1F, 0x0, 0xC0, 0x4F, 0xB9, 0x51, 0xED}};

	DEV_BROADCAST_DEVICEINTERFACE notificationFilter;
	ZeroMemory( &notificationFilter, sizeof(notificationFilter));
	notificationFilter.dbcc_size        = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	notificationFilter.dbcc_devicetype  = DBT_DEVTYP_DEVICEINTERFACE;
	notificationFilter.dbcc_classguid   = GUID_CLASS_USB_DEVICE;

	hDevNotify = RegisterDeviceNotification((HANDLE)winId(), &notificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE );

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
	if (!consoleAction->isEnabled())
	{
		consoleDockWidget = new QDockWidget(tr("RCSG application console"), this);
		consoleDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		console = new RCSGConsoleDockWindow(consoleDockWidget);
		consoleDockWidget->setWidget(console);
		addDockWidget(Qt::LeftDockWidgetArea, consoleDockWidget);
		connect(consoleDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onConsoleAction(bool)));
		consoleDockWidget->show();
	}
	if (!connectionsAction->isEnabled())
	{
		comPortsInfoDockWidget = new QDockWidget(tr("RCSG communication ports info"), this);
		comPortsInfoDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		comPortsInfo = new RCSGComPortsInfoDockWindow(comPortsInfoDockWidget);
		comPortsInfoDockWidget->setWidget(comPortsInfo);
		addDockWidget(Qt::RightDockWidgetArea, comPortsInfoDockWidget);
		connect(comPortsInfoDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onConnectionsAction(bool)));
		comPortsInfoDockWidget->hide();
	}
	if (!joystickAction->isEnabled())
	{
		joysticksInfoDockWidget = new QDockWidget(tr("RCSG joysticks info"), this);
		joysticksInfoDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		joysticksInfo = new RCSGJoysticksInfoDockWindow(joysticksInfoDockWidget);
		joysticksInfoDockWidget->setWidget(joysticksInfo);
		addDockWidget(Qt::RightDockWidgetArea, joysticksInfoDockWidget);
		connect(joysticksInfoDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onJoystickAction(bool)));
		joysticksInfoDockWidget->hide();
	}
	if (!ñameraAction->isEnabled())
	{
		cameraInfoDockWidget = new QDockWidget(tr("RCSG cameras info"), this);
		cameraInfoDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		cameraInfo = new RCSGCameraInfoDockWindow(cameraInfoDockWidget);
		cameraInfoDockWidget->setWidget(cameraInfo);
		addDockWidget(Qt::RightDockWidgetArea, cameraInfoDockWidget);
		connect(cameraInfoDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onCameraAction(bool)));
		cameraInfoDockWidget->hide();
	}
	if (!toolsCameraPreviewAction->isChecked())
	{
		cameraPreviewDockWidget = new QDockWidget(tr("RCSG cameras preview"), this);
		cameraPreviewDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		cameraPreview = new RCSGCameraPreviewDockWindow(cameraPreviewDockWidget);
		cameraPreviewDockWidget->setWidget(cameraPreview);
		addDockWidget(Qt::RightDockWidgetArea, cameraPreviewDockWidget);
		connect(cameraPreviewDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onCameraPreviewAction(bool)));
		cameraPreviewDockWidget->hide();
	}
	if (!toolsJoystickTestAction->isChecked())
	{
		joystickTestDockWidget = new QDockWidget(tr("RCSG joystick test"), this);
		joystickTestDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		joystickTest = new RCSGJoystickTestDockWindow(joystickTestDockWidget);
		joystickTestDockWidget->setWidget(joystickTest);
		addDockWidget(Qt::RightDockWidgetArea, joystickTestDockWidget);
		connect(joystickTestDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onJoystickTestAction(bool)));
		joystickTestDockWidget->hide();
	}
	if (!toolsCommunicationConsoleAction->isChecked())
	{
		communicationConsoleDockWidget = new QDockWidget(tr("RCSG communication console"), this);
		communicationConsoleDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		communicationConsole = new RCSGCommunicationConsoleDockWindow(communicationConsoleDockWidget);
		communicationConsoleDockWidget->setWidget(communicationConsole);
		addDockWidget(Qt::RightDockWidgetArea, communicationConsoleDockWidget);
		connect(communicationConsoleDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onCommunicationConsoleAction(bool)));
		communicationConsoleDockWidget->hide();
	}
	if (!robotsAction->isEnabled())
	{
		robotsInfoDockWidget = new QDockWidget(tr("RCSG robots info"), this);
		robotsInfoDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		robotsInfo = new RCSGRobotsInfoDockWindow(robotsInfoDockWidget);
		robotsInfoDockWidget->setWidget(robotsInfo);
		addDockWidget(Qt::RightDockWidgetArea, robotsInfoDockWidget);
		connect(robotsInfoDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onRobotsAction(bool)));
		robotsInfoDockWidget->hide();
	}
	if (!controlSystemGeneratorAction->isEnabled())
	{
		controlSystemGeneratorDockWidget = new QDockWidget(tr("RCSG control system generator"), this);
		controlSystemGeneratorDockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
		controlSystemGeneratorDockWindow = new RCSGControlSystemGeneratorDockWindow(controlSystemGeneratorDockWidget);
		controlSystemGeneratorDockWidget->setWidget(controlSystemGeneratorDockWindow);
		addDockWidget(Qt::RightDockWidgetArea, controlSystemGeneratorDockWidget);
		connect(controlSystemGeneratorDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(onControlSystemGeneratorAction(bool)));
		controlSystemGeneratorDockWidget->show();
	}
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

void RCSGMainWindow::onConsoleAction()
{
	consoleAction->setEnabled(!consoleAction->isEnabled());
	displayConsoleDockWindow();
}

void RCSGMainWindow::onConsoleAction(bool visible)
{
	consoleAction->setEnabled(!visible);
}

void RCSGMainWindow::onConnectionsAction()
{
	connectionsAction->setEnabled(!connectionsAction->isEnabled());
	displayComPortsInfoDockWindow();
}

void RCSGMainWindow::onConnectionsAction(bool visible)
{
	connectionsAction->setEnabled(!visible);
}

void RCSGMainWindow::onJoystickAction()
{
	joystickAction->setEnabled(!joystickAction->isEnabled());
	displayJoysticksInfoDockWindow();
}

void RCSGMainWindow::onJoystickAction(bool visible)
{
	joystickAction->setEnabled(!visible);
}

void RCSGMainWindow::onCommunicationConsoleAction()
{
	toolsCommunicationConsoleAction->setChecked(toolsCommunicationConsoleAction->isChecked());
	displayCommunicationConsoleDockWindow();
}

void RCSGMainWindow::onCommunicationConsoleAction( bool checked )
{
	toolsCommunicationConsoleAction->setChecked(checked);
}

void RCSGMainWindow::onJoystickTestAction()
{
	toolsJoystickTestAction->setChecked(toolsJoystickTestAction->isChecked());
	displayJoystickTestDockWindow();
}

void RCSGMainWindow::onJoystickTestAction( bool checked )
{
	toolsJoystickTestAction->setChecked(checked);
}

void RCSGMainWindow::onCameraPreviewAction()
{
	toolsCameraPreviewAction->setChecked(toolsCameraPreviewAction->isChecked());
	displayCameraPreviewDockWindow();
}

void RCSGMainWindow::onCameraPreviewAction(bool checked)
{
	toolsCameraPreviewAction->setChecked(checked);
}

void RCSGMainWindow::onCameraAction()
{
	ñameraAction->setEnabled(!ñameraAction->isEnabled());
	displayCameraInfoDockWindow();
}

void RCSGMainWindow::onCameraAction(bool visible)
{
	ñameraAction->setEnabled(!visible);
}

void RCSGMainWindow::onRobotsAction()
{
	robotsAction->setEnabled(!robotsAction->isEnabled());
	displayRobotsInfoDockWindow();
}

void RCSGMainWindow::onRobotsAction(bool visible)
{
	robotsAction->setEnabled(!visible);
}

void RCSGMainWindow::onControlSystemGeneratorAction()
{
	controlSystemGeneratorAction->setEnabled(!controlSystemGeneratorAction->isEnabled());
	displayControlSystemGeneratorDockWindow();
}

void RCSGMainWindow::onControlSystemGeneratorAction(bool visible)
{
	controlSystemGeneratorAction->setEnabled(!visible);
}

void RCSGMainWindow::displayConsoleDockWindow()
{
	if (!consoleAction->isEnabled())
	{
		consoleDockWidget->show();
		consoleDockWidget->raise();
	}
}

void RCSGMainWindow::displayComPortsInfoDockWindow()
{
	if (!connectionsAction->isEnabled())
	{
		comPortsInfoDockWidget->show();
		comPortsInfoDockWidget->raise();
	}
}

void RCSGMainWindow::displayJoysticksInfoDockWindow()
{
	if (!joystickAction->isEnabled())
	{
		joysticksInfoDockWidget->show();
		joysticksInfoDockWidget->raise();
	}
}

void RCSGMainWindow::displayCameraInfoDockWindow()
{
	if (!ñameraAction->isEnabled())
	{
		cameraInfoDockWidget->show();
		cameraInfoDockWidget->raise();
	}
}

void RCSGMainWindow::displayCameraPreviewDockWindow()
{
	if (toolsCameraPreviewAction->isChecked())
	{
		cameraPreviewDockWidget->show();
		cameraPreviewDockWidget->raise();
	} else {
		cameraPreviewDockWidget->hide();
	}
}

void RCSGMainWindow::displayJoystickTestDockWindow()
{
	if (toolsJoystickTestAction->isChecked())
	{
		joystickTestDockWidget->show();
		joystickTestDockWidget->raise();
	} else {
		joystickTestDockWidget->hide();
	}
}

void RCSGMainWindow::displayCommunicationConsoleDockWindow()
{
	if (toolsCommunicationConsoleAction->isChecked())
	{
		communicationConsoleDockWidget->show();
		communicationConsoleDockWidget->raise();
	} else {
		communicationConsoleDockWidget->hide();
	}
}
void RCSGMainWindow::displayRobotsInfoDockWindow()
{
	if (!robotsAction->isEnabled())
	{
		robotsInfoDockWidget->show();
		robotsInfoDockWidget->raise();
	}
}

void RCSGMainWindow::displayControlSystemGeneratorDockWindow()
{
	if (!controlSystemGeneratorAction->isEnabled())
	{
		controlSystemGeneratorDockWidget->show();
		controlSystemGeneratorDockWidget->raise();
	}
}

void RCSGMainWindow::joystickDevicesAvailable()
{
	QHash<QString,QObject*>* inputDevices = inputDevicesManager->getInputDevices();
	if (inputDevices!=NULL)
	{
		emit onJoystickAction();
		emit joysticksInfo->updateDevicesInformation(inputDevices);
	}
}
void RCSGMainWindow::cameraDevicesAvailable()
{
	QHash<QString,QObject*>* cameraDevices = cameraDevicesManager->getCameraDevices();
	if (cameraDevices!=NULL)
	{
		emit onCameraAction();
		emit cameraInfo->updateDevicesInformation(cameraDevices);
		emit cameraPreview->updateCameraPreviewList(cameraDevices);
	}
}

void RCSGMainWindow::comPortDevicesAvailable()
{
	QHash<QString,QObject*>* communicationDevices = communicationDevicesManager->getCommunocationDevices();
	if (communicationDevices!=NULL)
	{
		emit onConnectionsAction();
		emit comPortsInfo->updateDevicesInformation(communicationDevices);
	}
}

void RCSGMainWindow::robotsAvailable()
{
	QHash<QUuid,QObject*>* robots = robotsManager->getRobots();
	if (robots!=NULL)
	{
		emit onRobotsAction();
		emit robotsInfo->updateRobotsInformation(robots);
	}
}

void RCSGMainWindow::updateDevicesInformation()
{	
	canUpdateDevice.lock();
	communicationDevicesManager->populateDevices();
	inputDevicesManager->populateDevices();
	cameraDevicesManager->populateDevices();
	canUpdateDevice.unlock();
}
