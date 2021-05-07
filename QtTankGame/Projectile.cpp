#include "Projectile.h"
#include "game.h"
#include "player.h"
#include "Health.h"
#include "EnemyHealth.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

extern Game * game;

Projectile::Projectile()
{
    if (game->active == 1)
        setRect(100,0,50,10);

    if (game->active == 2)
        setRect(-50,0,50,10);

        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(50);

}

void Projectile::move()
{


    if (game->active == 1)
    {
        setPos(x()+10,y());

        QList<QGraphicsItem *> coll_items = collidingItems();

        for (int i=0, n=coll_items.size(); i<n; i++)
        {
           qDebug() << (Player(coll_items[i])).getHealth() << Qt::endl;
            if (typeid(*(coll_items[i])) == typeid(Player))
            {
                game->player2->decrease();
                //((Player)(coll_items[i])).decrease();
                //eh.decrease();
                //qDebug() << eh.getHealth() << endl;
                scene()->removeItem(this);
                delete this;
                game->swap();
            }
            if (typeid(*(coll_items[i])) == typeid(Wall))
            {
                //((Player)(coll_items[i])).decrease();
                //eh.decrease();
                //qDebug() << eh.getHealth() << endl;
                scene()->removeItem(this);
                delete this;
                game->swap();
            }
        }

        if (pos().x() < 0 || pos().x() > 700 || pos().y() < 0 || pos().y() > 700){
            scene()->removeItem(this);
            delete this;
            game->swap();
        }

    }

    if (game->active == 2)
    {
        setPos(x()-10,y());

        QList<QGraphicsItem *> coll_items = collidingItems();

        for (int i=0, n=coll_items.size(); i<n; i++)
        {
           qDebug() << (Player(coll_items[i])).getHealth() << Qt::endl;
            if (typeid(*(coll_items[i])) == typeid(Player))
            {
                game->player1->decrease();
                scene()->removeItem(this);
                delete this;
                game->swap();
            }
            if (typeid(*(coll_items[i])) == typeid(Wall))
            {
                //((Player)(coll_items[i])).decrease();
                //eh.decrease();
                //qDebug() << eh.getHealth() << endl;
                scene()->removeItem(this);
                delete this;
                game->swap();
            }
        }

        if (pos().x() < 0 || pos().x() > 700 || pos().y() < 0 || pos().y() > 700){
            scene()->removeItem(this);
            delete this;
            game->swap();
        }

    }
}
