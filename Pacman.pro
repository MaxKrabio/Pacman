#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T16:44:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Position.cpp \
    Game.cpp \
    Player.cpp \
    Size.cpp \
    Enemy.cpp \
    Maze.cpp

HEADERS  += mainwindow.h \
    Position.h \
    Game.h \
    Player.h \
    Size.h \
    Enemy.h \
    Maze.h

FORMS    += mainwindow.ui
