using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Joystick_2008_To_WPF.PInvoke
{
    
    public static class Hid
    {
        #region STRUCTURE
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        public struct HiddAttributes
        {
            public uint Size;
            public ushort VendorId;
            public ushort ProductId;
            public ushort VersionNumber;
        }
        #endregion
        #region FUNCTIONS
        [DllImport("hid.dll", SetLastError = true, CallingConvention = CallingConvention.StdCall)]
        public static extern bool HidD_GetProductString(IntPtr hidDeviceObject, StringBuilder buffer, Int32 bufferLength);
        [DllImport("hid.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern bool HidD_GetAttributes(IntPtr hDevice, ref HiddAttributes attributes);
        [DllImport("hid.dll", CharSet = CharSet.Auto, SetLastError = true, ExactSpelling = true)]
        public static extern uint HidD_GetHidGuid(out Guid hidGuid);
        #endregion
    }
}
