#ifndef PLAYER_H
#define PLAYER_H

//new code
#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();

};



//#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

//    void keyPressEvent(QKeyEvent *);

//    void mousePressEvent(QMouseEvent *);

//    void mouseMoveEvent(QMouseEvent *);

//private:
//    Ui::MainWindow *ui;
//    float lastX;
//    float lastY;
//};
#endif // PLAYER_H
