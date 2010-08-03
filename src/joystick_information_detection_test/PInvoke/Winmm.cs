using System;
using System.Security;
using System.Runtime.InteropServices;

namespace Joystick_2008_To_WPF.PInvoke
{
    public static class Winmm
    {
        
        private const String WinmmNativeLibrary = "winmm.dll";

        private const CallingConvention CALLING_CONVENTION = CallingConvention.StdCall;

        public static Int32 SndSync;
        public static Int32 SndAsync = 0x0001;
        public static Int32 SndNodefault = 0x0002;
        public static Int32 SndMemory = 0x0004;
        public static Int32 SndLoop = 0x0008;
        public static Int32 SndNostop = 0x0010;
        public static Int32 SndNowait = 0x00002000;
        public static Int32 SndAlias = 0x00010000;
        public static Int32 SndAliasId = 0x00110000;
        public static Int32 SndFilename = 0x00020000;
        public static Int32 SndResource = 0x00040004;
        public static Int32 SndPurge = 0x0040;
        public static Int32 SndApplication = 0x0080;
        public static Int32 TimerrBase = 96;

        public static Int32 TimerrNoerror;
        public static Int32 TimerrNocando = TimerrBase + 1;
        public static Int32 JoyButton1 = 1;
        public static Int32 JoyButton2 = 2;
        public static Int32 JoyButton3 = 4;
        public static Int32 JoyButton4 = 8;
        public static Int32 JoycapsHasz = 1;
        public static Int32 JoycapsHasr = 2;
        public static Int32 JoycapsHasu = 4;
        public static Int32 JoycapsHasv = 8;
        public static Int32 JoycapsHaspov = 16;
        public static Int32 JoycapsPOV4Dir = 32;
        public static Int32 JoycapsPovcts = 64;

        public static Int32 JoyReturnx = 0x00000001;
        public static Int32 JoyReturny = 0x00000002;
        public static Int32 JoyReturnz = 0x00000004;
        public static Int32 JoyReturnr = 0x00000008;
        public static Int32 JoyReturnu = 0x00000010;
        public static Int32 JoyReturnv = 0x00000020;
        public static Int32 JoyReturnpov = 0x00000040;
        public static Int32 JoyReturnbuttons = 0x00000080;
        public static Int32 JoyReturnrawdata = 0x00000100;
        public static Int32 JoyReturnpovcts = 0x00000200;
        public static Int32 JoyReturncentered = 0x00000400;
        public static Int32 JoyUsedeadzone = 0x00000800;
        public static Int32 JoyReturnall = (JoyReturnx | JoyReturny | JoyReturnz | JoyReturnr | JoyReturnu | JoyReturnv | JoyReturnpov | JoyReturnbuttons);
        public static Int32 JoyCalReadalways = 0x00010000;
        public static Int32 JoyCalReadxyonly = 0x00020000;
        public static Int32 JoyCalRead3 = 0x00040000;
        public static Int32 JoyCalRead4 = 0x00080000;
        public static Int32 JoyCalReadxonly = 0x00100000;
        public static Int32 JoyCalReadyonly = 0x00200000;
        public static Int32 JoyCalRead5 = 0x00400000;
        public static Int32 JoyCalRead6 = 0x00800000;
        public static Int32 JoyCalReadzonly = 0x00800000;
        public static Int32 JoyCalReadronly = 0x02000000;
        public static Int32 JoyCalReaduonly = 0x04000000;
        public static Int32 JoyCalReadvonly = 0x08000000;
        public static Int32 JoyPovcentered = -1;
        public static Int32 JoyPovforward;
        public static Int32 JoyPovright = 9000;
        public static Int32 JoyPovbackward = 18000;
        public static Int32 JoyPovleft = 27000;

