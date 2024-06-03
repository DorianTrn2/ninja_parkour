#include <QtTest/QtTest>
#include <QGraphicsView>
#include <QObject>

#include "../include/MainWindow.h"
#include "../include/MyScene.h"
#include "GoalClass.h"
#include "PlatformClass.h"
#include "SpikesClass.h"

class TestIntegrationMainWindow : public QObject {
Q_OBJECT

private slots:
    void initTestCase();
    void testMainWindowWithScene();

private:
    MainWindow *mainWindow;
    QGraphicsView *view;
    MyScene *scene;
};


