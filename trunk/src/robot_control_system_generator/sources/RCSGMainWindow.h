#ifndef RCSGMAINWINDOW_H
#define RCSGMAINWINDOW_H

#include <QMainWindow>

class RCSGMainWindow : public QMainWindow {
	Q_OBJECT

		Q_DISABLE_COPY(RCSGMainWindow)
	
public:
	RCSGMainWindow(QWidget *parent);
	~RCSGMainWindow();
};

#endif //RCSGMAINWINDOW_H
