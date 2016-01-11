/**
 * Project CodeClock
 */


#ifndef _ABSTRACTMODEL_H
#define _ABSTRACTMODEL_H

#include <QObject>
#include <QDateTime>

class AbstractTracker;
class AbstractTrackableProcess;

class AbstractModel: public QObject
{
    Q_OBJECT
public: 
    
    virtual QSharedPointer<AbstractTracker> tracker() const = 0;
    
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

signals:

    void started();

    void stopped();

    void dataChanged(const QQueue<QSharedPointer<AbstractTrackableProcess>>&);

public slots:

    virtual void startTracking(int _timerTimeoutMsec = 1000) = 0;

    virtual void stopTracking() = 0;

protected:

private:

};

#endif //_ABSTRACTMODEL_H
