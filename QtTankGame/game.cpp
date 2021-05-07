#include "game.h"
#include "player.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include "Health.h"
#include "EnemyHealth.h"
#include <QTimer>


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,700,700);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setFixedSize(700,700);

    //player 1
    player1 = new Player();
    player1->setRect(0,0,100,100);
    //left side
    player1->setPos(0,350);
    scene->addItem(player1);

    //player2
    player2 = new Player();
    player2->setRect(0,0,100,100);
    player2->setPos(600,350);
    scene->addItem(player2);

    //make item focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);


    //health
    health = new Health();
    scene->addItem(health);
    health->setPos(0,0);

    //enemyhealth
    enemyhealth = new EnemyHealth();
    scene->addItem(enemyhealth);
    enemyhealth->setPos(540,0);


    player2->setFocus();

    show();
}

void Game::swap()
{
    if (active == 1)
        active = 2;
    else
        active = 1;
}
