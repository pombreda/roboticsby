#include "RCSGWindowsEventFilter.h"

bool RCSGWindowsEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, long *result) 
{
	Q_UNUSED( result );
	Q_UNUSED( eventType );

	MSG* msg = reinterpret_cast<MSG*>(message);

	if(msg->message == WM_DEVICECHANGE)
	{
		switch(msg->wParam)
		{
		case DBT_DEVICEARRIVAL:
			mainWindow->deviceConnected();
			break;

		case DBT_DEVICEREMOVECOMPLETE:		
			mainWindow->deviceDisconnected();
			break;
		}
	}
	return false;
};
