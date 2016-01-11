#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <QObject>

class AbstractController : public QObject
{
    Q_OBJECT
public:

signals:

public slots:

    virtual void connectSignalsAndSlots() = 0;

protected:

private:

};

#endif // ABSTRACTCONTROLLER_H
