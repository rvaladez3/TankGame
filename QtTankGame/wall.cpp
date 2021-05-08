#include "wall.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

Wall::Wall(QGraphicsItem *parent){
    createline();
}

void Wall::createline(){
    setLine(0,0,0,9);

}
