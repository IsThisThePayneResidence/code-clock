/**
 * Project CodeClock
 */


#ifndef _CODECLOCKAPPLICATION_H
#define _CODECLOCKAPPLICATION_H

#include <QApplication>
#include "abstractmodel.h"
#include "model.h"


class CodeClockApplication: public QApplication
{
public: 

     CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application, const QString& _version);

     CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application,
                          const QString& _version, QSharedPointer<AbstractModel> _model);

    static QSharedPointer<CodeClockApplication> app();
    
    int exec();

private:

    QSharedPointer<AbstractModel> mModel;
};

#endif //_CODECLOCKAPPLICATION_H
