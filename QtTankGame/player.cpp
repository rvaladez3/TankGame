#include "player.h"
#include "game.h"
#include "Health.h"
#include "Projectile.h"

#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPLayer>


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

    if (event->key() == Qt::Key_S && pos().y() < 950) {
       setPos(x(),y()+10);
    }

    if (event->key() == Qt::Key_A && pos().x() > 0) {
       setPos(x()-10,y());
    }

    if (event->key() == Qt::Key_D && pos().x() < 1300){
       setPos(x()+10,y());
    }

    if(event->key() == Qt::Key_Space){

        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/Sounds/Sheeeesh.mp3"));
        music->play();
        if (game->bulletExists == 0)
        {
            //create projectile and pass it velocity in pixels
            Projectile * bullet = new Projectile(40);
            if (game->active == 1)
                bullet->setPos(x()+100,y()+10);
            else
                bullet->setPos(x()-50,y()+10);
            scene()->addItem(bullet);
        }
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


