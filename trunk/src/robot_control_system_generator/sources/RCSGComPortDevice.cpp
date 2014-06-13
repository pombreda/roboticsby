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

#include <QVariant>

#include <windows.h>
#include <initguid.h>
#include <setupapi.h>

#include "RCSGComPortDevice.h"

QVariant deviceRegistryProperty(HDEVINFO deviceInfoSet,
								PSP_DEVINFO_DATA deviceInfoData,
								DWORD property)
{
	DWORD dataType = 0;
	DWORD dataSize = 0;
	SetupDiGetDeviceRegistryProperty(deviceInfoSet, deviceInfoData,
		property, &dataType, NULL, 0, &dataSize);
	QByteArray data(dataSize, 0);
	if (!SetupDiGetDeviceRegistryProperty(deviceInfoSet, deviceInfoData, property, NULL,
		reinterpret_cast<unsigned char*>(data.data()),
		dataSize, NULL)
		|| !dataSize) {
			return QVariant();
	}

	switch (dataType) {

	case REG_EXPAND_SZ:
	case REG_SZ: {
		return QVariant(QString::fromWCharArray(reinterpret_cast<const wchar_t *>(data.constData())));
				 }

	case REG_MULTI_SZ: {
		QStringList list;
		int i = 0;
		forever {
			QString s = QString::fromWCharArray(reinterpret_cast<const wchar_t *>(data.constData()) + i);
			i += s.length() + 1;
			if (s.isEmpty())
				break;
			list.append(s);
		}
		return QVariant(list);
					   }

	default:
		break;
	}

	return QVariant();
}

QString devicePortName(HDEVINFO deviceInfoSet, PSP_DEVINFO_DATA deviceInfoData)
{
	 HKEY key = SetupDiOpenDevRegKey(deviceInfoSet, deviceInfoData, DICS_FLAG_GLOBAL,
		0, DIREG_DEV, KEY_READ);
	if (key == INVALID_HANDLE_VALUE)
		return QString();

	DWORD dataSize;
	if (RegQueryValueEx(key, L"PortName", NULL, NULL, NULL, &dataSize) != ERROR_SUCCESS) {
		RegCloseKey(key);
		return QString();
	}

	QByteArray data(dataSize, 0);

	if (RegQueryValueEx(key, L"PortName", NULL, NULL,
		reinterpret_cast<unsigned char *>(data.data()), &dataSize) != ERROR_SUCCESS) {
			RegCloseKey(key);
			return QString();
	}
	RegCloseKey(key);
	return QString::fromWCharArray(((const wchar_t *)data.constData()));
}

RCSGComPortDevice::RCSGComPortDevice(const LPTSTR &portName)
{	
	COMMCONFIG localCommConfig;
	ZeroMemory(&localCommConfig,sizeof(COMMCONFIG));
	ZeroMemory(&commConfig,sizeof(COMMCONFIG));
	DWORD dwSize = sizeof(COMMCONFIG);
	if( GetDefaultCommConfig(portName, &localCommConfig, &dwSize))
	{
		commConfig = localCommConfig;

		GUID guidsArray[] =
		{
			// Windows Ports Class GUID
			{ 0x4D36E978, 0xE325, 0x11CE, { 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18 } },
			// Virtual Ports Class GUID (i.e. com0com and etc)
			{ 0xDF799E12, 0x3C56, 0x421B, { 0xB2, 0x98, 0xB6, 0xD3, 0x64, 0x2B, 0xC8, 0x78 } },
			// Windows Modems Class GUID
			{ 0x4D36E96D, 0xE325, 0x11CE, { 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18 } },
			// Eltima Virtual Serial Port Driver v4 GUID
			{ 0xCC0EF009, 0xB820, 0x42F4, { 0x95, 0xA9, 0x9B, 0xFA, 0x6A, 0x5A, 0xB7, 0xAB } },
			// Advanced Virtual COM Port GUID
			{ 0x9341CD95, 0x4371, 0x4A37, { 0xA5, 0xAF, 0xFD, 0xB0, 0xA9, 0xD1, 0x96, 0x31 } },
		};

		for (int i = 0; i < ARRAYSIZE(guidsArray); ++i) {
			HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&guidsArray[i], NULL, 0, DIGCF_PRESENT);
			if (deviceInfoSet != INVALID_HANDLE_VALUE)
			{
				SP_DEVINFO_DATA deviceInfoData;
				ZeroMemory(&deviceInfoData, sizeof(deviceInfoData));
				deviceInfoData.cbSize = sizeof(deviceInfoData);

				DWORD index = 0;
				while (SetupDiEnumDeviceInfo(deviceInfoSet, index++, &deviceInfoData)) {
					if (devicePortName(deviceInfoSet, &deviceInfoData).contains(QString::fromStdWString(portName)))
					{
						commName = QString::fromStdWString(portName);
						commDescription = deviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_DEVICEDESC).toString();
						commManufacturer = deviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_MFG).toString();
					}
				}
				SetupDiDestroyDeviceInfoList(deviceInfoSet);
			}
		}
	}
}

void RCSGComPortDevice::errorDetailedInformation(LPTSTR functionName) 
{ 
	LPTSTR messageBuffer = NULL;
	DWORD lastError = GetLastError(); 

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		lastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &messageBuffer,
		0, NULL );

	QString result("");
	if (messageBuffer) {
		result = QString("[%1] failed with error %2: %3").arg(
			QString::fromWCharArray(functionName),
			QString::number(lastError),
			QString::fromWCharArray((LPTSTR)messageBuffer).trimmed());
	} else {
		result = QString("Unknown Error %1").arg(lastError);
	}
	LocalFree(messageBuffer);
	emit onDeviceError(result);
}

QString RCSGComPortDevice::commPortName() const
{
	return commName;
}

QString RCSGComPortDevice::commPortDescription() const
{
	return commDescription;
}

QString RCSGComPortDevice::commPortVendor() const
{
	return commManufacturer;
}

COMMCONFIG RCSGComPortDevice::commPortConfig() const
{
	return commConfig;
}
