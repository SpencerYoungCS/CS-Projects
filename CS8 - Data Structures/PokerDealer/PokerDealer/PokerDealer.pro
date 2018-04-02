TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    pokerDealer.cpp
#    emmaAI/ai_eb.cpp\
#    alexAI/alexpokerai.cpp \
#    alexAI/pokerFunctions.cpp

HEADERS += \
    pokerai.h \
    pokerClasses.h \
    humanplayer.h \
    fast_eval.h \
    arrays.h \
    poker.h \
    rankFunctions.h \
    humanplayer.h \
    handdetectionhelper.h \
    pokerDealer.h \
    spencerai.h
#    benAI/benPoker.h \
#    spencerAI/spencerai.h \
#    dunnAI/AlexDunnPokerAI.h \
#    emmaAI/ai_eb.h \
#    alexAI/alexpokerai.h \
#    alexAI/pokerFunctions.h

