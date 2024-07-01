//
// Created by doria on 01/06/2022.
//

#include "../include/Enemy1Slow.h"
#include <QDebug>
Enemy1Slow::Enemy1Slow(qreal x, qreal y, qreal xmin, qreal xmax, QGraphicsItem* parent) : Enemy1(x,y,xmin,xmax,parent){
    this->speed=6;
}

