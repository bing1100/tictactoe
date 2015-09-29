#-------------------------------------------------
#
# Project created by QtCreator 2015-09-28T20:56:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    view.h \
    controller.h \
    game.h

FORMS    += mainwindow.ui
