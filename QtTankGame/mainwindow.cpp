#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

        float y_inc = 0.0;
        float x_inc = 0.0;

        float y1 = ui->label->y();
        float x1 = ui->label->x();

        float y2 = ui->label_2->y();
        float x2 = ui->label_2->x();

        bool player = false;

        if (event->key() == Qt::Key_Up) {
            y_inc = -5.0f;
            player = true;
        }

        if (event->key() == Qt::Key_Down) {
            y_inc = +5.0f;
            player = true;
        }

        if (event->key() == Qt::Key_Left) {
            x_inc = -5.0f;
            player = true;
        }

        if (event->key() == Qt::Key_Right) {
            x_inc = +5.0f;
            player = true;
        }

        ui->label_2->move(QPoint(x2 + x_inc, y2 + y_inc));

        if(player == false)
        {
            if (event->key() == Qt::Key_W) {
                y_inc = -5.0f;
            }

            if (event->key() == Qt::Key_S) {
                y_inc = +5.0f;
            }

            if (event->key() == Qt::Key_A) {
                x_inc = -5.0f;
            }

            if (event->key() == Qt::Key_D) {
                x_inc = +5.0f;
            }

            ui->label->move(QPoint(x1 + x_inc, y1 + y_inc));
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    lastX = event->x();
    lastY = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    float xAtRelease = event->x();
    float yAtRelease = event->y();

    float dx = xAtRelease - lastX;
    float dy = yAtRelease - lastY;

    float x = ui->label->x();
    float y = ui->label->y();

    ui->label->move(QPoint(x + dx, y + dy));

    lastX = event->x();
    lastY = event->y();

}

