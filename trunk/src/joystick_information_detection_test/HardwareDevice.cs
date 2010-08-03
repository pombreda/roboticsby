using System;
using System.Runtime.InteropServices;

namespace Joystick_2008_To_WPF
{
    class HardwareDevice
    {
        #region CONSTANTS
        public const int JoyButton6 = 0x20;
        public static Int32 JoyReturnx = 0x00000001;
        public static Int32 JoyReturny = 0x00000002;
        public static Int32 JoyReturnz = 0x00000004;
        public static Int32 JoyReturnr = 0x00000008;
        public static Int32 JoyReturnu = 0x00000010;
        public static Int32 JoyReturnv = 0x00000020;
        public static Int32 JoyReturnpov = 0x00000040;
        public static Int32 JoyReturnbuttons = 0x00000080;
        public static Int32 JoyReturnall = (JoyReturnx | JoyReturny | JoyReturnz | JoyReturnr | JoyReturnu | JoyReturnv | JoyReturnpov | JoyReturnbuttons);
        #endregion
        //Dynamic information (X,Y,Z,...)
        public PInvoke.Winmm.Joyinfoex JoyInfoEx;
        //Static information (driver,max X, max Y,..)
        public PInvoke.Winmm.Joycaps Jc;
        public HardwareDevice()
        {
            JoyInfoEx = new PInvoke.Winmm.Joyinfoex { DwSize = Marshal.SizeOf(JoyInfoEx), DwFlags = JoyReturnall };
            Jc = new PInvoke.Winmm.Joycaps();
        }
    }
}