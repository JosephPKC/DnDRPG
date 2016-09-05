TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
# CONFIG -= qt
QT += sql

SOURCES += main.cpp \
    src/combat.cpp \
    src/dbmanager.cpp \
    src/effect.cpp \
    src/cosmicobject.cpp \
    data/essentials.cpp \
    src/gamemanager.cpp \
    src/item.cpp \
    src/itemfactory.cpp

HEADERS += \
    data/enumerations.h \
    data/effectreferencelist.h \
    src/combat.h \
    src/dbmanager.h \
    src/effect.h \
    data/essentials.h \
    src/cosmicobject.h \
    src/resultset.h \
    src/gamemanager.h \
    src/item.h \
    src/itemfactory.h
