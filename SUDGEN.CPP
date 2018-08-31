#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
int ab=10,cd=10,xy=1;
int play();
void cover();
void instruc()
{
	cleardevice();
	setbkcolor(12);
	setfillstyle(11,14);
	bar3d(0,0,getmaxx(),getmaxy(),0,0);
	settextstyle(7,0,5);
	outtextxy(150,15,"INSTRUCTIONS");
	outtextxy(150,22,"_____________");
	settextstyle(0,0,2);
	outtextxy(10,140,"HOW TO PLAY - ");
	outtextxy(10,300,"CONTROLS -");
	settextstyle(0,0,1);
	outtextxy(40,180,"Sudoku  is  a  puzzle  game .  The  main  motive  is  to  fill");
	outtextxy(40,205,"the  9 X 9  grid  by  numbers  from  1-9  such  that  no  same");
	outtextxy(40,230,"number  exists  in  the  same  row ,  same  coloumn  and  same");
	outtextxy(40,255,"block .  Apply  your brain and solve this challenging puzzle.");
	rectangle(160,350,200,390);
	rectangle(110,400,150,440);
	rectangle(160,400,200,440);
	rectangle(210,400,250,440);
	settextstyle(0,0,2);
	outtextxy(175,365,"W");
	outtextxy(125,415,"A");
	outtextxy(175,415,"S");
	outtextxy(225,415,"D");
	settextstyle(2,0,6);
	outtextxy(10,460,"PRESS ANY KEY TO ESCAPE");
	getch();
	}
void cover()
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	setfillstyle(11,13);
	bar3d(0,0,getmaxx(),getmaxy(),0,0);
	setcolor(15);
	settextstyle(0,0,0);
	outtextxy(10,10,"SUDOKU MASTER        SUDOKU MASTER        SUDOKU MASTER        SUDOKU MASTER");
	settextstyle(0,1,0);
	outtextxy(18,40,"SUKODU                                      MASTER");
	outtextxy(620,40,"SUDOKU                                      MASTER");
	settextstyle(0,0,0);
	outtextxy(10,460,"SUDOKU MASTER        SUDOKU MASTER        SUDOKU MASTER        SUDOKU MASTER");
	setcolor(RED);
	settextstyle(7,0,7);
	outtextxy(35,100,"SUDOKU MASTER");
	outtextxy(35,115,"______________");
	settextstyle(7,0,5);
	setcolor(YELLOW);
	outtextxy(100,225,"- PLAY");
	setcolor(MAGENTA);
	outtextxy(100,275,"- INSTRUCTIONS");
	outtextxy(100,325,"- EXIT");
	int x=225,I=1;
	char t;
	do
	{
		t=getch();
		if(t=='w'&&x>225)
		{
			setcolor(MAGENTA);
			if(I==2)
				outtextxy(100,x,"- INSTRUCTIONS");
			if(I==3)
				outtextxy(100,x,"- EXIT");
			x-=50;
			setcolor(YELLOW);
			if(I==2)
				outtextxy(100,x,"- PLAY");
			if(I==3)
				outtextxy(100,x,"- INSTRUCTIONS");
			I--;
			}
		else if(t=='s'&&x<325)
		{
			setcolor(MAGENTA);
			if(I==1)
				outtextxy(100,x,"- PLAY");
			if(I==2)
				outtextxy(100,x,"- INSTRUCTIONS");
			x+=50;
			setcolor(YELLOW);
			if(I==1)
				outtextxy(100,x,"- INSTRUCTIONS");
			if(I==2)
				outtextxy(100,x,"- EXIT");
			I++;
			}
		}while(t!=13);
	if(x==225)
		play();
	else if(x==275)
		instruc();
	else
		exit(0);
	ab=10;cd=10;
	cover();
	}
