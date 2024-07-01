//
// Created by doria on 01/07/2024.
//

#ifndef MYSCENE_CPP_FUNCTIONAL_H
#define MYSCENE_CPP_FUNCTIONAL_H
#include <iostream>
#include <QVector>

struct EntityState {
    bool isAlive;
    bool KeyRight;
    bool KeyLeft;
    int horizontalVelocity;
    int speed;
    bool lookingDirection;
    qreal x;
    qreal y;
};

struct GravityState {
    bool collideTop;
    bool OnFloor;
    bool KeyUp;
    int verticalVelocity;
    qreal x;
    qreal y;
    qreal dt;
    int gravity_const;
};

int calculateHorizontalVelocity(const EntityState& state);
bool calculateLookingDirection(const EntityState& state);
qreal calculateNewPositionX(qreal x, int horizontalVelocity);
int calculateVerticalVelocity(const GravityState& state);
qreal calculateNewPositionY(const GravityState& state);




#endif //MYSCENE_CPP_FUNCTIONAL_H
