#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>

class Projectile: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Projectile();
public slots:
    void move();




};

#endif // PROJECTILE_H
