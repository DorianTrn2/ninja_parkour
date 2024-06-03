#ifndef QT_PROJECT_TESTEX_H
#define QT_PROJECT_TESTEX_H


#include <QtTest/QtTest>
#include <QObject>

class TestEx : public QObject
{
Q_OBJECT

private slots:
    void test1();
    void test2();
};


#endif //QT_PROJECT_TESTEX_H
