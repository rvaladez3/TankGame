#include "Projectile.h"
#include <QTimer>
#include <QGraphicsScene>


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
    if (pos().x() < 0 || pos().x() > 700){
        scene()->removeItem(this);
        delete this;
    }
    else if (pos().y() < 0 || pos().y() > 700){
        scene()->removeItem(this);
        delete this;
    }
}
