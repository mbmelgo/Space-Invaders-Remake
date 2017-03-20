#include<graphics.h>
#include<math.h>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>  // mciSendString()
#include <conio.h>

//----Custom Classes-------
#include "MyPolygon.h"
#include "Bullet.h"
#include "Alien.h"
#include "Canon.h"
#include "Alphabets.h"
#include "MyText.h"
#include "GameAttributes.h"
#include "FireBar.h"

using namespace std;


class VectorContainer{
    public:
        vector<Bullet> bullets;
        vector<Alien> aliens;
};

void moveAlien(Alien alien,int x, int y, int type, int pixelSize, int color,int position){
    if (type == 0){
        if(position==0){
            alien.drawAlien1(x, y, pixelSize,color);
        }else if(position==1){
            alien.drawAlien1var1(x, y, pixelSize,color);
        }
    } else if (type == 1){
        if(position==0){
            alien.drawAlien2(x, y, pixelSize,color);
        }else if(position==1){
            alien.drawAlien2var1(x, y, pixelSize,color);
        }
    } else if(type == -1){
        alien.drawDrestroyAlien(x, y, pixelSize,color);
    }
}

vector<Alien> addAlien(vector<Alien> aliens, int pixelSize){
    Alien alien;
    int y = 10;
    int x;
    for(int j=0, ctr=0;j<2;j++){
        int type = j%2;
        x = 50;
        for(int i=0; i<5;i++,ctr++){
            alien.x = x;
            alien.y = y;
            alien.ctr = ctr;
            alien.type = type;
            aliens.push_back(alien);
            x = x + pixelSize*12;
        }
        y = y + pixelSize*10;
    }
    return aliens;
}

vector<Bullet> checkBullets(vector<Bullet> bullets){
    for(int b = 0; b<bullets.size();b++){
        int bx1 = bullets[b].x - 2;
        int by1 = bullets[b].y - 5;
        int bx2 = bullets[b].x + 2;
        int by2 = bullets[b].y - 5;
        if(bx1 < 0 || bx1 > 640 || by1 < 0 || by2 < 0){
            bullets.erase (bullets.begin()+b);
        }
    }
    return bullets;
}

