#include <iostream>
#include <limits.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <windows.h>
#include <time.h>

clock_t t; // clock intialized
bool intialize = true; //intialize first zombie postion 
short winloss; //Win/Loss check
int ax[300]; //max number of zombie positions
int ay[300];  
int zx; //zombie position  movement, shared in function Zmove and win/loss conditions
int zy;  

using namespace std;

class GameMap{
	public:
	int x, y; //coord
	short check; //check if valid move
	//int Zombies; // zombie count
	GameMap();
	void gotoxy(int,int); // Set pointer Location
	//void Zmove(); //Zombie movement
	short ZCheck(int, int); //Zombie movement check
	void MAP();   
	void Pmove(); //Player movement
	void ClearScreen();
	void Intro(); //starting art
	short Border(); //wall check
	void  Hide(); //hide curser
	
} ZRun;

GameMap::GameMap() { x = 0 ; y = 0; zx ; zy ; check = 2; }//Zombies;}  //intializing all variables in class


void GameMap::ClearScreen(){ //function to clear screen, adopted code

  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );	
	
}

void GameMap::gotoxy(int x, int y){ // Set pointer Location, adopted code
  
         HANDLE hConsoleOutput;
         COORD dwCursorPosition;  
  
         cout.flush();
         dwCursorPosition.X = x;
         dwCursorPosition.Y = y;
         hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
  return;
} 

void GameMap::Hide(){ // Hide curser, adopted code
     
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO cci;
     GetConsoleCursorInfo(hOut,&cci);
     cci.bVisible=0; //used 1 to appear, used 0 to disappear
     SetConsoleCursorInfo(hOut,&cci);
     return;
     }
   

//void GameMap::Zmove(){ //zombie movements
  
    //int m = ZRun.Zombies ;    // num of zombies    
	//int move;	 // zombie move to be used in switch statement
	//srand (time(NULL)); //time seed 
	
    
	  //		} 


short GameMap::ZCheck(int a , int b){  // wall/loss check
	
     if( a == ZRun.x && b == ZRun.y) //Player position check with zombie position
         return 1;  // GameOver zombie is over character
     else if( a == 0 || a == 79 || b == 0 || b >= 23 )
        return 0;  //Boarder do not move into
     else
        return 2; //free to move into		
}

void GameMap::MAP(){  //functions that makes the walls on the map
	 do{ // MAP
   		
		if(ZRun.y == 0 && ZRun.x <= 79 || ZRun.y == 23 && ZRun.x <= 79 ){  
		ZRun.gotoxy(ZRun.x,ZRun.y);
   		printf("%c", 219 );
   		ZRun.x++;
     	}
     
     	if(ZRun.x > 79){ 
		ZRun.x = 0;
		ZRun.y++;
		}
		
		if(ZRun.y == 1){
		ZRun.gotoxy(79,ZRun.y);
   		printf("%c", 219 );
   		ZRun.x++;
		}
		
		if(ZRun.y == 22 ){
		ZRun.gotoxy(0,ZRun.y);
   		printf("%c", 219 );
   		ZRun.y++;
		}
		
		if(ZRun.y >= 2 && ZRun.y <= 21 ){
		ZRun.gotoxy(0,ZRun.y);
   		printf("%c", 219 );	
   		ZRun.gotoxy(79,ZRun.y);
   		printf("%c", 219 );	
   		ZRun.x++;
		}	
		
 	}
	while(ZRun.y < 24);
	return;
}

short GameMap::Border(){  // WAll/win check  
     
     if( ZRun.x == 79 && ZRun.y == 22 )
         return 1;  // stage won
     else if( ZRun.x == 0 || ZRun.x == 79 || ZRun.y == 0 || ZRun.y >= 23 )
        return 0;  //Boarder do not move into
     else
         return 2; //free to move into
}  