        public static Int32 MmsyserrBase;
        public static Int32 MmsyserrNoerror;
        public static Int32 MmsyserrError = 1;
        public static Int32 MmsyserrBaddeviceid = 2;
        public static Int32 MmsyserrNotenabled = 3;
        public static Int32 MmsyserrAllocated = 4;
        public static Int32 MmsyserrInvalhandle = 5;
        public static Int32 MmsyserrNodriver = 6;
        public static Int32 MmsyserrNomem = 7;
        public static Int32 MmsyserrNotsupported = 8;
        public static Int32 MmsyserrBaderrnum = 9;
        public static Int32 MmsyserrInvalflag = 10;
        public static Int32 MmsyserrInvalparam = 11;
        public static Int32 MmsyserrLasterror = 11;

        public static Int32 JoyerrNoerror;
        public static Int32 JoyerrParms = 165;
        public static Int32 JoyerrNocando = 166;
        public static Int32 JoyerrUnplugged = 167;

        public static Int32 JOYSTICKID1;
        public static Int32 JOYSTICKID2 = 1;

        public static Int32 MmJoy1Move = 0x3A0;
        public static Int32 MmJoy2Move = 0x3A1;
        public static Int32 MmJoy1Zmove = 0x3A2;
        public static Int32 MmJoy2Zmove = 0x3A3;

        
        [StructLayout(LayoutKind.Sequential)]
        public struct Joycaps
        {
            /// <summary>
            ///     Manufacturer identifier. Manufacturer identifiers are defined in Manufacturer and Product Identifiers.
            /// </summary>
            //[CLSCompliant(false)]
            public ushort WMid;
            /// <summary>
            ///     Product identifier. Product identifiers are defined in Manufacturer and Product Identifiers.
            /// </summary>
            //[CLSCompliant(false)]
            public ushort WPid;
            /// <summary>
            ///     Null-terminated string containing the joystick product name.
            /// </summary>
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String SzPname;
            /// <summary>
            ///     Minimum X-coordinate.
            /// </summary>
            public Int32 WXmin;
            /// <summary>
            ///     Maximum X-coordinate.
            /// </summary>
            public Int32 WXmax;
            /// <summary>
            /// Minimum Y-coordinate.
            /// </summary>
            public Int32 WYmin;
            /// <summary>
            ///     Maximum Y-coordinate.
            /// </summary>
            public Int32 WYmax;
            /// <summary>
            ///     Minimum Z-coordinate.
            /// </summary>
            public Int32 WZmin;
            /// <summary>
            ///     Maximum Z-coordinate.
            /// </summary>
            public Int32 WZmax;
            /// <summary>
            ///     Number of joystick buttons.
            /// </summary>
            public Int32 WNumButtons;
            /// <summary>
            ///     Smallest polling frequency supported when captured by the  function.
            /// </summary>
            public Int32 WPeriodMin;

            public Int32 WPeriodMax;
            /// <summary>
            ///     Minimum rudder value. The rudder is a fourth axis of movement.
            /// </summary>
            public Int32 WRmin;
            /// <summary>
            ///     Maximum rudder value. The rudder is a fourth axis of movement.
            /// </summary>
            public Int32 WRmax;
            /// <summary>
            ///     Minimum u-coordinate (fifth axis) values.
            /// </summary>
            public Int32 WUmin;
            /// <summary>
            ///     Maximum u-coordinate (fifth axis) values.
            /// </summary>
            public Int32 WUmax;
            /// <summary>
            ///     Minimum v-coordinate (sixth axis) values.
            /// </summary>
            public Int32 WVmin;
            /// <summary>
            ///     Maximum v-coordinate (sixth axis) values.
            /// </summary>
            public Int32 WVmax;
            /// <summary>
            ///     Joystick capabilities The following flags define individual capabilities that a joystick might have:
            /// </summary>
            
