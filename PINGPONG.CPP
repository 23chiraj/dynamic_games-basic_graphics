#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<bios.h>
union REGS k,o;
int f=0,s=0,H=4,V=0,hu=60,hl=60,z=2,q;
float X,Y;
char m=' ',n=' ';
void fix(int x,int y, float a);
float find(float a,float x,float y);
int check()
{
if((240-Y)<=70)
{
if(hu<=(337+X) && hu>=(243+X))
return 0;
else
return 1;
}
else if((240-Y)>=410)
{
if(hl<=(337+X) && hl>=(243+X))
return 0;
else
return 1;
}
}
void input()
{

		o.h.ah=0;
		int86(22,&k,&o);
		if(o.h.ah==1)
		{
			exit(0);
			closegraph();
		}
		else if(o.h.ah==72)
		{
		 if(V==0)
		 V=1;
		 else
		 V=0;
		}
		else if(o.h.ah==77)
		{
		 H=1;
		}
		else if(o.h.ah==80 )
		{
		if(V==1)
		 V=0;
		 else
		 V=1;
		}
		else if(o.h.ah==75)
		{
			 H=-1;
		}

}
void main()
{
cout<<" Welcome to HIT-IT Game  ";
cout<<"\n\n\n\n Press ESC anytime to exit :";
cout<<"\n\n\n\n Select difficulty Level : ";
cout<<" \n 1. Champion ";
cout<<" \n 2. Very Hard ";
cout<<" \n 3. Hard ";
cout<<" \n 4. Medium ";
cout<<" \n 5. Easy ";
cout<<" \n 6. Very Easy \n ";
cin>>q;
cout<<"\n\n Press any key to continue :";
getch();
int gdriver=9,gmode=2,error,j,i,zz,g;
float a,x=0.0,y=0.0;
time_t t,T;
t=time(NULL);
randomize();
clrscr();
a=(random(360)*6.28)/360;
if(a<0.6)
a=0.6;
else if(a>5.68)
a=5.68;
else if(a>2.64 || a<3.14)
a= 2.64;
else if(a>3.14 || a<3.64)
a= 3.64;
initgraph(&gdriver,&gmode,"C:\\Tc\\bgi") ;
error=graphresult();
if(error!=grOk){
cout<<" There is some error in opening of this file \n";
cout<<" Error is :"<<grapherrormsg(error);
getch();
exit(1);}
fix(x,y,a);
do{
if(n=='+'){
setcolor(3);
for(g=0;g<31;g++)
line(0,g,639,g);
setcolor(14);
for(g=0;g<31;g++)
line(0,449+g,639,449+g);
setcolor(6);
for(g=0;g<61;g++)
line(g,30,g,449);
setcolor(15);
for(g=0;g<61;g++)
line(579+g,30,579+g,449);
for(i=s;i<=f;i++){
setfillpattern(0,0);
bar(60,30,579,449);
if(bioskey(1)!=0){
input();
z=1;}
if(V==0 && z==1){
if(H==1)
{
if(hu>=519)
hu=60;
else
hu=hu+40;}
else if(H==-1){
if(hu<=60)
hu=519;
else
hu=hu-40; }}
else if(V==1 && z==1){
if(H==1)
{
if(hl>=519)
hl=60;
else
hl=hl+40;}
else if(H==-1){
if(hl<=60)
hl=519;
else
hl=hl-40; }
}
z=0;
if(hl<=519 ){
setcolor(5);
for(g=0;g<20;g++)
line(hl,429+g,(hl+60),429+g);}
else {
setfillpattern(0,5);
bar(hl,429,(hl+40),449);
bar(60,429,100,449);}
if(hu<=519){
setcolor(9);
for(g=0;g<20;g++)
line(hu,g+30,(hu+60),g+30);}
else {
setfillpattern(0,9);
bar(hu,30,(hu+40),50);
bar(60,30,100,50);}
if(m=='x'){
X=i;
Y=(tan(a)*i)+y-(x*tan(a));}
else if(m=='y'){
Y=i;
X=(i-y+(x*tan(a)))/(tan(a)); }
setcolor(i%15+1);
for(j=0;j<18;j++)
arc(320+X,240-Y,0,360,j);
delay(q-1);
}
}


else if(n=='-'){
setcolor(4);
for(g=0;g<31;g++)
line(0,g,639,g);
setcolor(1);
for(g=0;g<31;g++)
line(0,449+g,639,449+g);
setcolor(11);
for(g=0;g<61;g++)
line(g,30,g,449);
setcolor(2);
for(g=0;g<61;g++)
line(579+g,30,579+g,449);
for(i=s;i>=f;i--){
setfillpattern(0,0);
bar(60,30,579,449);
if(bioskey(1)!=0){
input();
z=1;}
if(V==0 && z==1){
if(H==1)
{
if(hu>=519)
hu=60;
else
hu=hu+40;}
else if(H==-1){
if(hu<=60)
hu=519;
else
hu=hu-40; }}
else if(V==1 && z==1){
if(H==1)
{
if(hl>=519)
hl=60;
else
hl=hl+40;}
else if(H==-1){
if(hl<=60)
hl=519;
else
hl=hl-40; }
}
z=0;
if(hl<=519 ){
setcolor(9);
for(g=0;g<20;g++)
line(hl,429+g,(hl+60),429+g);}
else {
setfillpattern(0,9);
bar(hl,429,(hl+40),449);
bar(60,429,100,449);}
if(hu<=519){
setcolor(5);
for(g=0;g<20;g++)
line(hu,g+30,(hu+60),g+30);}
else {
setfillpattern(0,5);
bar(hu,30,(hu+40),50);
bar(60,30,100,50);}
if(m=='x'){
X=i;
Y=(tan(a)*i)+y-(x*tan(a));}
else if(m=='y'){
Y=i;
X=(i-y+(x*tan(a)))/(tan(a)); }
setcolor(i%15+1);
for(j=0;j<18;j++)
arc(320+X,240-Y,0,360,j);
delay(q-1);
}}
a=find(a,x,y);
x=X;
y=Y;
fix(x,y,a);
zz=check();
if(zz==1)
{
T=time(NULL);
char ab[4];
ab[0]=48+(T-t)/100;
ab[1]=48+((T-t)/10)%10;
ab[2]=48+(T-t)%10;
ab[3]=32;
cleardevice();
setcolor(3);
outtextxy(100,100," Your Score : ");
setcolor(2);
outtextxy(220,100,ab);
settextstyle(0,0,1);
setfillpattern(0,0);
bar(250,95,380,115);
setcolor(4);
outtextxy(160,200," Your game is over !!!!!!!");
setcolor(5);
outtextxy(160,260," Want to play again (y/n) :");
char pp;
cin>>pp;
if(pp=='y' || pp=='Y'){
closegraph();
main();      }
else
{
closegraph();
exit(1);
}}
}while(1);
getch();
closegraph();
}
float find(float a,float x,float y)
{
if(x==0 && Y==170 && a>0.61 && a<=1.57 )
return (6.28-a);
else if(x==0 && Y==170 && a>1.57 && a<=2.53)
return (6.28-a);
else if(x==0 && X==241 && a>=0 && a<=0.61)
return (3.14-a);
else if(x==0 && X==241 && a>5.67 && a<=6.28)
return (9.42-a);
else if(x==0 && Y==-171 && a>3.75 && a<=4.71 )
return (6.28-a);
else if(x==0 && Y==-171 && a>4.71 && a<=5.67)
return (6.28-a);
else if(x==0 && X==-241 && a>=3.14 && a<=3.75)
return (9.42-a);
else if(x==0 && X==-241 && a>2.53 && a<3.14)
return (3.14-a);
else if(y==-171 && ( Y==170 || Y==171) && a<1.57)
return (4.71+a);
else if(x==-241 && ( Y==170 || Y==171) )
return (4.71+a);
else if(x==241 && (Y==170 || Y==171) )
return (6.28-a);
else if(y==-171 && (Y==170 || Y==171) && a>1.57)
return (6.28-a);
else if((y==171 || y==170 ) && X==241)
return (9.42-a);
else if(y==-171 && X==241)
return (3.14-a);
else if(x==-241 && X==241 && a>4.71)
return (9.42-a);
else if(x==-241 && X==241 && a<1.57)
return (3.14-a);
else if(x==241 && Y==-171)
return (6.28-a);
else if(x==-241 && Y==-171)
return (6.28-a);
else if((y==170 || y==171) && Y==-171 && a>4.71)
return (6.28-a);
else if((y==170 ||  y==171) && Y==-171 && a<4.71)
return (6.28-a);
else if((y==170 || y==171) && X==-241)
return (9.42-a);
else if((y==170 ||  y==171) && X==241)
return (9.42-a);
else if(y==-171 && X==-241)
return (3.14-a);
else if(x==241 && X==-241 && a>3.14)
return (9.42-a);
else if(x==241 && X==-241 && a<3.14)
return (3.14-a);
else
return 0;
}
void fix(int x,int y,float a)
{
if(x==0.0 && y==0.0 && a>0.61 && a<=2.53 )
{
s=0;
f=170;
m='y';
n='+';
}
else if(x==0.0 && y==0.0 && ((a>5.67 && a<6.28) ||(a>=0 && a<0.61)))
{
s=0;
f=241;
m='x';
n='+';
}
else if(x==0.0 && y==0.0 && a>3.75 && a<=5.67 )
{
s=0;
f=-171;
m='y';
n='-';
}
else if(x==0 && y==0 && a>=2.53 && a<=3.75)
{
s=0;
f=-241;
m='x';
n='-';
}
else if(y==-171)
{
if(a>=0 && a<=1.57){
if(((tan(a)*(241-x))+y)<=171)
{
s=x;
f=241;
m='x';
n='+';
}
else if(((171-y+(tan(a)*x))/tan(a))<=241)
{
s=y;
f=171;
m='y';
n='+';
}  }
if(a>1.57 && a<=3.14){
if(((tan(a)*(-241-x))+y)<=171)
{
s=x;
f=-241;
m='x';
n='-';
}
else if(((171-y+(tan(a)*x))/tan(a))>=-241)
{
s=y;
f=171;
m='y';
n='+';
}  }
}
else if(x==-241)
{
if(a>=0 && a<=1.57){
if(((tan(a)*(241-x))+y)<=171)
{
s=x;
f=241;
m='x';
n='+';
}
else if(((171-y+(tan(a)*x))/tan(a))<=241)
{
s=y;
f=171;
m='y';
n='+';
}  }
if(a>=4.71 && a<6.28){
if(((tan(a)*(241-x))+y)>=-171)
{
s=x;
f=241;
m='x';
n='+';
}
else if(((-171-y+(tan(a)*x))/tan(a))<=241)
{
s=y;
f=-171;
m='y';
n='-';
}  }
}
else if(x==241)
{
if(a>=1.57 && a<=3.14){
if(((tan(a)*(-241-x))+y)<=171)
{
s=x;
f=-241;
m='x';
n='-';
}
else if(((171-y+(tan(a)*x))/tan(a))>=-241)
{
s=y;
f=171;
m='y';
n='+';
}  }
if(a>3.14 && a<=4.71){
if(((tan(a)*(-241-x))+y)>=-171)
{
s=x;
f=-241;
m='x';
n='-';
}
else if(((-171-y+(tan(a)*x))/tan(a))>=-241)
{
s=y;
f=-171;
m='y';
n='-';
}  }
}
else if(y==170 || y==171)
{
if(a>=4.71 && a<=6.28){
if(((tan(a)*(241-x))+y)>=-171)
{
s=x;
f=241;
m='x';
n='+';
}
else if(((-171-y+(tan(a)*x))/tan(a))<=241)
{
s=y;
f=-171;
m='y';
n='-';
}  }
if(a>3.14 && a<=4.71){
if(((tan(a)*(-241-x))+y)>=-171)
{
s=x;
f=-241;
m='x';
n='-';
}
else if(((-171-y+(tan(a)*x))/tan(a))>=-241)
{
s=y;
f=-171;
m='y';
n='-';
}  }
}
}