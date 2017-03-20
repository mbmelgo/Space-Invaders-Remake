#ifndef FIREBAR_H
#define FIREBAR_H

#include "MyPolygon.h"

class FireBar
{
    public:
        MyPolygon poly;
        void drawFireBar(int, int);
        void drawFireBarProgress(int, int, double,int);

    protected:

    private:
};

#endif // FIREBAR_H
