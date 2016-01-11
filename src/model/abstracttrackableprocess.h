/**
 * Project CodeClock
 */


#ifndef _ABSTRACTTRACKABLEPROCESS_H
#define _ABSTRACTTRACKABLEPROCESS_H

#include <QObject>

class AbstractTrackableProcess: public QObject
{
    Q_OBJECT
public: 
    
    virtual QString name() const = 0;

    virtual QString document() const = 0;

    virtual QString comment() const = 0;
    
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
    static quint64 totalDuration(QQueue<QSharedPointer<AbstractTrackableProcess>> _processes);

signals:

    void endDateTimeChanged(const QDateTime&);

    void durationChanged(quint64);

public slots:

    virtual void setEndDateTime(const QDateTime& _dateTime) = 0;

    virtual void setDuration(quint64 _msec) = 0;

protected:

private:

};

#endif //_ABSTRACTTRACKABLEPROCESS_H
