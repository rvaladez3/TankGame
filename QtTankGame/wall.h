#ifndef WALL_H
#define WALL_H
#include <QGraphicsLineItem>


class Wall: public QObject, public QGraphicsLineItem{
    QObject;
public:
  Wall(QGraphicsItem * parent = 0);

  void createline();
};

#endif // WALL_H
