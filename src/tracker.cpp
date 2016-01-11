#include <QSharedPointer>
#include <QProcess>
#include <QDebug>
#include "tracker.h"
#include "trackableprocess.h"

Tracker::Tracker(bool _isStarted, int _msec, QObject *_parent)
    : mTimer(QSharedPointer<QTimer>(new QTimer()))
{
    setParent(_parent);
    if(_isStarted)
    {
        mTimer->start(_msec);
        connect(mTimer.data(), SIGNAL(timeout()), mTimer.data(), SLOT(start(_msec)));
        mState = tr("Tracking");
    }
    else
        mState = tr("Stopped");
    mTimeoutMsec = _msec;
    connect(mTimer.data(), SIGNAL(timeout()), this, SLOT(track()));
}

QSharedPointer<AbstractTrackableProcess> Tracker::currentProcess() const
{
    mProcesses.back();
}


QQueue<QSharedPointer<AbstractTrackableProcess> > Tracker::processes(const QDateTime &_start, const QDateTime &_end) const
{
    QQueue<QSharedPointer<AbstractTrackableProcess> > res;
    for(auto i = mProcesses.cbegin(); i != mProcesses.cend(); ++i)
        if((*i)->isInInterval(_start, _end))
            res.append((*i));
}

QQueue<QSharedPointer<AbstractTrackableProcess> > Tracker::processes(const QString &_name, const QDateTime &_start, const QDateTime &_end) const
{
    QQueue<QSharedPointer<AbstractTrackableProcess> > res;
    for(auto i = mProcesses.cbegin(); i != mProcesses.cend(); ++i)
        if((*i)->isInInterval(_start, _end) && (*i)->name() == _name)
            res.append((*i));
}

QQueue<QSharedPointer<AbstractTrackableProcess> > Tracker::processes(const QString &_name) const
{
    QQueue<QSharedPointer<AbstractTrackableProcess> > res;
    for(auto i = mProcesses.cbegin(); i != mProcesses.cend(); ++i)
        if((*i)->name() == _name)
            res.append((*i));
}

QQueue<QSharedPointer<AbstractTrackableProcess> > Tracker::processes() const
{
    return mProcesses;
}

void Tracker::startTracking(int _timerTimeoutMsec)
{
    mTimer->start(_timerTimeoutMsec);
    mTimeoutMsec = _timerTimeoutMsec;
    connect(mTimer.data(), SIGNAL(timeout()), mTimer.data(), SLOT(start(_timerTimeoutMsec)));
    mState = tr("Tracking");
    emit trackingStarted(mTimeoutMsec);
}

void Tracker::stopTracking()
{
    disconnect(mTimer.data(), SIGNAL(timeout()), mTimer.data(), SLOT(start(int(_timerTimeoutMsec))));
    mState = tr("Stopped");
    emit trackingStopped();
}

QString Tracker::state() const
{
    return mState;
}


void Tracker::track()
{
QString procName;
#ifdef Q_OS_UNIX

    QScopedPointer<QProcess> proc(new QProcess());
    proc->start("bash -c \"echo $(cat /proc/$(xdotool getwindowpid $(xdotool getwindowfocus))/comm)\"");
    proc->waitForBytesWritten(mTimeoutMsec / 2);
    proc->waitForFinished(mTimeoutMsec / 2);
    procName = proc->readAllStandardOutput();

#endif
    qDebug() << "Current Process: " << procName;
    if(!mProcesses.isEmpty() && mProcesses.back()->name() == procName)
        mProcesses.back()->setDuration(mProcesses.back()->duration() + mTimeoutMsec);
    else
        mProcesses.push_back(QSharedPointer<AbstractTrackableProcess>(new TrackableProcess(procName)));
    emit tracked(mProcesses.back());
}

int Tracker::timeoutMsec() const
{
    return mTimeoutMsec;
}

void Tracker::setState(const QString &_state)
{
    mState = _state;
    emit stateChanged(mState);
}
