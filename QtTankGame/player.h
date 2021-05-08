#ifndef PLAYER_H
#define PLAYER_H

//new code
#include <QGraphicsRectItem>
#include <QObject>
#include "Health.h"


class Player: public QObject, public QGraphicsRectItem{

    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();

};

#endif
