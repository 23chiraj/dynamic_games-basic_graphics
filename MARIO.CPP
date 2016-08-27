
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<bios.h>
#include<stdlib.h>

union REGS o,k;
int X=40,Y=384,J=0,L=3,M=0,I1,I2,MM=1,CC=0,PP=0;
long int S=0;
char A[4],B[10],D[6],C[1],E[3];
time_t T1,T2;
void tim()
{
  setcolor(15);
  settextstyle(3,0,3);
  outtextxy(50,0,B);
  if(L==3)
  outtextxy(120,0,"x3");
  if(L==2)
  outtextxy(120,0,"x2");
  if(L==1)
  outtextxy(120,0,"x1");
  outtextxy(175,0,"Score :");
  D[0]=48+S/10000;
  D[1]=48+(S/1000)%10;
  D[2]=48+(S/100)%10;
  D[3]=48+(S/10)%10;
  D[4]=48+S%10;
  D[5]=32;
  outtextxy(255,0,D);
  I1=0,I2=M;
 while(I1<3){
if(I2%10==0)
outtextxy(450-I1*11,0,"0");
if(I2%10==1)
 outtextxy(450-I1*11,0,"1");
 if(I2%10==2)
outtextxy(450-I1*11,0,"2");
   if(I2%10==3)
 outtextxy(450-I1*11,0,"3");
   if(I2%10==4)
 outtextxy(450-I1*11,0,"4");
  if(I2%10==5)
 outtextxy(450-I1*11,0,"5");
  if(I2%10==6)
 outtextxy(450-I1*11,0,"6");
  if(I2%10==7)
 outtextxy(450-I1*11,0,"7");
  if(I2%10==8)
 outtextxy(450-I1*11,0,"8");
  if(I2%10==9)
 outtextxy(450-I1*11,0,"9");
 I1++;
 I2=I2/10;}
 setcolor(14);
 ellipse(389,17,0,360,5,9);
 setfillstyle(1,14);
 fillellipse(389,17,3,5);
 outtextxy(405,0,":");
 setcolor(15);
   T2=time(NULL);
	 A[0]=48+(500-(((T2-T1)*12)/5))/100;
	 A[1]=48+((500-(((T2-T1)*12)/5))/10)%10;
	 A[2]=48+(500-(((T2-T1)*12)/5))%10;
	 outtextxy(580,0,A);
	 }
/*duck*/
 void duck(int X,int Y){
setcolor(8);
setfillstyle(7,2);
sector(X-20,Y+42,0,180,15,30);
setcolor(15);
line(X-23,Y+13,X-7,Y+40);
line(X-30,Y+22,X-17,Y+40);
line(X-11,Y+19,X-26,Y+40);
line(X-36,Y+40,X-16,Y+13);
setcolor(8);
setfillstyle(1,6);
fillellipse(X-33,Y+44,3,4);
fillellipse(X-7,Y+44,3,4);
setcolor(14);
fillellipse(X-5,Y+5,4,3);
fillellipse(X-35,Y+5,4,3);
arc(X-5,Y+13,100,180,8);
arc(X-5,Y+13,100,180,7);
arc(X-5,Y+13,100,180,6);
arc(X-35,Y+15,0,90,7);
arc(X-35,Y+15,0,90,6);
arc(X-35,Y+15,0,90,5);
setfillstyle(1,15);
setcolor(15);
fillellipse(X-3,Y+5,2.1,1.5);
fillellipse(X-37.5,Y+5,2.1,1.5);
setcolor(0);
setfillstyle(0,0);
fillellipse(X-1.78,Y+5,.91,.75);
fillellipse(X-38.2,Y+5,.91,.75);
}

void bot(int X,int Y)
{
setcolor(8);
setfillstyle(11,6);
sector(X-20,Y+24,0,180,20,24);
setfillstyle(11,14);
pieslice(X-20,Y+24,180,360,16);
setfillstyle(1,15);
fillellipse(X-25,Y+28,3,5);
fillellipse(X-15,Y+28,3,5);
setfillstyle(1,0);
fillellipse(X-26,Y+28,2,3);
fillellipse(X-16,Y+28,2,3);
setfillstyle(1,9);
fillellipse(X-30,Y+39,4,6.5);
fillellipse(X-10,Y+39,4,6.5);
}

