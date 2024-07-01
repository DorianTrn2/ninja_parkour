//
// Created by doria on 27/05/2022.
//

#include "../include/Entity.h"
#include "../include/PlatformClass.h"
#include "../include/MovingPlatformClass.h"
#include "../include/Functional.h"
#include "../include/VoidClass.h"
#include "../include/SpikesClass.h"


Entity::Entity(QGraphicsItem* parent) : QGraphicsPixmapItem(parent){

    bottom = new QGraphicsLineItem(21,90, 56, 90, this);
    bottom->setOpacity(0);

    top = new QGraphicsLineItem(21,0, 56, 0, this);
    top->setOpacity(0);

    right = new QGraphicsLineItem(75,10, 75, 66, this);
    right->setOpacity(0);

    left = new QGraphicsLineItem(0,10, 0, 66, this);
    left->setOpacity(0);
}

void Entity::update() {
    collisionDetection();
    movements();
    gravity();

}

void Entity::gravity(){
    GravityState state = {this->collideTop, this->OnFloor, this->KeyUp, this->verticalVelocity, this->x(), this->y(), this->dt, GRAVITY_CONST}; // Assuming dt = 1 for simplicity

    state.verticalVelocity = calculateVerticalVelocity(state);
    qreal newPosY = calculateNewPositionY(state);

    this->verticalVelocity=state.verticalVelocity;
    this->setPos(state.x, newPosY);
}


void Entity::collisionDetection() {
    this->OnFloor = false;
    this->collideLeft = false;
    this->collideRight = false;
    this->collideTop = false;

    for (QGraphicsItem *foot : bottom->collidingItems()) {
        if (dynamic_cast<VoidClass *>(foot) || dynamic_cast<SpikesClass *>(foot)) {
            this->isAlive = false;
            return;
        }

        PlatformClass *testfoot = dynamic_cast<PlatformClass *>(foot);
        if (testfoot) {
            this->setPos(this->x(), testfoot->globalBoundingRect().y() - 89);
            this->OnFloor = true;
            this->verticalVelocity = 0;
        }
    }

    for (QGraphicsItem *topItem : top->collidingItems()) {
        PlatformClass *testTop = dynamic_cast<PlatformClass *>(topItem);
        if (testTop) {
            this->setY(testTop->globalBoundingRect().bottom() + 1);
            this->collideTop = true;
        }
    }

    for (QGraphicsItem *leftItem : left->collidingItems()) {
        PlatformClass *testLeft = dynamic_cast<PlatformClass *>(leftItem);
        if (testLeft) {
            this->setX(testLeft->globalBoundingRect().right());
            this->collideLeft = true;
            return;
        }
    }

    for (QGraphicsItem *rightItem : right->collidingItems()) {
        PlatformClass *testRight = dynamic_cast<PlatformClass *>(rightItem);
        if (testRight) {
            this->setX(testRight->globalBoundingRect().left() - 79);
            this->collideRight = true;
            return;
        }
    }
}


void Entity::jump(){
    if(this->OnFloor) {
        this->verticalVelocity = -JUMP_STRENGHT;
        this->setPos(this->x(), this->y() + dt * verticalVelocity);
    }
}
void Entity::movements(){
    if (!this->isAlive) return;

    EntityState state = {this->isAlive, this->KeyRight, this->KeyLeft, this->horizontalVelocity, this->speed, this->lookingDirection, this->x(), this->y()};

    state.horizontalVelocity = calculateHorizontalVelocity(state);
    state.lookingDirection = calculateLookingDirection(state);
    qreal newPosX = calculateNewPositionX(state.x, state.horizontalVelocity);
    this->lookingDirection = state.lookingDirection;
    this->setPos(newPosX, state.y);
}

Entity::~Entity(){
    delete bottom;
    delete top;
    delete right;
    delete left;
}