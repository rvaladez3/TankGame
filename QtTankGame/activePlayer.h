#ifndef ACTIVEPLAYER_H
#define ACTIVEPLAYER_H

#include <QGraphicsTextItem>

class ActivePlayer: public QGraphicsTextItem{
public:
    ActivePlayer(QGraphicsItem * parent=0);
    void switchPlayer();

};


#endif // ACTIVEPLAYER_H
