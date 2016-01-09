/**
 * Project CodeClock
 */


#ifndef _ABSTRACTMODEL_H
#define _ABSTRACTMODEL_H

#include "qobject.h"


class AbstractModel: public QObject
{
public: 
    
    virtual QSharedPointer<AbstractTracker> tracker() const = 0;
    
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
};

#endif //_ABSTRACTMODEL_H