/*
Copyright (C) 2013-2014, Sergey Gerasuto <contacts@robotics.by>

http://www.robotics.by/

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
- Neither the name of the RCSG Developers nor the names of its
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
`AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <windows.h>
#include <windowsx.h>
#include <mfapi.h>
#include <QIcon>
#include <QPixmap>
#include <QSvgRenderer>
#include <QPainter>

#include <ks.h>
#include <comdef.h>

#include "RCSGCameraDeviceThread.h"
#include "preview.h"

extern HICON qt_pixmapToWinHICON(const QPixmap &p);

CPreview* g_pPreview = NULL;
HDEVNOTIFY  g_hdevnotify = NULL;

template <class T> void safeRelease(T **ppT)
{
	if (ppT != NULL)
	{
		if (*ppT)
		{
			(*ppT)->Release();
			*ppT = NULL;
		}
	}
}

void ShowErrorMessage(LPCTSTR caption, HRESULT hr)
{
	_com_error error(hr);
	LPCTSTR errorText = error.ErrorMessage();
	MessageBox(NULL, errorText, caption, MB_ICONERROR);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_APP_PREVIEW_ERROR:
		{
			ShowErrorMessage(L"Error",(HRESULT)wParam);
		}
		break;

	case WM_DEVICECHANGE:
		{
			if (g_pPreview != NULL || (PDEV_BROADCAST_HDR)lParam != NULL)
			{
				HRESULT hr = S_OK;
				BOOL bDeviceLost = FALSE;

				hr = g_pPreview->CheckDeviceLost((PDEV_BROADCAST_HDR)lParam, &bDeviceLost);

				if (FAILED(hr) || bDeviceLost)
				{
					g_pPreview->CloseDevice();
					ShowErrorMessage(L"Lost the capture device.", hr);
					PostQuitMessage(0);
				}
			}
		}
		break;

	case WM_ERASEBKGND:
		return 1;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

VOID WINAPI ThreadProcedureCameraDevice(CameraDeviceThreadContext* context)
{
	if (context != NULL)
	{
		emit context->cameraDeviceThread->onCameraDeviceThreadInformation(QString(QObject::tr("Preview Thread for Web camera started.\n")));
		HWND hwnd = NULL;
		HRESULT hr = S_OK;
		IMFMediaType* cameraDeviceMediaTypeVideo = NULL;
		IMFMediaType* cameraDeviceMediaTypeAudio = NULL;
		cameraDeviceMediaTypeVideo = context->device->cameraDeviceVideoMediaTypes()->at(context->mediaType);
		if (context->device->cameraDeviceAudioMediaTypes()->size()>0)
		{
			cameraDeviceMediaTypeAudio = context->device->cameraDeviceAudioMediaTypes()->at(0);
		}

		hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

		if (SUCCEEDED(hr))
		{
			hr = MFStartup(MF_VERSION);
			if (SUCCEEDED(hr))
			{
				QString className = QString("SLOT%1 Class Name").arg(context->device->cameraVideoDeviceSlot());
				QString windowName = QString("Slot %1 - ").arg(context->device->cameraVideoDeviceSlot());
				QString fileCaptureName = QString("(%1) %2 [%3x%4].mp4").arg(QString::number(context->device->cameraVideoDeviceSlot()),context->device->cameraDeviceDescription(),QString::number(context->frameWidth),QString::number(context->frameHeight));
				fileCaptureName.replace(QString("\\"), QString(" "));
				fileCaptureName.replace(QString("/"), QString(" "));

				windowName.append(context->device->cameraDeviceDescription());
				std::wstring classNameWchar = className.toStdWString();
				std::wstring windowNameWchar = windowName.toStdWString();
				std::wstring fileCaptureNameWchar = fileCaptureName.toStdWString();

				WNDCLASS wc = {0};

				wc.lpfnWndProc   = WindowProc;
				wc.hInstance     = GetModuleHandle(NULL);
				wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
				wc.hIcon         = qt_pixmapToWinHICON(context->icon.pixmap(32,32));
				wc.lpszClassName = classNameWchar.c_str();

				ATOM atom = RegisterClass(&wc);
				if (atom)
				{
					if (SUCCEEDED(hr))
					{
						windowName.append(QString(" %1x%2").arg(QString::number(context->frameWidth),QString::number(context->frameHeight)));
						{
							std::wstring windowNameWchar = windowName.toStdWString();
							hwnd = CreateWindow(
								classNameWchar.c_str(),
								windowNameWchar.c_str(),
								WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX,
								0,
								0,
								context->frameWidth, 
								context->frameHeight, 
								NULL,
								NULL,
								GetModuleHandle(NULL),
								NULL
								);
						}

						if (hwnd)
						{
							CPreview *g_pPreview = new CPreview(hwnd, hwnd);

							DEV_BROADCAST_DEVICEINTERFACE di = { 0 };
							di.dbcc_size = sizeof(di);
							di.dbcc_devicetype  = DBT_DEVTYP_DEVICEINTERFACE;
							di.dbcc_classguid  = KSCATEGORY_CAPTURE; 

							g_hdevnotify = RegisterDeviceNotification(
								hwnd,
								&di,
								DEVICE_NOTIFY_WINDOW_HANDLE
								);

							if (g_hdevnotify)
							{
								struct ChooseDeviceParam
								{
									IMFActivate **ppDevices;    
									UINT32      count;          
								};

								ChooseDeviceParam videoCaptureDevices = { 0 };
								ChooseDeviceParam audioCaptureDevices = { 0 };

								IMFAttributes *pVideoAttributes = NULL;
								IMFAttributes *pAudioAttributes = NULL;

								if (context->saveAudio == FALSE && context->saveVideo == FALSE)
								{
									hr = MFCreateAttributes(&pVideoAttributes, 1);
									if (SUCCEEDED(hr))
									{
										hr = pVideoAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
										if (SUCCEEDED(hr))
										{
											hr = MFEnumDeviceSources(pVideoAttributes, &videoCaptureDevices.ppDevices, &videoCaptureDevices.count);
											safeRelease(&pVideoAttributes);
											if (SUCCEEDED(hr))
											{ 
												if (videoCaptureDevices.count > 0 )
												{
													{
														QString captureStatus = windowName;
														captureStatus.append(" - preview video stream");
														std::wstring captureStatusWchar = captureStatus.toStdWString();
														SetWindowText(hwnd,captureStatusWchar.c_str());
													}
													hr = g_pPreview->SetDevicePreview(videoCaptureDevices.ppDevices[context->device->cameraVideoDeviceSlot()], cameraDeviceMediaTypeVideo, context->mediaType);
												}
											}
										}
									}
								} else if (context->saveAudio == FALSE && context->saveVideo == TRUE)
								{
									hr = MFCreateAttributes(&pVideoAttributes, 1);
									if (SUCCEEDED(hr))
									{
										hr = pVideoAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
										if (SUCCEEDED(hr))
										{
											hr = MFEnumDeviceSources(pVideoAttributes, &videoCaptureDevices.ppDevices, &videoCaptureDevices.count);
											safeRelease(&pVideoAttributes);
											if (SUCCEEDED(hr))
											{ 
												if (videoCaptureDevices.count > 0 )
												{
													{
														QString captureStatus = windowName;
														captureStatus.append(" - saving video to disk");
														std::wstring captureStatusWchar = captureStatus.toStdWString();
														SetWindowText(hwnd,captureStatusWchar.c_str());
													}
													hr = g_pPreview->SetDevicePreviewAndSaveVideo(videoCaptureDevices.ppDevices[context->device->cameraVideoDeviceSlot()], cameraDeviceMediaTypeVideo, context->mediaType,fileCaptureNameWchar.c_str());													
												}
											}
										}
									}
								} else if (context->saveAudio == TRUE && context->saveVideo == TRUE)
								{
									hr = MFCreateAttributes(&pVideoAttributes, 1);
									if (SUCCEEDED(hr))
									{
										hr = pVideoAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
										if (SUCCEEDED(hr))
										{
											hr = MFEnumDeviceSources(pVideoAttributes, &videoCaptureDevices.ppDevices, &videoCaptureDevices.count);
											safeRelease(&pVideoAttributes);
											if (SUCCEEDED(hr))
											{
												if (cameraDeviceMediaTypeAudio!=NULL)
												{
													hr = MFCreateAttributes(&pAudioAttributes, 1);
													if (SUCCEEDED(hr))
													{
														hr = pAudioAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_GUID);
														if (SUCCEEDED(hr))
														{
															hr = MFEnumDeviceSources(pAudioAttributes, &audioCaptureDevices.ppDevices, &audioCaptureDevices.count);
															safeRelease(&pAudioAttributes);
															if (SUCCEEDED(hr))
															{ 
																if (videoCaptureDevices.count > 0 && audioCaptureDevices.count > 0)
																{
																	{
																		QString captureStatus = windowName;
																		captureStatus.append(" - saving video and audio to disk");
																		std::wstring captureStatusWchar = captureStatus.toStdWString();
																		SetWindowText(hwnd,captureStatusWchar.c_str());
																	}
																	hr = g_pPreview->SetDevice(videoCaptureDevices.ppDevices[context->device->cameraVideoDeviceSlot()], audioCaptureDevices.ppDevices[context->device->cameraVideoDeviceSlot()], cameraDeviceMediaTypeVideo, cameraDeviceMediaTypeAudio, context->mediaType,fileCaptureNameWchar.c_str());
																}
															}
														}
													}
												}
											}
										}
									}
								}

								for (DWORD i = 0; i < videoCaptureDevices.count; i++)
								{
									safeRelease(&videoCaptureDevices.ppDevices[i]);
								}
								CoTaskMemFree(videoCaptureDevices.ppDevices);

								for (DWORD i = 0; i < audioCaptureDevices.count; i++)
								{
									safeRelease(&audioCaptureDevices.ppDevices[i]);
								}
								CoTaskMemFree(audioCaptureDevices.ppDevices);

								if (FAILED(hr))
								{
									ShowErrorMessage(L"Error. Cannot create a video capture device.", hr);
								}
							}

							if (SUCCEEDED(hr))
							{
								ShowWindow(hwnd, SW_SHOWDEFAULT);
								UpdateWindow(hwnd);

								MSG msg = {0};

								while (GetMessage(&msg, NULL, 0, 0))
								{
									TranslateMessage(&msg);
									DispatchMessage(&msg);
								}
							}

							if (g_hdevnotify)
							{
								UnregisterDeviceNotification(g_hdevnotify);
							}

							if (g_pPreview!=NULL)
							{
								g_pPreview->CloseDevice();
								safeRelease(&g_pPreview);
							}
							DestroyWindow(hwnd);
						}
					}
				}
				UnregisterClass(wc.lpszClassName,wc.hInstance);
				MFShutdown();
			}
			CoUninitialize();
		}
	}
}

RCSGCameraDeviceThread::RCSGCameraDeviceThread(RCSGCameraDevice *device, UINT mediaType, BOOL saveVideo, BOOL saveAudio)
{
	cameraDevice = device;
	cameraMediaType = mediaType;
	globalCameraDeviceThreadHandle = NULL;
	threadContext = new CameraDeviceThreadContext;
	threadContext->cameraDeviceThread = this;
	threadContext->icon = createIconFromSVG(QString(":/icons/camera.svg"));
	threadContext->device = device;
	threadContext->mediaType = mediaType;
	threadContext->saveAudio = saveAudio;
	threadContext->saveVideo = saveVideo;
	HRESULT hr = MFGetAttributeSize(device->cameraDeviceVideoMediaTypes()->at(mediaType), MF_MT_FRAME_SIZE, &threadContext->frameWidth, &threadContext->frameHeight);
	if (FAILED(hr))
	{
		threadContext->frameWidth=0;
		threadContext->frameHeight=0;
	}
}

RCSGCameraDeviceThread::~RCSGCameraDeviceThread()
{
	if (INVALID_HANDLE_VALUE != globalCameraDeviceThreadHandle)
	{
		CloseHandle(globalCameraDeviceThreadHandle);
	}	
	if (threadContext!=NULL)
	{
		delete threadContext;
		threadContext = NULL;
	}
}

QIcon RCSGCameraDeviceThread::createIconFromSVG( const QString &filename )
{
	QSvgRenderer renderer(filename);
	QImage image(32, 32, QImage::Format_ARGB32);
	image.fill(0x00000000);
	QPainter painter(&image);
	renderer.render(&painter);
	return QIcon(QPixmap::fromImage(image));
}

void RCSGCameraDeviceThread::startCameraDeviceThread()
{	
	globalCameraDeviceThreadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcedureCameraDevice, threadContext, 0, &globalCameraDeviceThreadId);
	if (INVALID_HANDLE_VALUE == globalCameraDeviceThreadHandle)
	{
		CloseHandle(globalCameraDeviceThreadHandle);
		emit threadContext->cameraDeviceThread->onCameraDeviceThreadError(QString(tr("\nCreate Thread for Web camera preview issue.\n")));
	}
}
