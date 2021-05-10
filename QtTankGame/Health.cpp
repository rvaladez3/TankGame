#include "Health.h"
#include "game.h"
#include <QFont>
#include <QDebug>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //player starts with 100 hp
    health = 100;

    //qDebug() << "Health ID = " << id << Qt::endl;

    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16,QFont::Bold));
    //setPos(0,0);
}

void Health::decrease(){
    //if(health == 20){
     //health = 100;
     //setPlainText(QString("Player1 HP: \n") + QString::number(health));}
   //else{
    health = health - 20;
    if (id == 1)
        setPlainText(QString("Player1 HP: \n") + QString::number(health));
    else if (id == 2)
        setPlainText(QString("Player2 HP: \n") + QString::number(health));
    //qDebug() << health << Qt::endl;
    //}
}

int Health::getHealth(){
    return health;
}

void Health::setID(int num)
{
    //attach this health object to it's player
    id = num;

    //intialize player health on screen
    if (id == 1)
        setPlainText(QString("Player1 HP: \n") + QString::number(health));
    else if (id == 2)
        setPlainText(QString("Player2 HP: \n") + QString::number(health));

    //qDebug() << "ID after setting = " << id << Qt::endl;
}

