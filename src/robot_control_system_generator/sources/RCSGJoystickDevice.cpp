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
#include <windows.h>

extern "C"
{
#include <hidsdi.h>
#include <setupapi.h>
}

#include "RCSGJoystickDevice.h"

void extractJoystickInfo(unsigned short idVendor, unsigned short idProduct,  QString *joystickVendor, QString *joystickDescription)
{	
	HANDLE handle = NULL;
	HDEVINFO hDevInfo = NULL;
	GUID HidGuid;
	HidD_GetHidGuid(&HidGuid);
	hDevInfo = SetupDiGetClassDevs(&HidGuid, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);
	if (hDevInfo!=INVALID_HANDLE_VALUE)
	{
		DWORD MemberIndex = 0;
		while (handle==NULL)
		{
			SP_DEVICE_INTERFACE_DATA devInfoData;
			devInfoData.cbSize = sizeof(devInfoData);
			if (SetupDiEnumDeviceInterfaces(hDevInfo, 0, &HidGuid, MemberIndex, &devInfoData))
			{	
				DWORD RequiredSize = 0;
				if(SetupDiGetDeviceInterfaceDetail(hDevInfo, &devInfoData, NULL, 0,	&RequiredSize, NULL) == FALSE)
				{
					PSP_DEVICE_INTERFACE_DETAIL_DATA DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)HeapAlloc(GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS | HEAP_ZERO_MEMORY, RequiredSize);
					DeviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
					if(SetupDiGetDeviceInterfaceDetail(hDevInfo, &devInfoData, DeviceInterfaceDetailData, RequiredSize, NULL, NULL))
					{
						handle = CreateFile(DeviceInterfaceDetailData->DevicePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
						if (handle!=INVALID_HANDLE_VALUE)
						{
							HIDD_ATTRIBUTES Attributes;
							Attributes.Size = sizeof(Attributes);
							if (HidD_GetAttributes(handle, &Attributes))
							{
								if (Attributes.VendorID == idVendor &&	Attributes.ProductID == idProduct)
								{	
									WCHAR productBuffer[128];
									ZeroMemory(&productBuffer, ARRAYSIZE(productBuffer));
									WCHAR vendorBuffer[128];
									ZeroMemory(&vendorBuffer, ARRAYSIZE(vendorBuffer));
									if (HidD_GetManufacturerString(handle, vendorBuffer,ARRAYSIZE(vendorBuffer)*2))
									{
										if(joystickVendor->length()==0)
										{
											joystickVendor->append(QString::fromStdWString(vendorBuffer));
										}
									}
									if (HidD_GetProductString(handle, productBuffer, ARRAYSIZE(productBuffer)*2))
									{
										if(joystickDescription->length()==0)
										{
											joystickDescription->append(QString::fromStdWString(productBuffer));
										}
									}
								}
								else
								{	
									CloseHandle(handle);
									handle = NULL;
								}
							}
						}
					}
					HeapFree(GetProcessHeap(), 0, DeviceInterfaceDetailData);
				}				
				MemberIndex++;
			}
			else
			{	
				break;
			}
		}
	}

	if (hDevInfo != NULL)
	{
		SetupDiDestroyDeviceInfoList(hDevInfo);
	}
	if (handle != NULL)
	{
		CloseHandle(handle);
		handle = NULL;
	}
}

RCSGJoystickDevice::RCSGJoystickDevice(const UINT &joystickSlot)
{
	this->joystickSlot = joystickSlot;
	joystickVendor.clear();
	joystickDescription.clear();
	ZeroMemory(&joystickCapacites,sizeof(joystickCapacites));

	joyGetDevCaps(joystickSlot, &joystickCapacites, sizeof(JOYCAPS));
	JOYINFOEX ji;
	ZeroMemory(&ji, sizeof(JOYINFOEX));
	ji.dwSize = sizeof(JOYINFOEX);
	ji.dwFlags = JOY_RETURNALL;
	MMRESULT joystickFeadback = joyGetPosEx(joystickSlot, &ji);  
	if(joystickFeadback==JOYERR_NOERROR)
	{
		RCSGUsbIds idsDataBase;
		joystickVendor.append(idsDataBase.Manufacture(joystickCapacites.wMid));
		joystickDescription.append(idsDataBase.Product(joystickCapacites.wMid,joystickCapacites.wPid));
		if (joystickVendor.length()==0 || joystickDescription.length()==0)
		{
			QString vendor;
			QString description;
			extractJoystickInfo(joystickCapacites.wMid, joystickCapacites.wPid, &vendor, &description);
			if (joystickVendor.length()==0)
			{
				joystickVendor.append(vendor);
			}
			if (joystickDescription.length()==0)
			{
				joystickDescription.append(description);
			}
		}
	}
	joyReleaseCapture(joystickSlot);
}

const JOYCAPS RCSGJoystickDevice::joystickDeviceCapacites()
{
	return joystickCapacites;
}

const UINT RCSGJoystickDevice::joystickDeviceSlot()
{
	return joystickSlot;
}

const QString RCSGJoystickDevice::joystickDeviceDescription()
{
	return joystickDescription;
}

const QString RCSGJoystickDevice::joystickDeviceVendor()
{
	return joystickVendor;
}
