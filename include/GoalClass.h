//
// Created by doria on 29/05/2022.
//

#ifndef CPP_QT_TPMINIPROJET_GOALCLASS_H
#define CPP_QT_TPMINIPROJET_GOALCLASS_H
#include <QGraphicsItem>
#include <QBrush>

class GoalClass : public QGraphicsPixmapItem{
public:
    GoalClass(QGraphicsItem* parent = nullptr);
    virtual ~GoalClass();
};


#endif //CPP_QT_TPMINIPROJET_GOALCLASS_H
