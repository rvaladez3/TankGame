#include "game.h"
#include <QBrush>
#include <QTimer>
#include <QFont>
#include <QRandomGenerator>


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1400,1000);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(QBrush(QImage(":/Images/baby.jpg")));



    setFixedSize(1400,1000);



    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(700,525);
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));
    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(QRandomGenerator::global()->bounded(50,900),QRandomGenerator::global()->bounded(-100,400));



    //player 1
    player1 = new Player(0, 1);
    player1->setPixmap((QPixmap(":/Images/player.png")));
    //left side
    player1->setPos(0,525);
    scene->addItem(player1);

    //player2
    player2 = new Player(0, 2);
    player2->setPixmap((QPixmap(":/Images/enemy.png")));
    player2->setPos(1300,525);
    scene->addItem(player2);

    //make item focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);


    //health
    //health = new Health();
    scene->addItem((player1->h));
    (player1->h)->setPos(300,0);

    //enemyhealth
    scene->addItem((player2->h));
    (player2->h)->setPos(950,0);

    int playerStart = QRandomGenerator::global()->bounded(0,2);
    if(playerStart == 0)
        player1->setFocus();
    else
        player2->setFocus();

    //sets time limit for each turn
    playerTimer = new QTimer();
    connect(playerTimer, SIGNAL(timeout()), this, SLOT(swap()));

    playerTimer->start(30000);

    show();
}

void Game::swap()
{
    if (active == 1)
    {
        active = 2;
        player2->setFocus();
    }
    else
    {
        active = 1;
        player1->setFocus();
    }
    playerTimer->start(30000);
}

void Game::GameOver(int id)
{
    scene->clear();
    qDebug() << "Displaying Game Over message" << Qt::endl;


    QString str;

    if (id == 1)
        str = "Game Over!\nPlayer 1 Wins!";
    else
        str = "Game Over!\nPlayer 2 Wins!";

    QGraphicsTextItem *text = scene->addText(str);
    //text->setTextWidth(300);
    text->setPos(700, 525);

    qDebug() << "Game Over message displayed" << Qt::endl;
}

