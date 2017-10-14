#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
using namespace std ;
void firsttimerandom ( int arr[] [4] , const int row , const int col ); // this function will generate two random 2's when the game starts.
void random ( int arr[][4] , const int row , const int col , bool &generate_random ) ; // this function will generate a 2 or sometimes a four after every turn.
void output ( int arr[][4] , const int row , const int col , int &score , int &high_score ) ;// this function will display the output.
void play ( int arr[][4] , const int row , const int col , bool &generate_random , int &score , int &high_score);// this function will take your input and decide what to do next.
void moveup ( int arr[] [4] , const int row , const int col , bool &generate_random ); // this function will move the numbers upward if the correct key is pressed.
void movedown ( int arr[][4] , const int row , const int col , bool &generate_random );// this function will move the numbers down if the correct key is pressed.
void moveleft ( int arr[][4] , const int row , const int col , bool &generate_random );// this function will move the numbers left if correct key is pressed.
void moveright ( int arr[][4] , const int row , const int col , bool &generate_random );// this function will move the numbers right if the correct key is pressed.
void merge_boxes ( int arr[][4] , const int row , const int col , int move , bool &generate_random , int &score , int &high_score );// this function will merge same numbers.
bool game_continue ( int arr[][4] , const int row , const int col , bool &two_zero_four_eight );// this function will decide whether any possible move exists or not, if no game will end.
void save_game ( int arr[][4] , const int row , const int col , int &score , int &high_score ); // this function will save array and score in a file for later use.
void load_game ( int arr[][4] , const int row , const int col , int &score , int &high_score ); // this function will assign values in saved files to respective array and variables.
void main_2 ();// this function is basically void main but for original game , as i am also doing a bonous version.

void firsttimerandom_for_3 ( int arr3[] [5] , const int row , const int col ); // the functions perform the same as in the upper version.
void random_for_3 ( int arr3[][5] , const int row , const int col , bool &generate_random_for_3 ) ;
void output_for_3 ( int arr3[][5] , const int row , const int col , int &score , int &high_score ) ;
void play_for_3 ( int arr3[][5] , const int row , const int col , bool &generate_random_for_3 , int &score , int &high_score);
void moveup_for_3( int arr3[][5] , const int row , const int col , bool &generate_random_for_3 );
void movedown_for_3 ( int arr3[][5] , const int row , const int col , bool &generate_random_for_3 );
void moveleft_for_3 ( int arr3[][5] , const int row , const int col , bool &generate_random_for_3 );
void moveright_for_3 ( int arr3[][5] , const int row , const int col , bool &generate_random_for_3 ) ;
void merge_boxes_for_3 ( int arr3[][5] , const int row , const int col , int move , bool &generate_random_for_3 , int &score , int &high_score );
bool game_continue_for_3 ( int arr3[][5] , const int row , const int col  );
void save_game_for_3 ( int arr3[][5] , const int row , const int col , int &score , int &high_score );
void load_game_for_3 ( int arr3[][5] , const int row , const int col , int &score , int &high_score );
void main_3();

// THROUGHOUT THE CODE X WILL REPRESENT ROW AND Y WILL REPRESENT COLUMN ( AS X AND Y ARE USED TO DONATE COORDINATES THATS WHY I HAVE USED THEM )

void main ()
{
	HANDLE  hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int level_of_game = 0 ; // this variable will stor the option of game difficulty.
	cout << endl << "        " ; // spaces befor the box which will include the title 2048
	SetConsoleTextAttribute (hConsole , 655 );
	cout << "                                                            " << endl ; // width added to the box
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "        ";
	SetConsoleTextAttribute (hConsole , 655 );
	cout  <<"                   WELCOME TO 2048 GAME                     " << endl  ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "        " ;
	SetConsoleTextAttribute (hConsole , 655 );
	cout << "                                                            " << endl << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );

	SetConsoleTextAttribute (hConsole , 265 );
	cout << "SELECT LEVEL" << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );

	SetConsoleTextAttribute (hConsole , 151 );
	cout << "1.ORIGINAL ( TILES OF 2 )" << endl << endl  ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 151 );
	cout << "2.BONUS    ( TILES OF 3 )" << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout<< "LEVEL :" ;
    cin >> level_of_game ;
	cout << endl ;

	while ( level_of_game != 1 && level_of_game != 2 ) // if the user by mistakes input a wrong option it will ask him to reinput the option.
	{
		cout << "INVALID INPUT, PLEASE TRY AGAIN " << endl ;
		cout << "LEVEL :" ;
		cin >> level_of_game ;
		cout << endl ;
	}

	if ( level_of_game == 1 )
	{
		main_2(); // if option is 1 or Easy , the game will proceed to 2Chip Version
	}
	else if ( level_of_game == 2 )
	{
		main_3(); // if the option is 2 or Bonus , the game will proceed to 3Chip version.
	}

	system("pause");

}

