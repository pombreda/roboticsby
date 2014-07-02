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
             sources\RCSGJoystickTestDockWindow.h\
             sources\RCSGCommunicationProtocol.h\
             sources\RCSGCommunicationConsoleDockWindow.h\
             sources\RCSGRobotsInfoDockWindow.h\
             sources\RCSGControlSystemGeneratorDockWindow.h\
             sources\RCSGUserGraphicsItem.h\
             sources\RCSGRemoteCommunicationGraphicsItem.h\
             sources\RCSGRobotGraphicsItem.h\
             sources\RCSGProgramGraphicsItem.h\
             sources\RCSGNetworkGraphicsItem.h\
             sources\RCSGLinkGraphicsItem.h\
             sources\RCSGJoystickGraphicsItem.h\
             sources\RCSGCameraGraphicsItem.h\
             sources\RCSGCameraDevice.h\
             sources\RCSGCameraInfoDockWindow.h\
             sources\RCSGCameraPreviewDockWindow.h\
             sources\RCSGCameraDevicesManager.h\
             sources\RCSGAvailableUsersGraphicsItem.h\
             sources\RCSGAvailableRobotsGraphicsItem.h\
             sources\RCSGAvailableJoysticksGraphicsItem.h\
             sources\RCSGAvailableRemoteCommunicationsGraphicsItem.h\	
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
             sources\RCSGJoystickTestDockWindow.cpp\
             sources\RCSGJoysticksInfoDockWindow.cpp\
             sources\RCSGCommunicationProtocol.cpp\
             sources\RCSGCommunicationConsoleDockWindow.cpp\
             sources\RCSGRobotsInfoDockWindow.cpp\
             sources\RCSGControlSystemGeneratorDockWindow.cpp\
             sources\RCSGUserGraphicsItem.cpp\
             sources\RCSGRemoteCommunicationGraphicsItem.cpp\
             sources\RCSGRobotGraphicsItem.cpp\
             sources\RCSGProgramGraphicsItem.cpp\
             sources\RCSGNetworkGraphicsItem.cpp\
             sources\RCSGLinkGraphicsItem.cpp\
             sources\RCSGJoystickGraphicsItem.cpp\
             sources\RCSGCameraGraphicsItem.cpp\
             sources\RCSGCameraDevice.cpp\
             sources\RCSGCameraPreviewDockWindow.cpp\
             sources\RCSGCameraInfoDockWindow.cpp\
             sources\RCSGCameraDevicesManager.cpp\
             sources\RCSGAvailableUsersGraphicsItem.cpp\
             sources\RCSGAvailableRobotsGraphicsItem.cpp\
             sources\RCSGAvailableJoysticksGraphicsItem.cpp\
             sources\RCSGAvailableRemoteCommunicationsGraphicsItem.cpp\				
             sources\RCSGWindowsEventFilter.cpp
	     
FORMS	   =   

QT        += core gui widgets svg concurrent

RESOURCES  = rcsg.qrc

win32 {
   RC_FILE = rcsg.rc
   LIBS += -lsetupapi -ladvapi32 -lhid -lOle32 -lMfplat -lMf -lmfuuid -lStrmbase
}