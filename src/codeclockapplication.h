/**
 * Project CodeClock
 */


#ifndef _CODECLOCKAPPLICATION_H
#define _CODECLOCKAPPLICATION_H

#include "qapplication.h"


class CodeClockApplication: public QApplication
{
public: 
    
    /**
     * @param _argc
     * @param _argv
     * @param _organization
     * @param _application
     */
     CodeClockApplication(int _argc, char** _argv, const QString& _organization, const QString& _application);
    
    static QSharedPointer<CodeClockApplication> app();
    
    int exec();
};

#endif //_CODECLOCKAPPLICATION_H