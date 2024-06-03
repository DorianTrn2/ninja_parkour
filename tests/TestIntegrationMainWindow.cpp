#include "TestIntegrationMainWindow.h"

void TestIntegrationMainWindow::initTestCase() {
    mainWindow = new MainWindow();
    view = new QGraphicsView();
    scene = new MyScene(view);
    view->setScene(scene);
    mainWindow->setCentralWidget(view);
    mainWindow->show();
}

void TestIntegrationMainWindow::testMainWindowWithScene() {
    QTest::qWait(100);
    int initialCount = scene->items().count();

    scene->addItem(new GoalClass());
    scene->addItem(new PlatformClass(0, 0, 100, 20));
    scene->addItem(new SpikesClass());

    QCOMPARE(scene->items().count(), initialCount + 3);
}

//QTEST_MAIN(TestIntegrationMainWindow)
//#include "test_integration_mainwindow.moc"
