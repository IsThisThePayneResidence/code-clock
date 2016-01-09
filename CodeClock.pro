QT += core gui widgets
TARGET = CodeClock
CONFIG += console c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qobject.cpp \
    abstracttracker.cpp \
    model.cpp \
    abstractmodel.cpp \
    abstracttrackableprocess.cpp \
    abstractserializer.cpp \
    codeclockapplication.cpp \
    qapplication.cpp \
    main.cpp

HEADERS += \
    qobject.h \
    abstracttracker.h \
    model.h \
    abstractmodel.h \
    abstracttrackableprocess.h \
    abstractserializer.h \
    codeclockapplication.h \
    qapplication.h

DISTFILES += \
    README.md

