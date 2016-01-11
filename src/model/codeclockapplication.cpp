/**
 * Project CodeClock
 */


#include "codeclockapplication.h"
#include <QSharedPointer>
#include "../view/diagrams/linearview.h"
#include "../controller/controller.h"

/**
 * CodeClockApplication implementation
 */


/**
 * @param _argc
 * @param _argv
 * @param _organization
 * @param _application
 */
CodeClockApplication::CodeClockApplication(int _argc, char **_argv, const QString &_organization, const QString &_application, const QString &_version)
    : QApplication(_argc, _argv),
      mMainWindow(new CodeClockWindow(mView)),
      mModel(QSharedPointer<AbstractModel>(new Model(this))),
      mView(QSharedPointer<AbstractView>(new LinearView(mMainWindow.data()))),
      mController(QSharedPointer<AbstractController>(new Controller(mModel, mView, mMainWindow.data())))
{
    setOrganizationName(_organization);
    setApplicationName(_application);
    setApplicationDisplayName(_application);
    setApplicationVersion(_version);
}

CodeClockApplication::CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application,
                                           const QString& _version, QSharedPointer<AbstractModel> _model, QSharedPointer<AbstractView> _view,
                                           QSharedPointer<AbstractController> _controller)
    : QApplication(_argc, _argv),
      mMainWindow(new CodeClockWindow(mView)),
      mModel(_model),
      mView(_view),
      mController(_controller)
{
    setOrganizationName(_organization);
    setApplicationName(_application);
    setApplicationDisplayName(_application);
    setApplicationVersion(_version);
}

/**
 * @return QSharedPointer<CodeClockApplication>
 */
QSharedPointer<CodeClockApplication> CodeClockApplication::app()
{
    return QSharedPointer<CodeClockApplication>((CodeClockApplication*)qApp);
}

/**
 * @return int
 */
int CodeClockApplication::exec()
{
    mModel->startTracking();
    mMainWindow->show();
    return QApplication::exec();
}
