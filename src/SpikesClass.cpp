//
// Created by doria on 31/05/2022.
//

#include "../include/SpikesClass.h"

SpikesClass::SpikesClass(QGraphicsItem* parent) : QGraphicsPixmapItem(parent){
    QImage image("../ressources/textures/spikes.png");
    QImage imageconv = image.scaled(200, 50, Qt::KeepAspectRatio);
    this->setPixmap(QPixmap::fromImage(imageconv));
}


SpikesClass::~SpikesClass(){

}