void mario( )
{
int i,k;
if(MM==1)
{
	setcolor(2);
	ellipse(X+5-15,Y+12-48,0,360,1.8,2.9);
	arc(X-28,Y+11-48,100,280,2.7);
	arc(X-25,Y+11-48,100,280,2.9);
	arc(X-14,Y+15-48,215,300,7);
	setcolor(15);
	for(i=0;i<13;i++)
	arc(X-20,Y+9-48,0,180,i);
	line(X-29,Y+9-48,X,Y+9-48);
	ellipse(X-20,Y+13-48,160,375,13,18);
	ellipse(X-20,Y-48+66,0,180,20,35);
	line(X-8,Y+70-48,X-8,Y+42-48);
	line(X-32,Y+70-48,X-32,Y+42-48);
	setcolor(4);
	for(i=0;i<15;i++)
	line(X-32,Y-14+29+i,X-8,Y-14+29+i);
	setfillstyle(1,9);
	bar(X-28,Y+45-48,X-11,Y+62-48);
	setcolor(14);
	for(i=0;i<2;i++)
	line(X-26-i,Y+70-48,X-26-i,Y+36-48);
	setcolor(14);
	for(i=0;i<2;i++)
	line(X-12-i,Y+70-48,X-12-i,Y+36-48);
	setcolor(9);
	for(i=0;i<7;i++)
	line(X-30+i,Y-38+68,X-30+i,Y+78-38);
	for(i=0;i<7;i++)
	line(X+i-17,Y-38+68,X+i-17,Y+78-38);
	setcolor(8);
	for(i=0;i<17;i++)
	line(X+i-37,Y+41,X+i-37,Y+48);
	for(i=0;i<17;i++)
	line(X+i-19,Y+41,X+i-19,Y+48);

}
else if(MM==0)
{

	setcolor(14);
	ellipse(X+5-20,Y+12,0,360,1.5,2.5);
	arc(X-24,Y+11,100,280,2.5);
	arc(X-22,Y+11,100,280,2.5);
	arc(X-17,Y+15,230,300,4);
	setcolor(4);
	for(i=0;i<10;i++)
	arc(X-20,Y+9,0,180,i);
	line(X-29,Y+9,X,Y+9);
	ellipse(X-20,Y+9,180,360,9,14);
	arc(X-20,Y+54,45,135,28);
	line(X-8,Y+31,X-8,Y+42);
	line(X-32,Y+31,X-32,Y+42);
	setcolor(2);
	for(i=0;i<12;i++)
	line(X-27,Y+29+i,X-11,Y+29+i);
	setcolor(14);
	for(i=0;i<2;i++)
	line(X-26-i,Y+29,X-26-i,Y+38);
	setcolor(14);
	for(i=0;i<2;i++)
	line(X-12-i,Y+29,X-12-i,Y+38);
	setcolor(14);
	for(i=0;i<5;i++)
	line(X-32,Y+38+i,X-8,Y+38+i);
	setcolor(2);
	for(i=0;i<7;i++)
	line(X-30+i,Y+43,X-30+i,Y+45);
	for(i=0;i<7;i++)
	line(X+i-17,Y+43,X+i-17,Y+45);
	setcolor(14);
	for(i=0;i<12;i++)
	line(X+i-32,Y+47,X+i-32,Y+48);
	for(i=0;i<12;i++)
	line(X+i-19,Y+47,X+i-19,Y+48);
}
else if(MM==2)
{
	setcolor(15);
	ellipse(X+5-15,Y+12-48,0,360,1.8,2.9);
	arc(X-28,Y+11-48,100,280,2.7);
	arc(X-25,Y+11-48,100,280,2.9);
	arc(X-14,Y+15-48,215,300,7);
	setcolor(6);
	for(i=0;i<13;i++)
	arc(X-20,Y+9-48,0,180,i);
	setcolor(6);
	line(X-29,Y+9-48,X,Y+9-48);
	setcolor(15);
	ellipse(X-20,Y+13-48,160,375,13,18);
	ellipse(X-20,Y-48+66,0,180,20,35);
	line(X-8,Y+70-48,X-8,Y+42-48);
	line(X-32,Y+70-48,X-32,Y+42-48);
	setcolor(15);
	for(i=0;i<15;i++)
	line(X-32,Y-14+29+i,X-8,Y-14+29+i);
	setfillstyle(1,8);
	bar(X-28,Y+45-48,X-11,Y+62-48);
	setcolor(15);
	for(i=0;i<2;i++)
	line(X-26-i,Y+70-48,X-26-i,Y+36-48);
	setcolor(15);
	for(i=0;i<2;i++)
	line(X-12-i,Y+70-48,X-12-i,Y+36-48);
	setcolor(15);
	for(i=0;i<7;i++)
	line(X-30+i,Y-38+68,X-30+i,Y+78-38);
	for(i=0;i<7;i++)
	line(X+i-17,Y-38+68,X+i-17,Y+78-38);
	setcolor(15);
	for(i=0;i<17;i++)
	line(X+i-37,Y+41,X+i-37,Y+48);
	for(i=0;i<17;i++)
	line(X+i-19,Y+41,X+i-19,Y+48);

}
}

