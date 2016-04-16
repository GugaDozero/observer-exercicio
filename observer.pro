TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    feedobserver.cpp \
    feedsubject.cpp \
    main.cpp \
    subject.cpp

HEADERS += \
    feedobserver.h \
    feedsubject.h \
    iobserver.h \
    subject.h
