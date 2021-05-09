#include "Projectile.h"
#include "game.h"
#include "player.h"
#include "Health.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

extern Game * game;

int velocity;

Projectile::Projectile(int v)
{
    velocity = v;

    QTimer * timer = new QTimer();

    game->bulletExists = 1;

    if (game->active == 1)
    {
        setPixmap((QPixmap(":/Images/projectile.png")));
        setPos(x(),y()+90);
        connect(timer, SIGNAL(timeout()), this, SLOT(move1()));
    }

    if (game->active == 2)
    {
        setPixmap((QPixmap(":/Images/projectileE.png")));
        setPos(x(),y()+90);
        connect(timer, SIGNAL(timeout()), this, SLOT(move2()));
    }

    timer->start(50);

}

void Projectile::move1()
{
    if (game->active == 1)
    {
        setPos(x()+10,y());

        QList<QGraphicsItem *> coll_items = collidingItems();

        for (int i=0, n=coll_items.size(); i<n; i++)
        {
            //qDebug() << (Player(coll_items[i])).getHealth() << Qt::endl;
            if (typeid(*(coll_items[i])) == typeid(Player))
            {
                game->player2->decrease();

                scene()->removeItem(this);
                delete this;
                game->bulletExists = 0;

                if (game->player2->getHealth() <= 0)
                {
                    game->GameOver(1);
                    break;
                }
                else
                    game->swap();
            }
            if (typeid(*(coll_items[i])) == typeid(Wall))
            {
                scene()->removeItem(coll_items[i]);
                scene()->removeItem(this);
                delete this;
                game->bulletExists = 0;
                game->swap();
            }
        }

        if (pos().x() > 1349){
            scene()->removeItem(this);
            delete this;
            game->bulletExists = 0;
            game->swap();
        }
    }

    velocity--;
    if (velocity < 1)
    {
        scene()->removeItem(this);
        delete this;
        game->bulletExists = 0;
        game->swap();
    }
}

void Projectile::move2()
{
    if (game->active == 2)
    {
        setPos(x()-10,y());

        QList<QGraphicsItem *> coll_items = collidingItems();

        for (int i=0, n=coll_items.size(); i<n; i++)
        {
            //qDebug() << (Player(coll_items[i])).getHealth() << Qt::endl;
            if (typeid(*(coll_items[i])) == typeid(Player))
            {
                game->player1->decrease();
                scene()->removeItem(this);
                delete this;
                game->bulletExists = 0;

                if (game->player1->getHealth() <= 0)
                {
                    game->GameOver(2);
                    break;
                }
                else
                    game->swap();
            }
            if (typeid(*(coll_items[i])) == typeid(Wall))
            {
                scene()->removeItem(coll_items[i]);
                scene()->removeItem(this);
                delete this;
                game->bulletExists = 0;
                game->swap();
            }
        }

        if (pos().x() < 0){
            scene()->removeItem(this);
            delete this;
            game->bulletExists = 0;
            game->swap();
        }

    }

    velocity--;
    if (velocity < 1)
    {
        scene()->removeItem(this);
        delete this;
        game->bulletExists = 0;
        game->swap();
    }


}
