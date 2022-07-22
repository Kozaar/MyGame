#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene;
    player_ = new Player(1);
    ai_ = new Player(2);
    this->ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(ui->graphicsView->width()/2, ui->graphicsView->height()/2);
    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width()-10, ui->graphicsView->height()-10);
    drawStartFiled();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_newGame_clicked() {

}

void MainWindow::drawStartFiled() {
    this->ui->graphicsView->scene()->addRect(100, 100, 40, 60, QPen(Qt::darkBlue), QBrush(Qt::red));
    this->ui->graphicsView->scene()->addItem(this->player_->showing);
    this->ui->graphicsView->scene()->addItem(this->player_->weapon->showing);
    this->ui->graphicsView->scene()->addItem(this->ai_->showing);
    this->ui->graphicsView->scene()->addItem(this->ai_->weapon->showing);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        ui->graphicsView->scene()->addLine(50, 50, 300, 300);
    }
}


MainWindow::Weapon::Weapon(const Player& player) {
    this->didFire = false;
    this->sizeX = 6;
    this->sizeY = 6;
    this->positionX = player.positionX + (player.sizeX / 2 * player.directionX) +
            (player.sizeX / 2 * player.directionX) - this->sizeX / 2;
    this->positionY = player.positionY + (player.sizeY / 2 * player.directionY) -
            (player.sizeY / 2 * player.directionY) + player.sizeY / 2 - this->sizeY / 2;
    this->showing = new QGraphicsEllipseItem(this->positionX, this->positionY, this->sizeX, this->sizeY);
    this->showing->setBrush(QBrush(Qt::darkBlue));
}

MainWindow::Player::Player(int teams) {
    this->team = teams;
    this->sizeX = 20;
    this->sizeY = 20;
    if (teams == 1) {
        this->positionX = 500;
        this->positionY = 50;
        this->directionX = 0;
        this->directionY = 0;
        this->showing = new QGraphicsEllipseItem(this->positionX, this->positionY,
                                             this->sizeX, this->sizeY);
        this->showing->setBrush(QBrush(Qt::green));
    } else {
        this->positionX = 50;
        this->positionY = 400;
        this->directionX = 1;
        this->directionY = 1;
        this->showing = new QGraphicsEllipseItem(this->positionX, this->positionY,
                                             this->sizeX, this->sizeY);
        this->showing->setBrush(QBrush(Qt::red));
    }
    this->weapon = new Weapon(*this);
}
