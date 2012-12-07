@echo off
@echo *********************************
@echo * www.robotics.by Build creator * 
@echo *********************************

@echo Progress: Build Started using MVS 2008
@call 32bit\vs2008\cl2008_c#.cmd
C:\WINDOWS\Microsoft.NET\Framework\v3.5\Csc.exe /noconfig /nowarn:1701,1702 /platform:x86 /errorreport:prompt /warn:4 /define:TRACE /reference:"C:\WINDOWS\Microsoft.NET\DirectX for Managed Code\1.0.2902.0\Microsoft.DirectX.DirectInput.dll" /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\PresentationCore.dll" /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\PresentationFramework.dll" /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Core.dll" /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Data.DataSetExtensions.dll" /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Data.dll /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Data.Linq.dll" /reference:"C:\Program Files\Microsoft SQL Server Compact Edition\v3.5\Desktop\System.Data.SqlServerCe.dll" /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Drawing.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Management.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Transactions.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Windows.Forms.dll /reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Xml.dll /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Xml.Linq.dll" /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\UIAutomationProvider.dll" /reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.0\WindowsBase.dll" /debug:pdbonly /filealign:512 /optimize+ /out:..\bin\c#\Joystick_2008_To_WPF.exe /resource:..\src\joystick_information_detection_test\obj\x86\Release\Joystick_2008_To_WPF.g.resources /resource:..\src\joystick_information_detection_test\obj\x86\Release\Joystick_2008_To_WPF.Properties.Resources.resources /target:winexe ..\src\joystick_information_detection_test\App.xaml.cs ..\src\joystick_information_detection_test\BaseInformation.xaml.cs ..\src\joystick_information_detection_test\HardwareDevice.cs ..\src\joystick_information_detection_test\BaseStructs\Product.cs ..\src\joystick_information_detection_test\BaseStructs\Vendor.cs ..\src\joystick_information_detection_test\ColorsForButton.cs ..\src\joystick_information_detection_test\Controls\JoyEclipce.cs ..\src\joystick_information_detection_test\Controls\JoyRectangle.cs ..\src\joystick_information_detection_test\JoystickTesting.xaml.cs ..\src\joystick_information_detection_test\PInvoke\FindAllJoys.cs ..\src\joystick_information_detection_test\PInvoke\Hid.cs ..\src\joystick_information_detection_test\PInvoke\Kernel32.cs ..\src\joystick_information_detection_test\PInvoke\Setupapi.cs ..\src\joystick_information_detection_test\PInvoke\Winmm.cs ..\src\joystick_information_detection_test\Properties\AssemblyInfo.cs ..\src\joystick_information_detection_test\Properties\Resources.Designer.cs ..\src\joystick_information_detection_test\Properties\Settings.Designer.cs ..\src\joystick_information_detection_test\WorkWithDataBase\GetDatasFromXmlFile.cs ..\src\joystick_information_detection_test\WorkWithDataBase\UpdateDataBase.cs "..\src\joystick_information_detection_test\obj\x86\Release\BaseInformation.g.cs" "..\src\joystick_information_detection_test\obj\x86\Release\JoystickTesting.g.cs" "..\src\joystick_information_detection_test\obj\x86\Release\App.g.cs"
@echo Progress: Build Ended
@echo Progress: Delete temporary files
@del ..\bin\c#\*.pdb
@echo Progress: All operations finished
@pause
@echo on