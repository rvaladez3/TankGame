#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>

class Projectile: public QGraphicsRectItem, public QObject{
    Q_OBJECT
public:
    Projectile();
public slots:
    void move();

};

#endif // PROJECTILE_H
