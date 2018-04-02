TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    animal.cpp \
    useful.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    bintree.h \
    useful.h

