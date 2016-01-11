/**
 * Project CodeClock
 */


#ifndef _MODEL_H
#define _MODEL_H

#include <QSharedPointer>
#include "abstractmodel.h"
#include "tracker.h"

class Model: public AbstractModel
{
    Q_OBJECT
public: 

    Model(QSharedPointer<AbstractTracker> _tracker, QObject* _parent = nullptr);

    Model(QObject* _parent = nullptr);

    virtual QSharedPointer<AbstractTracker> tracker() const;
    
    virtual QSharedPointer<AbstractTrackableProcess> currentProcess() const;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes(const QDateTime& _start, const QDateTime& _end) const;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes(const QString& _name, const QDateTime& _start, const QDateTime& _end) const;

    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes(const QString& _name) const;
    
    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> processes() const;

signals:

    void startedTracking(int);

    void stoppedTracking();

    void trackerChanged(QSharedPointer<AbstractTracker>);

public slots:

    virtual void startTracking(int _timerTimeoutMsec = 1000);

    virtual void stopTracking();

    void setTracker(QSharedPointer<AbstractTracker> _tracker);

protected:

private:

    QSharedPointer<AbstractTracker> mTracker;

};

#endif //_MODEL_H
