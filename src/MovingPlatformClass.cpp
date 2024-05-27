//
// Created by doria on 01/06/2022.
//
#include "../include/MovingPlatformClass.h"

MovingPlatformClass::MovingPlatformClass(qreal x, qreal y, qreal w, qreal h, qreal speed, qreal xmax, QGraphicsItem* parent)
        : PlatformClass(x, y, w, h, parent), m_speed(speed), m_xmax(xmax), m_initialX(x) {
}

MovingPlatformClass::~MovingPlatformClass() {
    delete this;
}

void MovingPlatformClass::MovePlatform() {
    qreal newX = x() + m_speed;

    if (newX < m_initialX) {
        newX = m_initialX;
        m_speed = -m_speed;
    } else if (newX + boundingRect().width() > m_xmax) {
        newX = m_xmax - boundingRect().width();
        m_speed = -m_speed;
    }

    setX(newX);
}
