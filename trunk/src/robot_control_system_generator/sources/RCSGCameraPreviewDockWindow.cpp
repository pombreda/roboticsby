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

#include <windows.h>

#include "RCSGCameraDevice.h"
#include "RCSGCameraPreviewDockWindow.h"

void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
	while (QLayoutItem* item = layout->takeAt(0))
	{
		QWidget* widget;
		if (  (deleteWidgets)
			&& (widget = item->widget())  ) {
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

void RCSGCameraPreviewDockWindow::updateCameraPreviewList(QHash<QString,QObject*>* cameraDevices)
{
	clearLayout(mainCameraPreviewListLayout);

	QHash<QString,QObject*>::iterator iterator;
	for (iterator = cameraDevices->begin(); iterator != cameraDevices->end(); ++iterator)
	{
		RCSGCameraDevice *device = qobject_cast<RCSGCameraDevice*>(iterator.value());
		if (device!=NULL)
		{
			QHBoxLayout *cameraDeviceItemLayout = new QHBoxLayout;
			cameraDeviceItemLayout->setObjectName(QString::number(device->cameraDeviceSlot()));

			QLabel *cameraDeviceProductName = new QLabel;
			cameraDeviceProductName->setObjectName(QString::number(device->cameraDeviceSlot()));
			cameraDeviceProductName->setText(QString("[%1] %2").arg(QString::number(device->cameraDeviceSlot()),device->cameraDeviceDescription()));
			cameraDeviceItemLayout->addWidget(cameraDeviceProductName);
			QVector<IMFMediaType*>* mediaTypes = device->cameraDeviceMediaTypes();
			QComboBox *cameraDeviceMediaTypes = new QComboBox;
			cameraDeviceMediaTypes->setObjectName(QString::number(device->cameraDeviceSlot()));

			if (mediaTypes!=NULL)
			{
				QVector<QHash<QString,QString>> capacites = device->cameraDeviceCapacites();		
				QVector<QHash<QString,QString>>::Iterator iterator; 
				for (iterator = capacites.begin(); iterator != capacites.end(); ++iterator)
				{
					QHash<QString,QString> hashTable = (*iterator);
					QHash<QString,QString>::iterator iteratorHash;
					cameraDeviceMediaTypes->addItem(QString("%1, %2").arg(hashTable[QString("MF_MT_FRAME_SIZE")],hashTable[QString("MF_MT_FRAME_RATE")]));
				}
			}

			cameraDeviceItemLayout->addWidget(cameraDeviceMediaTypes);

			QPushButton *cameraDevicePreview = new QPushButton;
			cameraDevicePreview->setObjectName(QString::number(device->cameraDeviceSlot()));
			cameraDevicePreview->setText(tr("Preview"));
			cameraDevicePreview->setToolTip(QString("Starting preview for [%1] %2").arg(QString::number(device->cameraDeviceSlot()),device->cameraDeviceDescription()));
			connect(cameraDevicePreview, SIGNAL(clicked()), this, SLOT(startPreviewThread()));

			cameraDeviceItemLayout->addWidget(cameraDevicePreview);

			mainCameraPreviewListLayout->addLayout(cameraDeviceItemLayout);
		}
	}
}

void RCSGCameraPreviewDockWindow::startPreviewThread()
{
	QPushButton* cameraDevicePreview = qobject_cast<QPushButton*>(sender());
	QComboBox* cameraDeviceMediaTypes = NULL;

	if( cameraDevicePreview != NULL ) 
	{ 
		QVBoxLayout *itemsLayout = qobject_cast<QVBoxLayout*>(cameraDevicePreview->parentWidget()->layout());
		QString objectName = cameraDevicePreview->objectName();
		if( itemsLayout != NULL ) 
		{ 
			for (int i = 0; i < itemsLayout->count(); ++i)
			{
				QHBoxLayout* cameraDeviceItemLayout = qobject_cast<QHBoxLayout*>(itemsLayout->itemAt(i)->layout());
				if (cameraDeviceItemLayout!=NULL)
				{
					if (cameraDeviceItemLayout->objectName()==objectName)
					{
						cameraDeviceMediaTypes = NULL;
						for (int j = 0; j < cameraDeviceItemLayout->count(); ++j)
						{
							cameraDeviceMediaTypes = qobject_cast<QComboBox*>(cameraDeviceItemLayout->itemAt(i)->widget());
							if (cameraDeviceMediaTypes!=NULL)
							{
								if (cameraDeviceMediaTypes->objectName()==objectName)
								{
									break;
								}
							}
						}
						if (cameraDeviceMediaTypes!=NULL)
						{
							break;
						}
					}
				}
			}
		}
	}

	if (cameraDeviceMediaTypes!=NULL)
	{
		UINT selectedMediaType = cameraDeviceMediaTypes->currentIndex();
		selectedMediaType=+1;
	}
}


