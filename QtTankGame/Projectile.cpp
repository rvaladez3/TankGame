#include "Projectile.h"
#include <Qtimer>

Projectile::Projectile(){
    setRect(0,0,10,50);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Projectile::move(){

    setPos(x()+10,y());
}
