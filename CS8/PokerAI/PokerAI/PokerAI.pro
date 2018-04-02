TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=

include(deployment.pri)
qtcAddDeployment()

HEADERS +=

SUBDIRS += \
    pokerDealer.pro \
    pokerDealer.pro

