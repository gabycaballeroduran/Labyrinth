#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <QGraphicsRectItem>

class Movement: public QGraphicsRectItem{

// Movement with the arrow keys
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // MOVEMENT_H
