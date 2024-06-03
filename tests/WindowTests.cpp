#include "WindowTests.h"

void WindowTests::initTestCase() {
    current_widget = nullptr;

    mainWindow = new MainWindow();
    mainWindow->show();
}

void WindowTests::windowGenerationTest()
{
    QVERIFY(mainWindow != nullptr);
    QCOMPARE(mainWindow->windowTitle(), "Ninja Parkour");
}


void WindowTests::windowDeletionTest() {
    delete mainWindow;
    mainWindow = nullptr;
    QVERIFY(mainWindow==nullptr);
}