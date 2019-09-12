TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    node.h \
    linkedlist.h \
    ../../MergeSortList/MergeSortList/linkedlist.h

