######################################################################
# Tests build for Ninja Parkour game
######################################################################

TEMPLATE = app
TARGET = test_exe
INCLUDEPATH += ../include

QT += testlib gui core widgets multimedia

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR=..

OBJECTS_DIR = ../build/tests/obj
MOC_DIR = ../build/tests/moc

# Input
HEADERS += ../include/Enemy1.h \
           ../include/Functional.h \
           ../include/Enemy1Slow.h \
           ../include/Enemy1Fast.h \
           ../include/Entity.h \
           ../include/GoalClass.h \
           ../include/MainWindow.h \
           ../include/MovingPlatformClass.h \
           ../include/MyScene.h \
           ../include/PlatformClass.h \
           ../include/Player.h \
           ../include/SpikesClass.h \
           ../include/VoidClass.h \
           UnitTesting.h \
           WindowTests.h \
           TestIntegrationMainWindow.h \
           TestIntegrationMyScene.h \
           TestIntegrationEnemy1.h

SOURCES += ../src/Enemy1.cpp \
           ../src/Functional.cpp \
           ../src/Enemy1Fast.cpp \
           ../src/Enemy1Slow.cpp \
           ../src/Entity.cpp \
           ../src/GoalClass.cpp \
           main.cpp \
           ../src/MainWindow.cpp \
           ../src/MovingPlatformClass.cpp \
           ../src/MyScene.cpp \
           ../src/PlatformClass.cpp \
           ../src/Player.cpp \
           ../src/SpikesClass.cpp \
           ../src/VoidClass.cpp \
           UnitTesting.cpp \
           WindowTests.cpp \
           TestIntegrationMainWindow.cpp \
           TestIntegrationMyScene.cpp \
           TestIntegrationEnemy1.cpp

QMAKE_CXXFLAGS += -fPIC