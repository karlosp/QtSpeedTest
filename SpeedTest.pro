#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T19:28:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SpeedTest
TEMPLATE = app

CONFIG += static

SOURCES += main.cpp\
        mainwindow.cpp \
    IndicatorWidget.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    IndicatorWidget.h \
    qcustomplot.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
