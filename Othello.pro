#-------------------------------------------------
#
# Project created by QtCreator 2012-11-30T13:29:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Othello
TEMPLATE = app


SOURCES += main.cpp\
        othello.cpp \
    qboard.cpp \
    game.cpp

QMAKE_CXXFLAGS += -std=c++0x

HEADERS  += othello.h \
    qboard.h \
    game.h \
    piece.h \
    player.h

FORMS    += othello.ui
