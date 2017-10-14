#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
void menu()
{
	system("cls");
	HANDLE  hConsole;
    int k =10;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
	cout<<endl<<endl;
	cout<<"\t\tWelcome to Connect 4"<<endl<<endl<<endl;
	cout<<"\t\t1.Start game..."<<endl<<endl;
	cout<<"\t\t2.Instructions..."<<endl<<endl;
	cout<<"\t\t3.Exit..."<<endl<<endl;

}
void instructions()
{
	system ("cls");
	HANDLE  hConsole;
    int k =11;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
	cout<<endl<<endl<<endl;
	cout<<"\t Maze has six rows and seven columns.Enter the column no."<<endl;
	cout<<"\t where you want to put your piece.You have to connect your"<<endl;
	cout<<"\t four pieces(diagonaly,horizontaly,verticaly) in order to win"<<endl;
	cout<<"\t a game.if any player is unable to do so. the game will be drawn"<<endl<<endl;
	cout<<"\tNOTE:"<<endl;
	cout<<"\tPlayer 1 piece is 'x' and player 2 piece is 'o'"<<endl<<endl;
	cout<<"\tPress enter to return to menu.Press 'Esc' to exit";
}
char map[6][7];
void boundary(char map[][7])
{
	system("cls");
	HANDLE  hConsole;
    int k =14;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
	cout<<endl<<endl<<"\t"<<"\t\t";
	for (int i=0;i<6;i++)
	{
		for (int j=0;j<7;j++)
		{
			map[i][j]='_';
			cout<<map[i][j]<<" ";
		}
		cout<<endl<<endl<<"\t"<<"\t\t";
	}
	
}
void renew_boundary(char map[][7])
{
	system("cls");
	HANDLE  hConsole;
    int k =14;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
	cout<<endl<<endl<<"\t"<<"\t\t";
	for (int i=0;i<7;i++)
	{
		for (int j=0;j<7;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl<<endl<<"\t"<<"\t\t";
	}
	
}
bool win_condition(char a)
{
	bool A=0;
	bool B=0;
	renew_boundary(map);
	if (a=='x')
	{
		char player1='x';
	  for (int i=5;i>=0;i--)
	  {
		for (int j=6;j>=0;j--)
		{
	       if ((map[i][j]==player1 && map[i-1][j]==player1 && map[i-2][j]==player1 && map[i-3][j]==player1)||(map[i][j]==player1 && map[i][j-1]==player1 && map[i][j-2]==player1 && map[i][j-3]==player1)||
			   (map[i][j]==player1 && map[i+1][j+1]==player1 && map[i+2][j+2]==player1 && map[i+3][j+3]==player1)||(map[i][j]==player1 && map[i+1][j-1]==player1 && map[i+2][j-2]==player1 && map[i+3][j-3]==player1))
		   {
			  system("cls");
	          cout<<endl<<endl<<"\t\tCongratulations !"<<endl<<endl<<"\t\tPlayer 1 has won the game"<<endl<<endl;
		      cout<<"\t\tPress enter to return to menu.Press 'Esc' to exit";
		      return true;
		   }
		}
	  }
	}
	if (a=='o')
	{
		char player2='o';
	  for (int i=5;i>=0;i--)
	  {
		for (int j=6;j>=0;j--)
		{
	     if ((map[i][j]==player2 && map[i+1][j]==player2 && map[i+2][j]==player2 && map[i+3][j]==player2)||(map[i][j]==player2 && map[i][j-1]==player2 && map[i][j-2]==player2 && map[i][j-3]==player2)||
		     (map[i][j]==player2 && map[i+1][j+1]==player2 && map[i+2][j+2]==player2 && map[i+3][j+3]==player2)||(map[i][j]==player2 && map[i+1][j-1]==player2 && map[i+2][j-2]==player2 && map[i+3][j-3]==player2))
		   {
			   system("cls");
	           cout<<endl<<endl<<"\t\tCongratulations !"<<endl<<endl<<"\t\tPlayer 2 has won the game"<<endl<<endl;
		       cout<<"\tPress enter to return to menu.Press 'Esc' to exit";
		       return true;
		   }
		}
	  }




	}
		   
	  
	
	return false;
}

void turn_1(int a, char b)
{
	boundary(map);
	int count=0;
	bool win=0;
	b='x';
	while (!win)
	{
		if (b=='x')
		{
           cout<<endl<<"Player1 turn:";
		}
		else
		   cout<<endl<<"Player2 turn:";
	    cin>>a;
		if (a>0 && a<8)
	    {
		  a--;
		  for (int i=5;i>=0;i--)
		  {
		    if(map[i][a]=='_')
		    {
			   map[i][a]=b;
			   win_condition(b);
			   win=win_condition(b);
			   count++;
			   break;
			 }
		   }
		 }
	  
     else 
	 {	
		 cout<<"Invalid input try again:"<<endl;
	 }
		if (count==42)
		  break;
		else if (count%2!=0 && count<42)
	     b='o';
		else if (count%2==0&& count<42)
		 b='x';
		
	 }
		if (count==42)
		{
			system("cls");
		    cout<<endl<<endl<<endl<<"\t\t\tThe game is drawn";
			cout<<endl<<endl;
			cout<<"\t\t\tPress enter to return to menu.Press 'Esc' to exit";
		}
}

int main()
{
	const int row=6;
	const int columns=7;
	char map[row][columns];
	int key=0,back=0;
	menu();
	cout<<"Enter Key: ";
	cin>>key;
	while (key!=3 && back!=27)
	{  
	   
	  if (key==1)
	  {
		  int win=0;
		  int col_no=0,count=0;
		  char player='x';
	      turn_1(col_no,player);
		 while (back!=13)
		 {
			 back=getch();
			 if (back==13)
			  return main();
			 else if (back==27)
				 return 0;
		 }

	  }
	 else if (key==2)
	 {  
		 instructions();
		 while (back!=13)
		 {
			 back=getch();
			 if (back==13)
			  return main();
			 else if (back==27)
				 return 0;
		 }
	  }
	  
	    
	}
	return 0;
}
