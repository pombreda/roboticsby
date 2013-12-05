TARGET     = RCSG

TEMPLATE   = app

HEADERS    = sources\Version.h\
             sources\RCSGMainWindow.h\
             sources\RCSGAboutDialog.h

SOURCES    = sources\main.cpp\
             sources\RCSGMainWindow.cpp\
             sources\RCSGAboutDialog.cpp
	     
FORMS	   =   

QT        += core gui widgets

RESOURCES  = rcsg.qrc

win32 {
   RC_FILE = rcsg.rc
}