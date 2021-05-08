#include "player.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include "health.h"
#include "EnemyHealth.h"
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();

    Player * player1 = new Player();
    player1->setRect(0,0,100,100);
    scene->addItem(player1);


    Player * player2 = new Player();
    player2->setRect(0,0,100,100);
    scene->addItem(player2);

    Health * health = new Health();
    scene->addItem(health);


    EnemyHealth * enemyhealth = new EnemyHealth();
    scene->addItem(enemyhealth);


    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    //fixed scene
    view->setFixedSize(700,700);
    scene->setSceneRect(0,0,700,700);

    //left side
    player1->setPos(view->width()-view->width(),view->height()/2);

    //QObject::connect(,SIGNAL(timeout()),,SLOT(spawn()));
    //right side
    player2->setPos(view->width() - player1->rect().width(),view->height()/2);

    //make item focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFocus();


    //spawn enemies
    return a.exec();
}
