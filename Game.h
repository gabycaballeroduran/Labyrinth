#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "maze.h"
#include <QTimer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // constructors
    Game(QWidget* parent=NULL);

    // public methods
    //void displayMainMenu();

    // public attributes
    QGraphicsScene* scene;
    maze* m;
    QTimer * timer = new QTimer();
    QGraphicsTextItem *t;

public slots:
    void start();
    void startHard();
    void displayMainMenu();

private:
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void drawGUIHard();
    void Easy();
    void Hard();
};

#endif // GAME_H
