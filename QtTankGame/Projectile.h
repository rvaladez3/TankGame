#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>

class Projectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile(int);
public slots:
    void move();


};

#endif // PROJECTILE_H
