#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QObject>

class AbstractTrackableProcess;

class AbstractView : public QObject
{
    Q_OBJECT
public:

signals:

    void dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess>> _data);

public slots:

    virtual void setData(QQueue<QSharedPointer<AbstractTrackableProcess>> _data) = 0;

protected:

private:


};

#endif // ABSTRACTVIEW_H
