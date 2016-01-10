/**
 * Project CodeClock
 */


#include "codeclockapplication.h"
#include <QSharedPointer>

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
      mModel(QSharedPointer<AbstractModel>(new Model()))
{
    setOrganizationName(_organization);
    setApplicationName(_application);
    setApplicationDisplayName(_application);
    setApplicationVersion(_version);
}

CodeClockApplication::CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application,
                                            const QString& _version, QSharedPointer<AbstractModel> _model)
    : QApplication(_argc, _argv),
      mModel(_model)
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
    return QApplication::exec();
}
