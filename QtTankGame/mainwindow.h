#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *);

    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
    float lastX;
    float lastY;
};
#endif // MAINWINDOW_H
