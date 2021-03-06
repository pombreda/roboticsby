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

#include <QtWidgets>
#include <QSvgRenderer>

#include "RCSGAvailableUsersGraphicsItem.h"

RCSGAvailableUsersGraphicsItem::RCSGAvailableUsersGraphicsItem(QGraphicsItem *parent)
  : QGraphicsObject(parent)
{
	setAcceptDrops(true);
	itemFont = QFont("Helvetica",10);
	QFontMetrics fontMetric(itemFont);
	itemLabel = "Available Users";
	itemBoundsRect = QRectF(0, 0, itemFont.pointSize()*2+fontMetric.width(itemLabel), itemFont.pointSize()*4.5+25);
}

QRectF RCSGAvailableUsersGraphicsItem::boundingRect() const
{
	return itemBoundsRect;
}

void RCSGAvailableUsersGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	painter->setBrush(Qt::lightGray);
	painter->setFont(itemFont);
	painter->drawRoundedRect(0, 0, itemBoundsRect.width(), itemBoundsRect.height(), 10, 10, Qt::AbsoluteSize);
	painter->drawText(QPoint(itemFont.pointSize(), 1.5*itemFont.pointSize()), itemLabel);
}

void RCSGAvailableUsersGraphicsItem::dragEnterEvent( QGraphicsSceneDragDropEvent *event )
{
	Q_UNUSED(event);
}

void RCSGAvailableUsersGraphicsItem::dragLeaveEvent( QGraphicsSceneDragDropEvent *event )
{
	Q_UNUSED(event);
}

void RCSGAvailableUsersGraphicsItem::dropEvent( QGraphicsSceneDragDropEvent *event )
{
	Q_UNUSED(event);
}
