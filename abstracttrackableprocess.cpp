/**
 * Project CodeClock
 */


#include "abstracttrackableprocess.h"

/**
 * AbstractTrackableProcess implementation
 */


/**
 * @return QString
 */
virtual QString AbstractTrackableProcess::name() const 
{
    return QString();
}

/**
 * @return quint64
 */
virtual quint64 AbstractTrackableProcess::duration() const 
{
    return 0;
}

/**
 * @return QDateTime
 */
virtual QDateTime AbstractTrackableProcess::startDateTime() const 
{
    return QDateTime();
}

/**
 * @return QDateTime
 */
virtual QDateTime AbstractTrackableProcess::endDateTime() const 
{
    return QDateTime();
}

/**
 * @param _start
 * @param _end
 * @return bool
 */
virtual bool AbstractTrackableProcess::isInInterval(const QDateTime _start, const QDateTime _end) const 
{
    return false;
}

/**
 * @param _start
 * @param _end
 * @return bool
 */
virtual bool AbstractTrackableProcess::startsInInterval(const QDateTime _start, const QDateTime _end) const 
{
    return false;
}

/**
 * @param _start
 * @param _end
 * @return bool
 */
virtual bool AbstractTrackableProcess::endsInInterval(const QDateTime _start, const QDateTime _end) const 
{
    return false;
}

/**
 * @return QColor
 */
virtual QColor AbstractTrackableProcess::color() const 
{
    return QColor();
}

/**
 * @param _processes
 * @return quint64
 */
static quint64 AbstractTrackableProcess::totalDuration(QList<QSharedPointer<AbstractTrackableProcess>> _processes)
{
    return 0;
}