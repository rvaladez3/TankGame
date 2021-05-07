#include "game.h"
#include <QBrush>



Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,700,700);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    setFixedSize(700,700);

    wall = new Wall();
    scene->addItem(wall);
    wall->setPos(350,350);

    //player 1
    player1 = new Player(0, 1);
    player1->setPixmap((QPixmap(":/Images/player.png")));
    //left side
    player1->setPos(0,350);
    scene->addItem(player1);

    //player2
    player2 = new Player(0, 2);
    player2->setPixmap((QPixmap(":/Images/enemy.png")));
    player2->setPos(450,350);
    scene->addItem(player2);

    //make item focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);


    //health
    //health = new Health();
    scene->addItem((player1->h));
    (player1->h)->setPos(0,0);

    //enemyhealth
    scene->addItem((player2->h));
    (player2->h)->setPos(540,0);

    //set inital focus
    player1->setFocus();

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

}

void Game::GameOver(int id)
{
    scene->clear();

    QString str = "Game Over!\nPlayer ";
    str += ((char)(id + '0'));
    str += " Wins!";

    QGraphicsTextItem *text = scene->addText(str);
    //text->setTextWidth(300);
    text->setPos(300, 300);

    qDebug() << "Game Over message displayed" << Qt::endl;

}