VectorContainer checkCollision(VectorContainer vectorContainer, int pixelSize){
    for(int b = 0; b<vectorContainer.bullets.size();b++){
        int newX1 = vectorContainer.bullets[b].x - 5;
        int newY1 = vectorContainer.bullets[b].y;
        int newX2 = vectorContainer.bullets[b].x + 5;
        int newY2 = vectorContainer.bullets[b].y;
        int newX3 = vectorContainer.bullets[b].x - 5;
        int newY3 = vectorContainer.bullets[b].y + 10;
        int newX4 = vectorContainer.bullets[b].x + 5;
        int newY4 = vectorContainer.bullets[b].y + 10;

        int bx1 = cos(vectorContainer.bullets[b].angle) * (newX1 - vectorContainer.bullets[b].x) - sin(vectorContainer.bullets[b].angle) * (newY1 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].x;
        int by1 = sin(vectorContainer.bullets[b].angle) * (newX1 - vectorContainer.bullets[b].x) + cos(vectorContainer.bullets[b].angle) * (newY1 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].y;
        int bx2 = cos(vectorContainer.bullets[b].angle) * (newX2 - vectorContainer.bullets[b].x) - sin(vectorContainer.bullets[b].angle) * (newY2 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].x;
        int by2 = sin(vectorContainer.bullets[b].angle) * (newX2 - vectorContainer.bullets[b].x) + cos(vectorContainer.bullets[b].angle) * (newY2 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].y;
        int bx3 = cos(vectorContainer.bullets[b].angle) * (newX3 - vectorContainer.bullets[b].x) - sin(vectorContainer.bullets[b].angle) * (newY3 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].x;
        int by3 = sin(vectorContainer.bullets[b].angle) * (newX3 - vectorContainer.bullets[b].x) + cos(vectorContainer.bullets[b].angle) * (newY3 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].y;
        int bx4 = cos(vectorContainer.bullets[b].angle) * (newX4 - vectorContainer.bullets[b].x) - sin(vectorContainer.bullets[b].angle) * (newY4 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].x;
        int by4 = sin(vectorContainer.bullets[b].angle) * (newX4 - vectorContainer.bullets[b].x) + cos(vectorContainer.bullets[b].angle) * (newY4 - vectorContainer.bullets[b].y) + vectorContainer.bullets[b].y;
//
//        line(bx1, by1, bx2, by2);
//        line(bx1, by1, bx3, by3);
//        line(bx2, by2, bx4, by4);
//        line(bx3, by3, bx4, by4);
        for(int a = 0; a<vectorContainer.aliens.size();a++){
            int ax1 = vectorContainer.aliens[a].x - pixelSize*2;
            int ay1 = vectorContainer.aliens[a].y + 0;
            int ax2 = vectorContainer.aliens[a].x + pixelSize*8;
            int ay2 = vectorContainer.aliens[a].y + 0;
            int ax3 = vectorContainer.aliens[a].x - pixelSize*2;
            int ay3 = vectorContainer.aliens[a].y + pixelSize*8;
            int ax4 = vectorContainer.aliens[a].x + pixelSize*8;
            int ay4 = vectorContainer.aliens[a].y + pixelSize*8;
//            line(ax1, ay1, ax2, ay2);
//            line(ax1, ay1, ax3, ay3);
//            line(ax2, ay2, ax4, ay4);
//            line(ax3, ay3, ax4, ay4);
            if((ax1 <= bx1 && ax2 >= bx1 && ax3 <= bx1 && ax4 >= bx1 && ay1 <= by1 && ay2 <= by1 && ay3 >= by1 && ay4 >= by1) ||
               (ax1 <= bx2 && ax2 >= bx2 && ax3 <= bx2 && ax4 >= bx2 && ay1 <= by2 && ay2 <= by2 && ay3 >= by2 && ay4 >= by2) ||
               (ax1 <= bx3 && ax2 >= bx3 && ax3 <= bx3 && ax4 >= bx3 && ay1 <= by3 && ay2 <= by3 && ay3 >= by3 && ay4 >= by3) ||
               (ax1 <= bx4 && ax2 >= bx4 && ax3 <= bx4 && ax4 >= bx4 && ay1 <= by4 && ay2 <= by4 && ay3 >= by4 && ay4 >= by4)){
                Alien tmp = vectorContainer.aliens[a];
                vectorContainer.aliens.erase (vectorContainer.aliens.begin()+a);
                moveAlien(tmp, tmp.x, tmp.y, -1, pixelSize,12,-1);
                vectorContainer.bullets.erase (vectorContainer.bullets.begin()+b);
            }
        }
    }
    return vectorContainer;
}

boolean checkGameOver(vector<Alien> aliens){
    for(int a=0;a<aliens.size();a++) {
        int ay3 = aliens[a].y + 40;
        int ay4 = aliens[a].y + 40;
        if(ay3 >= 425 || ay4 >= 425){
            Sleep(2*1000);
            return true;
        }
    }
    return false;
}

