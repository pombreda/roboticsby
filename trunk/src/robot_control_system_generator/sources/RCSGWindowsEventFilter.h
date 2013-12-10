#ifndef RCSGWINDOWSEVENTFILTER_H_
#define RCSGWINDOWSEVENTFILTER_H_

#include <QAbstractNativeEventFilter>
#include <windows.h>
#include <dbt.h>

#include "RCSGMainWindow.h"

class RCSGWindowsEventFilter : public QAbstractNativeEventFilter
{
public:
	RCSGWindowsEventFilter(RCSGMainWindow *mainWindow) : mainWindow(mainWindow) {}

protected:
	virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);

private:
    RCSGMainWindow *mainWindow;
};

#endif //RCSGWINDOWSEVENTFILTER_H_
