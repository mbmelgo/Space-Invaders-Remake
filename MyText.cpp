#include "MyText.h"

using namespace std;

void MyText::writeYouWin(int x, int y, int inc, int color){
    alphabets.writeY(x,y,inc,0,color);
    alphabets.writeO(x,y,inc,1,color);
    alphabets.writeU(x,y,inc,2,color);
    alphabets.writeW(x,y,inc,3,color);
    alphabets.writeI(x,y,inc,4,color);
    alphabets.writeN(x,y,inc,5,color);
}

void MyText::writeYouLose(int x, int y, int inc, int color){
    alphabets.writeY(x,y,inc,0,color);
    alphabets.writeO(x,y,inc,1,color);
    alphabets.writeU(x,y,inc,2,color);
    alphabets.writeL(x,y,inc,3,color);
    alphabets.writeO(x,y,inc,4,color);
    alphabets.writeS(x,y,inc,5,color);
    alphabets.writeE(x,y,inc,6,color);
}

void MyText::writePause(int x, int y, int inc, int color){
    alphabets.writeP(x,y,inc,0,color);
    alphabets.writeA(x,y,inc,1,color);
    alphabets.writeU(x,y,inc,2,color);
    alphabets.writeS(x,y,inc,3,color);
    alphabets.writeE(x,y,inc,4,color);
}

void MyText::writeSpace(int x, int y, int inc, int color){
    alphabets.writeS(x,y,inc,0,color);
    alphabets.writeP(x,y,inc,1,color);
    alphabets.writeA(x,y,inc,2,color);
    alphabets.writeC(x,y,inc,3,color);
    alphabets.writeE(x,y,inc,4,color);
}

void MyText::writeInvaders(int x, int y, int inc, int color){
    alphabets.writeI(x,y+(8*inc),inc,0,color);
    alphabets.writeN(x,y+(8*inc),inc,1,color);
    alphabets.writeV(x,y+(8*inc),inc,2,color);
    alphabets.writeA(x,y+(8*inc),inc,3,color);
    alphabets.writeD(x,y+(8*inc),inc,4,color);
    alphabets.writeE(x,y+(8*inc),inc,5,color);
    alphabets.writeR(x,y+(8*inc),inc,6,color);
    alphabets.writeS(x,y+(8*inc),inc,7,color);
}

void MyText::writeSpaceInvaders(int x, int y, int inc, int color){
    writeSpace(x+(9*inc),y,inc,color);
    writeInvaders(x,y,inc,color);
}

void MyText::writeLevelNumber(int x, int y, int inc, string level, int color){
    for (int i = 0; i < level.size(); i++){
        char c = level.at(i);
        int digit = c - '0';
        if (digit == 0){
            alphabets.writeZero(x,y+(8*inc),inc,i,color);
        } else if (digit == 1){
            alphabets.writeOne(x,y+(8*inc),inc,i,color);
        } else if (digit == 2){
            alphabets.writeTwo(x,y+(8*inc),inc,i,color);
        } else if (digit == 3){
            alphabets.writeThree(x,y+(8*inc),inc,i,color);
        } else if (digit == 4){
            alphabets.writeFour(x,y+(8*inc),inc,i,color);
        } else if (digit == 5){
            alphabets.writeFive(x,y+(8*inc),inc,i,color);
        } else if (digit == 6){
            alphabets.writeSix(x,y+(8*inc),inc,i,color);
        } else if (digit == 7){
            alphabets.writeSeven(x,y+(8*inc),inc,i,color);
        } else if (digit == 8){
            alphabets.writeEight(x,y+(8*inc),inc,i,color);
        } else if (digit == 9){
            alphabets.writeNine(x,y+(8*inc),inc,i,color);
        }
    }
}

void MyText::writeLevelWord(int x, int y, int inc, int color){
    alphabets.writeL(x,y,inc,0,color);
    alphabets.writeE(x,y,inc,1,color);
    alphabets.writeV(x,y,inc,2,color);
    alphabets.writeE(x,y,inc,3,color);
    alphabets.writeL(x,y,inc,4,color);
}

void MyText::writeLevel(int x, int y, int inc, string level, int color){
    int tmp = x + 6*inc*2;
    tmp = tmp - ((level.size()-1)*inc*(6/level.size()));
    writeLevelNumber(tmp,y,inc,level,color);
    writeLevelWord(x,y,inc,color);
}

void MyText::writeGame(int x, int y, int inc, int color){
    alphabets.writeG(x,y,inc,0,color);
    alphabets.writeA(x,y,inc,1,color);
    alphabets.writeM(x,y,inc,2,color);
    alphabets.writeE(x,y,inc,3,color);
}

void MyText::writeOver(int x, int y, int inc, int color){
    alphabets.writeO(x,y+(8*inc),inc,0,color);
    alphabets.writeV(x,y+(8*inc),inc,1,color);
    alphabets.writeE(x,y+(8*inc),inc,2,color);
    alphabets.writeR(x,y+(8*inc),inc,3,color);
}

void MyText::writeGameOver(int x, int y, int inc, int color){
    writeGame(x,y,inc,color);
    writeOver(x,y,inc,color);
}

void MyText::writeStart(int x, int y, int inc, bool arrow, int color){
    if (arrow)
        alphabets.drawArrow(x-5,y,inc,0,color);
    alphabets.writeS(x,y,inc,1,color);
    alphabets.writeT(x,y,inc,2,color);
    alphabets.writeA(x,y,inc,3,color);
    alphabets.writeR(x,y,inc,4,color);
    alphabets.writeT(x,y,inc,5,color);
}

void MyText::writeInfo(int x, int y, int inc, bool arrow, int color){
    if (arrow)
        alphabets.drawArrow(x-5,y,inc,0,color);
    alphabets.writeI(x,y,inc,1,color);
    alphabets.writeN(x,y,inc,2,color);
    alphabets.writeF(x,y,inc,3,color);
    alphabets.writeO(x,y,inc,4,color);
}
