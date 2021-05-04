#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include "mainwindow.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    MainWindow * rect = new MainWindow();


    rect->setRect(0,0,100,100);

    scene->addItem(rect);

    //make item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    return a.exec();
}
