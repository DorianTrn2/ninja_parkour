//
// Created by doria on 29/05/2022.
//

#include "../include/GoalClass.h"

GoalClass::GoalClass(QGraphicsItem* parent) : QGraphicsPixmapItem(parent){
    QImage image("../ressources/textures/flag.png");
    QImage imageconv = image.scaled(150, 150, Qt::KeepAspectRatio);
    this->setPixmap(QPixmap::fromImage(imageconv));
}


GoalClass::~GoalClass(){

}