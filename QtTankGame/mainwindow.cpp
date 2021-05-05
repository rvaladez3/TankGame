#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "Projectile.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

//new code

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up && pos().y() > 0) {
        setPos(x(),y()-10);
    }

    if (event->key() == Qt::Key_Down && pos().y() < 600) {
       setPos(x(),y()+10);
    }

    if (event->key() == Qt::Key_Left && pos().x() > 0) {
       setPos(x()-10,y());
    }

    if (event->key() == Qt::Key_Right && pos().x() < 600){
       setPos(x()+10,y());
    }

    if(event->key() == Qt::Key_Space){
        Projectile * bullet = new Projectile();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        //qDebug() << "Bullet Created";
    }

}



//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//        float y_inc = 0.0;
//        float x_inc = 0.0;

//        float y1 = ui->label->y();
//        float x1 = ui->label->x();

//        float y2 = ui->label_2->y();
//        float x2 = ui->label_2->x();

//        bool player = false;



//        //label_2
//        if (event->key() == Qt::Key_Up && y2 > 10) {
//            y_inc = -5.0f;
//            player = true;
//        }

//        if (event->key() == Qt::Key_Down && y2 < 530) {
//            y_inc = +5.0f;
//            player = true;
//        }
//        //can't move past mid point
//        if (event->key() == Qt::Key_Left && x2 > 530) {
//            x_inc = -5.0f;
//            player = true;
//        }

//        if (event->key() == Qt::Key_Right && x2 < 1000) {
//            x_inc = +5.0f;
//            player = true;
//        }

//        if(event->key() == Qt::Key_Space){
//            Projectile * projectile = new Projectile();
//            qDebug() <<"Projectile created";
//            projectile->setPos(ui->label_2->x(),ui->label_2->y());
//            //scene->addItem(projectile);
//        }

//        ui->label_2->move(QPoint(x2 + x_inc, y2 + y_inc));

//        if(player == false)
//        {
//        //label
//        if (event->key() == Qt::Key_W && y1 > 10) {
//            y_inc = -5.0f;
//        }

//        if (event->key() == Qt::Key_S && y1 < 530) {
//            y_inc = +5.0f;
//        }

//        if (event->key() == Qt::Key_A && x1 > 10) {
//            x_inc = -5.0f;
//        }
//        //cant move past mid point
//        if (event->key() == Qt::Key_D && x1 < 470) {
//            x_inc = +5.0f;
//        }

//            ui->label->move(QPoint(x1 + x_inc, y1 + y_inc));
//        }
//}

//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//    lastX = event->x();
//    lastY = event->y();
//}

//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    float xAtRelease = event->x();
//    float yAtRelease = event->y();

//    float dx = xAtRelease - lastX;
//    float dy = yAtRelease - lastY;

//    float x = ui->label->x();
//    float y = ui->label->y();

//    ui->label->move(QPoint(x + dx, y + dy));

//    lastX = event->x();
//    lastY = event->y();

//}



