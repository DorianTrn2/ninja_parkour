#include "../include/MainWindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->mainView = new QGraphicsView;
    this->mainScene = new MyScene(this->mainView);
    this->mainView->setScene(mainScene);

    //this->PlayerView = new QGraphicsView;
    //this->PlayerView->setScene(mainScene);
    //PlayerView->resize(300, 300);
    //PlayerView->show();

    this->setCentralWidget(mainView);
    this->centralWidget()->setStyleSheet(
            "border-image:url(\"../ressources/backt.png\") 0 0 0 0 stretch stretch;" );
    this->setWindowTitle("My main window");
    this->resize(1920, 1080);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);

}

MainWindow::~MainWindow(){

}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true);
    msgBox.exec();
}