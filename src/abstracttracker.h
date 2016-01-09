/**
 * Project CodeClock
 */


#ifndef _ABSTRACTTRACKER_H
#define _ABSTRACTTRACKER_H

#include "qobject.h"


class AbstractTracker: public QObject
{
public: 
    
    virtual QSharedPointer<AbstractTrackableProcess> currentProcess() const = 0;
    
    /**
     * @param _start
     * @param _start
     */
    virtual QList<QSharedPointer<AbstractTrackableProcess>> processes(const QDate& _start, const QDate& _start) const = 0;
    
    /**
     * @param _name
     * @param _start
     * @param _start
     */
    virtual QList<QSharedPointer<AbstractTrackableProcess>> processes(const QString& _name, const QDate& _start, const QDate& _start) const = 0;
    
    /**
     * @param _name
     */
    virtual QList<QSharedPointer<AbstractTrackableProcess>> processes(const QString& _name) const = 0;
    
    virtual QList<QSharedPointer<AbstractTrackableProcess>> processes() const = 0;
    
    virtual void startTracking() = 0;
    
    virtual void stopTracking() = 0;
    
    virtual QString state() const = 0;
};

#endif //_ABSTRACTTRACKER_H