int c=0,p=0,u=0;
int game[10][176]={
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,0,0,0,10,10,10,11,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,0,0,0,0,0} ,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,0,0,0,0,0} ,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,0,0,0,0,0} ,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,10,13,10,11,10,0,0,0,0,0,0,0,0,11,0,0,0,0,0,12,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,13,10,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,10,13,0,0,0,11,0,0,11,0,0,11,0,0,0,0,0,10,0,0,0,0,0,0,15,0,0,15,0,0,0,0,0,0,0,0,0,0,15,15,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,10,10,11,10,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,0,0,15,15,0,0,0,0,0,0,0,0,15,15,15,0,0,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,0,0,0,0,0} ,
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,0,0,15,15,15,0,0,0,0,0,0,15,15,15,15,0,0,15,15,15,0,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,0,15,15,15,15,15,15,15,15,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,0,0,15,15,15,15,0,0,0,0,15,15,15,15,15,0,0,15,15,15,15,0,0,0,0,20,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,15,15,15,15,15,15,15,15,15,0,0,0,0,0},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	      };
int robot[]={21,48,80,81,95,96,111,112,114,115} ;
int crobot[6];
int crd[6]={0,0,0,0,0,0}   ;
int crl;
int du[]={55,56,100,159,160};
int cduck[3];
int cdd[]={0,0,0};
int cdl;

void mush(int x,int y)
{ int i;
 setfillstyle(1,9);
 setcolor(2);
 sector(x+20,y+24,0,205,20,24);
 sector(x+20,y+24,335,360,20,24);
 setcolor(2);
 for(i=0;i<10;i++)
 arc(x,y+48,0,90,10+i);
  for(i=0;i<10;i++)
 arc(x+40,y+48,90,180,10+i);
 setfillstyle(1,4);
fillellipse(x+20,y+20,4,5);
}
void flower(int x,int y)
{
setfillstyle(1,4);
fillellipse(x+20,y+24,17,17);
setfillstyle(1,14);
fillellipse(x+20,y+24,12,12);
setfillstyle(1,9);
fillellipse(x+20,y+24,7,7);
setfillstyle(1,2);
fillellipse(x+20,y+5,8,5);
fillellipse(x+20,y+43,8,5);
fillellipse(x+5,y+24,5,8);
fillellipse(x+35,y+24,5,8);
}

