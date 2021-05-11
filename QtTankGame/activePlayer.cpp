#include "activePlayer.h"
#include "game.h"
#include <QFont>
#include <QDebug>

extern Game * game;

ActivePlayer::ActivePlayer(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //qDebug() << "Health ID = " << id << Qt::endl;

    setDefaultTextColor(Qt::white);
    setFont(QFont("times",18,QFont::Bold));
}

void ActivePlayer::switchPlayer()
{
    if(game->active == 1){
        setPlainText(QString("Active Player: 1"));
    }
    else{
        setPlainText(QString("Active Player: 2"));
    }
}

