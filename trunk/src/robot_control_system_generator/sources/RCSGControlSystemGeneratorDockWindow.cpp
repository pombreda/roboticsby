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

#include "RCSGControlSystemGeneratorDockWindow.h"
#include "RCSGAvailableUsersGraphicsItem.h"
#include "RCSGAvailableJoysticksGraphicsItem.h"
#include "RCSGAvailableRobotsGraphicsItem.h"
#include "RCSGAvailableRemoteCommunicationsGraphicsItem.h"
#include "RCSGCameraGraphicsItem.h"
#include "RCSGJoystickGraphicsItem.h"
#include "RCSGLinkGraphicsItem.h"
#include "RCSGNetworkGraphicsItem.h"
#include "RCSGProgramGraphicsItem.h"
#include "RCSGRobotGraphicsItem.h"
#include "RCSGUserGraphicsItem.h"
#include "RCSGRobotGraphicsItem.h"

RCSGControlSystemGeneratorDockWindow::RCSGControlSystemGeneratorDockWindow(QWidget *parent):
	QGraphicsView(parent),scene(NULL)
{
	setRenderHint(QPainter::Antialiasing);
	setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	setBackgroundBrush(QColor(255, 255, 255));

	scene = new QGraphicsScene();

	int j = 25;

	RCSGAvailableRemoteCommunicationsGraphicsItem *item12 = new RCSGAvailableRemoteCommunicationsGraphicsItem;
	item12->setPos(j, 0.0);
	scene->addItem(item12);
	item12->update();
	j+=item12->boundingRect().width();

	RCSGAvailableRobotsGraphicsItem *item11 = new RCSGAvailableRobotsGraphicsItem;
	item11->setPos(j, 0.0);
	scene->addItem(item11);
	j+=item11->boundingRect().width();

	RCSGAvailableJoysticksGraphicsItem *item10 = new RCSGAvailableJoysticksGraphicsItem;
	item10->setPos(j, 0.0);
	scene->addItem(item10);
	j+=item10->boundingRect().width();

	RCSGAvailableUsersGraphicsItem *item9 = new RCSGAvailableUsersGraphicsItem;
	item9->setPos(j, 0.0);
	scene->addItem(item9);
	j+=item9->boundingRect().width();

	/*
	j = 25;

	RCSGCameraGraphicsItem *item8 = new RCSGCameraGraphicsItem;
	item8->setPos(j, 0.0);
	scene->addItem(item8);
	j+=40;

	RCSGJoystickGraphicsItem *item7 = new RCSGJoystickGraphicsItem;
	item7->setPos(j, 0.0);
	scene->addItem(item7);
	j+=40;

	RCSGLinkGraphicsItem *item6 = new RCSGLinkGraphicsItem;
	item6->setPos(j, 0.0);
	scene->addItem(item6);
	j+=40;

	RCSGNetworkGraphicsItem *item5 = new RCSGNetworkGraphicsItem;
	item5->setPos(j, 0.0);
	scene->addItem(item5);
	j+=40;

	RCSGProgramGraphicsItem *item4 = new RCSGProgramGraphicsItem;
	item4->setPos(j, 0.0);
	scene->addItem(item4);
	j+=40;

	RCSGRobotGraphicsItem *item3 = new RCSGRobotGraphicsItem;
	item3->setPos(j, 0.0);
	scene->addItem(item3);
	j+=40;

	RCSGUserGraphicsItem *item2 = new RCSGUserGraphicsItem;
	item2->setPos(j, 0.0);
	scene->addItem(item2);
	j+=40;
	*/
	setScene(scene);
}

RCSGControlSystemGeneratorDockWindow::~RCSGControlSystemGeneratorDockWindow()
{
	if (scene != NULL)
	{
		delete scene;
		scene = NULL;
	}
}

void RCSGControlSystemGeneratorDockWindow::resizeEvent( QResizeEvent *event )
{
	QGraphicsView::resizeEvent(event);
	scene->setSceneRect(0.0, 0.0, parentWidget()->width(), parentWidget()->height());
}
