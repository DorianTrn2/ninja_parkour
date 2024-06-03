#include "UnitTesting.h"


void UnitTesting::initTestCase() {
    view = new QGraphicsView();
    scene = new MyScene(view);
}



void UnitTesting::testInitialization() {
    QVERIFY(scene->p1 != nullptr);

    QVERIFY(scene->items().size() > 0);
}

void UnitTesting::testAddPlatforms() {
    int initialCount = scene->items().size();
    scene->addPlatforms(100, 100, 50, 50);
    QVERIFY(scene->items().size() == initialCount + 1);
}

void UnitTesting::testKeyPressEvents() {
    QKeyEvent leftPress(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    QKeyEvent leftRelease(QEvent::KeyRelease, Qt::Key_Left, Qt::NoModifier);
    QKeyEvent rightPress(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    QKeyEvent rightRelease(QEvent::KeyRelease, Qt::Key_Right, Qt::NoModifier);
    QKeyEvent jumpPress(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    QKeyEvent jumpRelease(QEvent::KeyRelease, Qt::Key_Up, Qt::NoModifier);


    QCoreApplication::sendEvent(scene, &leftPress);
    QVERIFY(scene->p1->KeyLeft);
    QVERIFY(!scene->p1->KeyRight);

    QCoreApplication::sendEvent(scene, &leftRelease);
    QVERIFY(!scene->p1->KeyLeft);

    QCoreApplication::sendEvent(scene, &rightPress);
    QVERIFY(scene->p1->KeyRight);
    QVERIFY(!scene->p1->KeyLeft);

    QCoreApplication::sendEvent(scene, &rightRelease);
    QVERIFY(!scene->p1->KeyRight);

    QCoreApplication::sendEvent(scene, &jumpPress);
    QVERIFY(scene->p1->KeyUp);

    QCoreApplication::sendEvent(scene, &jumpRelease);
    QVERIFY(!scene->p1->KeyUp);

}


//#include "test_myscene.moc"