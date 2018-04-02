TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    employee.cpp \
    hourlyemployee.cpp \
    salariedemployee.cpp \
    administrator.cpp \
    temporaryemployee.cpp \
    permanent.cpp

HEADERS += \
    employee.h \
    hourlyemployee.h \
    salariedemployee.h \
    administrator.h \
    temporaryemployee.h \
    permanent.h

