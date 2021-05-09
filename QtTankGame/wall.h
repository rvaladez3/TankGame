#ifndef WALL_H
#define WALL_H
#include <QGraphicsLineItem>


class Wall: public QObject, public QGraphicsLineItem{
    Q_OBJECT;
public:
  Wall(QGraphicsItem * parent = 0);

  void createline();
  int w,x,y,z;
};

#endif // WALL_H
