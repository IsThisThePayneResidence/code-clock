/**
 * Project CodeClock
 */


#ifndef _CODECLOCKAPPLICATION_H
#define _CODECLOCKAPPLICATION_H

#include <QApplication>
#include "abstractmodel.h"
#include "model.h"
#include "../view/codeclockwindow.h"
#include "../view/diagrams/abstractview.h"
#include "../controller/abstractcontroller.h"


class CodeClockApplication: public QApplication
{
public: 

     CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application, const QString& _version);

     CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application,
                          const QString& _version, QSharedPointer<AbstractModel> _model, QSharedPointer<AbstractView> _view, QSharedPointer<AbstractController> _controller);

    static QSharedPointer<CodeClockApplication> app();
    
    int exec();

private:

    QSharedPointer<AbstractModel> mModel;

    QSharedPointer<AbstractView> mView;

    QSharedPointer<AbstractController> mController;

    QSharedPointer<CodeClockWindow> mMainWindow;
};

#endif //_CODECLOCKAPPLICATION_H
