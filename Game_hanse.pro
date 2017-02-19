QT += core
QT -= gui

CONFIG += c++11

TARGET = Game_hanse
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    resources.cpp

HEADERS += \
    resources.h
