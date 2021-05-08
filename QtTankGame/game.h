#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "Health.h"
#include "EnemyHealth.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Player * player1;
    Player * player2;
    Health * health;
    EnemyHealth * enemyhealth;
};


#endif // GAME_H
