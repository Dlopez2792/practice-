#include <iostream>
#include <limits.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <windows.h>
using namespace std; 

class GameMap{
	public:
	int x, y; //coord
	void Intro(); //starting art
	void gotoxy(int,int); // Set pointer Location
	//short check; //check if valid move
	GameMap();
	void MAP(); 
} ZRun;

GameMap::GameMap() { x = 0 ; y = 0 }//Zombies;}  //intializing all variables in class

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

int main () {
	
	
	
	int 
	switch(i){ 
	case 'a': cout<<" You made a stupid decision, now your brain will get eaten by zombies.";
	break;
	case 'b': cout<<" Wrong choice you lost because you're not smart enough to survive doomsday";
	break;
	case 'c': cout<<" This is clearly not your day, you're about to get eaten alive..";
	break;
}
}

