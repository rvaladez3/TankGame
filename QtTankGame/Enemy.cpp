//#include "Enemy.h"
//#include <QTimer>
//#include <QGraphicsScene>
//#include <QList>
//#include <stdlib.h>//rand()


//Enemy::Enemy()
//{
//        setRect(0,0,100,100);
//        setPos(600,350);

//        int random_x = rand() & 300; //simply add 300 afterwards
//        int random_y = rand() & 700;//stay in range
//        //setPos(view->width()-view->width(),view->height()/2);
//        QTimer * timer = new QTimer();
//        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

//        timer->start(50);
//}

//void Enemy::move()
//{
//    //deletes object in the case that they're out of the object range
//    setPos(x()+5,y());
//    if (pos().x() < 0 || pos().x() > 700){
//        scene()->removeItem(this);
//        delete this;
//    }
//    else if (pos().y() < 0 || pos().y() > 700){
//        scene()->removeItem(this);
//        delete this;
//    }
//}
