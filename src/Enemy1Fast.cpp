//
// Created by doria on 01/06/2022.
//

#include "../include/Enemy1Fast.h"
#include <QDebug>
Enemy1Fast::Enemy1Fast(qreal x, qreal y, qreal xmin, qreal xmax, QGraphicsItem* parent) : Enemy1(x,y,xmin,xmax,parent){
    this->speed=13;
}


