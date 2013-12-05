#include <QTabWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

#include "Version.h"
#include "RCSGAboutDialog.h"

RCSGAboutDialog::RCSGAboutDialog(QWidget *p) : QDialog(p) {
	setWindowTitle(tr("About Robot Control System Generator"));

	QTabWidget *qtwTab = new QTabWidget(this);
	QVBoxLayout *vblMain = new QVBoxLayout(this);

	QTextEdit *qteLicense=new QTextEdit(qtwTab);
	qteLicense->setReadOnly(true);
	qteLicense->setPlainText(QLatin1String(licenseRCSG));

	QWidget *about=new QWidget(qtwTab);

	QLabel *text=new QLabel(about);
	text->setOpenExternalLinks(true);
	text->setText(tr(
	                  "<h3>%1 (%2)</h3>"
	                  "<p>Copyright %4 Sergey Gerasuto <a href='mailto:contacts@robotics.by'>contacts@robotics.by</a></p>"
	                  "<p><b>A robot control system generator application</b></p>"
	                  "<p><tt><a href=\"%3\">%3</a></tt></p>"
	              ).arg(QLatin1String(VER_PRODUCTNAME_STR)).arg(QLatin1String(RCSG_RELEASE)).arg(QLatin1String("http://www.robotics.by/")).arg(QLatin1String("2013-2014")));
	QHBoxLayout *qhbl=new QHBoxLayout(about);
	qhbl->addWidget(text);

	qtwTab->addTab(about, tr("&About RCSG"));
	qtwTab->addTab(qteLicense, tr("&License"));

	QPushButton *okButton = new QPushButton(tr("OK"), this);
	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

	vblMain->addWidget(qtwTab);
	vblMain->addWidget(okButton);
}
