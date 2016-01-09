/**
 * Project CodeClock
 */


#ifndef _ABSTRACTSERIALIZER_H
#define _ABSTRACTSERIALIZER_H

#include <QObject>


class AbstractSerializer: public QObject
{
    Q_OBJECT
public:
    QString serialize();

signals:

public slots:

protected:

private:

};

#endif //_ABSTRACTSERIALIZER_H
