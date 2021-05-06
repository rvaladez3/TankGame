#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //player starts with 100 hp
    health = 100;
    setPlainText(QString("Player1 HP: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health = health - 20;
    setPlainText(QString("Player1 HP: ") + QString::number(health));

}

int Health::getHealth(){
    return health;
}
