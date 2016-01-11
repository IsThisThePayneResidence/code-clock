QT += core gui widgets
TARGET = CodeClock
CONFIG += console c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    src/codeclockapplication.cpp \
    src/main.cpp \
    src/model.cpp \
    src/tracker.cpp \
    src/trackableprocess.cpp \
    src/codeclockwindow.cpp

HEADERS += \
    src/abstractmodel.h \
    src/abstractserializer.h \
    src/abstracttrackableprocess.h \
    src/abstracttracker.h \
    src/codeclockapplication.h \
    src/model.h \
    src/tracker.h \
    src/trackableprocess.h \
    src/codeclockwindow.h \
    src/abstractview.h

DISTFILES += \
    README.md

FORMS += \
    src/codeclockwindow.ui

