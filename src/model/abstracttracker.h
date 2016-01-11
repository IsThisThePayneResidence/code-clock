/**
 * Project CodeClock
 */


#ifndef _ABSTRACTTRACKER_H
#define _ABSTRACTTRACKER_H

#include "qobject.h"

class AbstractTrackableProcess;

class AbstractTracker: public QObject
{
    Q_OBJECT
public: 
    
    virtual QSharedPointer<AbstractTrackableProcess> currentProcess() const = 0;
    
    /**
     * @param _start
     * @param _start
     */
    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes(const QDateTime& _start, const QDateTime& _end) const = 0;
    
    /**
     * @param _name
     * @param _start
     * @param _start
     */
    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes(const QString& _name, const QDateTime& _start, const QDateTime& _end) const = 0;
    
    /**
     * @param _name
     */
    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes(const QString& _name) const = 0;
    
    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes() const = 0;
    
    virtual QString state() const = 0;

signals:

    void tracked(QSharedPointer<AbstractTrackableProcess>);

    void trackingStarted(int);

    void trackingStopped();

    void dataChanged(const QQueue<QSharedPointer<AbstractTrackableProcess>>&);

public slots:

    virtual void track() = 0;

    virtual void startTracking(int _timerTimeoutMsec = 1000) = 0;

    virtual void stopTracking() = 0;

protected:

private:
};

#endif //_ABSTRACTTRACKER_H
