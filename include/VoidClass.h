//
// Created by doria on 28/05/2022.
//

#ifndef CPP_QT_TPMINIPROJET_VOIDCLASS_H
#define CPP_QT_TPMINIPROJET_VOIDCLASS_H
#include <QGraphicsItem>


class VoidClass : public QGraphicsRectItem{
public:
    VoidClass(qreal x=0, qreal y=0, qreal w=0, qreal h=0, QGraphicsItem* parent = nullptr);
    virtual ~VoidClass();
};


#endif //CPP_QT_TPMINIPROJET_VOIDCLASS_H
