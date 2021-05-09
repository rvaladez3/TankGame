#include "wall.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineF>
#include <QRandomGenerator>

Wall::Wall(QGraphicsItem *parent):QGraphicsLineItem(parent){
    createline();
    QPen pen(Qt::red, 10);
    setPen(pen);
}

void Wall::createline(){

     w = QRandomGenerator::global()->bounded(50,400);
     x = QRandomGenerator::global()->bounded(50,800);
     y = QRandomGenerator::global()->bounded(50,400);
     z = QRandomGenerator::global()->bounded(50,800);

     setLine(w,x,y,z);
     line();


}
