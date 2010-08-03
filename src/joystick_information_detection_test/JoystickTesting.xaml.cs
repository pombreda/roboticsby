using System;
using System.Windows;
using System.Collections;
using System.Windows.Input;
using System.Windows.Interop;
using System.Diagnostics;
using Joystick_2008_To_WPF.BaseStructs;
using Joystick_2008_To_WPF.Controls;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using Joystick_2008_To_WPF.PInvoke;


namespace Joystick_2008_To_WPF
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    /// 
    public partial class JoystickTesting
    {
        #region CONSTANTS
        public const int MmJoy1Buttondown = 0x3B5;
        public const int MmJoy1Buttonup = 0x3B7;
        public const int MmJoy1Move = 0x3A0;
        public const int MmJoy1Zmove = 0x3A2;
        public const int MmJoy2Buttondown = 0x3B6;
        public const int MmJoy2Buttonup = 0x3B8;
        public const int MmJoy2Move = 0x3A1;
        public const int MmJoy2Zmove = 0x3A3;

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
        private readonly Winmm.Joyinfoex _joyInfoEx;
        private Winmm.Joyinfo _joyInfo;
        int _selectedJoy;
        BackgroundWorker _backgroundWorker;
        bool _changeingJoy = true;
        bool _canChange;
        private JoyEclipce _myEclipce;
        private JoyRectangle _myRectangle;
        private IntPtr _mainWindowPtr;
        HardwareDevice _hardwareDevice;
        List<FindAllJoys.FindingDevice> _devices;
        List<Vendor> _vendors;
        List<Product> _products;
        string _infAboutDatas = "";
        HwndSourceHook _hook;

        public JoystickTesting(Winmm.Joyinfoex joyInfoEx)
        {
            InitializeComponent();
            _hook = new HwndSourceHook(WndProc);
            _joyInfoEx = joyInfoEx;
        }

        public JoystickTesting()
        {
            var fi = new FileInfo("VendorsAndProductsBase.xml");
            if (!fi.Exists)
                fi.Create();
        }

        public Winmm.Joyinfoex JoyInfoEx
        {
            get { return _joyInfoEx; }
        }

        /// <summary>
        /// Is any joystick here or not?
        /// </summary>
        /// <returns></returns>
        bool JoyIsHere()
        {
            var count = 0;
            try
            {
                for (var i = 0; i < Winmm.joyGetNumDevs(); i++)
                {
                    _joyInfo = new Winmm.Joyinfo();
                    Winmm.joyGetPos(i, ref _joyInfo);
                    if (Winmm.joyGetPos(i, ref _joyInfo) == 0)
                    {
                        count++;
                    }
                }
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message, "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
            if (count == 0)
            {
                com_joysticks.Items.Clear();
                return false;
            }
            return true;
        }

        void ShowJoyStaticInf()
        {
            try
            {
                var m = com_joysticks.SelectedItem.ToString().Split(' ');
                _selectedJoy = int.Parse(m[0]) - 1;
               
                var t = Winmm.joyGetDevCaps(_selectedJoy, ref _hardwareDevice.Jc, Marshal.SizeOf(_hardwareDevice.Jc));
                if (t == Winmm.JoyerrParms)
                {
                    MessageBox.Show("Invalid joystick parameters 1", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return;
                }
                label_The_joystick_driver_ANSWER.Content = _hardwareDevice.Jc.SzPname;
                var count = Winmm.joyGetNumDevs();
                label_count_answer.Content = count.ToString();
                //Number of buttons
                label_Buttons_count_ANSWER.Content = _hardwareDevice.Jc.WNumButtons.ToString();
                //Max and min values of co-ordinates
                label_Max_val_X_VALUE.Content = _hardwareDevice.Jc.WXmax.ToString();
                label_Min_val_X_VALUE.Content = _hardwareDevice.Jc.WXmin.ToString();

                label_Max_val_Y_VALUE.Content = _hardwareDevice.Jc.WYmax.ToString();
                label_Min_val_Y_VALUE.Content = _hardwareDevice.Jc.WYmin.ToString();

                label_Max_val_Z_VALUE.Content = _hardwareDevice.Jc.WZmax.ToString();
                label_Min_val_Z_VALUE.Content = _hardwareDevice.Jc.WZmin.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        public IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
        {
            if (_canChange)
            {
                #region JOY 1
                if (msg == MmJoy1Buttondown)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    _myEclipce.UpdateColor(ColorsForButton.GenerateColour(PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons)));
                    label_buttons.Content = PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons);
                    label_but_num.Content = _hardwareDevice.JoyInfoEx.DwButtonNumber.ToString();
                }
                if (msg == MmJoy1Move)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    _myEclipce.UpdateEllipcePosition(_hardwareDevice.JoyInfoEx.DwXpos, _hardwareDevice.JoyInfoEx.DwYpos);
                    label_ANSWER_X.Content = _hardwareDevice.JoyInfoEx.DwXpos.ToString();
                    label_ANSWER_Y.Content = _hardwareDevice.JoyInfoEx.DwYpos.ToString();
                }
                if (msg == MmJoy1Zmove)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    _myRectangle.UpdateRectanglePosition(_hardwareDevice.JoyInfoEx.DwZpos);
                    label_ANSWER_Z.Content = _hardwareDevice.JoyInfoEx.DwZpos.ToString();
                    _myRectangle.UpdateColor(_hardwareDevice.JoyInfoEx.DwZpos, _hardwareDevice.Jc.WZmax);
                }
                if (msg == MmJoy1Buttonup)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    if (_hardwareDevice.JoyInfoEx.DwButtonNumber > 0)
                    {
                        _myEclipce.UpdateColor(ColorsForButton.GenerateColour(PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons)));
                        label_buttons.Content = PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons);
                        label_but_num.Content = _hardwareDevice.JoyInfoEx.DwButtonNumber.ToString();
                    }
                    else
                    {
                        _myEclipce.UpdateColor(null);
                        label_buttons.Content = "";
                        label_but_num.Content = "";
                    }
                }
                #endregion
                #region JOY 2
                if (msg == MmJoy2Buttondown)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    _myEclipce.UpdateColor(ColorsForButton.GenerateColour(PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons)));
                    label_buttons.Content = PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons);
                    label_but_num.Content = _hardwareDevice.JoyInfoEx.DwButtonNumber.ToString();
                }
                if (msg == MmJoy2Move)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    _myEclipce.UpdateEllipcePosition(_hardwareDevice.JoyInfoEx.DwXpos, _hardwareDevice.JoyInfoEx.DwYpos);
                    label_ANSWER_X.Content = _hardwareDevice.JoyInfoEx.DwXpos.ToString();
                    label_ANSWER_Y.Content = _hardwareDevice.JoyInfoEx.DwYpos.ToString();
                }
                if (msg == MmJoy2Zmove)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);
                    _myRectangle.UpdateRectanglePosition(_hardwareDevice.JoyInfoEx.DwZpos);
                    label_ANSWER_Z.Content = _hardwareDevice.JoyInfoEx.DwZpos.ToString();
                    _myRectangle.UpdateColor(_hardwareDevice.JoyInfoEx.DwZpos, _hardwareDevice.Jc.WZmax);
                }
                if (msg == MmJoy2Buttonup)
                {
                    Winmm.joyGetPosEx(_selectedJoy, ref _hardwareDevice.JoyInfoEx);

                    if (_hardwareDevice.JoyInfoEx.DwButtonNumber > 0)
                    {
                        _myEclipce.UpdateColor(ColorsForButton.GenerateColour(PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons)));
                        label_buttons.Content = PressedButtons(_hardwareDevice.JoyInfoEx.DwButtons);
                        label_but_num.Content = _hardwareDevice.JoyInfoEx.DwButtonNumber.ToString();
                    }
                    else
                    {
                        _myEclipce.UpdateColor(null);
                        label_buttons.Content = "";
                        label_but_num.Content = "";
                    }
                }
                #endregion
            }
            return IntPtr.Zero;
        }

        string PressedButtons(int inf)
        {
            var rezult = string.Empty;
            if (_hardwareDevice.JoyInfoEx.DwButtons > 0)
            {
                var table = new Hashtable();
                var val = 1;
                table.Add(1, 1);
                for (var i = 2; i < _hardwareDevice.Jc.WNumButtons + 2; i++)
                {
                    table.Add(i, val * 2);
                    val = val * 2;
                }
                for (var i = 12; i > 1; i--)
                {
                    if ((inf < Convert.ToInt32(table[i])) && (inf >= Convert.ToInt32(table[i - 1])))
                    {
                        rezult += (i - 1) + " ";
                        inf -= Convert.ToInt32(table[i - 1]);
                    }
                    if ((i - 1) == 1)
                    {
                        break;
                    }
                }
            }
            return rezult;
        }

        void FillComboBox()
        {
            com_joysticks.Items.Clear();
            string s;
            _devices = FindAllJoys.FindDevice(0, 0, out s);
            int index = 0;
            for (int i = 0; i < Winmm.joyGetNumDevs(); i++)
            {
                _joyInfo = new Winmm.Joyinfo();
                Winmm.joyGetPos(i, ref _joyInfo);
                if (Winmm.joyGetPos(i, ref _joyInfo) == 0)
                {
                    string names = WorkWithDataBase.GetDatasFromXmlFile.GetNames(index, _devices);
                    index++;
                    if ((names.Length > 0) && (names != " ()"))
                    {
                        com_joysticks.Items.Add((i + 1) + " " + names);
                    }
                    else
                    {
                        com_joysticks.Items.Add((i + 1) + " <Unknown joystick> ");
                    }
                }
            }
        }

        private void Image1PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            var proc = new Process { StartInfo = { FileName = "www.robotics.by" } };
            proc.Start();
        }

        private void ComJoysticksDropDownOpened(object sender, EventArgs e)
        {
            _hardwareDevice = new HardwareDevice();
            _myEclipce.Visibility = Visibility.Hidden;
            _myRectangle.Visibility = Visibility.Hidden;
            _canChange = false;
            string s;
            _devices = FindAllJoys.FindDevice(0, 0, out s);//VendorId ProductId
            FillComboBox();
            if (!_changeingJoy)
            {
                _changeingJoy = true;
            }
        }

        private void ComJoysticksSelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            try
            {
                if (JoyIsHere())
                {
                    if (_changeingJoy)
                    {
                        ShowJoyStaticInf();
                        int t = Winmm.joySetCapture(_mainWindowPtr, _selectedJoy, 15, false);
                        if (t == Winmm.JoyerrParms)
                        {
                            MessageBox.Show("Invalid joystick parameters 2", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
                            return;
                        }
                        _myEclipce.Visibility = Visibility.Visible;
                        _myRectangle.Visibility = Visibility.Visible;
                        _changeingJoy = false;
                        _canChange = true;
                    }
                }
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message, "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        private void ButUpdateJoysBaseClick(object sender, RoutedEventArgs e)
        {
            ControlsEnableIsTrue(false);

            _vendors = new List<Vendor>();
            _products = new List<Product>();
            _infAboutDatas = "";
            var fileInfo = new FileInfo("VENDORS.txt");
            if (fileInfo.Exists)
            {
                WorkWithDataBase.UpdateDataBase.GetDatasFromTxtFile(ref _vendors, ref _products, ref _infAboutDatas);
                _backgroundWorker = new BackgroundWorker();
                UpdateBase();
            }
            else
            {
                ControlsEnableIsTrue(true);
                MessageBox.Show("VENDORS.txt file is not exist", "WARNING", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        void UpdateBase()
        {
            _backgroundWorker.DoWork += BackgroundWorker1DoWork;
            _backgroundWorker.RunWorkerAsync();
        }

        private void ButShowBaseInformationClick(object sender, RoutedEventArgs e)
        {
            try
            {
                var fi = new FileInfo("VendorsAndProductsBase.xml");
                if (fi.Length > 10)
                {
                    var baseInfWind =
                        new BaseInformation(WorkWithDataBase.GetDatasFromXmlFile.ShowInformationAboutBase());
                    baseInfWind.Show();
                }
                else
                {
                    MessageBox.Show("Can not find the database, update it.", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        void ControlsEnableIsTrue(bool isEnable)
        {
            if (isEnable)
            {
                Dispatcher.Invoke(
                   new Action(() =>
                   {
                       but_UpdateJoysBase.IsEnabled = true;
                   }
                       )
                   );
                Dispatcher.Invoke(
                  new Action(() =>
                  {
                      com_joysticks.IsEnabled = true;
                  }
                       )
                   );
                Dispatcher.Invoke(
                  new Action(() =>
                  {
                      but_ShowBaseInformation.IsEnabled = true;
                  }
                      )
                  );
            }
            else
            {
                Dispatcher.Invoke(
                   new Action(() =>
                   {
                       but_UpdateJoysBase.IsEnabled = false;
                   }
                       )
                   );
                Dispatcher.Invoke(
                  new Action(() =>
                  {
                      com_joysticks.IsEnabled = false;
                  }
                       )
                   );
                Dispatcher.Invoke(
                  new Action(() =>
                  {
                      but_ShowBaseInformation.IsEnabled = false;
                  }
                      )
                  );
            }
        }

        private void BackgroundWorker1DoWork(object sender, DoWorkEventArgs e)
        {
            try
            {
                ControlsEnableIsTrue(false);
                WorkWithDataBase.UpdateDataBase.ToUpdateDataBase(_vendors, _products, _infAboutDatas);
                ControlsEnableIsTrue(true);
            }
            catch (Exception exc)
            {
                ControlsEnableIsTrue(true);
                MessageBox.Show(exc.Message, "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }

        static HwndSource HwndSourceOpen(Window w)
        {
            var src = HwndSource.FromHwnd(new WindowInteropHelper(w).Handle);
            return src;
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            _myEclipce = new JoyEclipce();
            _myRectangle = new JoyRectangle();
            big_canvas.Children.Add(_myEclipce);
            big_canvas.Children.Add(_myRectangle);
            _myEclipce.Visibility = Visibility.Hidden;
            _myRectangle.Visibility = Visibility.Hidden;

            _hook = new HwndSourceHook(WndProc);
            HwndSourceOpen(this).AddHook(_hook);
            _mainWindowPtr = new WindowInteropHelper(this).Handle;
        }
    }
}