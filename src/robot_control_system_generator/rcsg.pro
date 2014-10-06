TARGET     = RCSG

TEMPLATE   = app

HEADERS    = sources\Version.h\
             sources\RCSGMediaFoundationVideoBufferLock.h\
             sources\device.h\
             sources\preview.h\
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
	     sources\RCSGCameraDeviceThread.h\
	     sources\RCSGCameraInfoDockWindow.h\
             sources\RCSGCameraPreviewDockWindow.h\
             sources\RCSGCameraDevicesManager.h\
             sources\RCSGAvailableUsersGraphicsItem.h\
             sources\RCSGAvailableRobotsGraphicsItem.h\
             sources\RCSGAvailableJoysticksGraphicsItem.h\
             sources\RCSGAvailableRemoteCommunicationsGraphicsItem.h\
             sources\RCSGWindowsEventFilter.h\
	     sources\thirdparty\libyuv\libyuv.h\
	     sources\thirdparty\libyuv\libyuv_basic_types.h\
	     sources\thirdparty\libyuv\libyuv_compare.h\
	     sources\thirdparty\libyuv\libyuv_convert.h\
	     sources\thirdparty\libyuv\libyuv_convert_argb.h\
	     sources\thirdparty\libyuv\libyuv_convert_from.h\
	     sources\thirdparty\libyuv\libyuv_convert_from_argb.h\
	     sources\thirdparty\libyuv\libyuv_cpu_id.h\
	     sources\thirdparty\libyuv\libyuv_format_conversion.h\
	     sources\thirdparty\libyuv\libyuv_mjpeg_decoder.h\
	     sources\thirdparty\libyuv\libyuv_planar_functions.h\
	     sources\thirdparty\libyuv\libyuv_rotate.h\
	     sources\thirdparty\libyuv\libyuv_rotate_argb.h\
	     sources\thirdparty\libyuv\libyuv_row.h\
	     sources\thirdparty\libyuv\libyuv_scale.h\
	     sources\thirdparty\libyuv\libyuv_scale_argb.h\
	     sources\thirdparty\libyuv\libyuv_scale_row.h\
	     sources\thirdparty\libyuv\libyuv_version.h\
	     sources\thirdparty\libyuv\libyuv_video_common.h\
	     sources\thirdparty\libjpeg\jerror.h\
	     sources\thirdparty\libjpeg\jmorecfg.h\
	     sources\thirdparty\libjpeg\jconfig.h\
	     sources\thirdparty\libjpeg\jpeglib.h\
	     sources\thirdparty\libjpeg\jinclude.h\
	     sources\thirdparty\libjpeg\jpegint.h
		
SOURCES    = sources\main.cpp\
             sources\device.cpp\
             sources\preview.cpp\
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
	     sources\RCSGCameraDeviceThread.cpp\
             sources\RCSGCameraPreviewDockWindow.cpp\
             sources\RCSGCameraInfoDockWindow.cpp\
             sources\RCSGCameraDevicesManager.cpp\
             sources\RCSGAvailableUsersGraphicsItem.cpp\
             sources\RCSGAvailableRobotsGraphicsItem.cpp\
             sources\RCSGAvailableJoysticksGraphicsItem.cpp\
             sources\RCSGAvailableRemoteCommunicationsGraphicsItem.cpp\
             sources\RCSGWindowsEventFilter.cpp\
             sources\thirdparty\libyuv\libyuv_compare.cpp\
             sources\thirdparty\libyuv\libyuv_compare_common.cpp\
             sources\thirdparty\libyuv\libyuv_compare_win.cpp\
             sources\thirdparty\libyuv\libyuv_convert.cpp\
             sources\thirdparty\libyuv\libyuv_convert_argb.cpp\
             sources\thirdparty\libyuv\libyuv_convert_from.cpp\
             sources\thirdparty\libyuv\libyuv_convert_from_argb.cpp\
             sources\thirdparty\libyuv\libyuv_convert_jpeg.cpp\
             sources\thirdparty\libyuv\libyuv_convert_to_argb.cpp\
             sources\thirdparty\libyuv\libyuv_convert_to_i420.cpp\
             sources\thirdparty\libyuv\libyuv_cpu_id.cpp\
             sources\thirdparty\libyuv\libyuv_format_conversion.cpp\
             sources\thirdparty\libyuv\libyuv_mjpeg_decoder.cpp\
             sources\thirdparty\libyuv\libyuv_mjpeg_validate.cpp\
             sources\thirdparty\libyuv\libyuv_planar_functions.cpp\
             sources\thirdparty\libyuv\libyuv_rotate.cpp\
             sources\thirdparty\libyuv\libyuv_rotate_argb.cpp\
             sources\thirdparty\libyuv\libyuv_row_any.cpp\
             sources\thirdparty\libyuv\libyuv_row_common.cpp\
             sources\thirdparty\libyuv\libyuv_row_win.cpp\
             sources\thirdparty\libyuv\libyuv_scale.cpp\
             sources\thirdparty\libyuv\libyuv_scale_argb.cpp\
             sources\thirdparty\libyuv\libyuv_scale_common.cpp\
             sources\thirdparty\libyuv\libyuv_scale_win.cpp\
             sources\thirdparty\libyuv\libyuv_video_common.cpp
	     
FORMS	   =   

QT        += core gui widgets svg concurrent

RESOURCES  = rcsg.qrc

win32 {
   RC_FILE = rcsg.rc
   LIBS += -lsetupapi -ladvapi32 -lhid -lOle32 -lMfplat -lMf -lmfuuid -lmfreadwrite -ld3d9 -lStrmbase -lEvr
}