GameAttributes showResults(GameAttributes gameAtt, boolean youWin){
    for (int i=0;i<2;i++){
        setactivepage(gameAtt.page);
        setvisualpage(1-gameAtt.page);
        cleardevice();
        MyText gameTexts;
        if(youWin){
            mciSendString("stop destroy",NULL,0,NULL);
            mciSendString("stop warning",NULL,0,NULL);
            mciSendString("stop opening",NULL,0,NULL);
            mciSendString("stop shoot",NULL,0,NULL);
            mciSendString("stop warning",NULL,0,NULL);
            mciSendString("stop semiWarning",NULL,0,NULL);
            mciSendString("play you_win from 0",NULL,0,NULL);
            if(i==0)
                mciSendString("stop you_win",NULL,0,NULL);
            gameTexts.writeYouWin(140,190,10,gameAtt.youWinColor);
        } else{
            mciSendString("stop destroy",NULL,0,NULL);
            mciSendString("stop warning",NULL,0,NULL);
            mciSendString("stop opening",NULL,0,NULL);
            mciSendString("stop shoot",NULL,0,NULL);
            mciSendString("stop warning",NULL,0,NULL);
            mciSendString("stop semiWarning",NULL,0,NULL);
            mciSendString("play death from 0",NULL,0,NULL);
            if(i==0)
                mciSendString("stop death",NULL,0,NULL);
            gameTexts.writeYouLose(120,190,10,gameAtt.youLoseColor);
        }
        gameAtt.page = 1 - gameAtt.page;
        Sleep(1000);
    }
    return gameAtt;
}

