#include "Canon.h"

void Canon::drawPlatform(int x, int y, int color){
    for(int i=0;i<30;i+=5){
        for(int j=0;j<40;j+=5){
            drawPixel(x,y,j,i,color);
        }
    }
}

void Canon::drawCanon(int x, int y, double angle,int color){
    polygon.rotateGun(x,y,angle,color);
}

void Canon::drawPixel(int tmpX, int tmpY,int incrementX, int incrementY, int color){
    polygon.drawSquare(tmpX+incrementX,tmpY+incrementY,5,color);
}
