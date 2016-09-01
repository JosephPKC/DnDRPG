TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += sql




SOURCES += main.cpp \
    dbmanager.cpp

HEADERS += \
    dbmanager.h \
    data/enumerations.h
