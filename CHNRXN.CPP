#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
int co=1;
void set(int N[5][15],int C[5][5] );

void start(int a, int b );

void build2(int N[5][15], int a, int b ) ;

void manage(int N[5][15], int k, int z ,int C[5][5] );

void main()
{
	int a,b;
    int gdriver=DETECT,grade;
    initgraph(&gdriver,&grade,"C:\\Tc\\bgi");
	 cout<<" Welcome to Chain-Reaction Game \n";
		do{
			 cout<<" Enter a number of first player's choice  : \n";
				cin>>a;
				  cout<<" Enter a number of second player's choice : \n";
					 cin>>b;
						} while((a%15)==(b%15));

	 start(a,b);
						  }


void start(int a, int b)
{


  int N[5][15],C[5][5],k=0,x,y,z;
		int n=0,p=0,t=0;

	for(int i=0;i<5;i++)
	  for(int j=0;j<15;j++)
		 {
			N[i][j]=0;
			 C[i][j/3]=0;
								 }

do{ n=0,p=0;
	 set(N,C);
	 outtextxy(20,450,"  Enter any no. greater than 25 to quit !!!!");
  if((k%2)==0) {
		  if(k==0)
		   build2(N,a,b);
	 do{
			outtextxy(20,430,"  Player 1 : Enter your box no. :");
			  cin>>z;

				x=(z-1)/5;
				 y=(z-1)%5;

				 if(z>25){
				 closegraph();
				  exit(1);    }
					if(C[x][y]<0 || z<=0)
					 outtextxy(20,410," Wrong input !!!!!!!!!! ");
																		} while(C[x][y]<0 || z>25 || z<=0);

		manage(N,k,z,C);
								  }

	if((k%2)==1) {
		  do{
			outtextxy(20,430," Player 2 : Enter your box no. : ");
			  cin>>z;

				x=(z-1)/5;
				 y=(z-1)%5;
				 if(z>25){
				 closegraph();
				  exit(1);    }

					if(C[x][y]>0 || z<=0)
					 outtextxy(20,410," Wrong input !!!!!!!!!! ");
																		} while(C[x][y]>0 || z>25 || z<=0);

		manage(N,k,z,C);
								  }

		set(N,C);

		 build2(N,a,b);



	 for(i=0;i<5;i++)
		for(int j=0;j<5;j++)
		 {
			if(C[i][j]<0)
			 n++;

			  else if(C[i][j]>0)
				 p++;

				  else
					t++;
											}

		 settextstyle(1,0,3);
		 if( n==25)
			outtextxy(200,40," Player 2 wins !!!!!!!!!!! ");

			else if(p==25)
			  outtextxy(200,40," Player 1 wins !!!!!!!!!!! ");

			  k++;

					}while((n!=25) || (p=!25)) ;

																		}

void set(int N[5][15],int C[5][5])
{
  int i,j;

	 for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			C[i][j]=N[i][3*j]+N[i][3*j+1]+N[i][3*j+2];

							 }


