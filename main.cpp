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
using namespace std;
/* 
	PreProcessor Directives Section End 
*/

/* 
	Function Prototype section put the function you created inside of your section
*/

// Every One Participated in the creation of these functions
int randomResult(); 

void readWins(int&, int&, int&);

void writeWins(int&, int&, int&);



//void mainLoop(int&, int&, int&); maybe like this




// Rami's Function Prototypes

// Emily's Function Prototypes

// Hunter's Function Prototypes
void Pictionary(int& wins)
{
	int selection;
	int counter = 6;
	string guess;
	int increment = 1;
	int i = 0;
	char response = ' ';
	bool playagain = true;
	cout << "!!!!!INSTRUCTIONS!!!!!" << endl << "In this game the objective is to guess what the photo you select is" << endl << " The more wrong guesses you have the easier it will be to guess the photo you have 5 guesses for each photo."<< endl;
	while (playagain == true){
		cout << "Pick a number 1 to 3 (Input as 1,2, or 3) to pick the photo you would like to guess: ";
		cin >> selection;
		cout << endl << "You have selected photo number " << selection << " you will have 5 guesses to figure out the photo or you will lose." << endl;
		if (selection == 1)
		{

			while (guess != "horse" && playagain != false)
			{

				i++;
				switch (i) {
				case '1':

					cout << "__________________________________________AIgg" << endl << "_____________________________________gggggggggg_" << endl << "__________________________________ggggggggggg0gg" << endl << "_______________________________ggggggggggggggggggg" << endl;
					cout << "Please enter your 1st guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "horse" || guess == "Horse")
					{
						cout << " You got it the answer is horse" << endl;
						guess = "horse";
						wins = wins + increment;

					}
					break;
				case '2':

					cout << "__________________________________________AIgg" << endl << "_____________________________________gggggggggg_" << endl << "__________________________________ggggggggggg0gg" << endl << "_______________________________ggggggggggggggggggg" << endl;
					cout << "_____ggg____ggggggg__________gggggggggggg_____ggggg" << endl << "__ggggggggggggggggggggggggggggggggggggggg" << endl << "_gggggg__ggggggggggggggggggggggggggggggg" << endl << "gggggg___gggggggggggggggggggggggggggggg" << endl;
					cout << "Please enter your 2nd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "horse" || guess == "Horse")
					{
						cout << " You got it the answer is horse" << endl;
						guess = "horse";
						wins = wins + increment;

					}
					break;
				case '3':

					cout << "__________________________________________AIgg" << endl << "_____________________________________gggggggggg_" << endl << "__________________________________ggggggggggg0gg" << endl << "_______________________________ggggggggggggggggggg" << endl;
					cout << "_____ggg____ggggggg__________gggggggggggg_____ggggg" << endl << "__ggggggggggggggggggggggggggggggggggggggg" << endl << "_gggggg__ggggggggggggggggggggggggggggggg" << endl << "gggggg___gggggggggggggggggggggggggggggg" << endl;
					cout << "ggggg____ggggggggggggggggggggggggggggg" << endl << "gg_________ggggggggggggggggggggggggggg" << endl << "__________gggggggg_gggggggggggggggggg" << endl << "______gggggggggggg_____________ggggggg" << endl;
					cout << "Please enter your 3rd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "horse" || guess == "Horse")
					{
						cout << " You got it the answer is horse" << endl;
						guess = "horse";
						wins = wins + increment;

					}
					break;
				case '4':

					cout << "__________________________________________AIgg" << endl << "_____________________________________gggggggggg_" << endl << "__________________________________ggggggggggg0gg" << endl << "_______________________________ggggggggggggggggggg" << endl;
					cout << "_____ggg____ggggggg__________gggggggggggg_____ggggg" << endl << "__ggggggggggggggggggggggggggggggggggggggg" << endl << "_gggggg__ggggggggggggggggggggggggggggggg" << endl << "gggggg___gggggggggggggggggggggggggggggg" << endl;
					cout << "ggggg____ggggggggggggggggggggggggggggg" << endl << "gg_________ggggggggggggggggggggggggggg" << endl << "__________gggggggg_gggggggggggggggggg" << endl << "______gggggggggggg_____________ggggggg" << endl;
					cout << "_____gggg____gggg________________ggggg" << endl << "_____ggR_____ggg___________________gggg" << endl << "_____gg_____gggg___________ggg__ggggggggg" << endl << "____ggg______ggg____________gggggg____ggg" << endl;
					cout << "Please enter your 4th guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "horse" || guess == "Horse")
					{
						cout << " You got it the answer is horse" << endl;
						guess = "horse";
						wins = wins + increment;

					}
					break;
				case '5':

					cout << "__________________________________________AIgg" << endl << "_____________________________________gggggggggg_" << endl << "__________________________________ggggggggggg0gg" << endl << "_______________________________ggggggggggggggggggg" << endl;
					cout << "_____ggg____ggggggg__________gggggggggggg_____ggggg" << endl << "__ggggggggggggggggggggggggggggggggggggggg" << endl << "_gggggg__ggggggggggggggggggggggggggggggg" << endl << "gggggg___gggggggggggggggggggggggggggggg" << endl;
					cout << "ggggg____ggggggggggggggggggggggggggggg" << endl << "gg_________ggggggggggggggggggggggggggg" << endl << "__________gggggggg_gggggggggggggggggg" << endl << "______gggggggggggg_____________ggggggg" << endl;
					cout << "_____gggg____gggg________________ggggg" << endl << "_____ggR_____ggg___________________gggg" << endl << "_____gg_____gggg___________ggg__ggggggggg" << endl << "____ggg______ggg____________gggggg____ggg" << endl;
					cout << "__gggg_________ggg______________________gg" << endl << "__gg____________ggg______________________gg" << endl << "_________________gggg_____________________ggg" << endl << "__________________gggg_____________________ggg" << endl;
					cout << "Please enter your 5th and final guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "horse" || guess == "Horse")
					{
						cout << " You got it the answer is horse" << endl;
						guess = "horse";
						wins = wins + increment;

					}
					break;
				case '6':
					cout << "Better luck next time ):" << endl;
					guess = "lose";

					break;
				}
				if (guess == "lose") {
					break;
				}



			}

		}
		if (selection == 2 && playagain != false)
		{

			while (guess != "turtle")
			{

				i++;
				switch (i) {
				case '1':
					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << " You got it the answer is turtle" << endl;
						guess = "turtle";
						wins = wins + increment;

					}
					break;
				case '2':
					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "Please enter your 2nd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << " You got it the answer is turtle" << endl;
						guess = "turtle";
						wins = wins + increment;

					}
					break;
				case '3':

					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "$¶_$¶_$$$_$$$_$$$_$$$_$$$_$$$_$$$" << endl << "$______$_$$_$$$_$$$_$$$_$$$_$$$_$$$__$$" << endl;
					cout << "Please enter your 3rd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << " You got it the answer is turtle" << endl;
						guess = "turtle";
						wins = wins + increment;

					}
					break;
				case '4':

					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "$¶_$¶_$$$_$$$_$$$_$$$_$$$_$$$_$$$" << endl << "$______$_$$_$$$_$$$_$$$_$$$_$$$_$$$__$$" << endl;
					cout << "_$_$__$__$$$$_$$$_$$$_$$$_$$$_$$$$$$_$$" << endl << "__$$$_$$$$$$$$$$$$$$$$$_$$$$$$$$$$$$$" << endl;
					cout << "Please enter your 4th guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << " You got it the answer is turtle" << endl;
						guess = "turtle";
						wins = wins + increment;

					}
					break;
				case '5':

					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "$¶_$¶_$$$_$$$_$$$_$$$_$$$_$$$_$$$" << endl << "$______$_$$_$$$_$$$_$$$_$$$_$$$_$$$__$$" << endl;
					cout << "_$_$__$__$$$$_$$$_$$$_$$$_$$$_$$$$$$_$$" << endl << "__$$$_$$$$$$$$$$$$$$$$$_$$$$$$$$$$$$$" << endl;
					cout << "___________$$$$$$$_$$$$$$$_$_$$$$" << endl << "_________$$_$___$$_$____$$_$___$_$" << endl << "________$$$$$__$$$$$___$$$$$__$$$$$" << endl;
					cout << "Please enter your 5th and final guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << " You got it the answer is turtle" << endl;
						guess = "turtle";
						wins = wins + increment;

					}
					break;
				case '6':
					cout << "Better luck next time ):" << endl;
					guess = "lose";

					break;
				}
				if (guess == "lose") {
					break;
				}



			}

		}
		if (selection == 3 && playagain != false)
		{
			while (guess != "crab")
			{

				i++;
				switch (i) {
				case '1':

					cout << "______$$_____________________ $$" << endl << "____$$$__$__________________$__$$$" << endl << "___$$$___$$________________$$___$$$" << endl << "___$$$$$$$$________________$$$$$$$$" << endl;
					
					cout << "Please enter your 1st guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "crab" || guess == "Crab")
					{
						cout << " You got it the answer is crab" << endl;
						guess = "crab";
						wins = wins + increment;

					}
					break;
				case '2':
					cout << "______$$_____________________ $$" << endl << "____$$$__$__________________$__$$$" << endl << "___$$$___$$________________$$___$$$" << endl << "___$$$$$$$$________________$$$$$$$$" << endl;
					cout << "____$$$$$$__________________$$$$$$" << endl << "_____$$$$____$$0$$$$$0$$$____$$$$" << endl << "_______$$__$$$$$$$$$$$$$$$$__$$" << endl << "___$$___$$$$$$$$$$$$$$$$$$$$$$___$$" << endl;

					cout << "Please enter your 2nd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "crab" || guess == "Crab")
					{
						cout << " You got it the answer is crab" << endl;
						guess = "crab";
						wins = wins + increment;

					}
					break;
				case '3':
					cout << "______$$_____________________ $$" << endl << "____$$$__$__________________$__$$$" << endl << "___$$$___$$________________$$___$$$" << endl << "___$$$$$$$$________________$$$$$$$$" << endl;
					cout << "____$$$$$$__________________$$$$$$" << endl << "_____$$$$____$$0$$$$$0$$$____$$$$" << endl << "_______$$__$$$$$$$$$$$$$$$$__$$" << endl << "___$$___$$$$$$$$$$$$$$$$$$$$$$___$$" << endl;
					cout << "_$$__$$__$$$$$$$$$$$$$$$$$$$$__$$__$$" << endl << "$______$$$$$$$$$$$$$$$$$$$$$$$$______$" << endl << "$__$$$____$$$$$$$$$$$$$$$$$$____$$$__$" << endl;

					cout << "Please enter your 3rd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "crab" || guess == "Crab")
					{
						cout << " You got it the answer is crab" << endl;
						guess = "crab";
						wins = wins + increment;

					}
					break;
				case '4':
					cout << "______$$_____________________ $$" << endl << "____$$$__$__________________$__$$$" << endl << "___$$$___$$________________$$___$$$" << endl << "___$$$$$$$$________________$$$$$$$$" << endl;
					cout << "____$$$$$$__________________$$$$$$" << endl << "_____$$$$____$$0$$$$$0$$$____$$$$" << endl << "_______$$__$$$$$$$$$$$$$$$$__$$" << endl << "___$$___$$$$$$$$$$$$$$$$$$$$$$___$$" << endl;
					cout << "_$$__$$__$$$$$$$$$$$$$$$$$$$$__$$__$$" << endl << "$______$$$$$$$$$$$$$$$$$$$$$$$$______$" << endl << "$__$$$____$$$$$$$$$$$$$$$$$$____$$$__$" << endl;
					cout << "__$___$$$$_$$$$$$$$$$$$$$$$_$$$$___$" << endl << "_$_________$_$$$$$$$$$$$$_$_________$" << endl << "_$______$$$________________$$$______$" << endl;
					cout << "Please enter your 4th guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "crab" || guess == "Crab")
					{
						cout << " You got it the answer is crab" << endl;
						guess = "crab";
						wins = wins + increment;

					}
					break;
				case '5':
					cout << "______$$_____________________ $$" << endl << "____$$$__$__________________$__$$$" << endl << "___$$$___$$________________$$___$$$" << endl << "___$$$$$$$$________________$$$$$$$$" << endl;
					cout << "____$$$$$$__________________$$$$$$" << endl << "_____$$$$____$$0$$$$$0$$$____$$$$" << endl << "_______$$__$$$$$$$$$$$$$$$$__$$" << endl << "___$$___$$$$$$$$$$$$$$$$$$$$$$___$$" << endl;
					cout << "_$$__$$__$$$$$$$$$$$$$$$$$$$$__$$__$$" << endl << "$______$$$$$$$$$$$$$$$$$$$$$$$$______$" << endl << "$__$$$____$$$$$$$$$$$$$$$$$$____$$$__$" << endl;
					cout << "__$___$$$$_$$$$$$$$$$$$$$$$_$$$$___$" << endl << "_$_________$_$$$$$$$$$$$$_$_________$" << endl << "_$______$$$________________$$$______$" << endl;
					cout << "_______$______________________$" << endl << "______$________________________$" << endl << "______$_______________________ _$" << endl;

					cout << "Please enter your 5th and final guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "crab" || guess == "Crab")
					{
						cout << " You got it the answer is crab" << endl;
						guess = "crab";
						wins = wins + increment;

					}
					break;
				case '6':
					cout << "Better luck next time ):" << endl;
					guess = "lose";

					break;
				}
				if (guess == "lose") {
					break;
				}



			}

		}
		cout << "would you like to play again(y or n)?";
		cin >> response;
		cout << endl;
		switch (response) {
		case 'y':
		case 'Y':
			i = 0;
			selection = 0;
			guess.clear();
			break;
		case 'n':
		case 'N':
			playagain = false;
			break;

		}
		
	}

}
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
	
	;
	// bool controlled and flag controlled variables
	bool quitProgram = false;

	cout << hangmanWins << pictionaryWins << boardGameWins << endl;

	readWins(hangmanWins, pictionaryWins, boardGameWins);

	cout << hangmanWins << pictionaryWins << boardGameWins << endl;


	writeWins(hangmanWins, pictionaryWins, boardGameWins);
	
	
}


