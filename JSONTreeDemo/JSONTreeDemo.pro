#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T10:59:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JSONTreeDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsontreeview.cpp \
    jsinfo.cpp

HEADERS  += mainwindow.h \
    jsontreeview.h \
    jsinfo.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
