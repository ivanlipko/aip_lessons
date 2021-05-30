TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    drawlib.cpp

LIBS+=-lglut -lGL

HEADERS += \
    drawlib.h