/*
	Main Function End 
*/


/*
	Function Definition(s) Start 
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
		while (!winningOutput.eof() && winningOutput >> tempHolder >> tempHolder >> wins && arrayControlVariable != 3)
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


// this was talked about and further elaborated on in the zoom meeting
// purpose of this file is to write the wins of each game and the total number Wins to a text file and output it in a way thats legible to the end user. by using arrays we are are able to quickly access them 
// through a loop and outputting the results which is then used in the setw portion of the work. we can we the for loop to iterate throughout each loop. we create an empty loop to then output the results.
// we use .length method to get the amount of characters in the string (this was shown in one of the examples)
// arrays allow us to be more flexible and a good way to use loop to contain a collection of data. (i love arrays)
void writeWins(int& firstGame, int& secondGame, int& thirdGame)
{

	string gameWriteArray[] = { "HangMan Wins:", "Pictionary Wins:", "BoardGame Wins:", "Total Wins:" };
	int holdLoopResults[4]{};

	for (int goingThroughArrayLoop = 0; goingThroughArrayLoop != 4; goingThroughArrayLoop++)
	{
		holdLoopResults[goingThroughArrayLoop] = 30 - gameWriteArray[goingThroughArrayLoop].length() ;
		if (holdLoopResults[goingThroughArrayLoop] <= 0)
		{
			holdLoopResults[goingThroughArrayLoop] = 1;
		}

	}

	ofstream writeToWinFile;
	writeToWinFile.open("totalWins.txt");
	
	if (writeToWinFile) // we use an if (writeToWinFile) to make sure it already exists else do not write to file
	{
		int totalWinsInt = firstGame + secondGame + thirdGame;
		writeToWinFile << gameWriteArray[0] << setw(holdLoopResults[0]) << firstGame << endl;
		writeToWinFile << gameWriteArray[1] << setw(holdLoopResults[1]) << secondGame << endl;
		writeToWinFile << gameWriteArray[2] << setw(holdLoopResults[2]) << thirdGame << endl;
		writeToWinFile << gameWriteArray[3] << setw(holdLoopResults[3]) << totalWinsInt << endl;
	}

	writeToWinFile.close();
}




// Rami's Function Definitions

// Emily's Function Definitions

// Hunter's Function Definitions


/* 
	Function Definition End 
*/