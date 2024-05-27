//
// Created by doria on 27/05/2022.
//

#ifndef CPP_QT_TPMINIPROJET_PLAYER_H
#define CPP_QT_TPMINIPROJET_PLAYER_H
#include "Entity.h"
#include <QKeyEvent>

class Player : public Entity{
public:

    bool isHitting = false;
    Player(QGraphicsItem* parent = nullptr);
    void update();
    void gravity();
    void jump();
    void animation();
    virtual ~Player();



};


#endif //CPP_QT_TPMINIPROJET_PLAYER_H
