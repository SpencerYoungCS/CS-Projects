TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()


HEADERS += \
    ftokenize.h \
    stokenize.h \
    token.h \
    frequency.h \
    listfunctions.h \
    pair.h \
    functors.h

