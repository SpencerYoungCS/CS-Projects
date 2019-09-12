TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    useful.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    useful.h