void bars(int x,int y)
{ setfillstyle(1,2);
bar(x,y,x+40,y+48);
}
void brick_break(int x, int y)
{
  setfillstyle(2,4);
  bar3d(x,y,x+40,y+48,10,1);

}
void ground(int x, int y)
{
   setfillstyle(12,4);
  bar(x,y,x+40,y+12);
  setfillstyle(11,4);
  bar(x,y+12,x+40,y+24);
   setfillstyle(10,4);
  bar(x,y+24,x+40,y+36);
   setfillstyle(9,4);
  bar(x,y+36,x+40,y+48);
}
void brick_solid(int x, int y)
{
  setfillstyle(1,8);
  bar3d(x,y,x+40,y+48,10,1);

}
void brick_point(int x, int y)
{
  setfillstyle(9,6);
  bar3d(x,y,x+40,y+48,10,1);
  settextstyle(4,0,5);
  setcolor(14);
  outtextxy(x+10,y-1,"?");

}
void brick_point1(int x, int y)
{
  setfillstyle(9,6);
  bar3d(x,y,x+40,y+48,10,1);
  settextstyle(4,0,5);
  setcolor(14);
 ellipse(x+20,y+24,0,360,5,9);
 setfillstyle(1,14);
 fillellipse(x+20,y+24,3,5);

}

