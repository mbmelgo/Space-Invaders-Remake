#ifndef MYTEXT_H
#define MYTEXT_H
#include <string>
#include "Alphabets.h"

class MyText
{
    public:
        Alphabets alphabets;
        void writeYouWin(int,int,int,int);
        void writeYouLose(int, int, int,int);
        void writePause(int, int, int,int);
        void writeGame(int, int, int,int);
        void writeOver(int, int, int,int);
        void writeGameOver(int, int, int,int);
        void writeSpace(int, int, int,int);
        void writeInvaders(int, int, int,int);
        void writeSpaceInvaders(int, int, int,int);
        void writeLevel(int, int, int, std::string,int);
        void writeLevelNumber(int, int, int, std::string,int);
        void writeLevelWord(int, int, int,int);
        void writeStart(int, int, int,bool,int);
        void writeInfo(int, int, int,bool,int);
    protected:

    private:
};

#endif // MYTEXT_H
