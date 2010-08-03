using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading;

namespace Joystick_2008_To_WPF.PInvoke
{
    class FindAllJoys
    {
        public const short InvalidHandleValue = -1;
        public static bool CloseDevice(IntPtr hDevice)
        {
            return Kernel32.CloseHandle(hDevice);
        }

        private static void Delay(int milliseconds)
        {
            var event2 = new AutoResetEvent(false);
            event2.Reset();
            event2.WaitOne(milliseconds, false);
        }

        public static List<FindingDevice> FindDevice(int nVendorId, int nProductId, out string sDevicePath)
        {
            int index = 0;
            var devices = new List<FindingDevice>();
            Guid guid;
            sDevicePath = "";
            Hid.HidD_GetHidGuid(out guid);
            var hDevInfo = Setupapi.SetupDiGetClassDevsA(ref guid, IntPtr.Zero, IntPtr.Zero, 0x12);
            if (hDevInfo.ToInt32() == -1)
            {
                return null;
            }
            uint dw = 0;
            var deviceInterfaceData = new Setupapi.SpDeviceInterfaceData();

            deviceInterfaceData.CbSize = Marshal.SizeOf(deviceInterfaceData);

            var deviceInterfaceDetailData = new Setupapi.SpDeviceInterfaceDetailData {CbSize = 6};
            while (true)
            {
                deviceInterfaceData.CbSize = 0x1c;
                if (!Setupapi.SetupDiEnumDeviceInterfaces(hDevInfo, IntPtr.Zero, ref guid, dw, ref deviceInterfaceData))
                {
                    return devices;
                }
                dw++;
                uint dwRequiredSize = 0;
                if (Setupapi.SetupDiGetDeviceInterfaceDetailW(hDevInfo, ref deviceInterfaceData, ref deviceInterfaceDetailData, 0x1004, ref dwRequiredSize, IntPtr.Zero))
                {
                    var devicePath = deviceInterfaceDetailData.DevicePath;
                    var hDevice = Kernel32.CreateFile(devicePath, 0xc0000000, 3, IntPtr.Zero, 3, 0, IntPtr.Zero);
                    if (hDevice.ToInt32() != -1)
                    {
                        var f = new FindingDevice();
                        var attributes = new Hid.HiddAttributes {Size = 10};
                        Hid.HidD_GetAttributes(hDevice, ref attributes);
                        f.Attr = attributes;
                        f.Num = dw;
                        f.Index = index;
                        index++;
                        devices.Add(f);
                        
                        Kernel32.CloseHandle(hDevice);
                    }
                    else
                    {
                        Kernel32.GetLastError();
                    }
                }
            }
        }


        public static IntPtr OpenDevice(string sDevicePath)
        {
            return Kernel32.CreateFile(sDevicePath, 0xc0000000, 3, IntPtr.Zero, 3, 0, IntPtr.Zero);
        }


        public static int ReceiveData(IntPtr hDevice, byte[] abData, uint nDataLen, int nReportId)
        {
            uint num;
            if (!Kernel32.ReadFile(hDevice, abData, nDataLen, out num, IntPtr.Zero))
            {
                num = 0;
            }
            return (int)num;
        }

        public static bool ReceiveReport(IntPtr hDevice, byte[] abData, uint nReportLength)
        {
            uint num;
            if (!Kernel32.ReadFile(hDevice, abData, nReportLength, out num, IntPtr.Zero))
            {
                Kernel32.GetLastError();
                num = 0;
            }
            Delay(15);
            return (num == nReportLength);
        }

        public static bool SendData(IntPtr hDevice, byte[] abData, uint nDataLen, int nReportId)
        {
            var abReport = new byte[nDataLen + 1];
            abReport[0] = (byte)nReportId;
            for (var i = 0; i < nDataLen; i++)
            {
                abReport[i + 1] = abData[i];
            }
            return SendReport(hDevice, abReport, nDataLen + 1);
        }

        public static bool SendReport(IntPtr hDevice, byte[] abReport, uint nReportLength)
        {
            uint lpNumberOfBytesWritten;
            Kernel32.WriteFile(hDevice, abReport, nReportLength, out lpNumberOfBytesWritten, IntPtr.Zero);
            Delay(15);
            return (lpNumberOfBytesWritten == nReportLength);
        }

        public class FindingDevice
        {
            public int Index { get; set; }
            public uint Num { get; set; } 
            public Hid.HiddAttributes Attr { get; set; }
        }
    }
}
