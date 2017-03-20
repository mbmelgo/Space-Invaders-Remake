#ifndef MYPOLYGON_H
#define MYPOLYGON_H


class MyPolygon
{
    public:
        void drawRightTriangle(int, int, int, int);
        void drawReverseRightTriangle(int, int, int, int);
        void drawSquare(int, int, int, int);
        void rotateGun(int, int, double, int);
        void drawPixel(int, int, int, int, int, int);
        void drawFireBar(int, int);
        void drawFireBarProgress(int, int, double, int);
    protected:

    private:
};

#endif // MYPOLYGON_H
