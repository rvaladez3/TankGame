#include "Projectile.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Projectile::Projectile()
{
        setRect(0,0,50,10);
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(50);

}

void Projectile::move()
{
    //deletes object in the case that they're out of the object range
    setPos(x()+10,y());

    QList<QGraphicsItem *> coll_items = collidingItems();
    for (int i=0, n=coll_items.size(); i<n; i++)
    {
        if (typeid(*(coll_items[i])) == typeid(Player))
        {
            /*
            if()
            scene()->removeItem(this);
            delete this;
            */
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
}
