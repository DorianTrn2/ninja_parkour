//
// Created by doria on 30/05/2024.
//

#ifndef QT_PROJECT_UNITTESTING_H
#define QT_PROJECT_UNITTESTING_H

#include <QtTest/QtTest>
#include <QGraphicsView>
#include "MyScene.h"


class UnitTesting : public QObject {
Q_OBJECT
private:
    QGraphicsView *view;
    MyScene *scene;

private slots:

    void initTestCase();

    void testInitialization();

    void testAddPlatforms();

    void testKeyPressEvents();
};

#endif //QT_PROJECT_UNITTESTING_H
