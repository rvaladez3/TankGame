#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsView>
#include "health.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    MainWindow * player1 = new MainWindow();

    player1->setRect(0,0,100,100);

    scene->addItem(player1);

    //make item focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();


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

    return a.exec();
}
