#include <QApplication>
#include <QMessageBox>

#include "RCSGMainWindow.h"
#include "RCSGWindowsEventFilter.h"

int main(int argc, char **argv)
{
	int result = 0;
	QT_REQUIRE_VERSION(argc, argv, "5.1.1");

	QApplication a(argc, argv);	
	RCSGMainWindow mw(NULL);

	RCSGWindowsEventFilter filter(&mw); 
	a.installNativeEventFilter(&filter);
	
	mw.show();
	
	result = a.exec();
	a.removeNativeEventFilter(&filter);

	return result;
}