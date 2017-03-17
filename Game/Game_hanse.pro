QT += core
QT -= gui
QT += network
CONFIG += c++11

TARGET = Game_hanse
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    resources.cpp \
    player.cpp \
    game.cpp \
    trade.cpp \
    tcphandler.cpp

HEADERS += \
    resources.h \
    player.h \
    game.h \
    trade.h \
    tcphandler.h

DISTFILES +=
