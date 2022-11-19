/*
	Program Name: Carnival
	Program Group Leader: Rami Toma
	Program Group Members: Emily Burley and Hunter Donovan
	Rami's Portion of Work Final Revision Date: Month Day, 2022
	Emily's Portion of Work Final Revision Date: Month Day, 2022
	Hunter's Portion of Work Final Revision Date: Month Day, 2022
	Final Program Revision Date: Month Day, 2022

	Small Summary Of Program: 
		You choose a game to play or at random if not chosen a game to play it will be selected randomly and you play a small mini-game in which you follow a set of rules to play the game.

	You must give ample description for each function you create

	for each function put

*/


/* PreProcessor Directives Section Start */
#include <iostream> // for input and output default stream use
#include <string> // for string data type use
#include <iomanip> // output manipulation
#include <ctime> // to truly be random
#include <cstdlib> // for random use
#include <cmath> // maybe? in case we use it later otherwise deletion
#include <cctype> // maybe? in case we use it later otherwise deletion

/* PreProcessor Directives Section End */

/* Function Prototype section in which you put who created it, date of last revision  */

int randomResult(); // Everyone Partcipated in the creation of rand

/* Function ProtoType Section End  */

using namespace std; // so we dont have to constantly use std:: prefix


/* Main Function Start */
int main() 
{
	// variables
	int hangmanWins = 0;
	int pictionaryWins = 0;
	int boardGameWins = 0;

	// bool controlled and flag controlled variables
	bool quitProgram = false;
	
}


/* Main Function End */


/* Function Definition Start */


/* This Function primary purpose is:
		to act as a fail safe against user generated error when they choose which game and when to quit*/
int randomResult()
{
	int srand(time(0)); // this allows us to use a seed so the random can actually be random each time of running the function. time(0) indicates the number of seconds start from january 1, 1970.
	return rand() % 3 + 1; // indicates that we want to start at position 1 and not position 0 because rand() indicates a position start at 0 without the + 1 in the end
}


/* Function Definition End */