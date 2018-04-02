TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    iterator.cpp \
    sorted.cpp \
    stack.cpp \
    cursorlist.cpp \
    queue.cpp

HEADERS += \
    node.h \
    iterator.h \
    sorted.h \
    stack.h \
    cursorlist.h \
    queue.h

