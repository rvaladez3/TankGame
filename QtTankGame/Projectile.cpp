#include "Projectile.h"
#include <QTimer>



Projectile::Projectile()
{
    setRect(0,0,50,10);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Projectile::move()
{
    setPos(x()+10,y());
}
