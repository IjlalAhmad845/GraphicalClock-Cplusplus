#include <iostream>
#include<graphics.h>
#include<time.h>
#include<stdio.h>

#define BLACK           0
#define BLUE            1
#define GREEN           2
#define CYAN            3
#define RED             4
#define MAGENTA         5
#define BROWN           6
#define LIGHTGRAY       7
#define DARKGRAY        8
#define LIGHTBLUE       9
#define LIGHTGREEN      10
#define LIGHTCYAN       11
#define LIGHTRED        12
#define LIGHTMAGENTA    13
#define YELLOW          14
#define WHITE           15

using namespace std;
class graphical_clock
{public:
    int clockBGcolor=DARKGRAY,elements=LIGHTGRAY,second=YELLOW,minute=LIGHTGREEN,hour=RED;
int i,j,k,l,l1,p=0,num[6],date;

arccoordstype m[21];

void desingning()       ///=================================================================******CLOCK STRUCTURE*****
{ setfillstyle(SOLID_FILL,WHITE);     ///--------------for white background
   floodfill(1,1,1);
   setcolor(BLACK);                 ///----------------------------------------structure of clock is of black color
    circle(400,320,280);            ///======inner circle
    circle(400,320,300);            ///======outer circle
                ///-----------like index
    rectangle(10,10,30,20);         ///for second
    rectangle(10,30,30,40);         ///for minutes
    rectangle(10,50,30,60);         ///for hour


    setcolor(clockBGcolor);arc(400,320,90,90-l,210);getarccoords(&m[0]);
                            ///=========================================to print small clocks above the trajectory of HOUR
    setcolor(clockBGcolor);arc(400,320,90,90-k,210);getarccoords(&m[4]);
                            ///=========================================to print small clocks above the trajectory of MIN
    small_clocks();         ///-----------------small clocks called

    for(j=0;j<5;j++)
    rectangle(230+j,400+j,570-j,500-j);         ///------------digital clock
///---------------------------------------------------------------------------------------*****coloring*******----------------
      setfillstyle(SOLID_FILL,LIGHTBLUE);floodfill(400,22,BLACK);///--------------------------------boundary
      setfillstyle(SOLID_FILL,clockBGcolor);floodfill(400,41,BLACK);///-------------------------inside
      setfillstyle(XHATCH_FILL,LIGHTGRAY);floodfill(250,450,0);///---------------rectangle
setfillstyle(SOLID_FILL,second);floodfill(11,11,0);///------------------index second
setfillstyle(SOLID_FILL,minute);floodfill(11,31,0);///------------------index minutes
setfillstyle(SOLID_FILL,hour);floodfill(11,51,0);///--------------------index hour
settextstyle(2,0,5);setcolor(WHITE);
outtextxy(35,10,"<----SECOND HAND");outtextxy(35,30,"<-----MINUTE HAND");outtextxy(35,50,"<--------HOUR HAND");
}
  void needles()        ///=================================================================******NEEDLES*************
  {///-------------------------------------------------------------------------------Hour
      setcolor(clockBGcolor);arc(400,320,90,90-l,5);getarccoords(&m[1]);    ///------for center
                            arc(400,320,270,270-l,40);getarccoords(&m[2]);
setcolor(hour);
line(m[0].xend,m[0].yend,m[1].xend,m[1].yend);
line(m[2].xend,m[2].yend,m[1].xend,m[1].yend);

 ///------------------------------------------------------------------------------------------Min
setcolor(clockBGcolor);arc(400,320,90,90-k,5);getarccoords(&m[5]);  ///-----for center
                        arc(400,320,270,270-k,45);getarccoords(&m[6]);
setcolor(minute);
line(m[4].xend,m[4].yend,m[5].xend,m[5].yend);
line(m[6].xend,m[6].yend,m[5].xend,m[5].yend);

///-------------------------------------------------------------------------------------------Sec
setcolor(clockBGcolor);arc(400,320,90,90-i,230);getarccoords(&m[7]);
                          arc(400,320,270,270-i,50);getarccoords(&m[8]);///-------for secondary second hand
   setcolor(second);arc(400,320,90,90-i,5);getarccoords(&m[9]);         ///-----------for center

setcolor(second);
line(m[7].xend,m[7].yend,m[9].xend,m[9].yend);      ///-----------line move in circle
line(m[8].xend,m[8].yend,m[9].xend,m[9].yend);
///-------------------delay and counter is not necessary here because second hand is linked with digital clock


setcolor(0);
    circle(400,320,10);             ///----black outline center
    setfillstyle(SOLID_FILL,second);floodfill(400,320,0);///------------for printing center after hr and min hand
}
void glitch()           ///=================================================================******GLITCH REMOVER******
{setactivepage(p);
setvisualpage(1-p);
cleardevice();
p=1-p;

}
void clock_details()    ///=================================================================******CLOCK ELEMENTS******
{for(j=0;j<=360;j++)
{setcolor(clockBGcolor);
    arc(400,320,90-j,90,270);getarccoords(&m[10]);

    if(j%30==29 || j%30==1)
    arc(400,320,90-j,90,255-10);
    getarccoords(&m[11]);

setcolor(elements);

line(m[10].xstart,m[10].ystart,m[11].xstart,m[11].ystart);
}

}
void calculation()      ///=================================================================******CALCULATION*********
{time_t now=time(NULL);
char * tm=ctime(&now);
num[0]=atoi(&tm[17]);num[1]=num[0]/10;num[0]=num[0]%10;
num[2]=atoi(&tm[14]);num[3]=num[2]/10;num[2]=num[2]%10;
num[4]=atoi(&tm[11]);l1=num[4];
if(num[4]>12)num[4]=num[4]-12;       ///---------12 hrs format
num[5]=num[4]/10;num[4]=num[4]%10;
i=(num[1]*10+num[0])*6;
k=(num[3]*10+num[2])*6+i/60;
l=(num[5]*10+num[4])*30+k/12;
l1=l1*15+k/24;
date=atoi(&tm[8]);
date=date*12;
}
void digital()          ///=================================================================******DIGITAL CLOCK*******
{char  ch[50];
sprintf(ch,"%d%d %d%d %d%d",num[5],num[4],num[3],num[2],num[1],num[0]);

setcolor(GREEN);settextstyle(8,0,7);
outtextxy(248,416,ch);
circle(345,435,5);
circle(345,460,5);
circle(460,435,5);
circle(460,460,5);

}
void small_clocks()     ///=================================================================******SMALL CLOCKS********
{   setcolor(BLACK);
    circle(260,280,70);circle(260,280,60);             ///======minutes
    circle(540,280,70);circle(540,280,60);          ///======dates
    circle(400,170,70);circle(400,170,60);           ///======24 hr format

for(j=0;j<=360;j++)
{    setcolor(LIGHTGRAY);                 ///----------elements color is same as small clocks color
///================================first small clock            minutes
arc(260,280,90,90-j,55);getarccoords(&m[12]);
    if(j%30==0)
arc(260,280,90,90-j,45);
getarccoords(&m[13]);
///================================third small clock            24hr format
arc(540,280,90,90-j,55);getarccoords(&m[14]);
    if(j%15==0)
arc(540,280,90,90-j,45);
getarccoords(&m[15]);
///================================second small clock           dates
arc(400,170,90,90-j,55);getarccoords(&m[16]);
    if(j%12==0)
arc(400,170,90,90-j,45);
getarccoords(&m[17]);


setcolor(BLACK);
line(m[12].xend,m[12].yend,m[13].xend,m[13].yend);///-1
line(m[14].xend,m[14].yend,m[15].xend,m[15].yend);///-3
line(m[16].xend,m[16].yend,m[17].xend,m[17].yend);///-2
}

     setfillstyle(SOLID_FILL,LIGHTBLUE);floodfill(195,280,0);floodfill(475,280,0);floodfill(335,170,0); ///----extra clocks
     setfillstyle(SOLID_FILL,LIGHTGRAY);                ///=============PAINTING OF SMALL CLOCKS
     floodfill(250,280,0);floodfill(270,280,0);
     floodfill(510,280,0);floodfill(530,280,0);
     floodfill(390,170,0);floodfill(410,170,0);
      ///----inside small clocks


setcolor(elements);
arc(260,280,90,90-k,43);   getarccoords(&m[18]);///----1               DRAW trajectories for small clocks needles
arc(540,280,90,90-l1,43);  getarccoords(&m[19]);///----3
arc(400,170,90,90-date,43);getarccoords(&m[20]);///----2

setcolor(BLACK);                                ///-------------needles of small clocks
line(260,280,m[18].xend,m[18].yend);///-1
line(540,280,m[19].xend,m[19].yend);///-3
line(400,170,m[20].xend,m[20].yend);///-2

circle(260,280,5);              ///for printing center circle over line
circle(540,280,5);
circle(400,170,5);

      ///For center for all small clocks
      setfillstyle(SOLID_FILL,LIGHTRED);floodfill(261,280,0);floodfill(259,280,0);
      setfillstyle(SOLID_FILL,LIGHTRED);floodfill(541,280,0);floodfill(539,280,0);
      setfillstyle(SOLID_FILL,LIGHTRED);floodfill(399,170,0);floodfill(401,170,0);
setcolor(BLACK);}

};

int main()
{
   initwindow(800,650,"");
   graphical_clock ob;

///----------sequence is very necessary
   while(1)
   {    ob.desingning();
        ob.calculation();
        ob.needles();
        ob.clock_details();
        ob.digital();
        ob.glitch();
    if(GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_RETURN))                  ///-------------------------for closing program
    break;
}

  getch();
   closegraph();
}

