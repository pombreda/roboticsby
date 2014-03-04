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

#include <QTabWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

#include "Version.h"
#include "RCSGUsbIds.h"
#include "RCSGAboutDialog.h"

RCSGAboutDialog::RCSGAboutDialog(QWidget *p) : QDialog(p) {
	setWindowTitle(tr("About Robot Control System Generator"));

	QTabWidget *qtwTab = new QTabWidget(this);
	QVBoxLayout *vblMain = new QVBoxLayout(this);

	QTextEdit *qtLicense=new QTextEdit(qtwTab);
	qtLicense->setReadOnly(true);
	qtLicense->setPlainText(QLatin1String(licenseRCSG));

	QTextEdit *usbIdsLicense=new QTextEdit(qtwTab);
	usbIdsLicense->setReadOnly(true);
	usbIdsLicense->setPlainText(QLatin1String(licenseUsbIds));

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
	qtwTab->addTab(qtLicense, tr("&License"));
	qtwTab->addTab(usbIdsLicense, tr("&USB ID's database License"));
	
	vblMain->addWidget(qtwTab);

	resize(320, 240);
}
