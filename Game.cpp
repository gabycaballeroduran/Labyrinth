#include "Game.h"
#include "Movement.h"
#include "QtCore/qelapsedtimer.h"
#include "maze.h"
#include "Button.h"
#include <QGraphicsTextItem>
#include <QTime>

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,500);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,500);
    setScene(scene);
}

void Game::start(){
    // clear the screen
    scene->clear();
    Easy();
    drawGUI();

    // create the play button for the Menu
    Button* menu = new Button(QString("Menu"));
    int bxPos2 =0;
    int byPos2 =100;
    menu->setPos(bxPos2,byPos2);
    connect(menu,SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(menu);

}

void Game::startHard(){
    // clear the screen
    scene->clear();
    Hard();
    drawGUI();

    // create the play button for the Menu
    Button* menu = new Button(QString("Menu"));
    int bxPos2 =0;
    int byPos2 =100;
    menu->setPos(bxPos2,byPos2);
    connect(menu,SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(menu);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::drawGUI(){
    // draw the left panel
    drawPanel(0,0,100,768,Qt::lightGray,1);

}


void Game::Easy(){
    drawPanel(0,15,500,768,Qt::white,1);
    //Player
    Movement * player = new Movement();

    player->setRect(0,0,10,10);
    player->setFlags(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setBrush(Qt::red);
    player->setPos(130,45);
    //Put player in the scene
    scene->addItem(player);

    //Maze
    m = new maze();
    int** elements = m->easy();
    for(int i = 30;i<460; i++){
        for(int j = 0;j<460; j++){
            if(elements[i][j] == 1){
                QGraphicsRectItem *item = new QGraphicsRectItem();
                item->setPos(i,j);
                item ->setBrush(Qt::black);
                item->setRect(0,0,5,40);
                scene->addItem(item);
            }

        }
    }
    for(int i = 0;i<460; i++){
        for(int j = 0;j<460; j++){
            if(elements[i][j] == 1){
                QGraphicsRectItem *item = new QGraphicsRectItem();
                item->setPos(j+10,i);
                item ->setBrush(Qt::black);
                item->setRect(0,0,40,5);
                scene->addItem(item);
            }

        }
    }

    //End
    QGraphicsRectItem * end = new QGraphicsRectItem();

    end->setRect(0,0,40,40);
    end->setBrush(Qt::blue);
    end->setPos(470,400);
    scene->addItem(end);

}

void Game::Hard(){
    drawPanel(0,15,500,768,Qt::white,1);
    //Player
    Movement * player = new Movement();

    player->setRect(0,0,10,10);
    player->setFlags(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setBrush(Qt::red);
    player->setPos(130,45);
    //Put player in the scene
    scene->addItem(player);

    //Maze
    m = new maze();
    int** elements = m->hard();
    for(int i = 30;i<460; i++){
        for(int j = 0;j<460; j++){
            if(elements[i][j] == 1){
                QGraphicsRectItem *item = new QGraphicsRectItem();
                item->setPos(i,j);
                item ->setBrush(Qt::black);
                item->setRect(0,0,5,28);
                scene->addItem(item);
            }

        }
    }
    for(int i = 0;i<460; i++){
        for(int j = 0;j<460; j++){
            if(elements[i][j] == 1){
                QGraphicsRectItem *item = new QGraphicsRectItem();
                item->setPos(j+10,i);
                item ->setBrush(Qt::black);
                item->setRect(0,0,28,5);
                scene->addItem(item);
            }

        }
    }

    //End
    QGraphicsRectItem * end = new QGraphicsRectItem();

    end->setRect(0,0,40,40);
    end->setBrush(Qt::blue);
    end->setPos(470,400);
    scene->addItem(end);

}

void Game::displayMainMenu(){
    scene->clear();
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Maze"));
    QFont titleFont("Comic Sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button for a Normal game
    Button* easy = new Button(QString("Easy"));
    int bxPos = this->width()/2 - easy->boundingRect().width()/2;
    int byPos = 245;
    easy->setPos(bxPos,byPos);
    connect(easy,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(easy);

    // create the play button for a Hard game
    Button* hard = new Button(QString("Hard"));
    int bxPos2 = this->width()/2 - hard->boundingRect().width()/2;
    int byPos2 =290;
    hard->setPos(bxPos2,byPos2);
    connect(hard,SIGNAL(clicked()),this,SLOT(startHard()));
    scene->addItem(hard);


}


