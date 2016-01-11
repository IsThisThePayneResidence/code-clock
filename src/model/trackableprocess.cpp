#include <QDateTime>
#include <QColor>
#include "trackableprocess.h"

TrackableProcess::TrackableProcess(const QString &_name, const QString &_document, QObject *_parent)
    : mName(_name),
      mDocument(_document),
      mStartDateTime(QDateTime::currentDateTime()),
      mEndDateTime(QDateTime::currentDateTime())
{
    setParent(_parent);
}

QString TrackableProcess::name() const
{
    return mName;
}

QString TrackableProcess::document() const
{
    return mDocument;
}

QString TrackableProcess::comment() const
{
    return mComment;
}

quint64 TrackableProcess::duration() const
{
    return mStartDateTime.msecsTo(mEndDateTime);
}

QDateTime TrackableProcess::startDateTime() const
{
    return mStartDateTime;
}

QDateTime TrackableProcess::endDateTime() const
{
    return mEndDateTime;
}

bool TrackableProcess::isInInterval(const QDateTime _start, const QDateTime _end) const
{
    return (mStartDateTime >= _start && mEndDateTime <= _end);
}

bool TrackableProcess::startsInInterval(const QDateTime _start, const QDateTime _end) const
{
    return (mStartDateTime >= _start && mStartDateTime <= _end);
}

bool TrackableProcess::endsInInterval(const QDateTime _start, const QDateTime _end) const
{
    return (mEndDateTime >= _start && mEndDateTime <= _end);
}

QColor TrackableProcess::color() const
{
    return QColor("red"); //just for now
}

void TrackableProcess::setEndDateTime(const QDateTime &_dateTime)
{
    mEndDateTime = _dateTime;
    emit endDateTimeChanged(mEndDateTime);
}

void TrackableProcess::setDuration(quint64 _msec)
{
    mEndDateTime = QDateTime::fromMSecsSinceEpoch(mStartDateTime.toMSecsSinceEpoch() + _msec);
    emit durationChanged(_msec);
}

void TrackableProcess::setName(const QString &_name)
{
    mName = _name;
    emit nameChanged(mName);
}

void TrackableProcess::setColor(const QColor &_color)
{
    mColor = _color;
    emit colorChanged(mColor);
}

void TrackableProcess::setDocument(const QString &_document)
{
    mDocument = _document;
    emit documentChanged(mDocument);
}

void TrackableProcess::setComment(const QString &_comment)
{
    mComment = _comment;
    emit commentChanged(mComment);
}

void TrackableProcess::setStartDateTime(const QDateTime& _startDateTime)
{
    mStartDateTime = _startDateTime;
    emit startDateTimeChanged(mStartDateTime);
}
