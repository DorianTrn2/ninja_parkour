//
// Created by doria on 01/06/2022.
//

#include "../include/Enemy1.h"
#include <QDebug>
Enemy1::Enemy1(qreal x, qreal y, qreal xmin, qreal xmax, QGraphicsItem* parent) : Entity(parent){
    QString imgPath = "ressources/enemy1/walk/walk_1.png";
    QImage image(imgPath);

    QImage imageconv = image.scaled(100, 100, Qt::KeepAspectRatio);
    this->setPixmap(QPixmap::fromImage(imageconv));
    this->setPos(x+1,y);
    this->xmax = xmax;
    this->xmin = xmin;
    this->speed = 10;
    this->KeyLeft = false;
    this->KeyRight = true;

}

void Enemy1::KeyChange(){
    if(this->x() > xmax){
        this->KeyLeft = true;
        this->KeyRight = false;
        this->lookingDirection = true;
    }
    else if(this->x() < xmin){
        this->KeyLeft = false;
        this->KeyRight = true;
        this->lookingDirection = false;
    }
}


void Enemy1::update(){
    if(isAlive) {
        KeyChange();
        collisionDetection();
        movements();
        gravity();
        animation();
    }
    else{
        delete this;
        //this->set(null);
    }
}

void Enemy1::animation(){
    animationTimer++;

    if(animationTimer%3==0){
        animationTimer = 0;
        animationState++;
    }

    if(animationState==5){
        animationState=0;
    }
    std::string test = "ressources/enemy1/walk/walk_"+std::to_string(animationState+1)+".png";
    QString qstr = QString::fromStdString(test);
    QImage image(qstr);
    QImage imageconv = image.scaled(100, 100, Qt::KeepAspectRatio).mirrored(lookingDirection,false);
    this->setPixmap(QPixmap::fromImage(imageconv));

}


Enemy1::~Enemy1(){
}

