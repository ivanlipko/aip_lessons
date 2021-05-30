TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    draw.cpp \
    mechanics.cpp

#LIBS+=-lfreeglut -lopengl32     #windows
LIBS+=-lglut -lGL -lGLU         # unix

HEADERS += \
    draw.h \
    mechanics.h
