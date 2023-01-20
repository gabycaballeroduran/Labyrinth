#include <QApplication>
#include <QGraphicsRectItem>
#include "Game.h"
#include "Movement.h"
#include <QGraphicsView>
#include "maze.h"


int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

        Game *game = new Game();
        game->show();
        game->displayMainMenu();

        return a.exec();
}
