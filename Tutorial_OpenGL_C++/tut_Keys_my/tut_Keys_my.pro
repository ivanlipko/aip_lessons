TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    drawlib.cpp

LIBS+=-lglut -lGL -lGLU # linux libs # without qt =)
#LIBS+=-lfreeglut -lopengl32   # windows libs
#QT+=opengl

HEADERS += \
    drawlib.h
