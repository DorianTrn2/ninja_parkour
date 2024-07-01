######################################################################
# App build for Ninja Parkour game
######################################################################

TEMPLATE = app
TARGET = game
INCLUDEPATH += ../include

QT += gui core widgets multimedia

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR=..

OBJECTS_DIR = ../build/app/obj
MOC_DIR = ../build/app/moc

# Input
HEADERS += ../include/Enemy1.h \
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
           ../include/VoidClass.h
SOURCES += ../src/Enemy1.cpp \
           ../src/Enemy1Slow.cpp \
           ../src/Enemy1Fast.cpp \
           ../src/Entity.cpp \
           ../src/GoalClass.cpp \
           ../src/main.cpp \
           ../src/MainWindow.cpp \
           ../src/MovingPlatformClass.cpp \
           ../src/MyScene.cpp \
           ../src/PlatformClass.cpp \
           ../src/Player.cpp \
           ../src/SpikesClass.cpp \
           ../src/VoidClass.cpp

QMAKE_CXXFLAGS += -fPIC