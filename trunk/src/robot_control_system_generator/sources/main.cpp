#include <QApplication>
#include <QMessageBox>

#include "RCSGAboutDialog.h"
#include "RCSGMainWindow.h"

int main(int argc, char **argv)
{
	QT_REQUIRE_VERSION(argc, argv, "5.1.1");

	QApplication a(argc, argv);

	RCSGMainWindow mw(NULL);
	QWidget central(&mw);
	
	RCSGAboutDialog aboutDialog(&central);

	mw.setCentralWidget(&aboutDialog);
	mw.show();

	return a.exec();
}