GameAttributes startGame(GameAttributes gameAtt){
    VectorContainer vectorContainer;
    vectorContainer.aliens = addAlien(vectorContainer.aliens, gameAtt.pixelSize);
    Canon canon;
    boolean add = true, gameOver = false, youWin = false, yellow = false, red = false, someDied = false;
    double k = gameAtt.speed, angle = 0;
    int shootInterval = gameAtt.shootInterval, totalNumberOfAliens = vectorContainer.aliens.size(),position=0, status=-1;
    double percentage = 0.0;
    FireBar f;
    Bullet bDrawer;
    //----GAME LOOP----------
    printf("LEVEL %d\n", gameAtt.level);
    printf("THE GAME'S STARTING SPEED DELAY IS : %f\n", k);
    printf("THE GAME'S STARTING SHOOTING INTERVAL IS : %d\n", shootInterval);
    int scoreTotal = gameAtt.score;
    for(int i=0, j=0, b=0;!gameOver;i+=10){
        setactivepage(gameAtt.page);
        setvisualpage(1-gameAtt.page);
        cleardevice();
        if(vectorContainer.bullets.size() == 0 && gameAtt.bullets == 0){
            break;
        }
        if (someDied){
            if(status==-1)
                mciSendString("pause opening",NULL,0,NULL);
            else if(status==0){
                mciSendString("stop opening",NULL,0,NULL);
                mciSendString("pause semiWarning",NULL,0,NULL);
            }
            else if(status==1){
                mciSendString("stop semiWarning",NULL,0,NULL);
                mciSendString("pause warning",NULL,0,NULL);
            }
            mciSendString("play destroy from 0",NULL,0,NULL);
            Sleep(450);
            if(status==-1)
                mciSendString("play opening",NULL,0,NULL);
            else if(status==0)
                mciSendString("play semiWarning",NULL,0,NULL);
            else if(status==1)
                mciSendString("play warning from 0",NULL,0,NULL);
            someDied = false;
        }
        stringstream convert;
        convert << scoreTotal;
        string result = "Score: " + convert.str();
        char *score = new char[result.length() + 1];
        std::strcpy(score, result.c_str());
        setcolor(gameAtt.menuColor);
        outtextxy(550, 427, score);

        stringstream convert1;
        convert1 << gameAtt.level;
        string result1 = "Level: " + convert1.str();
        char *level = new char[result1.length() + 1];
        std::strcpy(level, result1.c_str());
        setcolor(gameAtt.menuColor);
        outtextxy(450, 427, level);

        stringstream convert2;
        convert2 << gameAtt.bullets;
        string result2 = "Bullets Left: " + convert2.str();
        char *bLeft = new char[result2.length() + 1];
        std::strcpy(bLeft, result2.c_str());
        setcolor(gameAtt.menuColor);
        outtextxy(450, 447, bLeft);

        if (j>=220){
            gameAtt.alienColor = 12;
            if (j==220 && !red){
                mciSendString("stop semiWarning",NULL,0,NULL);
                mciSendString("play warning from 0",NULL,0,NULL);
                k = k - (k * .06);
                shootInterval = shootInterval + ceil(shootInterval * .30);
                printf("\t\tSPEED DELAY IS NOW: %f\n", k);
                printf("\t\tSHOOTING INTERVAL IS NOW: %d\n", shootInterval);
                red = true;
                status = 1;
            }
        } else if(j>=100){
            gameAtt.alienColor = 14;
            if (j==100 && !yellow){
                mciSendString("stop opening",NULL,0,NULL);
                mciSendString("play semiWarning from 0",NULL,0,NULL);
                k = k - (k * .03);
                shootInterval = shootInterval + ceil(shootInterval * .10);
                printf("\t\tSPEED IS NOW: %f\n", k);
                printf("\t\tSHOOTING INTERVAL IS NOW: %d\n", shootInterval);
                yellow = true;
                status = 0;
            }
        } else {
            gameAtt.alienColor = 10;
            status = -1;
        }

        if (i == 300 && add){
            i = 10;
            j = j + 10;
            add = false;
        } else if (i == 310 && !add){
            i = 0;
            j = j + 10;
            add = true;
        }

        if (angle<35 && GetAsyncKeyState( VK_RIGHT ) & 0x8000){
            angle+=3;
        } else if (angle>-35 && GetAsyncKeyState( VK_LEFT ) & 0x8000){
            angle-=3;
        }
        if (b < shootInterval){
            b++;
            percentage = (double(b)/double(shootInterval)) * 100;
        }
        if (GetAsyncKeyState( VK_SPACE ) & 0x8000 && b==shootInterval && gameAtt.bullets > 0){
           if(status==-1)
                mciSendString("pause opening",NULL,0,NULL);
            else if(status==0){
                mciSendString("stop opening",NULL,0,NULL);
                mciSendString("pause semiWarning",NULL,0,NULL);
            }
            else if(status==1){
                mciSendString("stop semiWarning",NULL,0,NULL);
                mciSendString("pause warning",NULL,0,NULL);
            }
            mciSendString("play shoot from 0",NULL,0,NULL);
            Sleep(500);
            if(status==-1)
                mciSendString("play opening",NULL,0,NULL);
            else if(status==0)
                mciSendString("play semiWarning",NULL,0,NULL);
            else if(status==1)
                mciSendString("play warning from 0",NULL,0,NULL);
            Bullet bullet;
            bullet.x = 330;
            bullet.y = 460;
            bullet.angle = (angle*3.1428)/180;
            vectorContainer.bullets.push_back(bullet);
            b = 0;
            gameAtt.bullets = gameAtt.bullets - 1;
        }

        for(int ctr=0;ctr<vectorContainer.aliens.size();ctr++){
            if(add){
                vectorContainer.aliens[ctr].x = 50 + (vectorContainer.aliens[ctr].ctr%5*60);
                vectorContainer.aliens[ctr].x = vectorContainer.aliens[ctr].x + i;
            } else {
                vectorContainer.aliens[ctr].x = 350 + (vectorContainer.aliens[ctr].ctr%5*60);
                vectorContainer.aliens[ctr].x = vectorContainer.aliens[ctr].x - i;
            }
            vectorContainer.aliens[ctr].y = vectorContainer.aliens[ctr].type*50 + j;
            moveAlien(vectorContainer.aliens[ctr],vectorContainer.aliens[ctr].x, vectorContainer.aliens[ctr].y, vectorContainer.aliens[ctr].type, gameAtt.pixelSize, gameAtt.alienColor,position%2);
        }

        canon.drawPlatform(310,455,gameAtt.cannonColor);
        canon.drawCanon(330,460, angle,gameAtt.cannonColor);

        for(int ctr=0;ctr<vectorContainer.bullets.size();ctr++){
            vectorContainer.bullets[ctr].rotateBullet(vectorContainer.bullets[ctr].x,vectorContainer.bullets[ctr].y,vectorContainer.bullets[ctr].angle,gameAtt.cannonColor);
            vectorContainer.bullets[ctr].y -= cos(vectorContainer.bullets[ctr].angle)*10;
            vectorContainer.bullets[ctr].x += sin(vectorContainer.bullets[ctr].angle)*10;
        }

        f.drawFireBar(10,450);
        if (percentage <= 35){
            outtextxy(120, 447, "RELOADING!");
            gameAtt.firbarProgressColor = 12;
        } else if (percentage <= 70){
            outtextxy(120, 447, "RELOADING!");
            gameAtt.firbarProgressColor = COLOR(255,165,0);
        } else if (percentage <= 99){
            outtextxy(120, 447, "RELOADING!");
            gameAtt.firbarProgressColor = 14;
        } else {
            outtextxy(120, 447, "RELOADED!");
            gameAtt.firbarProgressColor = 10;
        }
        f.drawFireBarProgress(10,450,percentage,gameAtt.firbarProgressColor);
        int prevNumberOfAliens = vectorContainer.aliens.size();
        vectorContainer = checkCollision(vectorContainer, gameAtt.pixelSize );
        vectorContainer.bullets = checkBullets(vectorContainer.bullets);
        if (prevNumberOfAliens != vectorContainer.aliens.size()){
            someDied = true;
            scoreTotal = gameAtt.score + (totalNumberOfAliens - vectorContainer.aliens.size()) * gameAtt.pointsPerKill;
            gameAtt.bullets = gameAtt.bullets + gameAtt.bulletsPerKill;
        }

        if (vectorContainer.aliens.size()==0){
            youWin = true;
            gameOver = true;
        }
        if(checkGameOver(vectorContainer.aliens)){
            gameOver = true;
        }
        gameAtt.page = 1 - gameAtt.page;
        Sleep(k*1000);

        if(gameOver){
            break;
        }
        position++;
    }
    gameAtt.shootInterval = gameAtt.shootInterval + (ceil(gameAtt.shootInterval * .30) + ceil(gameAtt.shootInterval * .10));
    gameAtt.speed = gameAtt.speed - ((gameAtt.speed * .06) + (gameAtt.speed * .03));
    gameAtt.score = gameAtt.score + scoreTotal;
    gameAtt.gameOver = !youWin;
    printf("\n");
    return showResults(gameAtt,youWin);
}