void manage(int N[5][15],int k, int z, int C[5][5])
{
		int n=1,x,y,i;
		  int *A=new int[n];
			A[0]=z;

	 do{
		  for(i=0;i<n;i++)
			 {
				set(N,C);

				  x=(A[i]-1)/5;
					y=(A[i]-1)%5;

					if(A[i]==1 || A[i]==5 || A[i]==21 || A[i]==25)
					 {
						if(C[x][y]==0){
						  if((k%2)==0)
							N[x][3*y+1]=1;
							 else if((k%2)==1)
								N[x][3*y+1]=-1;
														}

							 else if(C[x][y]==1 || C[x][y]==-1 )
								{
								  N[x][3*y+1]=0;

									 if(A[i]==1){
										A[n]=2;
										 A[n+1]=6;
														}

										else if(A[i]==5){
										 A[n]=4;
										  A[n+1]=10;
										  }

											else if(A[i]==21){
											  A[n]=22;
												A[n+1]=16;
																	 }

												else if(A[i]==25){
												 A[n]=24;
												  A[n+1]=20;
												  }

								 n=n+2;
													  }
															  }

			  else if(A[i]==2 || A[i]==3 || A[i]==4 || A[i]==10 || A[i]==15 || A[i]==20 ||A[i]==6 || A[i]==16 || A[i]==11 || A[i]==22 ||A[i]==23 || A[i]==24  )
				 {

					if(C[x][y]==0)
					 {
						if((k%2)==0)
						  N[x][3*y+1]=1;

							else if((k%2)==1)
							  N[x][3*y+1]=-1;
														 }

							  else if( C[x][y]==1 || C[x][y]==-1)
								 {
									if((k%2)==0)
									{
									  N[x][3*y+1]=1;
										N[x][3*y+2]=1;
															 }

										 else if((k%2)==1)
										  {
											 N[x][3*y+1]=-1;
												N[x][3*y+2]=-1;
																	  }

																		  }


										else if(C[x][y]==2 || C[x][y]==-2)
										  {
											  N[x][3*y+1]=0;
												N[x][3*y+2]=0;

											 if( A[i]==2 || A[i]==3 || A[i]==4)
												{
												  A[n]=A[i]+1;
													A[n+1]=A[i]-1;
													 A[n+2]=A[i]+5;
																			 }

												 else if(A[i]==6 || A[i]==11 || A[i]==16)
												  {
													 A[n]=A[i]+1;
													  A[n+1]=A[i]+5;
														A[n+2]=A[i]-5;
																				}

											 else if(A[i]==10 || A[i]==15 || A[i]==20)
												  {
													 A[n]=A[i]-1;
													  A[n+1]=A[i]+5;
														A[n+2]=A[i]-5;
																				}

											  else if(A[i]==22 || A[i]==23 || A[i]==24)
												  {
													 A[n]=A[i]+1;
													  A[n+1]=A[i]-1;
														A[n+2]=A[i]-5;
																				}

												 n=n+3;
																  }
																		  }



  else if(A[i]==7 || A[i]==8 || A[i]==9 || A[i]==12 || A[i]==13 ||A[i]==14 || A[i]==17 || A[i]==18 || A[i]==19)
	{
	  if(C[x][y]==0)
	  {
		if((k%2)==0)
		 N[x][3*y]=1;
		  else if((k%2)==1)
			N[x][3*y]=-1;
											 }

	  else if(C[x][y]==1 || C[x][y]==-1 )
		{
		  if((k%2)==0)
			{
			 N[x][3*y]=1;
			  N[x][3*y+1]=1;
								  }

				else if((k%2)==1)
				 {
					N[x][3*y]=-1;
					 N[x][3*y+1]=-1;
											 }

														}

		  else if(C[x][y]==2 || C[x][y]==-2)
			{
			  if((k%2)==0)
				{
				  N[x][3*y]=1;
					N[x][3*y+1]=1;
					 N[x][3*y+2]=1;
										 }

				  else if((k%2)==1)
					 {
						N[x][3*y]=-1;
						  N[x][3*y+1]=-1;
							N[x][3*y+2]=-1;
													 }

														  }

			else if(C[x][y]==3 || C[x][y]==-3)
			 {
				N[x][3*y]=0;
				 N[x][3*y+1]=0;
				  N[x][3*y+2]=0;

					 A[n]=A[i]+1;
					  A[n+1]=A[i]-1;
						A[n+2]=A[i]+5;
						 A[n+3]=A[i]-5;

							n=n+4;
												}

																		 }

																			  }


																					} while(n!=i);

	 delete[n] A;
						}




void build2(int N[5][15],int a,int b)
 {
    int error;
    int x,z,i;
    int A[5][5];
    char y[2];
    for(x=0;x<5;x++)
    for(z=0;z<5;z++)
    A[x][z]=0;
    for(x=0;x<5;x++)
    for(z=0;z<15;z++)
     A[x][(z/3)]=A[x][(z/3)]+N[x][z];
    error=graphresult();
    if(error!=grOk){
    printf(" There is some error in this opening \n");
    printf(" Error is : %s ",grapherrormsg(error));
    getch();
    }
    cleardevice();
    if(co%2==1)
    setcolor(a%15+1);
    else
    setcolor(b%15+1);
    line(480,180,480,320);
    line(520,180,520,320);
    line(320,180,320,320);
    line(360,180,360,320);
    line(400,180,400,320);
    line(440,180,440,320);
    line(320,180,520,180);
    line(320,208,520,208);
    line(320,236,520,236);
    line(320,264,520,264);
    line(320,292,520,292);
    line(320,320,520,320);

    settextstyle(1,0,1);
    for(x=0;x<25;x++)
    {  setcolor(x%15+1);
    y[0]=48+(x+1)/10;
    y[1]=48+(x+1)%10;
    outtextxy(41+40*(x%5),181+28*(x/5),y);
    setfillpattern(0,0);
    bar(62+40*(x%5),181+28*(x/5),90+40*(x%5),205+28*(x/5)); }
    setcolor(co%15+1);
    line(40,180,40,320);
    line(80,180,80,320);
    line(120,180,120,320);
    line(160,180,160,320);
    line(200,180,200,320);
    line(240,180,240,320);
    line(40,180,240,180);
    line(40,208,240,208);
    line(40,236,240,236);
    line(40,264,240,264);
    line(40,292,240,292);
    line(40,320,240,320);
    setcolor(2);
    for(x=0;x<5;x++)
    for(z=0;z<5;z++)
    {
    if(A[x][z]==1 || A[x][z]==-1){
    if(A[x][z]==1)
    setcolor(a%15+1);
    else
    setcolor(b%15+1);
    for(i=0;i<8;i++)
    arc(330+40*z,190+28*x,0,360,i); }
    else  if(A[x][z]==2 || A[x][z]==-2){
      if(A[x][z]==2)
    setcolor(a%15+1);
    else
    setcolor(b%15+1);
     for(i=0;i<8;i++){
     arc(330+40*z,189+28*x,0,360,i);
      arc(340+40*z,189+28*x,0,360,i);
       } }
      else  if(A[x][z]==3 || A[x][z]==-3){
      if(A[x][z]==3)
    setcolor(a%15+1);
    else
    setcolor(b%15+1);
     for(i=0;i<8;i++){
     arc(330+40*z,189+28*x,0,360,i);
      arc(340+40*z,189+28*x,0,360,i);
       arc(350+40*z,189+28*x,0,360,i); } }
      }
      co++;
    }