            public Int32 WCaps;
            /// <summary>
            ///     Maximum number of axes supported by the joystick.
            /// </summary>
            public Int32 WMaxAxes;
            /// <summary>
            ///     Number of axes currently in use by the joystick.
            /// </summary>
            public Int32 WNumAxes;
            /// <summary>
            ///     Maximum number of buttons supported by the joystick.
            /// </summary>
            public Int32 WMaxButtons;
            /// <summary>
            ///     Null-terminated string containing the registry key for the joystick.
            /// </summary>
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String SzRegKey;
            /// <summary>
            ///     Null-terminated string identifying the joystick driver OEM.
            /// </summary>
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 260)]
            public String SzOemvxD;
        }

        #region Joyinfo
        /// <summary>
        /// The Joyinfo structure contains information about the joystick position and button state.
        /// </summary>
        
        [StructLayout(LayoutKind.Sequential)]
        public struct Joyinfo
        {
            /// <summary>
            ///     Current X-coordinate.
            /// </summary>
            public Int32 WXpos;
            /// <summary>
            ///     Current Y-coordinate.
            /// </summary>
            public Int32 WYpos;
            /// <summary>
            ///     Current Z-coordinate.
            /// </summary>
            public Int32 WZpos;
            /// <summary>
            ///     Current state of joystick buttons.
            /// </summary>
            
            public Int32 WButtons;
        }
        #endregion Joyinfo

        #region Joyinfoex
        /// <summary>
        ///     The Joyinfoex structure contains extended information about the joystick position, point-of-view position, and button state.
        /// </summary>
        
        [StructLayout(LayoutKind.Sequential)]
        public struct Joyinfoex
        {
            /// <summary>
            /// Size, in bytes, of this structure.
            /// </summary>
            public Int32 DwSize;
            /// <summary>
            /// Flags indicating the valid information returned in this structure. Members that do not contain valid information are set to zero.
            /// </summary>
            public Int32 DwFlags;
            /// <summary>
            /// Current X-coordinate.
            /// </summary>
            public Int32 DwXpos;
            /// <summary>
            /// Current Y-coordinate.
            /// </summary>
            public Int32 DwYpos;
            /// <summary>
            /// Current Z-coordinate.
            /// </summary>
            public Int32 DwZpos;
            /// <summary>
            /// Current position of the rudder or fourth joystick axis.
            /// </summary>
            public Int32 DwRpos;
            /// <summary>
            /// Current fifth axis position.
            /// </summary>
            public Int32 DwUpos;
            /// <summary>
            /// Current sixth axis position.
            /// </summary>
            public Int32 DwVpos;
            /// <summary>
            /// Current state of the 32 joystick buttons. The value of this member can be set to any combination of JOY_BUTTONn flags, where n is a value in the range of 1 through 32 corresponding to the button that is pressed.
            /// </summary>
            public Int32 DwButtons;
            /// <summary>
            /// Current button number that is pressed.
            /// </summary>
            public Int32 DwButtonNumber;
            /// <summary>
            /// Current position of the point-of-view control. Values for this member are in the range 0 through 35,900. These values represent the angle, in degrees, of each view multiplied by 100.
            /// </summary>
            public Int32 DwPOV;
            /// <summary>
            /// Reserved; do not use.
            /// </summary>
            public Int32 DwReserved1;
            /// <summary>
            /// Reserved; do not use.
            /// </summary>
            public Int32 DwReserved2;
        }
        #endregion Joyinfoex

        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION, CharSet = CharSet.Auto), SuppressUnmanagedCodeSecurity]
        public static extern Boolean PlaySound(String sound, IntPtr mod, Int32 soundFlags);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 timeBeginPeriod(Int32 period);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 timeEndPeriod(Int32 period);
        
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 timeGetTime();
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyConfigChanged(Int64 dwFlags);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyGetDevCaps(int uJoyID, ref Joycaps pjc, Int32 cbjc);
       
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyGetNumDevs();
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyGetPos(Int32 uJoyID, ref Joyinfo pji);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyGetPosEx(Int32 uJoyID, ref Joyinfoex pji);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyGetThreshold(Int32 uJoyID, IntPtr puThreshold);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joyReleaseCapture(UInt32 uJoyID);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joySetCapture(IntPtr hwnd, Int32 uJoyID, Int32 uPeriod, bool fChanged);
        
        [DllImport(WinmmNativeLibrary, CallingConvention = CALLING_CONVENTION), SuppressUnmanagedCodeSecurity]
        public static extern Int32 joySetThreshold(Int32 uJoyID, Int32 uThreshold);
    }
}
