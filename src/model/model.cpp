/**
 * Project CodeClock
 */


#include <QSharedPointer>
#include <QQueue>
#include <QSharedPointer>
#include "model.h"
#include "abstracttracker.h"

Model::Model(QSharedPointer<AbstractTracker> _tracker, QObject* _parent)
    : mTracker(_tracker)
{
    setParent(_parent);
    connect(mTracker.data(), SIGNAL(dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess> >)),
            this, SIGNAL(dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess> >)));
}

Model::Model(QObject *_parent)
    : mTracker(QSharedPointer<AbstractTracker>(new Tracker()))
{
    setParent(_parent);
    connect(mTracker.data(), SIGNAL(dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess> >)),
            this, SIGNAL(dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess> >)));
}

QSharedPointer<AbstractTracker> Model::tracker() const
{
    return mTracker;
}

QSharedPointer<AbstractTrackableProcess> Model::currentProcess() const
{
    return mTracker->currentProcess();
}

QQueue<QSharedPointer<AbstractTrackableProcess>> Model::processes(const QDateTime& _start, const QDateTime& _end) const
{
    return mTracker->processes(_start, _end);
}

QQueue<QSharedPointer<AbstractTrackableProcess>> Model::processes(const QString& _name, const QDateTime& _start, const QDateTime& _end) const
{
    return mTracker->processes(_name, _start, _end);
}

QQueue<QSharedPointer<AbstractTrackableProcess>> Model::processes(const QString& _name) const
{
    return mTracker->processes(_name);
}

QQueue<QSharedPointer<AbstractTrackableProcess>> Model::processes() const
{
    return mTracker->processes();
}

void Model::startTracking(int _timerTimeoutMsec)
{
    mTracker->startTracking(_timerTimeoutMsec);
    emit startedTracking(_timerTimeoutMsec);
}

void Model::stopTracking()
{
    mTracker->stopTracking();
    emit stoppedTracking();
}

void Model::setTracker(QSharedPointer<AbstractTracker> _tracker)
{
    mTracker = _tracker;
    emit trackerChanged(mTracker);
}
