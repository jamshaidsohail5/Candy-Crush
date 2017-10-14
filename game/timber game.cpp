#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
 using namespace std ;
 void move_ ( int arr[][2] , const int row , const int col , char &move);
 void first_time_random ( int arr[][2] , const int row , const int col );
 void random ( int arr[][2] , const int row , const int col );
 void random_branches ( int arr[][2] , const int row , const int col );
 bool continue_game ( int arr[][2] , const int row , const int col , char &move ) ;
 void output ( int arr[][2] , const int row , const int col , char &move , int &score , int &first);
 void main ()
 {
	 int ok = 0 ;
	 cout << "     __________________________INSTRUCTIONS_________________________ " << endl << endl << endl << endl ;

	 cout << " YOU HAVE TO CHOP THE TREE PRESSING A OR D " << endl <<" WHILE CHOPPING ,THE BRANCHES WILL COME DOWN"<< endl <<" AND YOU WILL HAVE TO MOVE YOU CHARACTER IN SUCH A WAY THAT HIS HEAD REMAINS" << endl <<" SAVE FROM THE BRANCHES " <<endl ;
	 cout << endl<< endl << endl << " PRESS ANY KEY TO CONTINUE " << endl ;
	 ok = _getch();
	 srand(time(NULL));
	 
	 char  move = '\0' ;
	 int score = 0 ;
	 int first = 0 ;
	 bool conti_game = true ;
	 bool conti = false ;
	 const int row = 15 ;
	 const int col = 2 ;
	 int arr[row][col] ;
	 for ( int i = 0 ; i < row ; i++ )
	 {
		 for ( int j= 0 ; j < col ; j++ )
		 {
			 arr[i][j] = 0 ;
		 }
	 }
	 
	 first_time_random ( arr , row , col );
	 conti = continue_game ( arr , row , col , move);
	 while ( conti_game)
	 {
		 int option = 0 ;
	     while ( conti )
	     {
	         output ( arr , row , col ,move , score , first);
	         move_ ( arr , row , col , move );
		     random ( arr , row , col );
	         output ( arr , row , col , move , score , first);
		     conti = true ;
		     conti = continue_game ( arr , row , col , move );
		     score++;
	     }

	     cout << endl << " ------------------- GAME OVER :'( --------------------" << endl ;

	     cout << "DO YOU WISH TO START A NEW GAME ?" << endl <<"1.YES" << endl <<"2.NO" << endl;
		 cout <<"Option :";
		 cin >> option;
	     while (option != 1 && option != 2 )
	     {
		     cout <<"Enter correct option >.<" ;
			 cout << endl <<"Option :";
		     cin >> option ;
	     }
	     if ( option == 1)
	     {
		     score = 0 ;
		     conti = true ;
	     }
	     else if ( option == 2 )
	     {
		     system("cls");
		     cout << endl << endl << "      ---------------THANKS FOR PLAYING , NOT REALLY----------------------" << endl ;
		     conti_game = false ;
	     }
	 }

	 
	 system("pause");
 }

 void first_time_random ( int arr[][2] , const int row , const int col )
 {
	 int left_right = 0 ;
	

	 for ( int i = 0 ; i < row - 2 ; i ++ )
	 {
		 left_right = rand() % 3 ;
		 if ( left_right == 0 )
		 {
			 arr[i][0] = 1 ;
		 }
		 else if ( left_right == 1 )
		 {
			 arr[i][1] = 1 ;
		 }
	 }
 }

 void move_ ( int arr[][2] , const int row , const int col , char &move)
 {
	 cout << "Enter Move :" ;
	 move = _getch();

	 while ( move != 'a' && move != 'd' )
	 {
		 cout << endl << "Invalid move >.< " << endl <<"Enter Move:" ;
		 move = _getch();
	 }

	 for ( int i = 14 ; i >0 ; i--)
	 {
		 arr[i][0] = arr[i-1][0] ;
		 arr[i][1] = arr[i-1][1] ;
		 
	 }
	 arr[0][0] = 0 ;
	 arr[0][1] = 0 ;
 }
 bool continue_game ( int arr[][2] , const int row , const int col , char &move)
 {
	 bool conti = true ;
	 if ( move == 'a' )
	 {
		 if ( arr[14][0] == 1 )
		 {
			 conti = false ;
		 }
	 }
	 else if ( move == 'd' )
	 {
		 if ( arr[14][1] == 1 )
		 {
			 conti = false ;
		 }
	 }
	 return conti ;
 }
 void output ( int arr[][2] , const int row , const int col , char &move , int &score , int &first)
 {
	 HANDLE  hConsole ;
	 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 system("cls");

	cout << endl << "        " ; 
	SetConsoleTextAttribute (hConsole , 279 );
	cout << "                                                            " << endl ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "        ";
	SetConsoleTextAttribute (hConsole , 279 );
	cout  <<"                           TIMBER MAN                       " << endl  ;
	SetConsoleTextAttribute (hConsole , 15 );
	cout << "        " ;
	SetConsoleTextAttribute (hConsole , 279 );
	cout << "                                                            " << endl << endl << endl ;
	SetConsoleTextAttribute (hConsole , 15 );


	 cout << endl << endl;
	 cout << "                         ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "  ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "                      ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "        ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "                    ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "            ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "                  ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "                ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                    ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "                ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                    ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "              ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                        ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;
	  cout << "              ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                        ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "            ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                            ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "            ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                            ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "          ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                                ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "          ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                                ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "         ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                                  ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;

	 cout << "         ";
	 SetConsoleTextAttribute (hConsole,290 );
	 cout << "                                  ";
	 SetConsoleTextAttribute (hConsole,15 );
	 cout << endl ;
			
	 for ( int i = 0 ; i < row - 1  ; i++ )
	 {
		 cout << "                 " ; 
			 if ( arr[i][0] == 1 )
			 {
				 SetConsoleTextAttribute (hConsole,2 );
				 cout << "{}" ;
				 SetConsoleTextAttribute (hConsole,15 );
				 SetConsoleTextAttribute (hConsole,4);
				 cout << "====" ;
				 SetConsoleTextAttribute (hConsole,15);
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "    "<< endl ;
			 }
			 else if ( arr[i][1] == 1 )
			 {
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 SetConsoleTextAttribute (hConsole,4);
				 cout << "====" ;
				 SetConsoleTextAttribute (hConsole,15);
				 SetConsoleTextAttribute (hConsole,2 );
				 cout << "{}" ;
				 SetConsoleTextAttribute (hConsole,15 );
				 cout << endl ;			
			 }
			 else
			 {
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "    " << endl ;
			 }

			 

		// }
	 }
	 if ( first == 0 )
			 {
				 cout << "                     */";	 
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "    "<< endl ;

				 cout << "                    -| " ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "    " << endl ;

				 cout << "                    / |" ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "    " << endl ;
				 first ++ ;
			 }
	 if ( move == 'a' )
	 {
	             cout << "                     */";	 
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "    "<< endl ;

				 cout << "                    -| " ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "  " ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "    " << endl ;
				 SetConsoleTextAttribute (hConsole,15 );

				 cout << "                    / |" ;
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "      " ;
				 SetConsoleTextAttribute (hConsole,15);
				 cout << "  ";
				 SetConsoleTextAttribute (hConsole,330 );
				 cout << "    " << endl ;
				 SetConsoleTextAttribute (hConsole,15 );
	 }
			 
	 
	 if ( move == 'd' )
	 {
		        cout << "                       ";
				SetConsoleTextAttribute (hConsole,330 ); 
				cout << "      " ;
				SetConsoleTextAttribute (hConsole,15);
				cout << " */";
				cout << endl ;
				cout << "                 "; 
				SetConsoleTextAttribute (hConsole,330 );
				cout << "    " ;
				SetConsoleTextAttribute (hConsole,15 );
				cout << "  "  ;
				SetConsoleTextAttribute (hConsole,330 ); 
				cout << "      " ;
				SetConsoleTextAttribute (hConsole,15);
				cout << "-| ";
				cout << endl ;
				cout << "                 ";
				SetConsoleTextAttribute (hConsole,330 );
				cout << "    " ;
				SetConsoleTextAttribute (hConsole,15 );
				cout << "  "  ;
				SetConsoleTextAttribute (hConsole,330 );
				cout << "      " ;
				SetConsoleTextAttribute (hConsole,15);
				cout << "/ \." << endl ;
	 }
	  cout << endl << "              Score is :" << score << endl ;
 }
 void random ( int arr[][2] , const int row , const int col )
 {
	 int left_right = 0 ;
	 left_right = rand() % 3 ;

	 if ( left_right == 0 )
	 {
		  arr[0][0] = 1 ;
	 }
	 else if ( left_right == 1 )
	 {
		  arr[0][1] = 1 ;
	 }
 }

 





