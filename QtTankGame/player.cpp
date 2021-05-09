#include "player.h"
#include "game.h"
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
        QList<QGraphicsItem *> coll_items = collidingItems();
        for (int i=0, n=coll_items.size(); i<n; i++)
        {
            if (typeid(*(coll_items[i])) == typeid(Wall))
            {
                scene()->removeItem(coll_items[i]);

                game->swap();
            }
        }

    }

    if (event->key() == Qt::Key_S && pos().y() < 920) {
       setPos(x(),y()+10);
       QList<QGraphicsItem *> coll_items = collidingItems();
       for (int i=0, n=coll_items.size(); i<n; i++)
       {
           if (typeid(*(coll_items[i])) == typeid(Wall))
           {
               scene()->removeItem(coll_items[i]);
               game->swap();
           }
       }
    }

    if (event->key() == Qt::Key_A && pos().x() > 0) {
       setPos(x()-10,y());
        QList<QGraphicsItem *> coll_items = collidingItems();
       for (int i=0, n=coll_items.size(); i<n; i++)
       {
           if (typeid(*(coll_items[i])) == typeid(Wall))
           {
               scene()->removeItem(coll_items[i]);
               game->swap();
           }
       }
    }

    if (event->key() == Qt::Key_D && pos().x() < 1300){
       setPos(x()+10,y());
       QList<QGraphicsItem *> coll_items = collidingItems();
      for (int i=0, n=coll_items.size(); i<n; i++)
      {
          if (typeid(*(coll_items[i])) == typeid(Wall))
          {
              scene()->removeItem(coll_items[i]);
              game->swap();
          }
      }
    }

    if(event->key() == Qt::Key_Space){
        if (game->bulletExists == 0)
        {
            //create projectile and pass it velocity in pixels
            Projectile * bullet = new Projectile(55);
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


