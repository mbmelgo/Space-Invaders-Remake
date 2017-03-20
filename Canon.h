#ifndef CANON_H
#define CANON_H

#include "MyPolygon.h"

class Canon
{
    public:
        MyPolygon polygon;
        void drawPlatform(int, int,int);
        void drawCanon(int, int, double,int);
        void drawPixel(int, int, int, int, int);

    protected:

    private:
};

#endif // CANON_H
