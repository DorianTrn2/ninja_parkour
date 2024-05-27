//
// Created by doria on 01/06/2022.
//

#ifndef CPP_QT_TPMINIPROJET_ENEMY1_H
#define CPP_QT_TPMINIPROJET_ENEMY1_H
#include "Entity.h"

#include <QKeyEvent>


class Enemy1 : public Entity{
public:
    qreal xmax;
    qreal xmin;
    Enemy1(qreal x, qreal y, qreal xmin, qreal xmax, QGraphicsItem* parent = nullptr);
    void update();
    void KeyChange();
    void animation();
    virtual ~Enemy1();
};


#endif //CPP_QT_TPMINIPROJET_ENEMY1_H
