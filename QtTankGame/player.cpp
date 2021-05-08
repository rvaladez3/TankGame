#include "player.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Enemy.h"
#include "Health.h"

//new code
static int count;
int player_num;
Health * h;
Player::Player(QGraphicsItem *parent)
{
    spawn();
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


void Player::spawn()
{
    count++;
    player_num=count;
    h = new Health();

}

int Player::getHealth(){

    return h->getHealth();
}

void Player::decreaseHealth()
{
    h->decrease();
}
