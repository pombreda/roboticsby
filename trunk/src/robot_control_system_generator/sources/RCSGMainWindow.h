#ifndef RCSGMAINWINDOW_H
#define RCSGMAINWINDOW_H

#include <QMainWindow>

#include <windows.h>
#include <dbt.h>

class RCSGMainWindow : public QMainWindow {
private:
	Q_OBJECT
	Q_DISABLE_COPY( RCSGMainWindow )

	HDEVNOTIFY hDevNotify;
	
public:
	RCSGMainWindow(QWidget *parent);
	~RCSGMainWindow();

public slots:
	void deviceConnected();
	void deviceDisconnected();

	void showAboutDialog();

private:
	void createActions();
	void createMenus();

	QMenu *helpMenu;

	QAction *aboutAction;
	QAction *aboutQtAction;
};

#endif //RCSGMAINWINDOW_H