void initial()
{  int j,l,k;
// for(j=c;j<(c+17);j++)
	{l=0;
	  for(k=0;k<10;k++)
	  if(robot[k]>=c&&robot[k]<=c+17)
	  if(crl==0)
	  { crd[l]=0;
	  crobot[l++]=(robot[k]-c)*40;
		robot[k]=0;

	  }
	  if(crl==0)
	   crl=l;

	   l=0;
	  for(k=0;k<5;k++)
	  if(du[k]>=c&&du[k]<=c+17)
	  if(cdl==0)
	  {  cdd[l]=0;
	   cduck[l++]=(du[k]-c)*40;
		du[k]=0;
	  }
	  if(cdl==0)
	   cdl=l;
	   }


}
void disp_animal()
{   int k;
  for(k=0;k<crl;k++)
  bot(crobot[k],384);
  for(k=0;k<cdl;k++)
  duck(cduck[k],384);
}
void move_animal()
{ int k,i;
 // if(crl==0)
  //return;

  for(k=0;k<crl;k++)     //eliminate
  {if(crobot[k]<40||crobot[k]>1280)
	{	for(i=k;i<crl-1;i++)
		crobot[i]=crobot[i+1];

		for(i=k;i<crl-1;i++)
		crd[i]=crd[i+1];

		crl--;
	}

  if(crd[k])
	crobot[k]+=8;
  else
	crobot[k]-=8;
  }
  for(k=0;k<cdl;k++)
  { if(cduck[k]<40||cduck[k]>640)
	{	for(i=k;i<cdl-1;i++)
		cduck[i]=cduck[i+1];

		for(i=k;i<cdl-1;i++)
		cduck[i]=cduck[i+1];

		cdl--;
	}


  if(cdd[k])
	cduck[k]+=4;
   else
	cduck[k]-=4;
  }

}
void direction()
{ int k;
  for(k=0;k<crl;k++)
  { if(crd[k]==0)
	{     if(game[8][c-2+crobot[k]/40])
		crd[k]=1;
	}
   else  if(game[8][c+crobot[k]/40])
		crd[k]=0;
   }
   for(k=0;k<cdl;k++)
  { if(cdd[k]==0)
	{     if(game[8][c-2+cduck[k]/40])
		cdd[k]=1;
	}
   else  if(game[8][c+cduck[k]/40])
		cdd[k]=0;
   }


}
void display()
{      int i,j;
 for(i=0;i<10;i++)
 {
	for(j=c;j<(c+17);j++)
	{
	  switch(game[i][j])
	  {
		case 10:brick_break(((j-c)*40)-p,i*48);break;
		case 11:brick_point(((j-c)*40)-p,i*48);break;
		case 12:brick_point1(((j-c)*40)-p,i*48);break;//manypoint
		case 13:brick_point(((j-c)*40)-p,i*48);break;//brick_advantage
		case 14:brick_point(((j-c)*40)-p,i*48);break;//star
		case 15:brick_solid(((j-c)*40)-p,i*48);break;
		case 20:bars(((j-c)*40)-p,i*48);break;
		case -1:ground(((j-c)*40)-p,i*48);break;
		case 21:mush(((j-c)*40)-p,i*48);break;
		case 22:flower(((j-c)*40)-p,i*48);break;
	  }

	}

 }
 mario();
}
void cond();
int walk_cond(int t=0)
{
  if(game[Y/48][c-t+X/40])
  return 0;
  else
  return 1;
}
int jump_cond()
{ int t;
  if(p)
  t=0;
  else
  t=1;

  if(game[Y/48-1][X/40-t])
  return 0;
  else
  return 1;
}
int down_cond()
{ int t;
  if(p)
  t=0;
  else
  t=1;

  if(game[Y/48+1][c+X/40-t])
  return 0;
  else
  return 1;

}
void jump();
void down()
{
while(1)
	{ // cleardevice();


	 setfillstyle(1,0);

       bar(0,25,640,480);
       for(int i=0;i<crl;i++)
	 bar(crobot[i]-40,384,crobot[i],432);
	  for(i=0;i<cdl;i++)
	 bar(cduck[i]-40,384,cduck[i],432);
       direction();
	   move_animal();
	    disp_animal();
	cond();
	if(!down_cond())
	return;
	else
	Y+=24;

		if(u==1)
		{c++;u=0;}
		display();
		delay(10);
		if(bioskey(1))
		{
			o.h.ah=0;
			int86(22,&k,&o);
			     delay(75);
			switch(o.h.ah)
		       {

				case 75: if(walk_cond())
					{
					if(X<=280&&X>40)
					X-=16;
					}
					break;//back
				case 77: if(walk_cond())
					{
						if(X>=280)
						{
						p+=8;
						if(p>40)
						{
						 p=0;
						 c++;
						}
					}
					else
						X+=16;
					}
					break;

				case 72:
					jump();
					break;

			}
			display();

		}
		else
			{

				display();
				delay(75);
			}
		}

}
void jump()
{       J++;
int zz=0;

       //cleardevice();
    setfillstyle(1,0);
    bar(0,25,640,480);
    for(int i=0;i<crl;i++)
	 bar(crobot[i]-40,384,crobot[i],432);
	  for(i=0;i<cdl;i++)
	 bar(cduck[i]-40,384,cduck[i],432);
	direction();
	  move_animal();
	  disp_animal();
	if(!jump_cond())
	return;
	else if(J<3)
	{
       //	 for(int i=0;i<2;i++)
	{	Y-=120;
		display();

		delay(100);
		if(bioskey(1))
		{
			o.h.ah=0;
			int86(22,&k,&o);
			switch(o.h.ah)
		       {
				case 75: if(walk_cond())
					{
					if(X<=280&&X>40)
					X-=16;
					}
					break;//back
				case 77: if(walk_cond())
					{
						if(X>=280)
						{
						p+=8;
						if(p>40)
						{
						 p=0;
						 c++;
						}
					}
					else
						X+=16;
					}
					break;//forward
				case 72:
					jump();
					break;

				}


			}
		display();
	       //	delay(150);
		int t;
		if(p)
		t=0;
		 else
		  t=1;

		switch(game[Y/48][c+X/40-t])
		{
		 case 10: zz=1;
			  if(MM==1 || MM==2){
			   game[Y/48][c+X/40-t]=0;
			     S=S+50; }
			     break;
		  case 11 : game[Y/48][c+X/40-t]=15;
			    M=M+1;
			    S=S+50;
			    zz=1;
			    break;

		   case 12 : zz=1;
			     if(CC==8){
			      game[Y/48][c+X/40-t]=15;
			      CC=0;
			      }
			     else if(game[Y/48][c+X/40-t]!=15)
			     {
			      M=M+1;
			      CC++;
			      S=S+100;
			       }
			      break;
		   case 13 :  zz=1;
			      if(MM==1 || MM==2){
			      game[Y/48][c+X/40-t]=22;}
			      else if(MM==0)
			      {
				game[Y/48][c+X/40-t]=21;
				}
				break;

		     case 14:  zz=1;
			       if(MM==1 || MM==2){
			      game[Y/48][c+X/40-t]=22;}
			      else if(MM==0)
			      {
				game[Y/48][c+X/40-t]=21;
				}
				break;
		       case 15:  S=S-25;
				 break;
				 }


		       switch(game[Y/48][c+X/40-t])
		       {
			 case 22: if(zz==0){
				    if(PP==3)
				    {
				    setcolor(14);
				    settextstyle(3,0,2);
				    outtextxy(320,240,"1 UP");
				    L++;
				    PP=0;
				    }
				  game[Y/48][c+X/40-t]=15;
				    S=S+2000;
				     zz=1;
				     MM=2;
				     PP++; }
				     break;

			 case 21 : if(zz==0){
				   game[Y/48][c+X/40-t]=15;
				      S=S+1000;
					 MM=1;
					     zz=1;}
				       break;
			      }






		  down();
	      }


    }


}
void front(){

	int gd=DETECT,gm,xx=0,yy=1;
	initgraph(&gd,&gm,"c:\\TC\\bgi");
	while(1){
	settextstyle(4,0,8);
       setcolor(4);
       outtextxy(160,50,"MARIO");
       settextstyle(4,0,4);
       setcolor(6);
       outtextxy(70,150,"MARIO");
       outtextxy(300,150,"SUPER MARIO");

       MM=0;
       X=120,Y=200;
       mario();
       MM=1;
       X=450,Y=250;
       mario();

       duck(40,yy*48);
       bot(630,(9-yy)*48);
       delay(200);
       if(xx==1)
       yy++;
       if(xx==0)
       yy--;
       if(yy==9)
       xx=0;
       if(yy==0)
       xx=1;
       setfillstyle(1,0);
       bar(0,0,40,480);
       bar(590,0,640,480);
       setcolor(9);
       setfillstyle(10,9);
       rectangle(180,350,480,440);
       settextstyle(1,0,2);
       outtextxy(190,310,"Press ENTER ");
       settextstyle(5,0,3);
       setcolor(2);
       outtextxy(200,355,"CREATED BY :");
       settextstyle(3,0,3);
       setcolor(14);
       outtextxy(210,390,"Coding Club @ NITD");
       if(bioskey(1))
       break;
       }
       X=40,Y=384;
       closegraph();

 }

