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

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHash>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>

#include <windows.h>

#include "RCSGCameraDevice.h"
#include "RCSGCameraPreviewDockWindow.h"
#include "RCSGCameraDeviceThread.h"

void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
	while (QLayoutItem* item = layout->takeAt(0))
	{
		QWidget* widget;
		if ((deleteWidgets)	&& (widget = item->widget())) {
				delete widget;
		}
		if (QLayout* childLayout = item->layout()) {
			clearLayout(childLayout, deleteWidgets);
		}
		delete item;
	}
}

RCSGCameraPreviewDockWindow::RCSGCameraPreviewDockWindow(QWidget *parent)
	:QWidget(parent)
{
	cameraDevices = NULL;
	cameraThreads = new QHash<QString,RCSGCameraDeviceThread*>;

	mainCameraPreviewListLayout = new QVBoxLayout;
	mainCameraPreviewThreadsStatusLayout = new QVBoxLayout;

	cameraPreviewGroupBox = new QGroupBox;
	cameraPreviewGroupBox->setTitle(tr("Available cameras"));
	cameraPreviewGroupBox->setLayout(mainCameraPreviewListLayout);

	cameraPreviewThreadsStatusGroupBox = new QGroupBox;
	cameraPreviewThreadsStatusGroupBox->setTitle(tr("Preview threads management"));
	cameraPreviewThreadsStatusGroupBox->setLayout(mainCameraPreviewThreadsStatusLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(cameraPreviewGroupBox);
	mainLayout->addWidget(cameraPreviewThreadsStatusGroupBox);
	
	setLayout(mainLayout);
}


RCSGCameraPreviewDockWindow::~RCSGCameraPreviewDockWindow()
{
	clearCameraThreads();
}


void RCSGCameraPreviewDockWindow::clearCameraThreads()
{
	if (cameraThreads!=NULL)
	{
		if (cameraThreads->size()>0)
		{
			qDeleteAll(cameraThreads->begin(),cameraThreads->end());
			cameraThreads->clear();
		} 
		
		delete cameraThreads;
		cameraThreads = NULL;
	}
}

void RCSGCameraPreviewDockWindow::updateCameraPreviewList(QHash<QString,QObject*>* devices)
{
	clearLayout(mainCameraPreviewListLayout);
	cameraDevices = devices;

	QHash<QString,QObject*>::iterator iterator;
	for (iterator = cameraDevices->begin(); iterator != cameraDevices->end(); ++iterator)
	{
		RCSGCameraDevice *device = qobject_cast<RCSGCameraDevice*>(iterator.value());
		if (device!=NULL)
		{
			QHBoxLayout *cameraDeviceItemLayout = new QHBoxLayout;
			cameraDeviceItemLayout->setObjectName(QString::number(device->cameraVideoDeviceSlot()));

			QLabel *cameraDeviceProductName = new QLabel;
			cameraDeviceProductName->setObjectName(QString::number(device->cameraVideoDeviceSlot()));
			cameraDeviceProductName->setText(QString("[%1] %2").arg(QString::number(device->cameraVideoDeviceSlot()),device->cameraDeviceDescription()));
			cameraDeviceItemLayout->addWidget(cameraDeviceProductName);
			QVector<IMFMediaType*>* mediaTypes = device->cameraDeviceVideoMediaTypes();
			QComboBox *cameraDeviceMediaTypes = new QComboBox;
			cameraDeviceMediaTypes->setObjectName(QString::number(device->cameraVideoDeviceSlot()));

			if (mediaTypes!=NULL)
			{
				QVector<QHash<QString,QString>> capacites = device->cameraDeviceVideoCapacites();		
				QVector<QHash<QString,QString>>::Iterator iterator; 
				for (iterator = capacites.begin(); iterator != capacites.end(); ++iterator)
				{
					QHash<QString,QString> hashTable = (*iterator);
					QHash<QString,QString>::iterator iteratorHash;
					cameraDeviceMediaTypes->addItem(QString("%1, %2 (%3)").arg(hashTable[QString("MF_MT_FRAME_SIZE")],hashTable[QString("MF_MT_FRAME_RATE")],hashTable[QString("MF_MT_SUBTYPE")]));
				}
			}

			cameraDeviceItemLayout->addWidget(cameraDeviceMediaTypes);

			QCheckBox *saveVideo = new QCheckBox;
			saveVideo->setObjectName(QString("Save video [%1]").arg(QString::number(device->cameraVideoDeviceSlot())));
			saveVideo->setText(tr("Save video"));
			saveVideo->setToolTip(QString("Allow save video for [%1] %2").arg(QString::number(device->cameraVideoDeviceSlot()),device->cameraDeviceDescription()));

			QCheckBox *saveAudio = new QCheckBox;
			saveAudio->setObjectName(QString("Save audio [%1]").arg(QString::number(device->cameraVideoDeviceSlot())));
			saveAudio->setText(tr("Save audio"));
			saveAudio->setToolTip(QString("Allow save audio for [%1] %2").arg(QString::number(device->cameraVideoDeviceSlot()),device->cameraDeviceDescription()));

			QPushButton *cameraDevicePreview = new QPushButton;
			cameraDevicePreview->setObjectName(QString::number(device->cameraVideoDeviceSlot()));
			cameraDevicePreview->setText(tr("Preview"));
			cameraDevicePreview->setToolTip(QString("Starting preview for [%1] %2").arg(QString::number(device->cameraVideoDeviceSlot()),device->cameraDeviceDescription()));
			connect(cameraDevicePreview, SIGNAL(clicked()), this, SLOT(startPreviewThread()));

			cameraDeviceItemLayout->addWidget(saveVideo);
			cameraDeviceItemLayout->addWidget(saveAudio);
			cameraDeviceItemLayout->addWidget(cameraDevicePreview);
			mainCameraPreviewListLayout->addLayout(cameraDeviceItemLayout);
		}
	}
}

void RCSGCameraPreviewDockWindow::startPreviewThread()
{
	QPushButton* cameraDevicePreview = qobject_cast<QPushButton*>(sender());
	QComboBox* cameraDeviceMediaTypes = NULL;
	QCheckBox *saveVideo = NULL;
	QCheckBox *saveAudio = NULL;

	if( cameraDevicePreview != NULL ) 
	{ 
		QVBoxLayout *itemsLayout = qobject_cast<QVBoxLayout*>(cameraDevicePreview->parentWidget()->layout());
		QString objectName = cameraDevicePreview->objectName();
		if( itemsLayout != NULL ) 
		{ 
			for (int i = 0; i < itemsLayout->count(); i++)
			{
				QHBoxLayout* cameraDeviceItemLayout = qobject_cast<QHBoxLayout*>(itemsLayout->itemAt(i)->layout());
				if (cameraDeviceItemLayout!=NULL)
				{
					if (cameraDeviceItemLayout->objectName()==objectName)
					{
						
						cameraDeviceMediaTypes = NULL;
						for (int j = 0; j < cameraDeviceItemLayout->count(); j++)
						{
							cameraDeviceMediaTypes = qobject_cast<QComboBox*>(cameraDeviceItemLayout->itemAt(j)->widget());
							if (cameraDeviceMediaTypes!=NULL)
							{
								if (cameraDeviceMediaTypes->objectName()==objectName)
								{
									break;
								}
							}
						}

						saveVideo = NULL;
						for (int j = 0; j < cameraDeviceItemLayout->count(); j++)
						{
							saveVideo = qobject_cast<QCheckBox*>(cameraDeviceItemLayout->itemAt(j)->widget());
							if (saveVideo!=NULL)
							{
								if (saveVideo->objectName()==QString("Save video [%1]").arg(objectName))
								{
									break;
								}
							}
						}

						saveAudio = NULL;
						for (int j = 0; j < cameraDeviceItemLayout->count(); j++)
						{
							saveAudio = qobject_cast<QCheckBox*>(cameraDeviceItemLayout->itemAt(j)->widget());
							if (saveAudio!=NULL)
							{
								if (saveAudio->objectName()==QString("Save audio [%1]").arg(objectName))
								{
									break;
								}
							}
						}

						if (cameraDeviceMediaTypes!=NULL && saveVideo!=NULL && saveAudio!=NULL)
						{
							break;
						}
					}
				}
			}
		}
	}

	if (cameraDeviceMediaTypes!=NULL && saveVideo!=NULL && saveAudio!=NULL && cameraDevices!=NULL)
	{
		QString cameraSlot = QString("SLOT%1").arg(cameraDevicePreview->objectName());
		RCSGCameraDevice *device = qobject_cast<RCSGCameraDevice*>(cameraDevices->value(cameraSlot));
		if (device!=NULL && cameraThreads!=NULL)
		{
			RCSGCameraDeviceThread *thread = cameraThreads->take(cameraSlot);
			if (thread!=NULL)
			{
				delete thread;
				thread = NULL;
			}
			
			thread = new RCSGCameraDeviceThread(device, cameraDeviceMediaTypes->currentIndex(), saveVideo->isChecked(), saveAudio->isChecked());
			cameraThreads->insert(cameraSlot, thread);
			cameraThreads->value(cameraSlot)->startCameraDeviceThread();
		}
	}
}


