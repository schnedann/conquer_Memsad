TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -O3

SOURCES += \
        main.cpp \
        scope_guard.cpp

HEADERS += \
    scope_guard.h \
    secubuff.h
