TARGET     = RCSG

TEMPLATE   = app

HEADERS    = sources\version.h

SOURCES    = sources\main.cpp
	     
FORMS	   =   

QT        += core gui widgets network

RESOURCES  = rcsg.qrc

win32 {
   RC_FILE = rcsg.rc
}