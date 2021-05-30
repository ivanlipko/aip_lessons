TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS+=-lglut -lGL -lGLU # without qt =)
#QT+=opengl

HEADERS +=