void func()
{
	settextstyle(0,0,3);
	setcolor(LIGHTRED);
	outtextxy(ab,cd,"SUDOKU MASTER");
	outtextxy(ab,15,"_____________");
	ab+=20;
	if(ab>300)
		ab=10;
	setcolor(xy);
	outtextxy(ab,cd,"SUDOKU MASTER");
	outtextxy(ab,15,"_____________");
	xy++;
	delay(150);
	if(xy==12)
		xy++;
	if(xy==15)
		xy=1;

	}
int play()
{
	clrscr();
	int X=100,Y=80,x=460,y=80;
	int xyz=0,f,g,count4,arr3[15][15],arr2[15][15],arr1[15][15],arr4[9][9]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},N,R,C,u,v,NUM,o,p,i,j,k,l,m,n,count1,count6=0,count2,count3,arr[9][9]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},V,A,B;
	char choice[2]="a\0";
	cleardevice();
	setbkcolor(12);
	setcolor(WHITE);
	settextstyle(0,0,3);
	outtextxy(10,10,"SUDOKU MASTER");
	outtextxy(10,15,"_____________");
	randomize();
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(arr[i][j]!=0)
				V=arr[i][j]+1;
			else
				V=1;
			for(k=V;k<=9;k++)
			{
				count1=0;count2=0;count3=0;count6=0;
				for(l=0;l<9;l++)
				{
					if(k==arr[i][l]&&l!=j)
					{
						count1=0;
						break;
						}
					else
						count1++;
					}
				for(m=0;m<9;m++)
				{
					if(k==arr[m][j]&&m!=i)
					{
						count2=0;
						break;
						}
					else
						count2++;
					}
				if(i==1||i==2||i==0)
					A=0;
				else if(i==4||i==5||i==3)
					A=3;
				else
					A=6;


				if(j==0||j==1||j==2)
					B=0;
				else if(j==3||j==4||j==5)
					B=3;
				else
					B=6;
				for(n=A;n<A+3;n++)
				{
					for(o=B;o<B+3;o++)
					{
						if(k==arr[n][o]&&n!=i&&o!=j)
						{
							count3=0;
							n+=4;
							break;
							}
						else
							count3++;
						}
					}
				if(count1>0&&count2>0&&count3>0)
				{
					 count6=1;
					 break;
					 }
				}
			if(count6==0)
			{
				arr[i][j]=0;
				if(j!=0)
					j-=2;
				else
				{
					j=7;
					i--;
					}
				continue;
				}
			NUM=random(9)+1;
			count1=0;count2=0;count3=0;count6=0;
			for(l=0;l<9;l++)
			{
				if(NUM==arr[i][l]&&l!=j)
				{
					count1=0;
					j--;
					break;
					}
				else
					count1++;
				}
			if(count1==0)
				continue;
			for(m=0;m<9;m++)
			{
				if(NUM==arr[m][j]&&m!=i)
				{
					count2=0;
					j--;
					break;
					}
				else
					count2++;
				}
			if(count2==0)
				continue;
			if(i==1||i==2||i==0)
				A=0;
			else if(i==4||i==5||i==3)
				A=3;
			else
				A=6;

			if(j==0||j==1||j==2)
				B=0;
			else if(j==3||j==4||j==5)
				B=3;
			else
				B=6;
			for(n=A;n<A+3;n++)
			{
				for(o=B;o<B+3;o++)
				{
					if(NUM==arr[n][o]&&n!=i&&o!=j)
					{
						count3=0;
						j--;
						n+=4;
						break;
						}
					else
						count3++;
					}
				}
			if(count3==0)
				continue;
			arr[i][j]=NUM;
			}
		}
	settextstyle(0,0,2);
	outtextxy(20,50,"Enter Difficulty Level - (1,2,3) ");
	choice[0]=getch();
	outtextxy(550,50,choice);
	switch(choice[0])
	{
		case '1': N=random(6)+49;
						break;
		case '2': N=random(6)+54;
						break;
		case '3': N=random(5)+60;
						break;
		default : N=random(6)+54;
		}
	int r[100],c[100];
	for(i=0;i<N;i++)
	{
		count4=0;
		R=random(9);
		r[i]=R;
		C=random(9);
		c[i]=C;
		for(j=0;j<i;j++)
		{
			if(R==r[j]&&C==c[j])
			{
				count4++;
				i--;
				break;
				}
			}
		if(count4==0)
			arr[R][C]=0;
		}
	for(int q=0;q<9;q++)
	{
		for(p=0;p<9;p++)
		{
			arr3[q][p]=arr[q][p];
			arr2[q][p]=arr[q][p];
			}
		}
	setcolor(WHITE);
	for(i=0;i<=9;i++)
	{
		if(i%3==0)
			setlinestyle(SOLID_LINE,1,3);
		else
			setlinestyle(DASHED_LINE,1,1);
		line(X,Y,x,y);
		Y+=40,y+=40;
		}
	X=100;Y=80;x=100;y=440;
	for(i=0;i<=9;i++)
	{
		if(i%3==0)
			setlinestyle(SOLID_LINE,1,3);
		else
			setlinestyle(DASHED_LINE,1,2);
		line(X,Y,x,y);
		X+=40;x+=40;
		}
	setcolor(YELLOW);
	settextstyle(0,0,2);
	float O=110,D=95;
	int t;
	char type[]="a\0";
	for(u=0;u<9;u++)
	{
		for(v=0;v<9;v++)
		{
			moveto(O,D);
			if(arr2[u][v]==0)
			{
				O+=40;
				moveto(O,D);
				}
			else
			{
				type[0]=(arr2[u][v]+48);
				outtext(type);
				O+=40;
				}
			}
		D+=40;
		O=110;
		}
	O=110;D=95;
	int a=0,w=0,z=0;
	moveto(20,450);
	settextstyle(2,0,6);
	outtext("PRESS ESCAPE TO EXIT");
	outtextxy(500,200,"HINT(h) - 3");
	outtextxy(500,210,"_______");
	settextstyle(0,0,2);
	for(q=0;q<9;q++)
	{
		for(p=0;p<9;p++)
			arr1[q][p]=arr[q][p];
		}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			count6=0;
			if(arr1[i][j]==0)
			{
				count4=0;
				if(arr[i][j]!=0)
					V=arr[i][j]+1;
				else
					V=1;
				for(k=V;k<=9;k++)
				{
					count1=0;count2=0;count3=0;
					for(l=0;l<9;l++)
					{
						if(k==arr[i][l]&&l!=j)
						{
							count1=0;
							goto label;
							}
						else
							count1++;
						}
					for(m=0;m<9;m++)
					{
						if(k==arr[m][j]&&m!=i)
						{
							count2=0;
							goto label;
							}
						else
							count2++;
						}
					if(i==1||i==2||i==0)
						A=0;
					else if(i==4||i==5||i==3)
						A=3;
					else
						A=6;


					if(j==0||j==1||j==2)
						B=0;
					else if(j==3||j==4||j==5)
						B=3;
					else
						B=6;
					for(n=A;n<A+3;n++)
					{
						for(o=B;o<B+3;o++)
						{
							if(k==arr[n][o]&&n!=i&&o!=j)
							{
								count3=0;
								goto label;
								}
							else
								count3++;
							}
						}
					if(count1>0&&count2>0&&count3>0)
					{
						count6=1;
						arr[i][j]=k;
						break;
						}
					label:;
					}
				if(count6==0)
				{
					arr[i][j]=0;
					count4++;
					if(j!=0)
						j-=2;
					else
					{
						i--;
						j=7;
						}
					}
				}
			else
			{
				if(count4>0)
				{
					if(j!=0)
						j-=2;
					else
					{
						i--;
						j=7;
						}
					}
				}
			}
		}
	do
	{
		moveto(O,D);
		do
		{
			while(!kbhit())
			{
				setcolor(15);
				outtextxy(O,D,"_");
				delay(100);
				setcolor(LIGHTRED);
				outtextxy(O,D,"_");
				delay(120);
				func();
				settextstyle(0,0,2);
				}
			t=getch();
			if(t=='d')
			{
				if((O+40)>430)
					break;
				O+=40;
				moveto(O,D);
				z++;
				if(arr4[w][z]!=0)
					setcolor(11);
				else if(arr3[w][z]!=0)
					setcolor(YELLOW);
				else if(arr2[w][z]!=0)
					setcolor(GREEN);
				if(arr2[w][z]!=0)
				{
					type[0]=arr2[w][z]+48;
					outtext(type);
					}
				}
			else if(t=='a')
			{
				if((O-40)<110)
					break;
				O-=40;
				moveto(O,D);
				z--;
				if(arr4[w][z]!=0)
					setcolor(11);
				else if(arr3[w][z]!=0)
					setcolor(YELLOW);
				else if(arr2[w][z]!=0)
					setcolor(GREEN);
				if(arr2[w][z]!=0)
				{
					type[0]=arr2[w][z]+48;
					outtext(type);
					}
				}
			else if(t=='w')
			{
				if((D-40)<95)
					break;
				D-=40;
				moveto(O,D);
				w--;
				if(arr4[w][z]!=0)
					setcolor(11);
				else if(arr3[w][z]!=0)
					setcolor(YELLOW);
				else if(arr2[w][z]!=0)
					setcolor(GREEN);
				if(arr2[w][z]!=0)
				{
					type[0]=arr2[w][z]+48;
					outtext(type);
					}
				}
			else if(t=='s')
			{
				if((D+40)>415)
					break;
				D+=40;
				moveto(O,D);
				w++;
				if(arr4[w][z]!=0)
					setcolor(11);
				else if(arr3[w][z]!=0)
					setcolor(YELLOW);
				else if(arr2[w][z]!=0)
					setcolor(GREEN);
				if(arr2[w][z]!=0)
				{
					type[0]=arr2[w][z]+48;
					outtext(type);
					}
				}
			else if(t=='h')
			{
				if(xyz==3)
				{
					sound(35);
					delay(100);
					nosound();
					}
				else
				{
					if(arr2[w][z]!=0)
					{
						setcolor(12);
						type[0]=arr2[w][z]+48;
						outtext(type);
						moveto(O,D);
						}
					setcolor(11);
					arr4[w][z]=arr[w][z];
					arr2[w][z]=arr[w][z];
					type[0]=arr[w][z]+48;
					outtext(type);
					settextstyle(2,0,6);
					setcolor(12);
					type[0]=51-xyz;
					outtextxy(594,200,type);
					xyz++;
					type[0]=51-xyz;
					setcolor(14);
					outtextxy(594,200,type);
					settextstyle(0,0,2);
					}
				break;
				}
			else if(t==27)
				break;
			else if(t==8&&arr3[w][z]==0&&arr4[w][z]==0)
			{
				setcolor(12);
				type[0]=arr2[w][z]+48;
				outtextxy(O,D,type);
				arr2[w][z]=0;
				moveto(O,D);
				}
			else
			{
				if(t==8)
					break;
				if(arr3[w][z]==0&&arr2[w][z]!=0)
				{
					type[0]=arr2[w][z]+48;
					setcolor(12);
					outtextxy(O,D,type);
					moveto(O,D);
					}
				if(arr3[w][z]!=0)
					break;
				setcolor(GREEN);
				arr2[w][z]=t-48;
				type[0]=arr2[w][z]+48;
				outtext(type);
				gotoxy(10,10);
				moveto(O,D);
				break;
				}
			}while(a==0);
		}while(t!=27);
	lable:
	int arr5[9][9];
	for(q=0;q<9;q++)
	{
		for(p=0;p<9;p++)
			arr5[q][p]=arr2[q][p];
		}
	settextstyle(0,0,2);
	setbkcolor(6);
	int count=0;
	cleardevice();
	for(int h=0;h<9;h++)
	{
		for(int d=0;d<9;d++)
		{
			if(arr2[h][d]!=arr[h][d])
			{
				count=0;
				break;
				}
			else
				count++;
			}
		if(count==0)
			break;
		}
	if(count==0)
	{
		setbkcolor(BROWN);
		setfillstyle(11,BLUE);
		bar3d(0,0,getmaxx(),getmaxy(),0,0);
		setcolor(YELLOW);
		outtextxy(10,20,"YOU MISSED IT ");
		outtextxy(10,45,"WANT TO SWITCH TO ANALYSER(1),");
		outtextxy(10,65,"SEE THE SOLUTION(2) OR EXIT(3)");
		type[0]=getch();
		outtextxy(520,65,type);
		if(type[0]!='1'&&type[0]!='2')
		{
			getch();
			return 0;
			}
		getch();
		cleardevice();
		setbkcolor(LIGHTGREEN);
		setcolor(BROWN);
		X=100;Y=80;x=460;y=80;
		for(i=0;i<=9;i++)
		{
			if(i%3==0)
				setlinestyle(SOLID_LINE,1,3);
			else
				setlinestyle(DASHED_LINE,1,1);
			line(X,Y,x,y);
			Y+=40,y+=40;
			}
		X=100;Y=80;x=100;y=440;
		for(i=0;i<=9;i++)
		{
			if(i%3==0)
				setlinestyle(SOLID_LINE,1,3);
			else
				setlinestyle(DASHED_LINE,1,2);
			line(X,Y,x,y);
			X+=40;x+=40;
			}
		settextstyle(0,0,2);
		char abc=type[0],pqr[]="SUDOKU ANALYSER";
		randomize();
		switch(abc)
		{
		      case '1':
				settextstyle(2,0,6);
				outtextxy(500,200,"HINT(h) - ");
				type[0]=51-xyz;
				outtextxy(594,200,type);
				outtextxy(500,210,"___________");
				outtextxy(20,450,"PRESS ESCAPE TO CHECK");
				settextstyle(0,0,3);
				int de=100;
				for(i=0;pqr[i]!='\0';i++)
				{
					if(pqr[i]==' ')
					{
						de+=30;
						continue;
						}
					setcolor(i+1);
					if(i+1==10)
						setcolor(1);
					type[0]=pqr[i];
					outtextxy(de,15,type);
					de+=27;
					delay(300);
					}
				outtextxy(100,25,"_________________");
				settextstyle(0,0,2);
				O=105;D=85;ab=110;cd=95;
				setcolor(5);
				setfillstyle(SOLID_FILL,12);
				for(u=0;u<9;u++)
				{
					for(v=0;v<9;v++)
					{
						setcolor(BLUE);
						if(arr4[u][v]!=0)
							setcolor(9);
						type[0]=arr2[u][v]+48;
						if(arr2[u][v]!=arr[u][v]&&arr2[u][v]!=0)
						{
							setcolor(12);
							rectangle(O,D,O+29,D+29);
							floodfill(O+5,D+5,12);
							setcolor(BLUE);
							}
						if(arr2[u][v]!=0)
							outtextxy(ab,cd,type);
						ab+=40;
						O+=40;
						}
					D+=40;
					cd+=40;
					O=105;ab=110;
					}
				O=110;D=95;w=0;z=0;
				do
				{
					moveto(O,D);
					do
					{
						while(!kbhit())
						{
							setcolor(15);
							outtextxy(O,D,"_");
							delay(100);
							if(arr5[w][z]==0||arr3[w][z]!=0)
								setcolor(LIGHTGREEN);
							else
								setcolor(12);
							outtextxy(O,D,"_");
							delay(120);
							settextstyle(0,0,2);
							}
						t=getch();
						if(t=='d')
						{
							if((O+40)>430)
								break;
							O+=40;
							moveto(O,D);
							z++;
							if(arr4[w][z]!=0)
								setcolor(9);
							else
								setcolor(BLUE);
							if(arr2[w][z]!=0)
							{
								type[0]=arr2[w][z]+48;
								outtext(type);
								}
							}
						else if(t=='a')
						{
							if((O-40)<110)
								break;
							O-=40;
							moveto(O,D);
							z--;
							if(arr4[w][z]!=0)
								setcolor(9);
							else
								setcolor(BLUE);
							if(arr2[w][z]!=0)
							{
								type[0]=arr2[w][z]+48;
								outtext(type);
								}
							}
						else if(t=='w')
						{
							if((D-40)<95)
								break;
							D-=40;
							moveto(O,D);
							w--;
							if(arr4[w][z]!=0)
								setcolor(9);
							else
								setcolor(BLUE);
							if(arr2[w][z]!=0)
							{
								type[0]=arr2[w][z]+48;
								outtext(type);
								}
							}
						else if(t=='s')
						{
							if((D+40)>415)
								break;
							D+=40;
							moveto(O,D);
							w++;
							if(arr4[w][z]!=0)
								setcolor(9);
							else
								setcolor(BLUE);
							if(arr2[w][z]!=0)
							{
								type[0]=arr2[w][z]+48;
								outtext(type);
								}
							}
						else if(t=='h')
						{
							if(xyz==3)
							{
								sound(35);
								delay(100);
								nosound();
								}
							else
							{
								if(arr5[w][z]!=0)
								{
									setcolor(12);
									type[0]=arr2[w][z]+48;
									outtextxy(O,D,type);
									moveto(O,D);
									}
								setcolor(9);
								arr4[w][z]=arr[w][z];
								arr2[w][z]=arr[w][z];
								type[0]=arr[w][z]+48;
								outtext(type);
								settextstyle(2,0,6);
								setcolor(LIGHTGREEN);
								type[0]=51-xyz;
								outtextxy(594,200,type);
								xyz++;
								type[0]=51-xyz;
								setcolor(BROWN);
								outtextxy(594,200,type);
								settextstyle(0,0,2);
								}
							}
						else if(t==27)
							break;
						else if(t==8&&arr3[w][z]==0&&arr4[w][z]==0)
						{
							if(arr5[w][z]==0||arr3[w][z]!=0)
								setcolor(LIGHTGREEN);
							else
								setcolor(12);
							type[0]=arr2[w][z]+48;
							outtextxy(O,D,type);
							arr2[w][z]=0;
							}

						else
						{
							if(t==8)
								break;
							if(arr3[w][z]==0&&arr2[w][z]!=0)
							{
								type[0]=arr2[w][z]+48;
								if(arr5[w][z]==0||arr3[w][z]!=0)
									setcolor(LIGHTGREEN);
								else
									setcolor(12);
								outtextxy(O,D,type);
								moveto(O,D);
								}
							if(arr3[w][z]!=0)
								break;
							setcolor(BLUE);
							arr2[w][z]=t-48;
							type[0]=arr2[w][z]+48;
							outtext(type);
							moveto(O,D);
							break;
							}
						}while(a==0);
					}while(t!=27);
				goto lable;

		      case '2': settextstyle(0,0,3);
				de=100;
				char pq[]="SUDOKU SOLVER";
				for(i=0;pq[i]!='\0';i++)
				{
					if(pq[i]==' ')
					{
						de+=30;
						continue;
						}
					setcolor(i+1);
					if(i+1==10)
						setcolor(1);
					type[0]=pq[i];
					outtextxy(de,15,type);
					de+=27;
					delay(300);
					}
				setcolor(15);
				outtextxy(100,25,"_______________");
				settextstyle(0,0,2);
				O=110;D=95;
				for(u=0;u<9;u++)
				{
					for(v=0;v<9;v++)
					{
						if(arr3[u][v]==0)
							setcolor(12);
						else
							setcolor(BLUE);
						type[0]=(arr[u][v]+48);
						outtextxy(O,D,type);
						O+=40;
						}
					D+=40;
					O=110;
					}
				settextstyle(2,0,6);
				outtextxy(20,450,"PRESS ANY KEY TO CONTINUE");
				getch();
				goto lable;
			}
		}
	else
	{
		outtextxy(10,10,"YOU CRACKED IT ");
		outtextxy(10,30,"CONGRATES");
		getch();
		}
	return 0;
	}
void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\bgi");
	cover();
	closegraph();
	}