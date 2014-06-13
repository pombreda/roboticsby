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

#ifndef RCSGMAINWINDOW_H
#define RCSGMAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <windows.h>
#include <dbt.h>

#include "RCSGConsoleDockWindow.h"
#include "RCSGCommunicationDevicesManager.h"
#include "RCSGInputDevicesManager.h"
#include "RCSGRobotsManager.h"
#include "RCSGComPortsInfoDockWindow.h"
#include "RCSGJoysticksInfoDockWindow.h"
#include "RCSGRobotsInfoDockWindow.h"
#include "RCSGControlSystemGeneratorDockWindow.h"

class RCSGCommunicationDevicesManager;
class RCSGInputDevicesManager;
class RCSGRobotsManager;

class RCSGMainWindow : public QMainWindow 
{
	Q_OBJECT

public:
	RCSGMainWindow(QWidget *parent);
	~RCSGMainWindow();

	public slots:
		void deviceConnected();
		void deviceDisconnected();
		void joystickDevicesAvailable();
		void comPortDevicesAvailable();
		void robotsAvailable();
		void showStatusBarMessage(const QString &message);
		void showApplicationConsoleMessage(const QString &message);
		void showApplicationConsoleAndStatusBarMessage(const QString &message);
		void showAboutDialog();

private:
	Q_DISABLE_COPY( RCSGMainWindow )

	HDEVNOTIFY hDevNotify;

	void createActions();
	void createMenus();
	void createStatusBar();
	void createToolBars();
	void createNotificationFilter();
	void createDockWindows();
	
	void displayConsoleDockWindow();
	void displayComPortsInfoDockWindow();
	void displayJoysticksInfoDockWindow();
	void displayRobotsInfoDockWindow();
	void displayControlSystemGeneratorDockWindow();

	void updateDevicesInformation();

	QIcon createIconFromSVG(const QString &filename);

	QMenu *helpMenu;

	QStatusBar *statusbar;

	QAction *aboutAction;
	QAction *aboutQtAction;

	QAction *consoleAction;
	QAction *startProcessAction;
	QAction *stopProcessAction;

	QAction *controlSystemGeneratorAction;
	QAction *joystickAction;
	QAction *connectionsAction;
	QAction *robotsAction;

	RCSGConsoleDockWindow *console;
	RCSGComPortsInfoDockWindow *comPortsInfo;
	RCSGJoysticksInfoDockWindow *joysticksInfo;
	RCSGRobotsInfoDockWindow *robotsInfo;
	RCSGControlSystemGeneratorDockWindow *controlSystemGeneratorDockWindow;

	QDockWidget *consoleDockWidget;
	QDockWidget *comPortsInfoDockWidget;
	QDockWidget *joysticksInfoDockWidget;
	QDockWidget *robotsInfoDockWidget;
	QDockWidget *controlSystemGeneratorDockWidget;

	QMutex canUpdateDevice;

	QString consoleMessage;

	QToolBar *toolsToolBar;
	QToolBar *simulationToolBar;

	RCSGCommunicationDevicesManager *communicationDevicesManager;
	RCSGInputDevicesManager *inputDevicesManager;
	RCSGRobotsManager *robotsManager;

	private slots:
		void onConsoleAction();
		void onConsoleAction(bool visible);
		void onConnectionsAction();
		void onConnectionsAction(bool visible);
		void onJoystickAction();
		void onJoystickAction(bool visible);
		void onRobotsAction();
		void onRobotsAction(bool visible);
		void onControlSystemGeneratorAction();
		void onControlSystemGeneratorAction(bool visible);
};

#endif //RCSGMAINWINDOW_H
