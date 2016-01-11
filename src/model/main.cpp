#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include "codeclockapplication.h"

int main(int _argc, char *_argv[])
{
    QScopedPointer<CodeClockApplication> app(new CodeClockApplication(_argc, _argv, "IsThisThePayneResidence [QCoder]", "CodeClock", "0.0.1"));

    return app->exec();
}

