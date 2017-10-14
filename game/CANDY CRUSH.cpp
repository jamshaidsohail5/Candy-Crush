#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<Windows.h>
#include<time.h> 
const int no_of_columns=7;
void initializingboard(char board[][no_of_columns],int no_of_rows);
void instructions(char board[][no_of_columns],int no_of_rows);
void printingboard(char board[][no_of_columns],int no_of_rows, int temp1, int temp2);
void playgame (char board[][no_of_columns],int no_of_rows, int &temp1, int &temp2);
int horizontalcheck(char board[][no_of_columns],int no_of_rows);
int verticlecheck(char board[][no_of_columns],int no_of_rows);
using namespace std;
void instructions(char board[][no_of_columns],int no_of_rows)
{
	cout<<"WELCOME TO MY FIRST GAME"<<endl;
	cout<<"You have to follow the following instructions"<<endl;
	cout<<"1:Go on the candy which you want to move and Press ENTER"<<endl;
	cout<<"2:Press W if you want to move it above"<<endl;
	cout<<"3:Press A if you want to move it left"<<endl;
	cout<<"4:Press S if you want to move it down"<<endl;
	cout<<"5:Press D if you want to move it right"<<endl;
	cout<<"\tENGOY PLAYING GAME!"<<endl;
}
void initializingboard(char board[][no_of_columns],int no_of_rows)
{
	cout<<setw(50)<<"WELCOME TO MY FIRST GAME\n\n";
	cout<<setw(50)<<"Important instructions\n\n\n\n"<<endl;
	int temp=0;
	int arr[6]={66,80,82,86,89,71};
	temp=rand()%6;
	srand (time(NULL));
	for(int i=0;i<no_of_rows;i++)
	{
		for(int j=0;j<no_of_columns;j++)
		{
			board[i][j]=arr[temp];
			temp=rand()%6;
		}
	}
	cout<<setw(43)<<"____________________________________\n\n";
}
void printingboard(char board[][no_of_columns],int no_of_rows, int temp1, int temp2)
{
	int k=1;
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	cout<<"________________________________\n";
	for(int i=0;i<no_of_rows;i++)
	{
		for(int j=0;j<no_of_columns;j++)
		{
			if(board[i][j]=='G')
			{
				SetConsoleTextAttribute(hconsole,10);
			}
			else  if(board[i][j]=='B')
			{
				SetConsoleTextAttribute(hconsole,01);
			}
			else if(board[i][j]=='R')
			{
				SetConsoleTextAttribute(hconsole,12);
			}
			else if(board[i][j]=='P')
			{
				SetConsoleTextAttribute(hconsole,13);
			}
			else if(board[i][j]=='Y')
			{
				SetConsoleTextAttribute(hconsole,06);
			}
			else if(board[i][j]=='V')
			{
				SetConsoleTextAttribute(hconsole,8);
			}

			if(i==temp2&&j==temp1)
			{
				SetConsoleTextAttribute(hconsole,150);	                 
			}


			cout<<"   "<<setw(3)<<board[i][j];

		}

		cout<<endl<<endl;
	}
	instructions(board,no_of_rows);
	cout<<"________________________________\n";
	while (k!=0)
	{
		playgame(board,no_of_rows, temp1, temp2);
	}
}
void playgame(char board[][no_of_columns],int no_of_rows, int &temp1, int &temp2)
{
	HANDLE hconsole=0;
	int ret;
	int inde;
	int swaA=0,swaD=0,swaS=0,swaW=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	int ch=0;
	int k=1;
	verticlecheck(board,no_of_rows);
	horizontalcheck(board,no_of_rows);
	ch=_getch();
	if (ch=='d'||ch=='D')
	{
		if (temp1<6)
			temp1++;
	}
	if (ch=='a'||ch=='A')
	{
		if (temp1>0)
			temp1--;
	}
	if (ch=='s'||ch=='S')
	{
		if (temp2<6)
			temp2++;
	}
	if (ch=='w'||ch=='W')
	{
		if (temp2>0)
			temp2--;
	}
	if(ch==13)
	{	swaA=swaD=swaS=swaW=0;
		inde=-1;
		ch=_getch();
		int swapA=0,swapB=0;
		if(ch=='a'||ch=='A')
		{

			if(temp1!=0)
			{
				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2][temp1-1];
				board[temp2][temp1-1]=swapA;	
				inde=temp1;
				swaA=1;
}
			
		}
		if(ch=='s'||ch=='S')
		{
			if(temp2<no_of_rows-1)
			{

				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2+1][temp1];
				board[temp2+1][temp1]=swapA;	
				inde=temp2;
				swaS=1;
			
			}	
						
		}
		if(ch=='d'||ch=='D')
		{
			if(temp1<no_of_columns-1)
			{

				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2][temp1+1];
				board[temp2][temp1+1]=swapA;
				inde=temp1;
				swaD=1;
			
			}	
				
		}
		if(ch=='w'||ch=='W')
		{
			if(temp2!=0)
			{

				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2-1][temp1];
				board[temp2-1][temp1]=swapA;
				inde=temp2;
				swaW=1;
				
			}	

				
		}
		int check=0;		
		ret=0;
		ret=horizontalcheck(board,no_of_rows);
		ret=verticlecheck(board,no_of_rows);
		while(ret!=0)
		{
			check=-1;
			ret=horizontalcheck(board,no_of_rows);
			ret=verticlecheck(board,no_of_rows);
		}
		if(ret==0&&check==0)
		{
			if(swaA==1&&inde!=-1){
				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2][temp1-1];
				board[temp2][temp1-1]=swapA;	
			}
			if(swaS==1&&inde!=-1){
				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2+1][temp1];
				board[temp2+1][temp1]=swapA;	
			}
			if(swaD==1&&inde!=-1){
				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2][temp1+1];
				board[temp2][temp1+1]=swapA;
			}
			if(swaW==1&&inde!=-1){
				swapA=board[temp2][temp1];
				board[temp2][temp1]=board[temp2-1][temp1];
				board[temp2-1][temp1]=swapA;
			}

		}
		check=0;
		ret=0;

	}
	printingboard(board,no_of_rows,temp1,temp2);
}
int horizontalcheck(char board[][no_of_columns],int no_of_rows)
{
	int te=0;
	int arr[6]={66,80,82,86,89,71};
	te=rand()%6;
	srand (time(NULL));
	int ret=0;
	char temp=0;
	int found=0;
	for(int i=0;i<no_of_rows;i++)
	{

		for(int j=0; j<no_of_columns;j++)
		{

			found=0;
			temp=board[i][j];
			for(int l=j;l<no_of_columns && board[i][l]==temp;l++)
				found++;
			if(found>2)
			{
				ret=1;
				for(int l=j;l<j+found;l++)
				{
					for(int t=i;t>0;t--)
					{
						board[t][l]=board[t-1][l];
						te=rand()%6;
					}
					te=rand()%6;
					board[0][l]=arr[te];
				}
			}

		}

	}
	return ret;
}
int verticlecheck(char board[][no_of_columns],int no_of_rows)
{
	int te=0;
	int arr[6]={66,80,82,86,89,71};
	te=rand()%6;
	srand (time(NULL));

	int ret=0;
	char temp=0;
	int found=0;
	for(int j=0; j<no_of_columns;j++)
	{
		for(int i=0;i<no_of_rows;i++)
		{

			found=0;
			temp=board[i][j];
			for(int l=i;l<no_of_columns && board[l][j]==temp;l++)
				found++;
			if(found>2)
			{
				ret=1;
				for(int l=i;l<i+found;l++)
				{
					if(l-found>=0)
					{
						board[l][j]=board[l-found][j];
					}
					else
					{
						te=rand()%6;
						board[l][j]=arr[te];
					}
					
				}
				for(int l=i-1;l>=0;l--)
				{
					if(l-found-1>=0)
					{
						board[l][j]=board[l-found][j];
					}
					else
					{
						te=rand()%6;
						board[l][j]=arr[te];
					}
				}	

			}



		}

	}
	return ret;
}
int main()
{
	const int cols=7;
	const int rows=7;
	int t=0, t1=0;
	char board1[rows][cols];

	initializingboard(board1,rows);
	printingboard(board1,cols,t,t1);

	system("pause");
	return 0;
}
