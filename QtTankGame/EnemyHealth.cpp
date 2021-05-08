#include "EnemyHealth.h"
#include <QFont>
#include<QGraphicsItem>


EnemyHealth::EnemyHealth(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    //player starts with 100 hp
    health = 100;
    setPlainText(QString("Player2 HP: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    setPos(540,0);

}

void EnemyHealth::decrease(){
    health = health - 20;
    setPlainText(QString("Player2 HP: ") + QString::number(health));

}

int EnemyHealth::getHealth(){
    return health;
}
