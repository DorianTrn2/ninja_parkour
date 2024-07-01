//
// Created by doria on 03/06/2024.
//

#ifndef QT_PROJECT_TESTINTEGRATIONENEMY1_H
#define QT_PROJECT_TESTINTEGRATIONENEMY1_H
#include <QtTest/QtTest>
#include "../include/MyScene.h"
#include "Enemy1.h"
#include "Player.h"
#include "Enemy1Fast.h"
#include "Enemy1Slow.h"

class TestIntegrationEnemy1 : public QObject {
    Q_OBJECT

private slots:
    void testAddEnemy();
    void testEnemyMovement();
    void testPlayerKilledByEnemy();

private:
    QGraphicsView *view;
    MyScene *scene;
};


#endif //QT_PROJECT_TESTINTEGRATIONENEMY1_H
