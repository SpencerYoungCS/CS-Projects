TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    random.cpp \
    templatedcompare.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    simplecompare.h \
    random.h \
    templatedcompare.h

