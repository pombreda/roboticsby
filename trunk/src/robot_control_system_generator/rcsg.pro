TARGET     = RCSG

TEMPLATE   = app

HEADERS    = sources\Version.h\
             sources\RCSGMainWindow.h\
             sources\RCSGAboutDialog.h\
	     sources\RCSGConsole.h\	
             sources\RCSGWindowsEventFilter.h     

SOURCES    = sources\main.cpp\
             sources\RCSGMainWindow.cpp\
             sources\RCSGAboutDialog.cpp\
             sources\RCSGConsole.cpp\	
             sources\RCSGWindowsEventFilter.cpp
	     
FORMS	   =   

QT        += core gui widgets svg

RESOURCES  = rcsg.qrc

win32 {
   RC_FILE = rcsg.rc
}