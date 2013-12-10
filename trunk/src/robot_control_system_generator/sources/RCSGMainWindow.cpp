#include <QApplication>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "RCSGMainWindow.h"
#include "RCSGAboutDialog.h"

RCSGMainWindow::RCSGMainWindow(QWidget *p) : QMainWindow(p), hDevNotify(NULL){

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
		qDebug() << "Error: Failed to register device notification!";
		qApp->quit();
	}
	
	createActions();
	createMenus();

	resize(640, 480);
}

RCSGMainWindow::~RCSGMainWindow() {
	UnregisterDeviceNotification(hDevNotify);
}

void RCSGMainWindow::deviceConnected()
{
	qDebug() << "DeviceConnected";
}

void RCSGMainWindow::deviceDisconnected()
{
	qDebug() << "DeviceDisconnected";
}

void RCSGMainWindow::showAboutDialog()
{
	RCSGAboutDialog aboutDialog(this);
	aboutDialog.exec();
}

void RCSGMainWindow::createActions()
{
	aboutAction = new QAction(tr("&About"), this);
	aboutAction->setStatusTip(tr("Show the RCSG About box"));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));

	aboutQtAction = new QAction(tr("About &Qt"), this);
	aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void RCSGMainWindow::createMenus()
{
	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}