GameAttributes gameMenu(GameAttributes gameAtt){
    boolean menuSelected = true;
    while(true){
        setactivepage(gameAtt.page);
        setvisualpage(1-gameAtt.page);
        cleardevice();
        MyText gameTexts;
        gameTexts.writeSpaceInvaders(80,50,10, gameAtt.menuColor);
        gameTexts.writeStart(240,250,5,menuSelected, gameAtt.menuColor);
        gameTexts.writeInfo(240,300,5,!menuSelected, gameAtt.menuColor);

        gameAtt.page = 1 - gameAtt.page;
        if (GetAsyncKeyState( VK_RETURN ) & 0x8000){
            mciSendString("pause menu",NULL,0,NULL);
            mciSendString("play select from 0",NULL,0,NULL);
            Sleep(1000);
            break;
        }
        if (GetAsyncKeyState( VK_UP ) & 0x8000) {
            menuSelected = true;
        } else if (GetAsyncKeyState( VK_DOWN ) & 0x8000) {
            menuSelected = false;
        }
    }
    gameAtt.menuSelected = menuSelected;
    return gameAtt;
}

GameAttributes gameLevel(GameAttributes gameAtt){
    for(int i=0;i<2;i++){
        setactivepage(gameAtt.page);
        setvisualpage(1-gameAtt.page);
        cleardevice();
        MyText gameTexts;
        stringstream convert;
        convert << gameAtt.level;
        gameTexts.writeLevel(190,140,10,convert.str(), gameAtt.menuColor);
        gameAtt.page = 1 - gameAtt.page;
        Sleep(1*1000);
    }
    return gameAtt;
}