void second()
{
int s=0;
for(int i=0;i>=0;i++)
  {
  setcolor(i);
   rectangle(10,10,630,470);
   settextstyle(4,0,3);
   outtextxy(100,100,"Enter Your Name:");
   if(bioskey(1))
   {
      B[s++]=getch();
      if(B[s-1]=='0')
      {B[s-1]='\0';return;}
      B[s]='\0';
      outtextxy(350,100,B);


   }
   delay(300);
   }


}

void main()
{
	int gd=DETECT,gm,x,y,i;

	front();
	initgraph(&gd,&gm,"c:\\TC\\bgi");     //Initializing Graphics Mode
	 second();
      MM=0;
      X=150;Y=200;
      mario();
      MM=1;
      X=300;Y=200;
      mario();
      MM=2;
      X=450;Y=200;
      mario();
      outtextxy(130,250,"1");
      outtextxy(280,250,"2");
      outtextxy(430,250,"3");
      outtextxy(100,280,"Enter Mario Choice:");
      char ch=getch();
      switch(ch)
      {
       case '1':MM=0;
		outtextxy(300,280,"1"); break;
       case '2':MM=1;
		outtextxy(300,280,"2"); break;
       case '3':MM=2;
		outtextxy(300,280,"3"); break;
       default :MM=0;
		outtextxy(300,280,"1"); break;
	}
	X=40;Y=384;
	  for(i=0;i>=0;i++)
   {           setcolor(i);
   outtextxy(100,330,"Welcome");
   outtextxy(350,330,B);
   outtextxy(100,370,"Hit Any Key to play...");

	if(bioskey(1))
	break;

   }
display();

       T1=time(NULL);
	while(1)
	{  setfillstyle(1,0);
	 bar(0,0,640,42);

	 for(i=0;i<crl;i++)
	 bar(crobot[i]-40,384,crobot[i],432);
	  for(i=0;i<cdl;i++)
	 bar(cduck[i]-40,384,cduck[i],432);

	   tim();
	   initial();

	   direction();
	   move_animal();
	    disp_animal();

	   display();
	   delay(5);
		 cond();

		if(bioskey(1))

		{//cleardevice();


		 setfillstyle(1,0);
	     bar(0,25,640,480);
	     for(i=0;i<crl;i++)
	 bar(crobot[i]-40,384,crobot[i],432);
	  for(i=0;i<cdl;i++)
	 bar(cduck[i]-40,384,cduck[i],432);
		direction();
	   move_animal();
	    disp_animal();
		//display();
		o.h.ah=0;
		int86(22,&k,&o);
		J=0;
	       switch(o.h.ah)
	       {
		case 1: getch();
			exit(0);
			closegraph();
			break;
		case 72: J=0;
			jump();
			break;//up
		case 75: if(walk_cond(1))
				{
					if(X<=280&&X>40)
					X-=8;
				}
			break;//back
		case 77: if(walk_cond())
			{
				if(X>=280)
				{
					p+=8;
					if(p>40)
					{
					 p=0;
					 c++;
					}
				}
				else
				X+=8;
			}
			break;
		}
		if(Y<384)
		u=1;
		else
		u=0;
		if(game[Y/48+1][c+X/40-1]!=-1)
		down();

		}
	}
	getch();
}

