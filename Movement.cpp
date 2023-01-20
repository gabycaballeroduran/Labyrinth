#include "Movement.h"
#include <QKeyEvent>

// Movement
void Movement::keyPressEvent(QKeyEvent *event){
   if(event->key() == Qt::Key_Left){
       setPos(x()-5,y());
   }
   else if(event->key() == Qt::Key_Right){
       setPos(x()+5,y());
   }
   else if(event->key() == Qt::Key_Up){
       setPos(x(),y()-5);
   }
   else if(event->key() == Qt::Key_Down){
       setPos(x(),y()+5);
   }
}
