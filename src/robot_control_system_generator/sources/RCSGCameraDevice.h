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

#include <windows.h>
#include <mfapi.h>

class RCSGCameraDevice : public QObject
{
	Q_OBJECT

public:
	RCSGCameraDevice(const UINT &cameraSlot);
	~RCSGCameraDevice();

	UINT cameraVideoDeviceSlot() const;
	QString cameraDeviceDescription() const;
	QString cameraAudioDeviceDescription() const;
	QVector<IMFMediaType*>* cameraDeviceVideoMediaTypes() const;
	QVector<IMFMediaType*>* cameraDeviceAudioMediaTypes() const;
	QString cameraDeviceVendor() const;
	QVector<QHash<QString,QString>> cameraDeviceVideoCapacites() const;
	QVector<QHash<QString,QString>> cameraDeviceAudioCapacites() const;

private:
	template <class T> void safeRelease(T **ppT);
	template <class T> void safeReleaseAllCount(T **ppT);
	WORD extractVid(LPCWSTR symbolicLink);
	WORD extractPid(LPCWSTR symbolicLink);
	QString decodeMediaTypeKey(const GUID &giud);
	QString decodeMediaTypeValue(const GUID &giud, const PROPVARIANT &variant);
	void enumerateVideoCapabilities();
	void enumerateAudioCapabilities();

	UINT cameraVideoSlot;
	UINT cameraAudioSlot;
	QVector<IMFMediaType*>* cameraVideoMediaTypes;
	QVector<IMFMediaType*>* cameraAudioMediaTypes;
	QVector<QHash<QString,QString>> cameraMediaTypesVideoDeviceCapacites;
	QVector<QHash<QString,QString>> cameraMediaTypesAudioDeviceCapacites;

	QString cameraDescription;
	QString cameraVendor;
	QString cameraVideoUniqueDeviceId;
	QString cameraAudioDescription;
	QString cameraAudioUniqueDeviceId;
};

#endif //RCSGCAMERADEVICE_H_
