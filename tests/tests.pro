######################################################################
# Tests build for Ninja Parkour game
######################################################################

TEMPLATE = app
TARGET = test_exe
INCLUDEPATH += ../include

QT += testlib

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR=..

OBJECTS_DIR = ../build/tests/obj
MOC_DIR = ../build/tests/moc

# Input
HEADERS += TestEx.h

SOURCES += TestEx.cpp

include(../build/moc/testsTestEx.moc)

QMAKE_CXXFLAGS += -fPIC