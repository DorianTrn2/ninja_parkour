#include "../include/MyScene.h"

MyScene::MyScene(QGraphicsView* newView, QObject* parent) : QGraphicsScene(parent) {
    this->view = newView;
    QPixmap* platfo = new QPixmap("ressources/textures/brick2.png");
    this->platfor = new QBrush(*platfo);
    delete platfo;
    addPlatforms(-50,-300,50,1380);
    addPlatforms(0,500,1000,580);
    addPlatforms(1300,500,200,580);

    addPlatforms(2000,480,300,600);
    addPlatforms(2600,200,200,400);
    addPlatforms(2550,750,250,330);
    addPlatforms(2950, 650,50, 430);
    addPlatforms(3150,750,250,330);
    addPlatforms(3550, 650,50, 1080-650);
    addPlatforms(3850, 600,50, 1080-600);
    addPlatforms(4150, 550,50, 1080-550);
    addPlatforms(5000, 750, 1400, 1080-750);
    addPlatforms(5200, 650, 150, 1080-750);
    addPlatforms(6250, 650, 150, 1080-750);

    addPlatforms(6900, 600, 700, 1080-650);

    addPlatforms(7000, 220, 140,200);
    setupEnemies();



    addMovingPlatforms(450, 450, 100, 50, 2, 600);
    addMovingPlatforms(2400, 600, 100, 50, 3, 2600);
    addMovingPlatforms(3200, 550, 100, 20, 3, 3700);


    addSpikes(700, 500);
    addSpikes(2150, 480);
    addSpikes(7000, 600);

    vide = new VoidClass(0,1080, 10000, 300);
    QPixmap* videtext = new QPixmap("ressources/textures/black.png");
    QBrush* videbrush = new QBrush(*videtext);
    vide->setBrush(*videbrush);
    this->addItem(vide);

    end = new GoalClass();
    end->setPos(7500, 460);
    this->addItem(end);

    QImage image("ressources/ninja/idle/idle_1.png");
    QImage imageconv = image.scaled(100, 100, Qt::KeepAspectRatio).mirrored(true,false);
    this->p1 = new Player();
    this->p1->setPixmap(QPixmap::fromImage(imageconv));
    this->addItem(p1);
    p1->setPos(250,500);
    //p1->setPos(7300,500);



    this->timer = new QTimer(this);
    this->timer->start(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

}

void MyScene::update(){

    this->chrono += 5;
    if(gameOn) {

        if (p1->collidesWithItem(end)) {
            endGame();
        }

        movePlatforms();

        if(!this->enemies.isEmpty()){
            entitiesLogic();
        }

        if (p1->isAlive) {
            playerUpdate();
        }
        else if (gameOn) {
            deathMenu();
        }
        else {
            winMenu();
        }
    }
}

void MyScene::winMenu(){
    menu = new QGraphicsPixmapItem(QPixmap("ressources/textures/winmenu.png"));
    QPointF topLeft = view->mapToScene(0, 0);
    menu->setPos(topLeft.x() + 920/2,topLeft.y()+500/2);
    addItem(menu);
    QGraphicsTextItem* endtext = new QGraphicsTextItem(QString::number(this->chrono), menu);
    endtext->setPos(450, 70);
    QColor* col = new QColor(255,255,255);
    endtext->setDefaultTextColor(*col);
    delete col;
    endtext->setScale(10);
    timer->stop();
}

void MyScene::deathMenu(){
    menu = new QGraphicsPixmapItem(QPixmap("ressources/textures/deathmenu.png"));
    QPointF topLeft = view->mapToScene(0, 0);
    menu->setPos(topLeft.x() + 920/2,topLeft.y()+500/2);
    addItem(menu);
    gameOn = false;
    timer->stop();
}

void MyScene::playerUpdate(){
    p1->update();
    for (QGraphicsView *x : this->views()) {
        x->centerOn(p1);
    }
}

void MyScene::endGame(){
    p1->isAlive = false;
    this->gameOn = false;
}

void MyScene::movePlatforms(){
    for(MovingPlatformClass* temp : this->movingplatforms){
        temp->MovingPlatformClass::MovePlatform();
    }
}

void MyScene::entitiesLogic(){
    for(Enemy1* enem : this->enemies) {
        enem->update();
        if(p1->collidesWithItem(enem)){
            p1->isAlive = false;
        }
        if(this->Hit != nullptr){
            if(enem->collidesWithItem(Hit)) {
                killEnemy(enem);
            }
        }
    }
}

void MyScene::killEnemy(Enemy1* enem){
    enem->isAlive = false;
    this->removeItem(enem);
    enemies.removeOne(enem);
    delete enem;
}

void MyScene::setupEnemies(){
    addSlowEnemies(550, 450, 550, 550);
    addFastEnemies(5360,550, 5360, 5700);
    addSlowEnemies(5700,550, 5700, 6100);
}

void MyScene::addPlatforms(qreal x, qreal y, qreal w, qreal h){
    PlatformClass* plat = new PlatformClass(x, y, w, h);
    plat->setBrush(*platfor);
    plat->setPen(Qt::NoPen);
    this->platforms.push_back(plat);
    this->addItem(plat);
}

void MyScene::addMovingPlatforms(qreal x, qreal y, qreal w, qreal h, qreal speed, qreal xmax){
    MovingPlatformClass* plat = new MovingPlatformClass(x,y,w,h,speed,xmax);
    plat->setBrush(*platfor);
    plat->setPen(Qt::NoPen);
    this->platforms.push_back(plat);
    this->movingplatforms.push_back(plat);
    this->addItem(plat);
}

void MyScene::addSlowEnemies(qreal x, qreal y, qreal xmin, qreal xmax){
    Enemy1* ene = new Enemy1Slow(x,y,xmin, xmax);
    this->addItem(ene);
    this->enemies.push_back(ene);
}

void MyScene::addFastEnemies(qreal x, qreal y, qreal xmin, qreal xmax){
    Enemy1* ene = new Enemy1Fast(x,y,xmin, xmax);
    this->addItem(ene);
    this->enemies.push_back(ene);
}
void MyScene::addEnemies(qreal x, qreal y, qreal xmin, qreal xmax){
    addSlowEnemies(x,y,xmin,xmax);
}


void MyScene::addSpikes(qreal x, qreal y){
    SpikesClass* spik = new SpikesClass();
    spik->setPos(x,y-45);
    this->spikes.push_back(spik);
    this->addItem(spik);

}



void MyScene::keyPressEvent(QKeyEvent* event){

    switch (event->key()) {
        case Qt::Key_R:
            if (gameOn) break;
                this->removeItem(menu);
                delete menu;
                menu = nullptr;
                Respawn();
                gameOn = true;
            break;

        case Qt::Key_F:
            if (this->isHitting) break;
                this->hitTimer = new QTimer();
                this->hitTimer->start(200);
                this->isHitting = true;
                p1->isHitting = true;
                if (p1->lookingDirection) {
                    Hit = new QGraphicsRectItem(-160, -25, 100, 150, p1);
                } else {
                    Hit = new QGraphicsRectItem(60, -25, 100, 150, p1);
                }
                Hit->setOpacity(1);
                this->addItem(Hit);
                connect(hitTimer, SIGNAL(timeout()), this, SLOT(deleteHit()));
                break;

        case Qt::Key_Left:
        case Qt::Key_Q:
            p1->KeyLeft = true;
            p1->KeyRight = false;
            p1->animationTimer = 0;
            break;

        case Qt::Key_Right:
        case Qt::Key_D:
            p1->KeyRight = true;
            p1->KeyLeft = false;
            p1->animationTimer = 0;
            break;

        case Qt::Key_Up:
        case Qt::Key_Z:
            p1->KeyUp = true;
            p1->animationTimer = 0;
            p1->jump();
            break;

        case Qt::Key_Down:
        case Qt::Key_S:
            p1->KeyDown = true;
            break;

        default:
            break;
    }
}

void MyScene::deleteHit() {
    this->removeItem(Hit);
    delete this->hitTimer;
    delete this->Hit;
    this->Hit = nullptr;
    this->isHitting = false;
    p1->isHitting = false;
}
void MyScene::keyReleaseEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Left or event->key() == Qt::Key_Q){
        p1->KeyLeft = false;
    }

    if(event->key() == Qt::Key_Right or event->key() == Qt::Key_D){
        p1->KeyRight = false;

    }

    if(event->key() == Qt::Key_Up or event->key() == Qt::Key_Z){
        p1->KeyUp = false;
    }

    if(event->key() == Qt::Key_Down or event->key() == Qt::Key_S){
        p1->KeyDown = false;
    }
}

void MyScene::Respawn(){
    this->chrono = 0;
    delete this->p1;
    //qDebug() << enemies;

    for(Enemy1* enem : this->enemies){
        enem->isAlive = false;
        //qDebug() << enem;
        //qDebug() << enem->isAlive;
        this->removeItem(enem);
        enemies.pop_back();
        enem->update();

    }
    setupEnemies();
    QImage image("ressources/ninja/idle/idle_1.png");
    QImage imageconv = image.scaled(100, 100, Qt::KeepAspectRatio);
    this->p1 = new Player();
    this->p1->setPixmap(QPixmap::fromImage(imageconv));
    this->addItem(p1);
    p1->setPos(250,500);
    timer->start(33);
    this->chrono = 0 ;
}


MyScene::~MyScene() {
    for (QGraphicsItem *platform : this->platforms) {
        removeItem(platform);
        delete platform;
    }
    for (QGraphicsItem *spike : this->spikes) {
        removeItem(spike);
        delete spike;
    }
    for (Entity *e : this->enemies) {
        removeItem(e);
        delete e;
    }

    delete p1;
    delete timer;
    delete end;
    delete vide;
    delete platfor;
    delete menu;

}
