#ifndef TRACKABLEPROCESS_H
#define TRACKABLEPROCESS_H

#include <QObject>
#include <QDateTime>
#include <QColor>
#include "abstracttrackableprocess.h"

class TrackableProcess : public AbstractTrackableProcess
{
    Q_OBJECT
public:

    TrackableProcess(const QString& _name, QObject* _parent = nullptr);

    virtual QString name() const Q_DECL_OVERRIDE;

    virtual QString document() const Q_DECL_OVERRIDE;

    virtual QString comment() const Q_DECL_OVERRIDE;

    virtual quint64 duration() const Q_DECL_OVERRIDE;

    virtual QDateTime startDateTime() const Q_DECL_OVERRIDE;

    virtual QDateTime endDateTime() const Q_DECL_OVERRIDE;

    virtual bool isInInterval(const QDateTime _start, const QDateTime _end) const Q_DECL_OVERRIDE;

    virtual bool startsInInterval(const QDateTime _start, const QDateTime _end) const Q_DECL_OVERRIDE;

    virtual bool endsInInterval(const QDateTime _start, const QDateTime _end) const Q_DECL_OVERRIDE;

    virtual QColor color() const Q_DECL_OVERRIDE;

signals:

    void endDateTimeChanged(const QDateTime&);

    void durationChanged(quint64);

    void startDateTimeChanged(const QDateTime&);

    void commentChanged(const QString&);

    void documentChanged(const QString&);

    void nameChanged(const QString&);

    void colorChanged(const QColor&);

public slots:

    virtual void setEndDateTime(const QDateTime &_dateTime) Q_DECL_OVERRIDE;

    virtual void setDuration(quint64 _msec) Q_DECL_OVERRIDE;

    void setStartDateTime(const QDateTime& _startDateTime);

    void setComment(const QString& _comment);

    void setDocument(const QString& _document);

    void setName(const QString& _name);

    void setColor(const QColor& _color);

protected:

private:

    QString mName;

    QString mDocument;

    QString mComment;

    QDateTime mStartDateTime;

    QDateTime mEndDateTime;

    QColor mColor;

};

#endif // TRACKABLEPROCESS_H
