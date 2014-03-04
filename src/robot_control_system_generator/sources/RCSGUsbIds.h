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

#ifndef USBIDS_H_
#define USBIDS_H_

#include <windows.h>
#include <QHash>
#include <QString>


static const char *licenseUsbIds = 
"\n"
"	List of USB ID's\n"
"\n"
"	Maintained by Stephen J. Gowdy <linux.usb.ids@gmail.com>\n"
"	If you have any new entries, please submit them via\n"
"		http://www.linux-usb.org/usb-ids.html\n"
"	or send entries as patches (diff -u old new) in the\n"
"	body of your email (a bot will attempt to deal with it).\n"
"	The latest version can be obtained from\n"
"		http://www.linux-usb.org/usb.ids\n"
"\n"
" Version: 2014.02.03\n"
" Date:    2014-02-03 20:34:03\n";

class RCSGUsbIds
{
public:
	RCSGUsbIds();
	QString Manufacture(WORD manufactureId);
	QString Product(WORD manufactureId, WORD productId);

private:
	QHash<WORD, QString> mh;
	QHash<WORD, QHash<WORD, QString>> mph;
	void InitManufacturesUsbIdsHash();
	void InitManufacturesProductsUsbIdsHash();
	void InsertVendors(DWORD *mid, char **mids, unsigned int size);
	void InsertProducts(DWORD vendorId ,DWORD *mid, char **mids, unsigned int size);
};

#endif //USBIDS_H_