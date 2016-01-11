/**
 * Project CodeClock
 */


#ifndef _ABSTRACTTRACKABLEPROCESS_H
#define _ABSTRACTTRACKABLEPROCESS_H

#include "qobject.h"


class AbstractTrackableProcess: public QObject
{
public: 
    
    virtual QString name() const = 0;
    
    virtual quint64 duration() const = 0;
    
    virtual QDateTime startDateTime() const = 0;
    
    virtual QDateTime endDateTime() const = 0;
    
    /**
     * @param _start
     * @param _end
     */
    virtual bool isInInterval(const QDateTime _start, const QDateTime _end) const = 0;
    
    /**
     * @param _start
     * @param _end
     */
    virtual bool startsInInterval(const QDateTime _start, const QDateTime _end) const = 0;
    
    /**
     * @param _start
     * @param _end
     */
    virtual bool endsInInterval(const QDateTime _start, const QDateTime _end) const = 0;
    
    virtual QColor color() const = 0;
    
    /**
     * @param _processes
     */
    static quint64 totalDuration(QList<QSharedPointer<AbstractTrackableProcess>> _processes);
};

#endif //_ABSTRACTTRACKABLEPROCESS_H