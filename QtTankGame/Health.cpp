#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    healthT1 = 100;
    healthT2 = 100;

    setPlainText(QString("Tank1 Health: ") + QString::number(healthT1));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

    setPlainText(QString("Tank2 Health: ") + QString::number(healthT2));

}

//if any health was
void Health::decrease(int t1, int t2)
{
    healthT1 = healthT1 - t1;
    healthT2 = healthT2 - t2;
}



int Health::getHealthT1()
{
    return healthT1;
}

int Health::getHealthT2()
{
    return healthT2;
}