void main_2()
{
	srand(time(NULL)) ;
	HANDLE  hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int option = 0 ; // this integer will stor the option for start new game or continue last game.
	int score = 0 ; // current score will be saved in this variable.
	int high_score = 0 ; // high_score will be saved in it.
	bool conti = false ; // this variable will decide the termination of game.
	bool generate_random = false ; // sometimes in the game a move is made that makes no change in the board and hence random number will not appear.
	bool conti_for_new_game = true ;
	bool two_zero_four_eight = true ;// this variable will decide if the user wants to quit or play a new game after Game Over.
	const int row = 4;
	const int col = 4 ;
	int arr [row][col] ; // this is our array, all changes are going to be made in it.

	for ( int i = 0 ; i < row ; i++ ) // initializing our array.
	{
		for ( int j = 0 ; j<col ; j++ )
		{
			arr[i][j] = 0 ;
		}
	}
	ifstream highscore ("highscore.txt"); // will get your high score from previously played game
	if ( highscore.is_open())
	{
		highscore >> high_score ;
	}

	cout << "             " ; // this again is used to put spaces before the box with title 2048.
	SetConsoleTextAttribute (hConsole , 279 );
	cout << "                                                   " << endl ; //width is added.
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "             ";
	SetConsoleTextAttribute (hConsole , 279 );
	cout << "                     2048 GAME                     "  << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "             ";
	SetConsoleTextAttribute (hConsole , 279 );
	cout << "                                                   " << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );

	cout << "DO YOU WISH TO START A NEW GAME OR CONTINUE PREVIOUS GAME ?" << endl << endl ;
	cout << "1.NEW GAME" << endl << "2.LOAD GAME" << endl << "Option <1 OR 2> :" ;
	cin>> option ;
	cout << endl;
	if ( option != 1 && option != 2 ) // if by mistake user enters wrong input itll retake it.
	{
	      while ( option != 1 && option != 2 )
	    {
		   cout << "INVALID CHOICE ! PLEASE TRY AGAIN " << endl << "OPTION <1 OR 2> :" ;
		   cin >> option ;
		   cout << endl ;
	    }
	}
	if ( option == 2 )
	{
		load_game ( arr , row , col , score , high_score); // this function will grab the data saved in out files and assign it to respective variables and arrays.
	}
	else
	{
	   firsttimerandom(arr,row,col); // if there is no saved game a new game will be started.
	   save_game(arr,row,col,score,high_score); // the new game now becomes our saved game.
	}
	conti = game_continue(arr,row,col,two_zero_four_eight); // this will merge_boxes if game is ok to proceed further.
	while (conti_for_new_game) // conti_for_new_game , starts a new game when previous game is ended.
	{
		int newgame = 0 ; // this variable will store information if the user wants to play a new game after his game ends.
	    while ( conti )
	    {
	       output ( arr , row , col , score , high_score ) ;
	       play ( arr , row , col , generate_random, score , high_score);
	       output ( arr , row , col , score , high_score);
	       random ( arr , row , col ,generate_random);
	       save_game ( arr , row , col , score , high_score );
	       generate_random = false; // it is made false so conditions can be checked again whether to generate another random number or not.
	       conti = false ;
	       conti = game_continue(arr,row,col,two_zero_four_eight);
	    }
	    random(arr,row,col,generate_random);// for generating random 2 in the last box.
	    output(arr,row,col , score , high_score); // for outputing the box after random 2 in generated in the last box.
		
		if ( two_zero_four_eight == false ) // this stop is activated when 2048 is reached in the game.
		{
			system("cls");
			output ( arr , row , col , score , high_score);
			cout << endl << endl ;
			cout << "             " ; // this again is used to put spaces before the box with title 2048.
	        SetConsoleTextAttribute (hConsole , 279 );
	        cout << "                                                   " << endl ; //width is added.
	        SetConsoleTextAttribute (hConsole , 15 );
	        cout << "             ";
	        SetConsoleTextAttribute (hConsole , 279 );
	        cout << "        CONGRATULATIONS YOU WON THE GAME !!!       "  << endl ;
	        SetConsoleTextAttribute (hConsole , 15 );
	        cout << "             ";
	        SetConsoleTextAttribute (hConsole , 279 );
	        cout << "                                                   " << endl << endl ;
	        SetConsoleTextAttribute (hConsole , 15 );
		}
		else // if game is over due to inavailability of new boxes.
		{
		    cout <<endl << "--------------------GAME OVER--------------------" << endl << endl  ;
		}
	    cout << "Do YOU WISH TO START A NEW GAME ?" << endl << "1.YES" << endl << "2.NO" << endl << "OPTION :" ; 
	    cin >> newgame ;
	    cout << endl ;
		while ( newgame != 1 && newgame != 2 )
		{
			cout <<"INVALID INPUT , PLEASE TRY AGAIN" << endl <<"OPTION :";
			cin >> newgame ;
			cout << endl;
		}
	    if(newgame == 1 )
	    {
		    for ( int i = 0 ; i < row ; i++ ) // if new game is selected the array is being initialized for another go.
	        {
		          for ( int j = 0 ; j<col ; j++ )
		        {
			        arr[i][j] = 0 ;
		        }
	        }
	   
		    conti = true; // so the loop given above can once again work.
			two_zero_four_eight = true ; // as we start a new game so there is no 2048, hence this condition becomes true.
		    score = 0 ;
	        firsttimerandom(arr,row,col); // two generate two random numbers
	        save_game(arr,row,col,score,high_score); // when new game is started this new game is saved so when it is loaded it will give the latest game.
	    } 
	    else // if you dont want to play another game than this else will give your score and high score and end the game.
	    {
		    system("cls");
		    cout << endl << endl << endl << endl << endl << endl << endl ;
			cout << "                            " ;
		    SetConsoleTextAttribute(hConsole , 655 );
	        cout <<  "GAME OVER !!!" << endl << endl ;
            SetConsoleTextAttribute(hConsole , 15 );
		    if ( score == high_score)
		    {
			    cout << "     --------------- CONGRATULATIONS NEW HIGH SCORE ---------------" << endl << endl ;
		    }
			cout << "                       " ;
		    SetConsoleTextAttribute(hConsole , 279 );
	        cout <<  "CURRENT SCORE IS :" << score << endl << endl ;
            SetConsoleTextAttribute(hConsole , 15 );
			cout << "                          " ;
		    SetConsoleTextAttribute(hConsole , 279 );
	        cout << "HIGH SCORE :" << high_score << endl << endl ;
            SetConsoleTextAttribute(hConsole , 15 );

		    conti_for_new_game = false; // this is made false to break the outer loop and end the game.
	    }
	}
}
void firsttimerandom ( int arr [][4] , const int row , const int col )
{
	int x = 0 , y = 0 , counter = 1 ; // we need two random numbers hence we will use counter for that
    bool stop = true ; // stop tells when the array has 0 and is suitable for puting a 2 in it.
	while ( counter <= 2 )
	{
	    while(stop)
		    {
			    x = rand() % (row); // will give the random row index of the array
			    y = rand() % (col); // will give the random column index of the array
			    if(arr[x][y] == 0 )
			    {
				    arr[x][y] = 2;
				    stop = false ;
			    }
		    }
		counter++;
	    stop = true ;// so loop can run again.
	}
}
void random ( int arr[][4] , const int row , const int col , bool &generate_random  )
{
	int x = 0 , y = 0 , probability = 0 ; // probability will be used for selecting 2 or 4 for output.
	bool stop = true ;
	bool conti = false;  // will merge_boxes if array has any space availabe for accomodating a 2 or a 4.
	int counter = 0 ;
	probability = rand()%7 ;

	for ( int i = 0 ; i < row ; i++ ) // if no space is available , but boxes may add up than no random number will be generated.
	{
		for ( int j = 0 ; j < col ; j++ )
		{
			if (arr[i][j] == 0 )
			{
				conti = true ;
				i = row ;
				j = col ;
			}
		}
	}

	if (conti && generate_random) // generate random will be true if in the last move a change occured in the box.
	{
		while(stop)
		{
			x = rand() % (row);
			y = rand() % (col);
			if(arr[x][y] == 0 )
			{
				if ( probability == 0 )
				{
					arr[x][y] = 4 ;
					stop = false;
				}
				else
				{
					arr[x][y] = 2 ;
				    stop = false ;
				}
			}
		}
	}	
}
void output ( int arr [][4] , const int row , const int col , int &score , int &high_score )
{
	HANDLE  hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int x = 0, y = 0; // coordinates of arr
	int temp_arr = 0 ; // this array will be divided by 10 giving the number of digits in the current index of array, helping in setting the board.
	int digit = 0 ; // digits in each coordinate of arr

	system("cls"); // it will remove the previous board before the next one appears.

	cout << endl << "               " ; // like above this will give spaces before start of box.
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                                                      " << endl; // will give width to the box
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "               "; 
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                      2048 GAME                       "  << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "               ";
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                                                      " << endl << endl ; // will give width to the box.
	SetConsoleTextAttribute (hConsole , 15 );cout << endl ;

    cout << "    "; // spaces before top edge of the board starts.
    SetConsoleTextAttribute(hConsole, 130);
	cout << "                                "; // top edge of the board.
	SetConsoleTextAttribute(hConsole, 15);

	while (x < row) // as we need for rows
	{
	    cout << endl;
		cout << "    " ; // everything before while (y <col) is used to design the upper part of each box containing the number.
		SetConsoleTextAttribute (hConsole , 130 );
		cout << " ";
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << " " ;
		SetConsoleTextAttribute (hConsole , 15 );
		cout << endl ;
			
		while (y < col ) // from here our box containing array starts.
		{
			temp_arr = arr[x][y] ;
			while ( temp_arr > 0 )
			{
				temp_arr = temp_arr / 10;
				digit++;
			}
			if ( y == 0 )
			{
				cout << "    " ; // spaces before the start of each box.
				SetConsoleTextAttribute (hConsole , 130 );
				cout << " " ; // outline for the board on the left side.
				SetConsoleTextAttribute (hConsole , 15 );
			}
			else // if y != 0 it means we are in 2nd , 3rd or 4th column and hence we dont need the spaces that first column needed.
			{ 
				SetConsoleTextAttribute (hConsole , 130 );
				cout << " ";
				SetConsoleTextAttribute (hConsole , 15 );
			}
			if ( digit == 0 || digit == 1 ) // spaces in boxes are put in accordance with the digits present in that index.
			{
				if ( arr[x][y] == 0 )
				{
					SetConsoleTextAttribute (hConsole , 250 );
					cout << "      "; // digit is 0 we would want the box to remain empty therefore we wont output the array.
					SetConsoleTextAttribute (hConsole , 15);	
				}
				else
				{
					if ( arr[x][y] == 2 ) // every number is being seperately checked so that it may have its own color.
					{
					    SetConsoleTextAttribute (hConsole , 245); 
					    cout << "  " << arr[x][y] << "   ";
					    SetConsoleTextAttribute (hConsole , 15 );
					}
					else if ( arr[x][y] == 4 )
					{
						SetConsoleTextAttribute (hConsole , 249);
					    cout << "  " << arr[x][y] << "   ";
					    SetConsoleTextAttribute (hConsole , 15 );
					}
					else if ( arr[x][y] == 8 )
					{
						SetConsoleTextAttribute (hConsole , 252);
					    cout << "  " << arr[x][y] << "   ";
					    SetConsoleTextAttribute (hConsole , 15 );
					}

				}
			}
			else if ( digit == 2 )
			{
				if ( arr[x][y] == 16 )
				{
				    SetConsoleTextAttribute (hConsole , 248);
				    cout << "  " << arr[x][y] << "  " ;
				    SetConsoleTextAttribute ( hConsole , 15);
				}
				else if ( arr [x][y] == 32)
				{
					SetConsoleTextAttribute (hConsole , 245);
				    cout << "  " << arr[x][y] << "  " ;
				    SetConsoleTextAttribute ( hConsole , 15);
				}
				else if ( arr[x][y] == 64 )
				{
					SetConsoleTextAttribute (hConsole , 250);
				    cout << "  " << arr[x][y] << "  " ;
				    SetConsoleTextAttribute ( hConsole , 15);
				}

			}
			else if ( digit == 3 )
			{
				if ( arr[x][y] == 256 )
				{
					SetConsoleTextAttribute (hConsole , 244);
				    cout << " " << arr[x][y] << "  " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}
				else
				{
				    SetConsoleTextAttribute (hConsole , 249);
				    cout << " " << arr[x][y] << "  " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}
			}
			else if ( digit == 4 )
			{
				if ( arr[x][y] == 1024 )
				{
					SetConsoleTextAttribute (hConsole , 245);
				    cout << " " << arr[x][y] << " " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}
				else
				{
				    SetConsoleTextAttribute (hConsole , 250);
				    cout << " " << arr[x][y] << " " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}
			}
				
				SetConsoleTextAttribute (hConsole , 130 );
				cout << " " ; // this will give the outline of the board on the right side.
				SetConsoleTextAttribute (hConsole , 15 );
				
				digit = 0 ;
				y++;
		}
		cout << endl ; // from this point onward everything is done for lower half of the box containing the number. Spaces are broken because we want different colors at diff points.
		cout << "    ";
		SetConsoleTextAttribute(hConsole, 130);
		cout << " ";
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << " ";
		SetConsoleTextAttribute(hConsole, 15);
		cout << endl ;
		cout << "    ";
		SetConsoleTextAttribute(hConsole, 130);
		cout << "                                ";
		SetConsoleTextAttribute(hConsole, 15);
		x++;
		y=0;
	}
	cout << endl << endl ;
	cout << "YOUR CURRENT SCORE :" << score << "           YOUR HIGH SCORE :"<< high_score << endl ; // this will be printed below the board.	
}
void play ( int arr [][4] , const int row , const int col , bool &generate_random , int &score , int &high_score)
{
	HANDLE hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int move = 0 ;

	cout << endl << "Press :" << endl << endl << "                              " ; // will give the directions to which key will perform which function.
	SetConsoleTextAttribute (hConsole , 350 ); 
	cout <<" ARROW KEYS " << endl;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "                                    OR" << endl;
	SetConsoleTextAttribute (hConsole , 158 );
	cout <<" w/W to move up   "  ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 236 );
	cout << " s/S to move down "  ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 243 );
	cout<<" d/D to move right " ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 132 );
	cout << " a/A to move left " ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << endl << "Your Move Please:" ;

	move = _getch() ; // so we wont have to press enter to initiate the move.
	if (move == 0 || move == 0xE0) move = _getch();
	while ( move != 'w' && move != 'W' && move != 72 && move != 's' && move != 'S' && move != 80 && move != 'd' && move != 'D' && move != 77 && move != 'a' && move != 'A' && move != 75)
	{
		cout << endl << "Invalid move try again !!!" ;
		cout << endl << "Your Move Please:" ;
		move = _getch();
	}
	if ( move == 'w' || move == 'W' || move == 72)
	{
		moveup ( arr , row , col , generate_random ); // if user wants numbers to go up than this function will be called.
		
	}
	else if ( move == 's' || move == 'S' || move == 80)
	{
		movedown ( arr , row , col , generate_random);// if user wants numbers to go down than this function will be called.
	}
	else if ( move == 'a' || move == 'A' || move == 77 )
	{
		moveleft ( arr , row , col , generate_random ) ;// if user wants numbers to go left than this function will be called.
	}
	else if ( move == 'd' || move == 'D' || move == 75)
	{
		moveright (arr , row , col , generate_random );// if user wants numbers to go right than this function will be called.
	}
    merge_boxes ( arr , row , col , move , generate_random , score , high_score); // this function will merge_boxes if numbers add or not, if they do itll add them.
}
void moveup ( int arr [][4] , const int row , const int col , bool &generate_random)
{
	int x = 0 , y = 0 , tempx = 0 ; // tempx is basically increment of x which will help in merge_boxesing various conditions.
	while ( y < col )
	{
		while ( x < row )
		{
			if ( arr[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempx = x+1;
				while ( tempx < row ) // this will check for each index in each column.
				{
					if ( arr[tempx][y] != 0)
					{
						arr[x][y] = arr[tempx][y];
					    arr[tempx][y] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random = true ;
						tempx = row;
					}
					tempx++;
				}
			}
			x++;
		}
		y++;
		x = 0 ;
	}
}
void movedown ( int arr [][4] , const int row , const int col , bool &generate_random)
{
	int x = row - 1 , y = 0 , tempx = 0 ; // same thing is happening as in moveup function only the order of merge_boxesing is reversed.
	while ( y < col )
	{
		while ( x >= 0 )
		{
			if ( arr[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempx = x-1;
				while ( tempx >= 0 ) // this will check for each index in each column.
				{
					if ( arr[tempx][y] != 0)
					{
						arr[x][y] = arr[tempx][y];
					    arr[tempx][y] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random = true ;
						tempx = 0;
					}
					tempx--;
				}
			}
			x--;
		}
		y++;
		x = row - 1 ;
	}
}
void moveleft ( int arr [][4] , const int row , const int col , bool &generate_random)
{
	int x = 0 , y = 0 , tempy = 0 ; // this time we want a temporary variable for columns because they are going to be merge_boxesed first. Rest is what happened in move up.
	while ( x < row )
	{
		while ( y < col )
		{
			if ( arr[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempy = y+1;
				while ( tempy < col ) // this will check for each index in each row.
				{
					if ( arr[x][tempy] != 0)
					{
						arr[x][y] = arr[x][tempy];
					    arr[x][tempy] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random = true ;
						tempy = col;
					}
					tempy++;
				}
			}
			y++;
		}
		x++;
		y = 0 ;
	}
}
void moveright ( int arr [][4] , const int row , const int col , bool &generate_random)
{
	int x = 0 , y = col - 1 , tempy = 0 ;// same thing as in moveleft only merge_boxesing from the opposite side.
	while ( x < row )
	{
		while ( y >= 0 )
		{
			if ( arr[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempy = y-1;
				while ( tempy >= 0 ) // this will check for each index in each row.
				{
					if ( arr[x][tempy] != 0)
					{
						arr[x][y] = arr[x][tempy];
					    arr[x][tempy] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random = true ;
						tempy = 0;
					}
					tempy--;
				}
			}
			y--;
		}
		x++;
		y = col - 1 ;
	}
}
void merge_boxes ( int arr[][4] , const int row , const int col , int move , bool &generate_random , int &score , int &high_score)
{
	int x = 0 , y = 0 , tempx = 0 , tempy = 0 ; // for merging boxes we require both temporary variables for rows and columns and hence we declare tempx and tempy.
	char adding = move ;
	if ( adding == 'w' || adding == 'W' || adding == 72 )
	{
		while ( y < col )
		{
			while ( x < row )
			{
				tempx = x + 1 ;
				if ( arr[x][y] == arr[tempx][y] && arr[x][y] != 0 && arr[x][y] != 2048 && tempx <=3  ) // we merge_boxes arr[x][y] != 0 for random condition so generate random remains false. and we dont want to merge if 2048 is reached.
				{
					arr[x][y] = arr[x][y] + arr [tempx][y]; // this time array is being doubled.
					arr[tempx][y] = 0 ;
					score = score + arr[x][y] ; // score is increasing.
					generate_random = true ; // this means that a change has occured in the box and a new number should be generated.
				}
				x++;
			}
			y++;
			x=0 ;
		}
		moveup ( arr , row , col , generate_random );// to rearrange output after addition.
	}
	else if ( adding == 's' || adding == 'S' || adding == 80 ) // same thing as above
	{
		x = row - 1 ;
		y = 0 ;
		while ( y < col )
		{
			while ( x >= 0 )
			{
				tempx = x - 1 ;
				if ( arr[x][y] == arr[tempx][y] && arr[x][y] != 0 && arr[x][y] != 2048 && tempx >= 0 )
				{
					arr[x][y] = arr[x][y] + arr [tempx][y];
					arr[tempx][y] = 0 ;
					score = score + arr[x][y] ;
					generate_random = true ; // this means that a change has occured in the box and a new number should be generated.
				}
				x--;
			}
			y++;
			x= row - 1 ;
		}
		movedown(arr,row,col , generate_random); // to rearrange output after addition 
	}
	else if ( adding == 'a' || adding == 'A' || adding == 75 ) // same thing as above.
	{
		while ( x < row )
		{
			while ( y < col )
			{
				tempy = y + 1 ;
				if ( arr[x][y] == arr[x][tempy] && arr[x][y] != 0 && arr[x][y] != 2048 && tempy <=3)
				{
					arr[x][y] = arr[x][y] + arr [x][tempy];
					arr[x][tempy] = 0 ;
					score = score + arr[x][y] ;
					generate_random = true ; // this means that a change has occured in the box and a new number should be generated.
				}
				y++;
			}
			x++;
			y=0 ;
		}
		moveleft ( arr , row , col , generate_random );// to rearrange output after addition.
	}
	else if ( adding == 'd' || adding == 'D' || adding == 77) // same thing as above .
	{
		x = 0 ;
		y = col - 1 ;
		while ( x < row)
		{
			while ( y >= 0 )
			{
				tempy = y - 1 ;
				if ( arr[x][y] == arr[x][tempy] && arr[x][y] != 0 && arr[x][y] != 2048 && tempy >= 0 )
				{
					arr[x][y] = arr[x][y] + arr [x][tempy];
					arr[x][tempy] = 0 ;
					score = score + arr[x][y] ;
					generate_random = true ; // this means that a change has occured in the box and a new number should be generated
				}
				y--;
			}
			x++;
			y= col - 1 ;
		}
		moveright(arr,row,col , generate_random); // to rearrange output after addition.
	}
	if ( high_score <= score )
	{
		high_score = score ;
	}
}
bool game_continue ( int arr[][4] , const int row , const int col , bool &two_zero_four_eight )
{
	bool conti = false ;
	int x = 0 ,  y = 0 , tempx = 0 , tempy = 0 ;
	while( x < row )
	{
		while ( y < col )
		{
			if ( arr[x][y] == 2048 ) // if a space is empty we would want our game to continue.
			{
				two_zero_four_eight = false ; // this will stop the game because 2048 is reached.
				x= row ;
				y = col ;
			}
			y++;
		}
		x++;
		y = 0;
	}

	if ( two_zero_four_eight ) // if 2048 is not reached itll then check for other possibilities if any for game ending.
	{
	    x=0;
	    y=0;
	    while( x < row )
	    {
		    while ( y < col )
		    {
			    if ( arr[x][y] == 0 ) // if a space is empty we would want our game to continue.
			    {
				    conti = true ;
				    x= row ;
				    y = col ;
			    }
			    y++;
		     }
		     x++;
		     y = 0;
	    }
	    x=0;
	    y=0;
	    if ( conti == false ) // if there is no index with number 0 , than this lopp which check is any two same numbers come together.
	    {
		    while ( x < row )
		    {
			
			    while ( y < col )
			    {
				    tempy = y + 1 ;
				    if ( arr[x][y] == arr[x][tempy] && arr[x][y] != 2048 && tempy < col) // if any two numbers are same it means that they can be added and game continues.
				    {
					    conti = true ;
					    x = row ;
					    y = col ;
				    }
				    y++;
			    }
			    x++;
		        y = 0 ;
			
		    }
	    }
	    x = 0 ;
	    y = 0 ;
	    if ( conti == false )
	    {
		    while ( y < col )
		    {
			    while ( x < row )
			    {
				    tempx = x + 1 ;
				    if ( arr[x][y] == arr[tempx][y] && arr[x][y] != 2048 && tempx < row ) // if any two numbers are same it means they can bee added and hence game continues.
				    {
					    conti = true ;
					    x = row ;
					    y = col ;
				    }
				    x++;
			    }
			    y++;
			    x = 0 ;
		    }
	    }
	}
	    return conti; // returning the value of conti so where game continues or not can be judged in main_2() ;
}
void save_game ( int arr[][4] , const int row , const int col , int &score , int &high_score )
{
	int x = 0 ;
	int y = 0 ;

	ofstream my_arr ("myarr.txt"); // saving array in this file so if game is loaded the array can also be loaded
	if ( my_arr.is_open() )
	{
		while ( x < row )
		{
			while ( y < col ) 
			{
				my_arr << arr[x][y] ;
				my_arr << ' ';
				y++;
			}
			my_arr << '\n';
			x++;
			y = 0 ;
		}
		my_arr.close();
	}
	else
	{
		cout << "Cannot open file myarr.txt " << endl ;
	}

	ofstream myscore ("mycurrentscore.txt"); // saving current score in this file.
	if ( myscore.is_open ())
	{
		myscore << score ;
		myscore.close();
	}
	else
	{
		cout << " Cannot open file mycurrentscore.txt " << endl ;
	}

	ofstream highscore ("highscore.txt"); // saving high score in this file.
	if ( highscore.is_open())
	{
		highscore << high_score ;
		highscore.close();
	}
	else
	{
		cout << "Cannot open file highscore.txt" << endl ;
	}
}
void load_game ( int arr[][4] , const int row , const int col , int &score, int &high_score )
{
	int x = 0 ; 
	int y = 0 ;
	int counter = 0 ;
	ifstream myarr ("myarr.txt"); // if game is loaded this file will return the value of array.
	if (myarr.is_open())
	{
		while ( x < row && !( myarr.eof()))
		{
			while ( y < col )
			{
				myarr >>arr[x][y] ;
				if ( arr[x][y] != 0 )
				{
					counter++;
				}
				y++;	
			}
			x++;
			y=0;
	    }

		ifstream myscore ("mycurrentscore.txt"); // this will return the current score which was made when the game was quit.
		if ( myscore.is_open())
		{
			myscore >> score ;
		}

	   ifstream highscore ("highscore.txt"); // this will return high score.
	   if ( highscore.is_open())
	   {
		highscore >> high_score ;
	   }
    }

	if ( counter == 0 ) // this will show that no game was saved and hence two 2's will be generated.
	{
		int start_new_game;
		system("cls");
		cout << endl << endl <<"  NO PREVIOUS GAME FOUND, PRESS ANY KEY TO START A NEW GAME" << endl ;
		start_new_game = _getch();
		firsttimerandom(arr,row,col);
		save_game ( arr, row ,  col , score ,high_score );
	}
}

// BONOUS VERSION OF THE GAME STARTS FROM HERE.

void main_3 ()
{
	srand(time(NULL)) ;
	HANDLE  hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int option = 0 ;
	int score = 0 ;
	int high_score = 0 ;
	bool conti = false ;
	bool generate_random_for_3 = false ;
	bool conti_for_new_game = true ;
	const int row = 5;
	const int col = 5 ;
	int arr3 [row][col] ;
	
	ifstream highscore ("highscore3.txt");
	if ( highscore.is_open())
	{
		highscore >> high_score ;
	}

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j<col ; j++ )
		{
			arr3[i][j] = 0 ;
		}
	}
	cout << "           " ;
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                                                      " << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "           " ;
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "              2048 GAME (BONUS VERSION)               "  << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "           ";
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                                                      " << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );

	cout <<  "DO YOU WISH TO START A NEW GAME OR CONTINUE PREVIOUS GAME ?" << endl << endl ;
	cout << "1.NEW GAME" << endl << "2.LOAD GAME" << endl << "Option <1 OR 2> :" ;
	cin>> option ;
	cout << endl;
	if ( option != 1 && option != 2 )
	{
	      while ( option != 1 && option != 2 )
	    {
		   cout << "INVALID CHOICE ! PLEASE TRY AGAIN " << endl << "OPTION <1 OR 2> :" ;
		   cin >> option ;
		   cout << endl ;
	    }
	}
	if ( option == 2 )
	{
		load_game_for_3 ( arr3 , row , col , score , high_score);
	}
	else
	{
	   firsttimerandom_for_3(arr3,row,col);  
	   save_game_for_3(arr3,row,col,score,high_score);
	}
	conti = game_continue_for_3(arr3,row,col);
	while (conti_for_new_game) 
	{
	    int newgame = 0 ;
	    while ( conti )
	    {
	       output_for_3 ( arr3 , row , col , score , high_score ) ;
	       play_for_3 ( arr3 , row , col , generate_random_for_3, score , high_score);
	       output_for_3 ( arr3 , row , col , score , high_score);
	       random_for_3 ( arr3 , row , col ,generate_random_for_3);
	       save_game_for_3 ( arr3 , row , col , score , high_score );
	       generate_random_for_3 = false ;
	       conti = false ;
	       conti = game_continue_for_3(arr3,row,col);
	    }
	    random_for_3(arr3,row,col,generate_random_for_3);
	    output_for_3(arr3,row,col , score , high_score);
		cout <<endl << "--------------------GAME OVER--------------------" << endl << endl  ;
	    cout << "Do YOU WISH TO START A NEW GAME ?" << endl << "1.YES" << endl << "2.NO" << endl << "Option :" ;
	    cin >> newgame ;
	    cout << endl ;
	    if( newgame == 1 )
	    {
		    for ( int i = 0 ; i < row ; i++ )
	        {
		         for ( int j = 0 ; j<col ; j++ )
		         {
			         arr3[i][j] = 0 ;
		         }
	        }
		 conti = true;
		 score = 0 ;
	     firsttimerandom_for_3(arr3,row,col);
	     save_game_for_3(arr3,row,col,score,high_score);
	     } 
	     else
	     {
		     system("cls");
		    cout << endl << endl << endl << endl << endl << endl << endl ;
			cout << "                            " ;
		    SetConsoleTextAttribute(hConsole , 655 );
	        cout <<  "GAME OVER !!!" << endl << endl ;
            SetConsoleTextAttribute(hConsole , 15 );
		    if ( score == high_score)
		    {
			    cout << "     --------------- CONGRATULATIONS NEW HIGH SCORE ---------------" << endl << endl ;
		    }
			cout << "                       " ;
		    SetConsoleTextAttribute(hConsole , 279 );
	        cout <<  "CURRENT SCORE IS :" << score << endl << endl ;
            SetConsoleTextAttribute(hConsole , 15 );
			cout << "                          " ;
		    SetConsoleTextAttribute(hConsole , 279 );
	        cout << "HIGH SCORE :" << high_score << endl << endl ;
            SetConsoleTextAttribute(hConsole , 15 );

		    conti_for_new_game = false; // this is made false to break the outer loop and end the game
	     }
    }
}
void firsttimerandom_for_3 ( int arr3 [][5] , const int row , const int col )
{
	int x = 0 , y = 0 , counter = 1 ; bool stop = true ;
	while ( counter <= 3 )
	{
	    while(stop)
	    {
		    x = rand() % (row);
		    y = rand() % (col);
		    if(arr3[x][y] == 0 )
		    {
			    arr3[x][y] = 3;
			    stop = false ;
		    }
	     }
	stop = true ;
	counter++;
	}
	
}
void random_for_3 ( int arr3[][5] , const int row , const int col , bool &generate_random_for_3  )
{
	int x = 0 , y = 0 ; // rows and columns
	bool stop = true ;
	bool conti = false;
	int counter = 0 ;
	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < col ; j++ )
		{
			if (arr3[i][j] == 0 )
			{
				conti = true ;
				i = row ;
				j = col ;
			}
		}
	}
	if (conti && generate_random_for_3)
	{
		for ( int random_counter = 1 ; random_counter <= 2 ; random_counter++ )
		{
		    while(stop)
		    {
			    x = rand() % (row);
			    y = rand() % (col);
			    if(arr3[x][y] == 0 )
			    {
				    arr3[x][y] = 3;
				    stop = false ;
			    }
		    }
			stop = true ;
	    }
	}
	generate_random_for_3=false;
}
void output_for_3 ( int arr3 [][5] , const int row , const int col , int &score , int &high_score )
{
	HANDLE  hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int x = 0, y = 0; // coordinates of arr3
	int upperlinecounter = 0; // to print upper line "----------" of the boxes
	int counter = 0 ; // as we need four boxes so we will set this counter to 4
	int temp_arr3 = 0 ; // used to stor coordinate of current index of arr3
	int digit = 0 ; // digits in each coordinate of arr3
	int space = 0;// to move board to the middle of screen

	system("cls");
	cout << endl << "                " ;
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                                                      " << endl;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "                "; 
	SetConsoleTextAttribute (hConsole , 155 );// set color.
	cout << "              2048 GAME (BONUS VERSION)               "  << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "                ";
	SetConsoleTextAttribute (hConsole , 155 );
	cout << "                                                      " << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );cout << endl ;


	cout << "    ";
    SetConsoleTextAttribute(hConsole, 130);
	cout << "                                        ";
	SetConsoleTextAttribute(hConsole, 15);
	while (x < row)
	{
		cout << endl;
		cout << "    " ;
		SetConsoleTextAttribute (hConsole , 130 );
		cout << " ";
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute (hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute (hConsole , 130 );
		cout << " " ;
		SetConsoleTextAttribute (hConsole , 15 );
		cout << endl ;
			

		while (y < col )
		{
			temp_arr3 = arr3[x][y] ;
			while ( temp_arr3 > 0 )
			{
				temp_arr3 = temp_arr3 / 10;
				digit++;
			}
			if ( y == 0 )
			{

				cout << "    " ; // for start of each box ;
				SetConsoleTextAttribute (hConsole , 130 );
				cout << " " ;
				SetConsoleTextAttribute (hConsole , 15 );
			}
			else
			{ 
				SetConsoleTextAttribute (hConsole , 130 );
				cout << " ";
				SetConsoleTextAttribute (hConsole , 15 );
			}
			if ( digit == 0 || digit == 1 )
			{
				if ( arr3[x][y] == 0 )
				{
					SetConsoleTextAttribute (hConsole , 250 );
					cout << "      ";
					SetConsoleTextAttribute (hConsole , 15);
						
				}
				else
				{
					if ( arr3[x][y] == 3 )
					{
					    SetConsoleTextAttribute (hConsole , 245); // 249 , 252
					    cout << "  " << arr3[x][y] << "   ";
					    SetConsoleTextAttribute (hConsole , 15 );
					}
					else if ( arr3[x][y] == 9 )
					{
						SetConsoleTextAttribute (hConsole , 252); // 249 , 252
					    cout << "  " << arr3[x][y] << "   ";
					    SetConsoleTextAttribute (hConsole , 15 );
					}
				}
			}
			else if ( digit == 2 )
			{
				if ( arr3[x][y] == 27 )
				{
				    SetConsoleTextAttribute (hConsole , 249);
				    cout << "  " << arr3[x][y] << "  " ;
				    SetConsoleTextAttribute ( hConsole , 15);
				}
				else if ( arr3[x][y] == 81 )
				{
					 SetConsoleTextAttribute (hConsole , 248); // 249 , 252
					 cout << "  " << arr3[x][y] << "  ";
					 SetConsoleTextAttribute (hConsole , 15 );
				}

			}
			else if ( digit == 3 )
			{
				if ( arr3[x][y] == 243 )
				{
				    SetConsoleTextAttribute (hConsole , 245);
				    cout << " " << arr3[x][y] << "  " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}
				else
				{
					SetConsoleTextAttribute (hConsole , 252);
				    cout << " " << arr3[x][y] << "  " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}

			}
			else if ( digit == 4 )
			{
				if ( arr3[x][y] == 2187 )
				{
				    SetConsoleTextAttribute (hConsole , 245);
				    cout << " " << arr3[x][y] << " " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}
				else
				{
					SetConsoleTextAttribute (hConsole , 249);
				    cout << " " << arr3[x][y] << " " ;
				    SetConsoleTextAttribute (hConsole , 15);
				}

			}
				
			SetConsoleTextAttribute (hConsole , 130 );
			cout << " " ;
			SetConsoleTextAttribute (hConsole , 15 );
				
			digit = 0 ;
			y++;
		}

		cout << endl ;
		cout << "    ";
		SetConsoleTextAttribute(hConsole, 130);
		cout << " ";
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << "  " ;
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleTextAttribute(hConsole, 250);
		cout << "      ";
		SetConsoleTextAttribute(hConsole , 15 );
		SetConsoleTextAttribute(hConsole, 130);
		cout << " ";
		SetConsoleTextAttribute(hConsole, 15);

		cout << endl ;
		cout << "    ";
		SetConsoleTextAttribute(hConsole, 130);
		cout << "                                        ";
		SetConsoleTextAttribute(hConsole, 15);
		x++;
		y=0;
		space=0;
	}
    cout << endl << endl ; ;
	cout << "YOUR CURRENT SCORE :" << score << "           YOUR HIGH SCORE :"<< high_score << endl ;
}
void play_for_3 ( int arr3 [][5] , const int row , const int col , bool &generate_random_for_3 , int &score , int &high_score)
{
	HANDLE hConsole ;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int move = 0 ;
	cout << endl << "Press :" << endl << endl << "                              " ;
	SetConsoleTextAttribute (hConsole , 350 ); 
	cout <<" ARROW KEYS " << endl;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "                                   OR" << endl;
	SetConsoleTextAttribute (hConsole , 158 );
	cout <<" w/W to move up   "  ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 236 );
	cout << " s/S to move down "  ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 243 );
	cout <<" d/D to move right " ;
	SetConsoleTextAttribute (hConsole , 15 );
	SetConsoleTextAttribute (hConsole , 132 );
	cout << " a/A to move left " ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << endl << "Your Move Please:" ;
	move = _getch() ;
	if (move == 0 || move == 0xE0) 
		move = _getch();
	while ( move != 'w' && move != 'W' && move != 72 && move != 's' && move != 'S' && move != 80 && move != 'd' && move != 'D' && move != 77 && move != 'a' && move != 'A' && move != 75)
	{
		cout << endl << "Invalid move tryagain " ;
		cout << endl << "Your Move Please:" ;
		move = _getch();
	}
	if ( move == 'w' || move == 'W' || move == 72 )
	{
		moveup_for_3 ( arr3 , row , col , generate_random_for_3 );
		
	}
	else if ( move == 's' || move == 'S' || move == 80)
	{
		movedown_for_3 ( arr3 , row , col , generate_random_for_3);
	}
	else if ( move == 'a' || move == 'A' || move == 75)
	{
		moveleft_for_3 ( arr3 , row , col , generate_random_for_3 ) ;
	}
	else if ( move == 'd' || move == 'D' || move == 77)
	{
		moveright_for_3 (arr3 , row , col , generate_random_for_3 );
	}
     merge_boxes_for_3 ( arr3 , row , col , move , generate_random_for_3 , score , high_score) ;
}
void moveup_for_3 ( int arr3 [][5] , const int row , const int col , bool &generate_random_for_3)
{
	int x = 0 , y = 0 , tempx = 0 ;
	while ( y < col )
	{
		while ( x < row )
		{
			if ( arr3[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempx = x+1;
				while ( tempx < row )
				{
					if ( arr3[tempx][y] != 0)
					{
						arr3[x][y] = arr3[tempx][y];
					    arr3[tempx][y] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random_for_3 = true ;
						tempx = row;
					}
					tempx++;
				}
			}
			x++;
		}
		y++;
		x = 0 ;
	}
}
void movedown_for_3 ( int arr3 [][5] , const int row , const int col , bool &generate_random_for_3)
{
	int x = row - 1 , y = 0 , tempx = 0 ;
	while ( y < col )
	{
		while ( x >= 0 )
		{
			if ( arr3[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempx = x-1;
				while ( tempx >= 0 )
				{
					if ( arr3[tempx][y] != 0)
					{
						arr3[x][y] = arr3[tempx][y];
					    arr3[tempx][y] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random_for_3 = true ;
						tempx = 0;
					}
					tempx--;
				}
			}
			x--;
		}
		y++;
		x = row - 1 ;
	}
}
void moveleft_for_3 ( int arr3 [][5] , const int row , const int col , bool &generate_random_for_3)
{
	int x = 0 , y = 0 , tempy = 0 ;
	while ( x < row )
	{
		while ( y < col )
		{
			if ( arr3[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempy = y+1;
				while ( tempy < col )
				{
					if ( arr3[x][tempy] != 0)
					{
						arr3[x][y] = arr3[x][tempy];
					    arr3[x][tempy] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random_for_3 = true ;
						tempy = col;
					}
					tempy++;
				}
			}
			y++;
		}
		x++;
		y = 0 ;
	}
}
void moveright_for_3 ( int arr3 [][5] , const int row , const int col , bool &generate_random_for_3)
{
	int x = 0 , y = col - 1 , tempy = 0 ;
	while ( x < row )
	{
		while ( y >= 0 )
		{
			if ( arr3[x][y] == 0 ) // if array[x][y] already has a number than we dont want to change it.
			{
				tempy = y-1 ;
				while ( tempy >= 0 )
				{
					if ( arr3[x][tempy] != 0)
					{
						arr3[x][y] = arr3[x][tempy];
					    arr3[x][tempy] = 0 ; // after shifting this index becomes empty having 0.
					    generate_random_for_3 = true ;
						tempy = 0;
					}
					tempy--;
				}
			}
			y--;
		}
		x++;
		y = col - 1 ;
	}
}
void merge_boxes_for_3 ( int arr3[][5] , const int row , const int col , int move , bool &generate_random_for_3 , int &score , int &high_score)
{
	int x = 0 , y = 0 , tempx1 = 0 , tempx2 = 0 , tempy1 = 0 , tempy2 = 0 ;
	char adding = move ;
	if ( adding == 'w' || adding == 'W' || move == 72 ) // intendation required
	{
		while ( y < col )
		{
			while ( x < row )
			{
				tempx1 = x + 1 ;
				tempx2 = x + 2 ;
				if ( arr3[x][y] == arr3[tempx1][y] && arr3[x][y] == arr3 [tempx2][y] && arr3[x][y] != 0 && arr3[x][y] != 6561 && tempx2 <=4  ) // we merge_boxes_for_3 arr3[x][y] != 0 for random_for_3 condition so generate random_for_3 remains false.
				{
					arr3[x][y] = arr3[x][y] + arr3 [tempx1][y] + arr3 [tempx2][y];
					arr3[tempx1][y] = 0 ;
					arr3[tempx2][y] = 0 ;
					score = score + arr3[x][y] ;
					generate_random_for_3 = true ;
				}
				x++;
			}
			y++;
			x=0 ;
		}
		moveup_for_3 ( arr3 , row , col , generate_random_for_3 );// to rearrange output_for_3
	}
	else if ( adding == 's' || adding == 'S' || move == 80 ) // intendation required
	{
		x = row - 1 ;
		y = 0 ;
		while ( y < col )
		{
			while ( x >= 0 )
			{
				tempx1 = x - 1 ;
				tempx2 = x - 2 ;
				if ( arr3[x][y] == arr3[tempx1][y] && arr3[x][y] == arr3 [tempx2][y] && arr3[x][y] != 0 && arr3[x][y] != 6561 && tempx2 >= 0 )
				{
					arr3[x][y] = arr3[x][y] + arr3 [tempx1][y] + arr3[tempx2][y];
					arr3[tempx1][y] = 0 ;
					arr3[tempx2][y] = 0 ;
					score = score + arr3[x][y] ;
					generate_random_for_3 = true ;
				}
				x--;
			}
			y++;
			x= row - 1 ;
		}
		movedown_for_3(arr3,row,col , generate_random_for_3); // rearrange output_for_3 
	}
	else if ( adding == 'a' || adding == 'A' || move == 75 ) // intendation required
	{
		while ( x < row )
		{
			while ( y < col )
			{
				tempy1 = y + 1 ;
				tempy2 = y + 2 ;
				if ( arr3[x][y] == arr3[x][tempy1] && arr3[x][y] == arr3[x][tempy2] && arr3[x][y] != 0 && arr3[x][y] != 6561 && tempy2 <=4)
				{
					arr3[x][y] = arr3[x][y] + arr3 [x][tempy1] + arr3[x][tempy2];
					arr3[x][tempy1] = 0 ;
					arr3[x][tempy2] = 0 ;
					score = score + arr3[x][y] ;
					generate_random_for_3 = true ;
				}
				y++;
			}
			x++;
			y=0 ;
		}
		moveleft_for_3 ( arr3 , row , col , generate_random_for_3 );// to rearrange output_for_3
	}
	else if ( adding == 'd' || adding == 'D' || move == 77) // intendation required
	{
		x = 0 ;
		y = col - 1 ;
		while ( x < row )
		{
			while ( y >= 0 )
			{
				tempy1 = y - 1 ;
				tempy2 = y - 2 ;
				if ( arr3[x][y] == arr3[x][tempy1] && arr3[x][y] == arr3[x][tempy2] && arr3[x][y] != 0 && arr3[x][y] != 6561 && tempy2 >= 0 )
				{
					arr3[x][y] = arr3[x][y] + arr3 [x][tempy1] + arr3[x][tempy2];
					arr3[x][tempy1] = 0 ;
					arr3[x][tempy2] = 0 ;
					score = score + arr3[x][y] ;
					generate_random_for_3 = true ;
				}
				y--;
			}
			x++;
			y= col - 1 ;
		}
		moveright_for_3(arr3,row,col , generate_random_for_3); // rearrange output_for_3 
	}
	if ( high_score <= score )
	{
		high_score = score ;
	}
}
bool game_continue_for_3 ( int arr3[][5] , const int row , const int col  )
{
	bool conti = false ;
	int x = 0 ,  y = 0 , tempx1 = 0 , tempy1 = 0 , tempx2 = 0 , tempy2 = 0 ;
	while( x < row )
	{
		while ( y < col )
		{
			if ( arr3[x][y] == 0 )
			{
				conti = true ;
				x = row ;
				y = col ;
			}
			y++;
		}
		x++;
		y = 0;
	}
	x=0;
	y=0;
	if ( conti == false )
	{
		while ( x < row )
		{
			while ( y < col )
			{
				tempy1 = y + 1 ;
				tempy2 = y + 2 ;
				if ( arr3[x][y] == arr3[x][tempy1] && arr3[x][y] == arr3[x][tempy2] && arr3[x][y] != 6561 && tempy2 < col)
				{
					conti = true ;
					x = row ;
					y = col ;
				}
				y++;
			}
			x++;
		    y = 0 ;		
		}
	}
	x = 0 ;
	y = 0 ;
	if ( conti == false )
	{
		while ( y < col )
		{
			while ( x < row )
			{
				tempx1 = x + 1 ;
				tempx2 = x + 2 ;
				if ( arr3[x][y] == arr3[tempx1][y] && arr3[x][y] == arr3[tempx2][y] && arr3[x][y] != 6561 && tempx2 < row )
				{
					conti = true ;
					x = row ;
					y = col ;
				}
				x++;
			}
			y++;
			x = 0 ;
		}
	}
	return conti;
}
void save_game_for_3 ( int arr3[][5] , const int row , const int col , int &score , int &high_score )
{
	int x = 0 ;
	int y = 0 ;

	ofstream my_arr3 ("myarr3.txt");
	if ( my_arr3.is_open() )
	{
		while ( x < row )
		{
			while ( y < col ) 
			{
				my_arr3 << arr3[x][y] ;
				y++;
				my_arr3 << ' ' ;
			}
			my_arr3 << '\n' ;
			x++;
			y = 0 ;
		}
		my_arr3.close();
	}
	else
	{
		cout << "Cannot open file myarr3.txt" << endl;
	}

	ofstream myscore ("mycurrentscore3.txt");
	if ( myscore.is_open ())
	{
		myscore << score ;
		myscore.close();
	}
	else
	{
		cout << "Cannot open file mycurrentscore3.txt" << endl ;
	}

	ofstream highscore ( "highscore3.txt");
	if ( highscore.is_open())
	{
		highscore << high_score ;
		highscore.close();
	}
	else
	{
		cout << "Cannot open file highscore3.txt" << endl ;
	}
}
void load_game_for_3 ( int arr3[][5] , const int row , const int col , int &score, int &high_score )
{
	int x = 0 ; 
	int y = 0 ;
	int counter = 0 ;

	ifstream myarr3 ("myarr3.txt");
	if ( myarr3.is_open())
	{
		while ( x < row && !(myarr3.eof()))
		{
			while ( y < col )
			{
				myarr3 >> arr3[x][y] ;
				if ( arr3[x][y] != 0 )
				{
					counter++;
				}
				y++;	
			}
			x++;
			y=0;
	    }

		ifstream myscore ("mycurrentscore3.txt");
		if ( myscore.is_open())
		{
			myscore >> score;
		}
		else
		{
			cout <<"Cannot open file mycurrentscore3.txt " << endl ;
		}

	   ifstream highscore ("highscore3.txt");
	   if ( highscore.is_open())
	   {
		highscore >> high_score ;
	   }
    }
	else 
	{
		cout << "Cannot open file myarr3.txt"<<endl ;
	}

	if ( counter == 0 )
	{
		int start_new_game = 0 ;
		system("cls");
		cout << endl << endl << "  NO PREVIOUS GAME FOUND, PRESS ANY KEY TO CONTINUE" << endl;
		start_new_game = _getch();
		firsttimerandom_for_3(arr3,row,col);
		save_game_for_3 (  arr3,  row , col ,score ,high_score );
	}
}




	