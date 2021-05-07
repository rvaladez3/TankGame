#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "player.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include <QString>
#include "Health.h"
#include <QTimer>
#include "wall.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    void swap();
    void GameOver(int);

    QGraphicsScene * scene;
    Player * player1;
    Player * player2;
    int active = 1;
    Health * health;
    Wall * wall;
};


#endif // GAME_H
