
#include "TestIntegrationMyScene.h"

void TestIntegrationMyScene::initTestCase() {
    view = new QGraphicsView();
    scene = new MyScene(view);
}


void TestIntegrationMyScene::testAddGoal() {
    int initialCount = scene->items().count();
    GoalClass *goal = new GoalClass();
    scene->addItem(goal);
    QCOMPARE(scene->items().count(), initialCount + 1);
}

void TestIntegrationMyScene::testAddPlatform() {
    int initialCount = scene->items().count();
    PlatformClass *platform = new PlatformClass(0, 0, 100, 20);
    scene->addItem(platform);
    QCOMPARE(scene->items().count(), initialCount + 1);
}

void TestIntegrationMyScene::testAddSpikes() {
    int initialCount = scene->items().count();
    SpikesClass *spikes = new SpikesClass();
    scene->addItem(spikes);
    QCOMPARE(scene->items().count(), initialCount + 1);
}


//QTEST_MAIN(TestIntegrationMyScene)
//#include "test_integration_myscene.moc"