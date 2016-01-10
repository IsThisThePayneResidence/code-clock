#ifndef TRACKER_H
#define TRACKER_H

#include <QObject>
#include <QQueue>
#include <QTimer>
#include <QDateTime>
#include <QSharedPointer>
#include "abstracttracker.h"
#include "abstracttrackableprocess.h"

class Tracker : public AbstractTracker
{
    Q_OBJECT
public:
    Tracker(bool _isStarted = true, int _msec = 1000, QObject* _parent = nullptr);

    virtual QSharedPointer<AbstractTrackableProcess> currentProcess() const Q_DECL_OVERRIDE;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess> > processes(const QDateTime &_start, const QDateTime &_end) const Q_DECL_OVERRIDE;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess> > processes(const QString &_name, const QDateTime &_start, const QDateTime &_end) const Q_DECL_OVERRIDE;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess> > processes(const QString &_name) const Q_DECL_OVERRIDE;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess> > processes() const Q_DECL_OVERRIDE;

    virtual QString state() const Q_DECL_OVERRIDE;

    int timeoutMsec() const;

signals:

    void tracked(QSharedPointer<AbstractTrackableProcess>);

    void trackingStarted(int _timerTimeoutMsec = 1000);

    void trackingStopped();

    void stateChanged(const QString&);

public slots:

    virtual void track() Q_DECL_OVERRIDE;

    virtual void startTracking(int _timerTimeoutMsec = 1000) Q_DECL_OVERRIDE;

    virtual void stopTracking() Q_DECL_OVERRIDE;

    void setState(const QString& _state);

protected:

private:

     QQueue<QSharedPointer<AbstractTrackableProcess>> mProcesses;

     QSharedPointer<QTimer> mTimer;

     QString mState;

     int mTimeoutMsec;
};

#endif // TRACKER_H
