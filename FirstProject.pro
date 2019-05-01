#-------------------------------------------------
#
# Project created by QtCreator 2019-02-15T20:12:57
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstProject
TEMPLATE = app


SOURCES += main.cpp\
    firstwindow.cpp \
    dialogsettings.cpp \
    tablewindow.cpp \
    querywindow.cpp \
    input2nums.cpp

HEADERS  += \
    firstwindow.h \
    dialogsettings.h \
    skeys.h \
    tablewindow.h \
    querywindow.h \
    input2nums.h

FORMS    += \
    firstwindow.ui \
    dialogsettings.ui \
    tablewindow.ui \
    querywindow.ui \
    input2nums.ui
