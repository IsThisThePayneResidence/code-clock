/**
 * Project CodeClock
 */


#include "codeclockapplication.h"

/**
 * CodeClockApplication implementation
 */


/**
 * @param _argc
 * @param _argv
 * @param _organization
 * @param _application
 */
 CodeClockApplication::CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application)
{

}

/**
 * @return QSharedPointer<CodeClockApplication>
 */
static QSharedPointer<CodeClockApplication> CodeClockApplication::app()
{
    return QSharedPointer<CodeClockApplication>();
}

/**
 * @return int
 */
int CodeClockApplication::exec()
{
    return 0;
}