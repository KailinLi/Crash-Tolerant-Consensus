#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T16:38:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CTC
TEMPLATE = app


SOURCES += main.cpp\
        ctc.cpp \
    ctcfunction.cpp \
    slock.cpp \
    crashprocessor.cpp \
    normalprocessor.cpp \
    coloritem.cpp

HEADERS  += ctc.h \
    ctcfunction.h \
    slock.h \
    crashprocessor.h \
    normalprocessor.h \
    coloritem.h

FORMS    += ctc.ui
CONFIG += c++11
