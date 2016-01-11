QT += core gui widgets
TARGET = code-clock
CONFIG += console c++14
CONFIG -= app_bundle

TEMPLATE = app

DISTFILES += \
    README.md

HEADERS += \
    src/model/abstractmodel.h \
    src/model/abstractserializer.h \
    src/model/abstracttrackableprocess.h \
    src/model/abstracttracker.h \
    src/model/abstractview.h \
    src/model/codeclockapplication.h \
    src/model/model.h \
    src/model/trackableprocess.h \
    src/model/tracker.h \
    src/view/codeclockwindow.h

SOURCES += \
    src/model/codeclockapplication.cpp \
    src/model/main.cpp \
    src/model/model.cpp \
    src/model/trackableprocess.cpp \
    src/model/tracker.cpp \
    src/view/codeclockwindow.cpp

FORMS += \
    src/view/codeclockwindow.ui


