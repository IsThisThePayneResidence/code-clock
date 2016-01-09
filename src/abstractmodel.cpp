/**
 * Project CodeClock
 */


#include "abstractmodel.h"

/**
 * AbstractModel implementation
 */


/**
 * @return QSharedPointer<AbstractTracker>
 */
virtual QSharedPointer<AbstractTracker> AbstractModel::tracker() const 
{
    return QSharedPointer<AbstractTracker>();
}

/**
 * @return QSharedPointer<AbstractTrackableProcess>
 */
virtual QSharedPointer<AbstractTrackableProcess> AbstractModel::currentProcess() const 
{
    return QSharedPointer<AbstractTrackableProcess>();
}

/**
 * @param _start
 * @param _start
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractModel::processes(const QDate& _start, const QDate& _start) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @param _name
 * @param _start
 * @param _start
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractModel::processes(const QString& _name, const QDate& _start, const QDate& _start) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @param _name
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractModel::processes(const QString& _name) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> AbstractModel::processes() const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @return void
 */
virtual void AbstractModel::startTracking()
{
    return;
}

/**
 * @return void
 */
virtual void AbstractModel::stopTracking()
{
    return;
}