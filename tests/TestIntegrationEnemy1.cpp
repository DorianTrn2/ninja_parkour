#include "TestIntegrationEnemy1.h"

void TestIntegrationEnemy1::testAddEnemy() {
    view = new QGraphicsView();
    scene = new MyScene(view);


    int initialCount = scene->items().size();

    scene->addEnemies(100, 100, 50, 150);

    QCOMPARE(scene->items().size(), initialCount+5); // entity + hitbox

}

void TestIntegrationEnemy1::testEnemyMovement() {
    Enemy1* enemy = new Enemy1(100, 100, 50, 150);
    scene->addItem(enemy);
    scene->enemies.push_back(enemy);

    QVERIFY(enemy != nullptr);

    for (int i = 0; i < 3; ++i) {
        enemy->update();
    }

    QVERIFY(enemy->x() != 100);
}

void TestIntegrationEnemy1::testPlayerKilledByEnemy() {

    Enemy1* enemy = new Enemy1(100, 100, 99, 101);
    scene->addItem(enemy);
    scene->enemies.push_back(enemy);

    scene->p1->setPos(100, 100);

    scene->update();

    QVERIFY(enemy != nullptr);
    QVERIFY(scene->p1->collidesWithItem(enemy));


}
