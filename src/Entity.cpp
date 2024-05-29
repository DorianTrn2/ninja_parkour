//
// Created by doria on 27/05/2022.
//

#include "../include/Entity.h"
#include "../include/PlatformClass.h"
#include "../include/MovingPlatformClass.h"

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
    gravity();

}

void Entity::gravity(){
    if(this->collideTop){
        verticalVelocity = 0;
    }
    if(!this->OnFloor){
        this->setPos(this->x(), this->y()+dt*verticalVelocity);
        verticalVelocity = verticalVelocity + dt*GRAVITY_CONST*2;
    }
    else{
    }
}


void Entity::collisionDetection() {
    // Réinitialisation des indicateurs de collision
    this->OnFloor = false;
    this->collideLeft = false;
    this->collideRight = false;
    this->collideTop = false;

    // Vérification de collision avec les éléments en bas
    for (QGraphicsItem *foot : bottom->collidingItems()) {
        if (dynamic_cast<VoidClass *>(foot) || dynamic_cast<SpikesClass *>(foot)) {
            this->isAlive = false;
            return;
        }

        PlatformClass *testfoot = dynamic_cast<PlatformClass *>(foot);
        if (testfoot) {
            // Réglage de la position verticale et des indicateurs de collision
            this->setPos(this->x(), testfoot->globalBoundingRect().y() - 89);
            this->OnFloor = true;
            this->verticalVelocity = 0;
        }
    }

    // Vérification de collision avec les éléments en haut
    for (QGraphicsItem *topItem : top->collidingItems()) {
        PlatformClass *testTop = dynamic_cast<PlatformClass *>(topItem);
        if (testTop) {
            this->setY(testTop->globalBoundingRect().bottom() + 1);
            this->collideTop = true;
        }
    }

    // Vérification de collision avec les éléments à gauche
    for (QGraphicsItem *leftItem : left->collidingItems()) {
        PlatformClass *testLeft = dynamic_cast<PlatformClass *>(leftItem);
        if (testLeft) {
            this->setX(testLeft->globalBoundingRect().right());
            this->collideLeft = true;
            return;
        }
    }

    // Vérification de collision avec les éléments à droite
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
    if(this->isAlive) {
        this->setPos(this->x() + horizontalVelocity, this->y());
        if (this->KeyRight) {
            horizontalVelocity += 20;
            lookingDirection = false;
            if (horizontalVelocity > speed) {
                horizontalVelocity = speed;
            }
        } else if (this->KeyLeft) {
            horizontalVelocity -= 20;
            lookingDirection = true;
            if (horizontalVelocity < -speed) {
                horizontalVelocity = -speed;
            }
        } else horizontalVelocity = 0;
    }
}

Entity::~Entity(){

}