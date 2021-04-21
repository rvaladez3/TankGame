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
    float y = ui->label_2->y();
    float x = ui->label_2->x();
    float y_inc = 0.0;

    if (event->key() == Qt::Key_Up) {
        y_inc = -5.0f;
    }

    if (event->key() == Qt::Key_Down) {
        y_inc = +5.0f;
    }

    ui->label_2->move(QPoint(x, y + y_inc));
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

