using System;
using System.Runtime.InteropServices;

namespace Joystick_2008_To_WPF.PInvoke
{
    public static class Setupapi
    {
        #region STRUCTURES
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        public struct SpDeviceInterfaceData
        {
            public int CbSize;
            public Guid InterfaceClassGuid;
            public IntPtr Flags;
            public IntPtr Reserved;
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto, Pack = 1)]
        public struct SpDeviceInterfaceDetailData
        {
            public uint CbSize;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 0x1000)]
            public string DevicePath;
        }

        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto, Pack = 1)]
        public struct SpDevinfoData
        {
            public uint CbSize;
            public Guid ClassGuid;
            public uint DevInst;
            public IntPtr Reserved;
        }
        #endregion
        #region FUNCTIONS
        [DllImport("setupapi.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern bool SetupDiDestroyDeviceInfoList(IntPtr hDevInfo);
        [DllImport("setupapi.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern bool SetupDiEnumDeviceInterfaces(IntPtr hDevInfo, IntPtr pDeviceInfoData, ref Guid guid, uint dw, ref SpDeviceInterfaceData deviceInterfaceData);
        [DllImport("setupapi.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern IntPtr SetupDiGetClassDevsA(ref Guid classGuid, IntPtr sEnumerator, IntPtr hWndParent, uint dwFlags);
        [DllImport("setupapi.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern bool SetupDiGetDeviceInterfaceDetailW(IntPtr hDevInfo, ref SpDeviceInterfaceData deviceInterfaceData, ref SpDeviceInterfaceDetailData deviceInterfaceDetailData, uint dwDeviceInterfaceDetailDataSize, ref uint dwRequiredSize, IntPtr deviceInfoData);
        [DllImport("setupapi.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern bool SetupDiGetDeviceRegistryPropertyA(IntPtr hDevInfo, ref SpDevinfoData devInfoData, uint dwProperty, ref uint dwPropertyRefDataType, ref byte[] bPropertyBuffer, uint dwPropertyBufferSize, ref uint dwRequiredSize);
        #endregion
    }
}
