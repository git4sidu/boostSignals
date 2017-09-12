TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.cpp


LIBS += -LC:/boost/stage/lib
INCLUDEPATH += C:/boost

QMAKE_CXXFLAGS += -std=c++17

HEADERS += \
    inlcudes.h
