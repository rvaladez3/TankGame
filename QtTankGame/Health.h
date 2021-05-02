#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsSimpleTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent = 0);
    //update health for player
    //take inputs of how much damage was taken if any
    void decrease(int t1, int t2);

    //get health for player
    int getHealthT1();
    int getHealthT2();

private:
    int healthT1;
    int healthT2;
};

#endif // HEALTH_H
