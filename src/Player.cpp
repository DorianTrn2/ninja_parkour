//
// Created by doria on 27/05/2022.
//
#include "../include/Entity.h"
#include "../include/Player.h"

Player::Player(QGraphicsItem* parent) : Entity(parent){
this->speed = 20;
}


void Player::update(){
    Entity::collisionDetection();
    movements();
    gravity();
    animation();
}

void Player::gravity(){
    if(this->collideTop){
        verticalVelocity = 0;
    }
    if(!this->OnFloor and this->KeyUp){
        this->setPos(this->x(), this->y()+dt*verticalVelocity);
        if(verticalVelocity>0) {
            verticalVelocity = (verticalVelocity + dt * GRAVITY_CONST * 2) * 0.9;
        }
        else verticalVelocity = verticalVelocity + dt*GRAVITY_CONST*2;

    }
    else if(!this->OnFloor and !this->KeyUp){
        this->setPos(this->x(), this->y()+dt*verticalVelocity);
        verticalVelocity = verticalVelocity + dt*GRAVITY_CONST*4;
    }

    else{
    }
}

void Player::jump(){
    if(this->OnFloor and this->isAlive) {
        this->verticalVelocity = -JUMP_STRENGHT;
        this->setPos(this->x(), this->y() + dt * verticalVelocity);
    }
}

void Player::animation(){
    std::string temp;
    int actAnimationID;

    if(isHitting){
        actAnimationID = 3;
        temp = "attack";

    }

    else if(!this->OnFloor){
        actAnimationID=2;
        temp = "jump";
    }
    else if(horizontalVelocity!=0){
        actAnimationID=1;
        temp = "walk";
    }
    else{
        actAnimationID=0;
        temp = "idle";
    }
    if(actAnimationID==animationNumber){
        animationTimer++;
    }
    else{
        animationNumber = actAnimationID;
        animationTimer = 0;
        animationState = 0;
    }

    if(animationTimer%3==0){
        animationTimer = 0;
        animationState++;
    }

    if(actAnimationID == 3){
        if(animationState==3){
            animationState=0;
        }
    }

    else if(actAnimationID==0){
        if(animationState==5){
            animationState=0;
        }
    }

    else if(actAnimationID==1){
        if(animationState==5){
            animationState=0;
        }
    }

    else if(actAnimationID==2){
        if(animationState==3){
            animationState=2;
        }
    }

    std::string test = "ressources/ninja/"+temp+"/"+temp+"_"+std::to_string(animationState+1)+".png";
    QString qstr = QString::fromStdString(test);
    QImage image(qstr);
    QImage imageconv = image.scaled(100, 100, Qt::KeepAspectRatio).mirrored(lookingDirection,false);
    this->setPixmap(QPixmap::fromImage(imageconv));
}


Player::~Player(){
}

