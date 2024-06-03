#include <QtTest/QtTest>
#include <QApplication>
#include "WindowTests.h"
#include "UnitTesting.h"
#include "TestIntegrationMainWindow.h"
#include "TestIntegrationMyScene.h"
#include "TestIntegrationEnemy1.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    int status = 0;
    std::cout<<"START TEST MODULES"<<std::endl;
    status |= QTest::qExec(new WindowTests, argc, argv);
    status |= QTest::qExec(new UnitTesting, argc, argv);
    status |= QTest::qExec(new TestIntegrationMainWindow, argc, argv);
    status |= QTest::qExec(new TestIntegrationMyScene, argc, argv);
    status |= QTest::qExec(new TestIntegrationEnemy1, argc, argv);

    std::cout<<"END TEST MODULES"<<std::endl;

    return status;
}