//-------------------------------------//
//-------------------------------------//
//  Aaryn Biro -- Assignment 3 - 1037  //
//-------------------------------------//
//------------UNO Card Game-------------//

#include <iostream>
#include <string>
#include "UnoGame.h"
#include <time.h>
//#include "vld.h"
#define NULL 0
using namespace std;

int main(){

srand((unsigned int)time(NULL));		//randomize the game

cout << "	     Welcome to UNO!\n" << endl;
	
UnoGame gameon;							//create game
		
gameon.play();							//everything in game play

return 0;
}

