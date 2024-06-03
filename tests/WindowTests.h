#ifndef WINDOWTESTS_H
#define WINDOWTESTS_H

#include <QtTest/QtTest>
#include <QObject>
#include "../include/MainWindow.h"

class WindowTests : public QObject
{
Q_OBJECT

private:
    MainWindow* mainWindow;
    QWidget* current_widget;


private slots:
    // Init
    void initTestCase();
    void windowGenerationTest();

    // Cleanup
    void windowDeletionTest();
};

#endif // WindowTests