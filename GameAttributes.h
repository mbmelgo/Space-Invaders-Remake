#ifndef GAMEATTRIBUTES_H
#define GAMEATTRIBUTES_H


class GameAttributes
{
    public:
        int page = 0;
        int score = 0;
        int bullets = 5;
        int pixelSize = 3;
        boolean gameOver = true;
        double speed = .08;
        int shootInterval = 2;
        int level = 1;
        int alienColor = 10;
        int firbarProgressColor = 10;
        int youWinColor = 10;
        int youLoseColor = 12;
        int cannonColor = 12;
        int menuColor = COLOR(64,224,208);
        int pointsPerKill = 5;
        int bulletsPerKill = 2;
        boolean menuSelected = true;
    protected:

    private:
};

#endif // GAMEATTRIBUTES_H
