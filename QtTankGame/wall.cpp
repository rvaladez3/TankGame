#include "wall.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineF>

Wall::Wall(QGraphicsItem *parent):QGraphicsLineItem(parent){
    createline();
}

void Wall::createline(){
     setLine(0,-250,0,250);
     line();


}
