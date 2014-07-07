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

#ifndef RCSGCAMERADEVICE_H_
#define RCSGCAMERADEVICE_H_

#include <QObject>
#include <QVector>
#include <mfapi.h>

#include <windows.h>

class RCSGCameraDevice : public QObject
{
	Q_OBJECT

public:
	RCSGCameraDevice(const UINT &cameraSlot);
	~RCSGCameraDevice();

	UINT cameraDeviceSlot() const;
	QString cameraDeviceDescription() const;
	QVector<IMFMediaType*>* cameraDeviceMediaTypes() const;
	QString cameraDeviceVendor() const;
	QVector<QHash<QString,QString>> cameraDeviceCapacites() const;

private:
	template <class T> void safeRelease(T **ppT);
	WORD extractVid(LPCWSTR symbolicLink);
	WORD extractPid(LPCWSTR symbolicLink);
	QString decodeMediaTypeKey(const GUID &giud);
	QString decodeMediaTypeValue(const GUID &giud, const PROPVARIANT &variant);
	void sortMediaTypesDeviceCapacitesByFrameSize();
	UINT cameraSlot;
	QVector<IMFMediaType*>* cameraMediaTypes;
	QVector<QHash<QString,QString>> cameraMediaTypesDeviceCapacites;
	QString cameraDescription;
	QString cameraVendor;
};

#endif //RCSGCAMERADEVICE_H_
