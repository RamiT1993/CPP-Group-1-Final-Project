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


/* 
	PreProcessor Directives Section Start 
*/
#include <iostream> // for input and output default stream use
#include <string> // for string data type use
#include <iomanip> // output manipulation
#include <fstream> // for reading and writing files to a file stored on the secondary storage device
#include <ctime> // to truly be random
#include <cstdlib> // for random use
#include <cmath> // maybe? in case we use it later otherwise deletion
#include <cctype> // maybe? in case we use it later otherwise deletion

/* 
	PreProcessor Directives Section End 
*/

/* 
	Function Prototype section in which you put who created it, date of last revision  
*/

// Every One Participated in the creation of these functions
int randomResult(); // November 18th, 2022

void readWins(int&, int&, int&);




// Rami's Function Prototypes

// Emily's Function Prototypes

// Hunter's Function Prototypes

/* 
	Function ProtoType Section End  
*/

using namespace std; // so we dont have to constantly use std:: prefix


/* 
	Main Function Start 
*/
int main() 
{
	// variables
	int hangmanWins = 0;
	int pictionaryWins = 0;
	int boardGameWins = 0;

	// bool controlled and flag controlled variables
	bool quitProgram = false;

	readWins(hangmanWins, pictionaryWins, boardGameWins);

	
	
}


/*
	Main Function End 
*/


/*
	Function Definition Start 
*/

// Every One Participated in the creation of these functions


//This Function primary purpose is to act as a fail safe against user generated error when they choose which game and when to quit. We don't want the program to crash when the user messes up the button or key prompt		
int randomResult()
{
	int srand(time(0)); // this allows us to use a seed so the random can actually be random each time of running the function. time(0) indicates the number of seconds start from january 1, 1970.
	return rand() % 3 + 1; // indicates that we want to start at position 1 and not position 0 because rand() indicates a position start at 0 without the + 1 in the end
}

// purpose of this function is to read the total wins, this was talked about and developed together at the zoom meeting, since we all inputted on this information together
void readWins(int& firstGame, int& secondGame, int& thirdGame)
{
	ifstream winningOutput; // creates a variable for writing
	winningOutput.open("totalWins.txt"); // opens the file for reading
	if (winningOutput) // (filestreamvariable) checks if file exists (!filestreamvariable) checks if file stream variable file does not exist
	{
		string tempHolder; // used just to hold the total wins from each game and gets deleted once it exits the scope
		int wins = 0; // holds the read file wins
		int winsArray[3]{}; // holds the wins from all three game to then be inputted later in the reference variables in array format
		int arrayControlVariable = 0; // control the array element so it does not go out of scope

		// this whole section makes sure that the file does not reach the end of the array and goes out of scope and se
		while (!winningOutput.eof() && winningOutput >> tempHolder >> wins && arrayControlVariable != 3)
		{
			if (wins <= 0)
			{
				wins = 0;
				winsArray[arrayControlVariable] = wins;

			}
			else
			{
				winsArray[arrayControlVariable] = wins;
			}
			
			arrayControlVariable++;
		}
		
		firstGame = winsArray[0];
		secondGame = winsArray[1];
		thirdGame = winsArray[2];

		
		//cout << firstGame << " " << secondGame << " " << thirdGame;


	}
	else
	{
		cout << "Save file does not exist and/or manipulated in some way. Resetting all Wins to 0";
		firstGame = 0;
		secondGame = 0;
		thirdGame = 0;
		// cout << firstGame << secondGame << thirdGame; used to check if wins are set to 0

	}

	winningOutput.close(); // to close the file after opening it of course.
}



// Rami's Function Definitions

// Emily's Function Definitions

// Hunter's Function Definitions


/* 
	Function Definition End 
*/