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

#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <QUUID>

#include "RCSGRobotsManager.h"
#include "RCSGHockeyRobot.h"

QVector<QUuid> globalRobotsHolder;

RCSGRobotsManager::RCSGRobotsManager( RCSGMainWindow *mainWindow ):
	mainWindow(mainWindow),robots(NULL)
{
	robots = new QHash<QUuid,QObject*>;
}

RCSGRobotsManager::~RCSGRobotsManager()
{
	if (robots != NULL)
	{
		qDeleteAll(robots->begin(),robots->end());
		robots->clear();
		delete robots;
		robots = NULL;
	}
}

void enumeratingRobots()
{
	globalRobotsHolder.clear();
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000001"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000002"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000003"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000004"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000005"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000006"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000007"));
	globalRobotsHolder.append(QUuid("00000000-0000-0000-0000-000000000008"));
}

void RCSGRobotsManager::populateRobots()
{
	cancelPopulatingRobots();
	QObject::connect(&populatingRobotsWatcher, SIGNAL(finished()), this, SLOT(finishedPopulatingRobots()));
	populatingRobotsWatcher.setFuture(QtConcurrent::run(enumeratingRobots));
}

void RCSGRobotsManager::cancelPopulatingRobots()
{
	populatingRobotsWatcher.cancel();
	populatingRobotsWatcher.waitForFinished();
}

void RCSGRobotsManager::finishedPopulatingRobots()
{
	if (robots != NULL)
	{
		qDeleteAll(robots->begin(),robots->end());
		robots->clear();
	}

	{
		QVector<QUuid>::iterator iterator;
		for (iterator = globalRobotsHolder.begin(); iterator != globalRobotsHolder.end(); ++iterator)
		{
			RCSGHockeyRobot *robot = new RCSGHockeyRobot(*iterator);
			robots->insert((*iterator),robot);
		}
	}

	QHash<QString,QObject*>::iterator iterator;
	QString message(QString("Robots in database: %1\n").arg(robots->size()));
	mainWindow->showApplicationConsoleMessage(message);
	emit onRobotsManagerNewRobots();
}

QHash<QUuid,QObject*>* RCSGRobotsManager::getRobots() const
{
	return robots;
}