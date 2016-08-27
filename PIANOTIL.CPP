#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<bios.h>
#include<stdio.h>
union REGS km,o;
int x[4]={60,146,232,318},s,P=0,N=0,d,m,b[4]={0,0,0,0},a[4]={0,1,2,3},z[4]={0,0,0,0},y[4]={0,-80,-160,-240};
void input()
{
    int k=0,k1,k2,kk,k3;
   int la=z[0]*10+y[0],sl,tl,fl;
     for(s=0;s<4;s++)
       if(la<=z[s]*10+y[s] )
       { la=z[s]*10+y[s];
	  k=s;       }

	 kk=k;

	 if(b[k]==7 || b[k]==4){
	  for(s=0;s<4;s++)
	 {
	  if(k!=s){
	   sl=z[s]*10+y[s];
	   break;
	   } }
	  for(s=0;s<4;s++) {
	  if((10*z[s]+y[s])>=sl && (z[s]*10+y[s])<la)
	  {
	    sl=z[s]*10+y[s];
	     k1=s;
		  }
		   }
	  kk=k1;
		}

	  if((b[k1]==7 || b[k1]==4) && ( b[k]==7 || b[k]==4)){
	  for(s=0;s<4;s++)
	 {
	  if(k!=s && k1!=s){
	   tl=z[s]*10+y[s];
	   break;
	   }
	    }
	  for(s=0;s<4;s++) {
	  if((10*z[s]+y[s])>=tl && (z[s]*10+y[s])<sl)
	  {
	    tl=z[s]*10+y[s];
	     k2=s;
		  }
		    }
	      kk=k2;
	      }

	    if((b[k1]==7 || b[k1]==4) && ( b[k]==7 || b[k]==4) && (b[k2]==7 || b[k2]==4))
	     {
	     for(s=0;s<4;s++)
	      if(s!=k1 && s!=k2 && s!=k)
		k3=s;

		kk=k3;
			 }

		o.h.ah=0;
		int86(22,&km,&o);
		if(o.h.ah==1)
		{
			exit(0);
			closegraph();
		}
		else if(o.h.ah==72)
		{
		    if(a[kk]==0 ){
		    b[kk]=7;
		    P=P+1;
		    }
		   else if(a[kk]!=0)
		   {
		    b[kk]=4;
		    N=N+1;
		     }
		 }
		else if(o.h.ah==80)
		{
		  if(a[kk]==2){
		    b[kk]=7;
		    P=P+1;
		    }
		      else if(a[kk]!=2)
		   {
		     b[kk]=4;
		     N=N+1;
		 }
		}
		else if(o.h.ah==77)
		{
		  if(a[kk]==3){
		    b[kk]=7;
		    P=P+1;
		    }
		  else if(a[kk]!=3)
		   {
		   b[kk]=4;
		   N=N+1;
		 }
		}
		else if(o.h.ah==75)
		{
		  if(a[kk]==1){
		    b[kk]=7;
		    P=P+1;
		    }
		    else if(a[kk]!=1)
		   {
		    b[kk]=4;
		    N=N+1;
		 }
		}

}
void main()
{
char c,C[2],NA[20];
int o,aa;
time_t t,T,tt;
clrscr();
cout<<" Welcome to Piano Tiles Game \n";
cout<<" Enter your name : \n";
gets(NA);
cout<<" Choose your level : \n";
cout<<" 1.Champion \n 2. Hard \n 3. Easy\n";
do{
cin>>aa;
if(aa!=1 && aa!=2 && aa!=3)
cout<<" Wrong input!!!!!!!!!!\n Re-Enter your choice :\n";
}while(aa!=1 && aa!=2 && aa!=3);
cout<<" Press R to read rules : \n";
cout<<" OR Press any alphabet to Start: \n";
cin>>c;
if(c=='R' || c=='r'){
cout<<"\n 1. You have to press direction  arrows   according  to \n the written directions on the box. \n";
cout<<"\n 2. You can do a mistake in every 6 tiles.......... but\n  have to do 2 mistakes in every 10 Tiles .\n " ;
cout<<"\n 3. Times in seconds decide your concentration quotient.\n ";
getch();
}
t=time(NULL);
int gdriver=9,gmode=2,error,i,j,k,l=0;
initgraph(&gdriver,&gmode,"C:\\tc\\bgi") ;
error=graphresult();
if(error!=grOk){
cout<<" There is some error in opening of this file \n";
cout<<" Error is :"<<grapherrormsg(error);
getch();
exit(1);}
setfillpattern("11111111",9);
bar(420,0,639,80);
setfillpattern("11111111",14);
bar(599,0,639,479);
setfillpattern("11111111",4);
bar(420,399,639,479);
setcolor(14);
for(i=0;i<61;i++) {
line(i,0,i,80);
line(360+i,0,360+i,80);}
setcolor(9);
for(i=0;i<61;i++) {
line(i,399,i,479);
line(360+i,399,360+i,479);}
for(i=0;i<16;i++){
if((i%2)==1)
setcolor(7);
if((i%2)==0)
setcolor(0);
for(j=0;j<20;j++)
line(0,80+20*i+j,60,+j+80+20*i);
for(j=0;j<20;j++)
line(360,80+20*i+j,420,+j+80+20*i);
}
for(i=0;i<7;i++){
if((i%2)==1)
setcolor(0);
if((i%2)==0)
setcolor(7);
for(j=0;j<43;j++)
line(60+43*i+j,0,60+43*i+j,80);
if((i%2)==1)
setcolor(4);
for(j=0;j<43;j++)
line(60+43*i+j,399,60+43*i+j,479);  }
setcolor(7);
for(k=60;k<361;k++)
line(k,80,k,399);
do {
T=time(NULL);
for(m=0;m<4;m++){
setcolor(b[m]);
for(k=0;k<43;k++)
line(x[m]+k,y[m]+10*(z[m]),x[m]+k,y[m]+10*z[m]+80);
setcolor(9);
settextstyle(0,0,2);
outtextxy(422,130,"PIANO TILES ");
setcolor(4);
settextstyle(0,0,0);
outtextxy(430,200,"Correct Responses:");
setcolor(14);
C[0]=48+P;
C[1]=32;
outtextxy(574,200,C);
setcolor(0);
bar(585,200,600,215);
setcolor(14);
outtextxy(430,260,"Wrong Responses:");
C[0]=48+N;
C[1]=32;
setcolor(4);
outtextxy(560,260,C);
setcolor(0);
bar(570,260,600,275);
setcolor(14);
outtextxy(455,300," Level ");
C[0]=48+aa;
C[1]=32;
setcolor(12);
outtextxy(525,300,C);
setcolor(0);
bar(540,300,600,315);
settextstyle(0,0,2);
setcolor(9);
outtextxy(460,350,NA);


if((P+N)<=6){
if(N>=2) {
closegraph();
cout<<" Your score is :"<<T-t;
getch();
}
}
else if((P+N)>=10)
{
if(N<2)
{
closegraph();
cout<<" Your score is :"<<T-t;
getch();
}
else {
N=0;
P=0;
}
}

settextstyle(0,0,0);
if(a[m]==0){
setcolor(4);
outtextxy(x[m]+16,y[m]+10*z[m]+40,"UP");
}
else if(a[m]==3){
setcolor(9);
outtextxy(x[m],y[m]+10*z[m]+40,"RIGHT");
}
else if(a[m]==1){
setcolor(14);
outtextxy(x[m]+4,y[m]+10*z[m]+40,"LEFT");
}
else if(a[m]==2){
setcolor(2);
outtextxy(x[m]+4,y[m]+10*z[m]+40,"DOWN");
}
if((y[m]+10*(z[m]+1)+80)>=399)
{
tt=time(NULL);
a[m]=tt%4;
y[m]=0;
z[m]=0;
x[m]=60+43*a[m]*2;
b[m]=0;
}
if(bioskey(1)!=0)
input();
delay(7-(3-aa)*2);
z[m]++;
setcolor(7);
for(k=0;k<43;k++) {
if((y[m]+10*z[m])>40)
line(x[m]+k,0,x[m]+k,80);
line(x[m]+k,399,x[m]+k,479);
}
}
delay(25-(3-aa)*4);
setfillpattern(0,0);
setcolor(0);
bar(420,80,599,399);
setcolor(7);
for(k=60;k<361;k++)
line(k,80,k,399);
}while(1);
getch();
closegraph();
}