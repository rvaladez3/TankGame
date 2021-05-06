#include "Projectile.h"
#include "player.h"
#include "Health.h"
#include "EnemyHealth.h"
#include "ActivePlayer.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

Projectile::Projectile()
{
        setRect(100,0,50,10);
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(50);

}

void Projectile::move()
{
    //ActivePlayer* a = new ActivePlayer();

    //if (a->getActive() == 1)
    //{
        //EnemyHealth eh;

        setPos(x()+10,y());

        QList<QGraphicsItem *> coll_items = collidingItems();

        for (int i=0, n=coll_items.size(); i<n; i++)
        {
           qDebug() << ((Player*)(coll_items[i])->getHealth()) << endl;
            if (typeid(*(coll_items[i])) == typeid(Player))
            {

                //*coll_items[i]->decreaseHealth();
                //eh.decrease();
                //qDebug() << eh.getHealth() << endl;
                scene()->removeItem(this);
                delete this;

            }
        }

        if (pos().x() < 0 || pos().x() > 700){
            scene()->removeItem(this);
            delete this;
        }
        else if (pos().y() < 0 || pos().y() > 700){
            scene()->removeItem(this);
            delete this;
        }
   //}
}
