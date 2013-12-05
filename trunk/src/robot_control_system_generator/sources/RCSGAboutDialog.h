#ifndef RCSGABOUTDIALOG_H_
#define RCSGABOUTDIALOG_H_

#include <QObject>
#include <QDialog>

class RCSGAboutDialog : public QDialog {
	private:
		Q_OBJECT
		Q_DISABLE_COPY(RCSGAboutDialog)
	public:
		RCSGAboutDialog(QWidget *parent);
};

#endif //RCSGABOUTDIALOG_H_
