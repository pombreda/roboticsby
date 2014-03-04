TARGET     = RCSG

TEMPLATE   = app

HEADERS    = sources\Version.h\
             sources\RCSGUsbIds.h\
             sources\RCSGMainWindow.h\
             sources\RCSGAboutDialog.h\
	     sources\RCSGCommunicationDevicesManager.h\
             sources\RCSGComPortDevice.h\              
             sources\RCSGInputDevicesManager.h\
             sources\RCSGJoystickDevice.h\
             sources\RCSGKeyboardDevice.h\
             sources\RCSGRobotsManager.h\		
             sources\RCSGHockeyRobot.h\
             sources\RCSGConsoleDockWindow.h\
             sources\RCSGComPortsInfoDockWindow.h\
             sources\RCSGJoysticksInfoDockWindow.h\	
             sources\RCSGWindowsEventFilter.h     

SOURCES    = sources\main.cpp\
             sources\RCSGUsbIds.cpp\		
             sources\RCSGMainWindow.cpp\
             sources\RCSGAboutDialog.cpp\
	     sources\RCSGCommunicationDevicesManager.cpp\
             sources\RCSGComPortDevice.cpp\
             sources\RCSGInputDevicesManager.cpp\
             sources\RCSGJoystickDevice.cpp\   	
             sources\RCSGKeyboardDevice.cpp\
	     sources\RCSGRobotsManager.cpp\
             sources\RCSGHockeyRobot.cpp\
             sources\RCSGConsoleDockWindow.cpp\
             sources\RCSGComPortsInfoDockWindow.cpp\
             sources\RCSGJoysticksInfoDockWindow.cpp\	
             sources\RCSGWindowsEventFilter.cpp
	     
FORMS	   =   

QT        += core gui widgets svg concurrent

RESOURCES  = rcsg.qrc

win32 {
   RC_FILE = rcsg.rc
   LIBS += -lsetupapi -ladvapi32 -lhid
}