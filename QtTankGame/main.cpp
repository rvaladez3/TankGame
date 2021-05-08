#include "player.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include "health.h"
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();

    Player * player1 = new Player();
    player1->setRect(0,0,100,100);
    scene->addItem(player1);

    //make item focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    Health * health = new Health();
    scene->addItem(health);


    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    //fixed scene
    view->setFixedSize(700,700);
    scene->setSceneRect(0,0,700,700);

    //left side
    player1->setPos(view->width()-view->width(),view->height()/2);

    //right side
    //player1->setPos(view->width() - player1->rect().width(),view->height()/2);


    //spawn enemies
    return a.exec();
}
