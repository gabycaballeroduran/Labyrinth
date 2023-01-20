#include "maze.h"

int** list = new int*[460];

int x_map = 460;
int y_map = 460;

int** maze::easy()
{
    for(int i = 0; i< x_map; i++) {
            list[i] = new int[x_map];
            for(int j = 0; j < y_map; j++){
                list[i][j] = (i+j);
            }
        }

     for(int x = 0; x< x_map; x=x+40){

         for(int y = 0; y< y_map; y =y+30){
             if((( y>0 && y<(y_map-1) && x>0 && x<(x_map-1) ) && (arc4random()%8<2))){
                 list[x][y] = 1;
             }
             else{
                 list[x][y] = -1;

             }
         }
     }
     return list;
}

int** maze::hard()
{
    for(int i = 0; i< x_map; i++) {
            list[i] = new int[x_map];
            for(int j = 0; j < y_map; j++){
                list[i][j] = (i+j);
            }
        }

     for(int x = 0; x< x_map; x=x+35){

         for(int y = 0; y< y_map; y =y+25){
             if((( y>0 && y<(y_map-1) && x>0 && x<(x_map-1) ) && (arc4random()%10<3))){
                 list[x][y] = 1;
             }
             else{
                 list[x][y] = -1;

             }
         }
     }
     return list;
}