void GameMap::Pmove(){ //player movement 
	
		short pos;
		short esc = 0;


         if ( !esc ) {
                   
         esc = GetAsyncKeyState ( VK_ESCAPE );
         Sleep(100); // character movement delay

         if ( GetAsyncKeyState ( VK_UP ) & SHRT_MAX )
              {      //moving up key 
                       --ZRun.y;
                       ZRun.check = ZRun.Border(); // check if valid move
                         if( ZRun.check > 0){ // move is allowed
                       ZRun.gotoxy(ZRun.x,ZRun.y+1);
                       cout<<" ";
                       }
                       else
                         ZRun.y++;
                        }
         else if ( GetAsyncKeyState ( VK_DOWN ) & SHRT_MAX )
              {    //moving down key
                         ZRun.y++;
                         ZRun.check = ZRun.Border(); // check if valid move
                         if( ZRun.check > 0){ // move is allowed
                         ZRun.gotoxy(ZRun.x,ZRun.y-1);
                         cout<<" ";
                         }
                         else
                         --ZRun.y;
                        }
         else if ( GetAsyncKeyState ( VK_LEFT ) & SHRT_MAX )
              {    //moving left key
                         --ZRun.x;
                         ZRun.check = ZRun.Border(); // check if valid move
                         if( ZRun.check > 0){ // move is allowed
                         ZRun.gotoxy(ZRun.x+1,ZRun.y);
                         cout<<" ";
                         }
                         else
                         ZRun.x++;
                        }
         else if ( GetAsyncKeyState ( VK_RIGHT ) & SHRT_MAX )
              {   //moving right key
                         ZRun.x++;
                         ZRun.check = ZRun.Border(); // check if valid move
                         if( ZRun.check > 0){ // move is allowed
                         ZRun.gotoxy(ZRun.x-1,ZRun.y);
                         cout<<" ";
                         }
                         else
                         --ZRun.x;
                        }
                        
              for(int r=0; r <= 300; r++){		//checks players movement against all zombie positions
              	ZRun.check = ZRun.ZCheck(ax[r],ay[r]);	//if player moves into a zombie loss condition is set
              	if(ZRun.check == 1)
               	winloss = 2;
              }       
                        
              }
        
         ZRun.gotoxy(ZRun.x,ZRun.y);
         SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  0x07); //color player white
         printf("%c", 001 ); //print player character
                      
         return;	
}

void GameMap::Intro(){
    
    //Intro Art
    ZRun.gotoxy(15,3);
   char playerName[20];
	cout<< "\n Hello, what is your name?\n ";
	cin>>playerName ;
	cout<< "\n Welcome to DOOMSDAY PIZZA RUN "<<playerName <<". \n"
		<< " In this game you will be required to go get pizza from a local delivery shop without getting eaten.\n"
		<< " More zombies will show up the longer you take so you better run quick! \n";
    	ZRun.gotoxy(25,17);
    	cout << "Press Any Key to Start...";
     	getch(); //to start action 
     return;   
     }

int main()
{
	 
    t = clock(); //sets t to the clock
    //ZRun.Zombies = 200;  // Zombie count 
    
    
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  0x07);	
 
    ZRun.Intro(); //display intro art
    
    Sleep(500);
    ZRun.ClearScreen(); // clear screen
    
    //Print Map
	ZRun.MAP(); //print map walls
   
   SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  0x08);
   	
   ZRun.gotoxy(1,1); //go to player starting position
  
   printf("%c \n" , 001);  //print player in start position
   ZRun.x=1; //set players coord
   ZRun.y=1;  
   
  int delay; //time delay for zombie movements 
   
  ZRun.Hide();   // hide the curser
  while(true){
              
              ZRun.Pmove(); //players move
              	
            
              delay = clock() - t; // clock - time to get delay
              if( delay > 1500 ){
              //ZRun.Zmove();  //zombies move is time delay is 1500 ticks of more have passed 
  			  t = clock(); //reset t to current time for next delay cycle
              }
              
              ZRun.check = ZRun.Border(); // check if win condition
               if( ZRun.check == 1)
               winloss = 1; //won
				
				if(winloss != 0) // win/loss check then break from loop
				break;
  }
  
  if (winloss == 1){

  	// round won 
  	ZRun.ClearScreen(); 
  	ZRun.gotoxy(0,1);
  	cout << "Contragulations you won!!!" ;
	}
  else if (winloss == 2){
	// round lost 
  	ZRun.ClearScreen(); 
  	ZRun.gotoxy(0,1);
  	cout << "GAME OVER!!!" ; 
	cout << "\n\nZombies got you. Restart to try again" ;
  }
	
   cin.get();
   return 0; //end and exit
}
