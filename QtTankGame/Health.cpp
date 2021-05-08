#include "Health.h"
#include <QFont>
#include <QDebug>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //qDebug() << "Hi" << Qt::endl;
    //player starts with 100 hp
    health = 100;
    setPlainText(QString("Player1 HP: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    setPos(0,0);
}

void Health::decrease(){
    health = health - 20;
    setPlainText(QString("Player1 HP: ") + QString::number(health));
    qDebug() << health << Qt::endl;
}

int Health::getHealth(){
    return health;
}

