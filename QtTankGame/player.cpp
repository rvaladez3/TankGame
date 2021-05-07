#include "player.h"
#include "game.h"
#include "Enemy.h"
#include "Health.h"
#include "Projectile.h"

#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>


extern Game * game;

int player_num;

Player::Player(QGraphicsItem *parent, int num)
{
    spawn(num);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W && pos().y() > 0) {
        setPos(x(),y()-10);
    }

    if (event->key() == Qt::Key_S && pos().y() < 600) {
       setPos(x(),y()+10);
    }

    if (event->key() == Qt::Key_A && pos().x() > 0) {
       setPos(x()-10,y());
    }

    if (event->key() == Qt::Key_D && pos().x() < 600){
       setPos(x()+10,y());
    }

    if(event->key() == Qt::Key_Space){
        Projectile * bullet = new Projectile();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}


void Player::spawn(int num)
{
    //count++;
    player_num = num;
    h = new Health();
    h->setID(num);
}

int Player::getHealth()
{
    return h->getHealth();
}

void Player::decrease()
{
    h->decrease();
}


