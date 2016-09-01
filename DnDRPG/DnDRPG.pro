TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += sql




SOURCES += main.cpp \
    dbmanager.cpp \
    effect.cpp \
    src/combat.cpp \
    src/dbmanager.cpp \
    src/effect.cpp \
    src/cosmicobject.cpp

HEADERS += \
    dbmanager.h \
    data/enumerations.h \
    data/effectreferencelist.h \
    src/combat.h \
    src/dbmanager.h \
    src/effect.h \
    data/essentials.h \
    src/cosmicobject.h
