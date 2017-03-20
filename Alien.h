#ifndef ALIEN_H
#define ALIEN_H

#include "MyPolygon.h"

class Alien
{
    public:
        MyPolygon polygon;
        int x, y, ctr, type;
        void drawAlien1(int,int,int,int);
        void drawAlien1var1(int,int,int,int);
        void drawAlien2(int,int,int,int);
        void drawAlien2var1(int,int,int,int);
        void drawDrestroyAlien(int,int,int,int);

    protected:

    private:
};

#endif // ALIEN_H
