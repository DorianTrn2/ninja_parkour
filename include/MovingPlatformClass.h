#ifndef MOVINGPLATFORMCLASS_H
#define MOVINGPLATFORMCLASS_H

#include "PlatformClass.h"
#include <QTimer>

class MovingPlatformClass : public PlatformClass{
Q_OBJECT
public:
    MovingPlatformClass(qreal x, qreal y, qreal w, qreal h, qreal speed, qreal xmax, QGraphicsItem* parent = nullptr);

    ~MovingPlatformClass() override;
    void MovePlatform();

private:
    qreal m_speed;
    qreal m_xmax;
    qreal m_initialX;
};

#endif // MOVINGPLATFORMCLASS_H
