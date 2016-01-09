/**
 * Project CodeClock
 */


#include "model.h"

/**
 * Model implementation
 */


/**
 * @return QSharedPointer<AbstractTracker>
 */
virtual QSharedPointer<AbstractTracker> Model::tracker() const 
{
    return QSharedPointer<AbstractTracker>();
}

/**
 * @return QSharedPointer<AbstractTrackableProcess>
 */
virtual QSharedPointer<AbstractTrackableProcess> Model::currentProcess() const 
{
    return QSharedPointer<AbstractTrackableProcess>();
}

/**
 * @param _start
 * @param _start
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> Model::processes(const QDate& _start, const QDate& _start) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @param _name
 * @param _start
 * @param _start
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> Model::processes(const QString& _name, const QDate& _start, const QDate& _start) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @param _name
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> Model::processes(const QString& _name) const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @return QList<QSharedPointer<AbstractTrackableProcess>>
 */
virtual QList<QSharedPointer<AbstractTrackableProcess>> Model::processes() const 
{
    return QList<QSharedPointer<AbstractTrackableProcess>>();
}

/**
 * @return void
 */
virtual void Model::startTracking()
{
    return;
}

/**
 * @return void
 */
virtual void Model::stopTracking()
{
    return;
}