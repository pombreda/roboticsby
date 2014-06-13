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

#include "RCSGRobotGraphicsItem.h"

RCSGRobotGraphicsItem::RCSGRobotGraphicsItem()
{
    setToolTip(QString("Click and drag Robot Object"));
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
	rectOfRobot = QRectF(0, 0, 25, 25);
	QSvgRenderer renderer(QString(":/icons/flatrobot.svg"));
	imageOfRobot = QImage(rectOfRobot.width(), rectOfRobot.height(), QImage::Format_ARGB32);
	imageOfRobot.fill(0x00000000);
	QPainter painter(&imageOfRobot);
	renderer.render(&painter);
}

QRectF RCSGRobotGraphicsItem::boundingRect() const
{
	return rectOfRobot;
}

void RCSGRobotGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
	painter->drawImage(rectOfRobot, imageOfRobot, rectOfRobot);
}

void RCSGRobotGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ClosedHandCursor);
}

void RCSGRobotGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);
	mime->setImageData(imageOfRobot);
	drag->setPixmap(QPixmap::fromImage(imageOfRobot));
    drag->setHotSpot(QPoint(0, 0));
    drag->exec();
    setCursor(Qt::OpenHandCursor);
}

void RCSGRobotGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}
