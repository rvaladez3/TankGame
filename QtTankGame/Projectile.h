#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>

class Projectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile(int);
public slots:
    void move1();
    void move2();


};

#endif // PROJECTILE_H
