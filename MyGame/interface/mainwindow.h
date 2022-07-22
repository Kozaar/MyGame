#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include "../controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_newGame_clicked();

private:
    Ui::MainWindow *ui;
    Controller controller_;
    class Player;
    class Weapon;

    class Weapon {
    public:
        QGraphicsEllipseItem *showing;
        double positionX;
        double positionY;
        double sizeX;
        double sizeY;
        bool didFire;

        explicit Weapon(const Player& player);
    };

    class Player {
    public:
        QGraphicsEllipseItem *showing;
        Weapon *weapon;
        double positionX;
        double positionY;
        double sizeX;
        double sizeY;
        int directionX;
        int directionY;
        int team;

        explicit Player(int teams);
    };

    Player *player_;
    Player *ai_;

    void drawStartFiled();
    void keyPressEvent(QKeyEvent* event);
};

#endif // MAINWINDOW_H
