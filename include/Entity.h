//
// Created by doria on 27/05/2022.
//

#ifndef CPP_QT_TPMINIPROJET_ENTITY_H
#define CPP_QT_TPMINIPROJET_ENTITY_H

#include <QWidget>
#include <QGraphicsItem>
#include <QTimer>
#include <iostream>
#include <QLine>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <string>
#define GRAVITY_CONST 700
#define JUMP_STRENGHT 500
#define MAX_SPEED 20


class Entity : public QGraphicsPixmapItem {

public:
    int speed;
    bool KeyUp = false;
    bool KeyDown = false;
    bool KeyRight = false;
    bool KeyLeft = false;
    QGraphicsLineItem* bottom;
    QGraphicsLineItem* top;
    QGraphicsLineItem* right;
    QGraphicsLineItem* left;

    qreal dt = qreal(30)/1000;
    int verticalVelocity = 1;
    int horizontalVelocity = 0;
    bool OnFloor = false;
    bool collideLeft = false;
    bool collideRight = false;
    bool collideTop = false;
    bool lookingDirection = false;
    int animationNumber = 0; //0 = idle, 1 = walking, 2 = jumping, 3 = attacking
    int animationTimer = 0; // itterations since actual animationNumber
    int animationState = 0; // actual image from animation
    bool isAlive = true;


    Entity(QGraphicsItem* parent = nullptr);
    void update();
    void gravity();
    void collisionDetection();
    void jump();
    void movements();

    virtual ~Entity();
};


#endif //CPP_QT_TPMINIPROJET_ENTITY_H
