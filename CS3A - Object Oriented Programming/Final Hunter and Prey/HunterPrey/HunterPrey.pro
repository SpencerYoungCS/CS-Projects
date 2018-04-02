TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
#CONFIG -= qt

QT += core gui widgets opengl


SOURCES += main.cpp \
    organism.cpp \
    ants.cpp \
    doodlebugs.cpp \
    world.cpp \
    wall.cpp \
    glwidget.cpp \
    coord.cpp \
    mygui.cpp \
    virus.cpp

HEADERS += \
    organism.h \
    ants.h \
    doodlebugs.h \
    world.h \
    wall.h \
    coordinate.h \
    constants.h \
    glwidget.h \
    coord.h \
    mygui.h \
    virus.h

