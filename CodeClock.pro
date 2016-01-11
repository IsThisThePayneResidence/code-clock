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
    src/model/codeclockapplication.h \
    src/model/model.h \
    src/model/trackableprocess.h \
    src/model/tracker.h \
    src/view/codeclockwindow.h \
    src/view/diagrams/abstractview.h \
    src/view/diagrams/linearview.h \
    src/view/process/abstractprocessview.h \
    src/view/process/rectangularprocessview.h \
    src/controller/abstractcontroller.h \
    src/controller/controller.h

SOURCES += \
    src/model/codeclockapplication.cpp \
    src/model/main.cpp \
    src/model/model.cpp \
    src/model/trackableprocess.cpp \
    src/model/tracker.cpp \
    src/view/codeclockwindow.cpp \
    src/view/diagrams/linearview.cpp \
    src/view/process/rectangularprocessview.cpp \
    src/controller/controller.cpp

FORMS += \
    src/view/codeclockwindow.ui