GameAttributes gameOver(GameAttributes gameAtt){
    for(int i=0;i<2;i++){
        setactivepage(gameAtt.page);
        setvisualpage(1-gameAtt.page);
        cleardevice();
        MyText gameTexts;
        gameTexts.writeGameOver(215,140,10,gameAtt.youLoseColor);
        gameAtt.page = 1 - gameAtt.page;
        Sleep(2*1000);
    }
    return gameAtt;
}

GameAttributes gameInfo(GameAttributes gameAtt){
    while(true){
        setactivepage(gameAtt.page);
        setvisualpage(1-gameAtt.page);
        cleardevice();
        MyText gameTexts;
        gameTexts.writeInfo(240,10,5,false,gameAtt.menuColor);

        outtextxy(100, 100, "=====================  INGAME INFO  =====================");
        outtextxy(100, 130, "* PRESS RIGHT ARROW KEY TO ROTATE CANON TO THE RIGHT");
        outtextxy(100, 160, "* PRESS LEFT ARROW KEY TO ROTATE CANON TO THE LEFT");
        outtextxy(100, 190, "* PRESS ENTER KEY TO SHOOT");

        outtextxy(100, 250, "======================  MENU INFO  ======================");
        outtextxy(100, 280, "* PRESS UP ARROW KEY TO MOVE ARROW SELECTOR UP");
        outtextxy(100, 310, "* PRESS DOWN ARROW KEY TO MOVE ARROW SELECTOR DOWN");
        outtextxy(100, 340, "* PRESS ENTER KEY TO SELECT");

        outtextxy(100, 370, "========================================================");
        outtextxy(100, 400, "* PRESS ESC KEY TO RETURN TO MAIN MENU");

        gameAtt.page = 1 - gameAtt.page;
        if (GetAsyncKeyState( VK_ESCAPE ) & 0x8000){
            break;
        }
    }
    return gameAtt;
}

void openSoundFX(){
    mciSendString("open ./midi/select.mid alias select",NULL,0,NULL);
    mciSendString("open ./midi/opening.mid alias opening",NULL,0,NULL);
    mciSendString("open ./midi/opening_2.mid alias menu",NULL,0,NULL);
    mciSendString("open ./midi/shoot.mid alias shoot",NULL,0,NULL);
    mciSendString("open ./midi/destroy.mid alias destroy",NULL,0,NULL);
    mciSendString("open ./midi/warning.mid alias warning",NULL,0,NULL);
    mciSendString("open ./midi/you_win.mid alias you_win",NULL,0,NULL);
    mciSendString("open ./midi/death.mid alias death",NULL,0,NULL);
    mciSendString("open ./midi/semi-warning.mid alias semiWarning",NULL,0,NULL);
}

int main(){
    initwindow(640,480,"Space Invaders",GetSystemMetrics(SM_CXSCREEN)/6,GetSystemMetrics(SM_CYSCREEN)/8);
    GameAttributes gameAtt;
    openSoundFX();
    while(true){
        if (gameAtt.gameOver){
            GameAttributes gameAttTmp;
            gameAtt = gameAttTmp;
            mciSendString("play menu from 0",NULL,0,NULL);
            gameAtt = gameMenu(gameAtt);
        }
        if (gameAtt.menuSelected){
            mciSendString("play opening from 0",NULL,0,NULL);
            gameAtt = gameLevel(gameAtt);
            gameAtt = startGame(gameAtt);
            gameAtt.level++;
            if (gameAtt.gameOver){
                gameAtt = gameOver(gameAtt);
            }
        } else {
            mciSendString("play menu from 0",NULL,0,NULL);
            gameAtt = gameInfo(gameAtt);
        }
        Sleep(1*1000);
    }
    getch();
    closegraph();      /* closes down the graphics system */
    return 0;
}
