//
// Created by doria on 27/05/2022.
//

#ifndef CPP_QT_TPMINIPROJET_PLATFORMSCLASS_H
#define CPP_QT_TPMINIPROJET_PLATFORMSCLASS_H

#include <QGraphicsItem>
#include <QBrush>


class PlatformClass : public QObject, public QGraphicsRectItem {
Q_OBJECT
public:
    PlatformClass(qreal x = 0, qreal y = 0, qreal w = 0, qreal h = 0, QGraphicsItem *parent = nullptr);

    virtual ~PlatformClass();

    QRectF globalBoundingRect() {
        return mapRectToScene(boundingRect());
    }
};


#endif //CPP_QT_TPMINIPROJET_PLATFORMCLASS_H
