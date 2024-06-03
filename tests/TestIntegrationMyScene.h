#ifndef QT_PROJECT_TESTINTEGRATIONMYSCENE_H
#define QT_PROJECT_TESTINTEGRATIONMYSCENE_H
#include <QtTest/QtTest>
#include "../include/MyScene.h"
#include "GoalClass.h"
#include "PlatformClass.h"
#include "SpikesClass.h"


class TestIntegrationMyScene : public QObject{
    Q_OBJECT
private slots:
    void initTestCase();
    void testAddGoal();
    void testAddPlatform();
    void testAddSpikes();

private:
    QGraphicsView *view;
    MyScene *scene;
};


#endif //QT_PROJECT_TESTINTEGRATIONMYSCENE_H
