/**
 * Project CodeClock
 */


#include "abstracttracker.h"

/**
 * AbstractTracker implementation
 */


/**
 * @return QSharedPointer<AbstractTrackableProcess>
 */
virtual QSharedPointer<AbstractTrackableProcess> AbstractTracker::currentProcess() const 
{
    return QSharedPointer<AbstractTrackableProcess>();
}

/**
 * @param _start
 * @param _start
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractTracker::processes(const QDate& _start, const QDate& _start) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @param _name
 * @param _start
 * @param _start
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractTracker::processes(const QString& _name, const QDate& _start, const QDate& _start) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @param _name
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractTracker::processes(const QString& _name) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractTracker::processes() const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @return void
 */
virtual void AbstractTracker::startTracking()
{
    return;
}

/**
 * @return void
 */
virtual void AbstractTracker::stopTracking()
{
    return;
}

/**
 * @return QString
 */
virtual QString AbstractTracker::state() const 
{
    return QString();
}