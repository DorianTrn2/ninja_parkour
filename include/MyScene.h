#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsItem>
#include <QTimer>
#include <iostream>
#include <QList>
#include <QDebug>
#include <QLine>
#include <QVector>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDialogButtonBox>
#include <QPushButton>
#include <string>

#include "Entity.h"
#include "Player.h"
#include "PlatformClass.h"
#include "VoidClass.h"
#include "GoalClass.h"
#include "SpikesClass.h"
#include "MovingPlatformClass.h"
#include "Enemy1.h"




class MyScene : public QGraphicsScene {
    Q_OBJECT

public:
    VoidClass* vide;
    QVector<QGraphicsItem*> platforms;
    QVector<MovingPlatformClass*> movingplatforms;
    QVector<QGraphicsItem*> spikes;
    QVector<Enemy1*> enemies;
    Player* p1;
    QBrush* platfor;
    QGraphicsPixmapItem* menu;
    GoalClass* end;
    QGraphicsView* view;
    QTimer* hitTimer;
    QGraphicsRectItem* Hit = nullptr;
    bool isHitting = false;
    int chrono = 0;
    bool gameOn = true;
    void addPlatforms(qreal x, qreal y, qreal w, qreal h);
    void addMovingPlatforms(qreal x, qreal y, qreal w, qreal h, qreal speed, qreal xmax);
    void addEnemies(qreal x, qreal y, qreal xmin, qreal xmax);
    void addSpikes(qreal x, qreal y);
    void setupEnemies();
    MyScene(QGraphicsView* newView, QObject* parent = nullptr);
    void Respawn();
    virtual ~MyScene();

private:
    QTimer* timer;

protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

public slots:
    void update();
    void deleteHit();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