void cond()
{ int flag=0,k ;
 for(int i=0;i<cdl;i++)
	if((cduck[i]-X)<=32&&(cduck[i]-X)>=-32&&Y==384)
	{ if(J>0)
	      {	cduck[i]=0; S+=200;}
	else
	{ if(MM)
	{MM--;  cduck[i]=0; }
	else
	flag=1;
	 break;

	}
      }

 for(i=0;i<crl;i++)
	if((crobot[i]-X)<=32&&(crobot[i]-X)>=-32&&Y==384)
	{if(J>0)
		{crobot[i]=0;   S+=100;}

      else
	{if(MM)
	{MM--; crobot[i]=0; }
	else
	flag=1;
	break;
	}
   }
 if(Y>=480|| (500-(((T2-T1)*12)/5))<=0)
 flag=1;
 int xx=0,yy=1;


 if(flag)
{
    if(L>1)
    {L--;main(); }
    cleardevice();
	while(1){
	settextstyle(4,0,8);
       setcolor(4);
       outtextxy(160,50,"MARIO");
       settextstyle(4,0,4);
       setcolor(6);
       outtextxy(70,150,"MARIO");
       outtextxy(300,150,"SUPER MARIO");

       MM=0;
       X=120,Y=200;
       mario();
       MM=1;
       X=450,Y=250;
       mario();

       duck(40,yy*48);
       bot(630,(9-yy)*48);
       delay(200);
       if(xx==1)
       yy++;
       if(xx==0)
       yy--;
       if(yy==9)
       xx=0;
       if(yy==0)
       xx=1;
       setfillstyle(1,0);
       bar(0,0,40,480);
       bar(590,0,640,480);
       setcolor(4);
       settextstyle(4,0,6);
       outtextxy(100,350," GAME OVER");
       settextstyle(3,0,6);
       setcolor(14);
       outtextxy(100,250,B);
      /* setcolor(9);
       setfillstyle(10,9);
       rectangle(180,350,480,440);
       settextstyle(5,0,3);
       setcolor(2);
       outtextxy(200,355,"CREATED BY :");
       settextstyle(3,0,5);
       setcolor(14);
       outtextxy(210,390,"GIRRAJ & CO."); */
       if(bioskey(1))
       break;
       }
 getch();
 getch();
 cleardevice();
 setcolor(4);
settextstyle(3,0,6);
outtextxy(100,200," THANK YOU");
delay(2000);
closegraph();
 exit(0);
 }
} 

