#-------------------------------------------------
#
# Project created by QtCreator 2014-04-02T22:56:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rhex
TEMPLATE = app


SOURCES += main.cpp\
        rhex.cpp \
        qextserial/qextserialport.cpp

HEADERS  += rhex.h \
        qextserial/qextserialport_global.h \
        qextserial/qextserialport.h \
        ../../debugger.h


win32 {
     SOURCES += qextserial/qextserialport_win.cpp
}

unix {
     SOURCES += qextserial/qextserialport_unix.cpp
}

FORMS    += rhex.ui

RESOURCES += \
    images.qrc
