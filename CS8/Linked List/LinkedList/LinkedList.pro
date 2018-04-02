TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    map.h \
    node.h \
    list.h \
    frequency.h \
    pair.h \
    listfunctions.h \
    functors.h

