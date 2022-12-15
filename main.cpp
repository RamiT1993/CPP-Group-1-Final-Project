/*
	Program Name: Carnival
	Program Group Leader: Rami Toma
	Program Group Members: Emily Burley and Hunter Donovan
	Rami's Portion of Work Final Revision Date: Noveember 30th, 2022 @ 3.54 a.m.
	Emily's Portion of Work Final Revision Date: Month Day, 2022
	Hunter's Portion of Work Final Revision Date: Month Day, 2022
	Final Program Revision Date: Month Day, 2022

	Small Summary Of Program:
		You choose a game to play or at random if not chosen a game to play it will be selected randomly and you play a small mini-game in which you follow a set of rules to play the game.

	You must give ample description for each function you create
*/

// Start of preprocessor directives section

#include <iostream> // for input and output default stream use
#include <string> // for string data type use
#include <iomanip> // output manipulation
#include <fstream> // for reading and writing files to a file stored on the secondary storage device
#include <ctime> // to truly be random
#include <cstdlib> // for random use
#include <cmath> // maybe? in case we use it later otherwise deletion
#include <cctype> // useful for changing a character tolower but remember it changes to an int

using namespace std; // so we dont have to constantly use std:: prefix

// End of preprocessor directives section

// Start of structure defintion section

// Emily: This structure stores each player's information during the board game.
struct player
{
	string userName;
	char gamePiece;
	int currentSpace;
};

// End of structure definition section

// // Start of function prototype section

// // Every One Participated in the creation of the following functions
int randomResult(int, int);
// void readWins(int&, int&, int&);
// void writeWins(int&, int&, int&);

// //void mainLoop(int&, int&, int&); maybe like this

// // Rami's function prototypes

// int difficultyChoiceAndSpacingAndGuess(bool& quitVariable, string& actualWordChosen, const string stringArrayWord[][9], string& amountOfSpacesBasedUponDifficulty, const int guessArrayes[], int& max_guesses);
// //string choosingTheWord(const string stringArrayWord[][3], const int& intDifficulty, string& returnToThis);
// //int maxGuesses(const int guessArray[], const int& intDifficulty);
// int choosingALetter(char& charInputOfLetter, bool& quitter);
// void mainHangManFunc(int& gameOneIncrement, const string stringArrayWords[][9], const int guessArray[], char alphabet[], const int& m);

// Emily's function prototypes

void BoardGame();
void WelcomeAndRules();
void DeclarePlayers(int numberOfPlayers, bool isPlayingCPU, player arrayOfPlayers[]);
int RollDie();
bool TakeTurn(int playerNumber, player arrayOfPlayers[]);

// // Hunter's Function Prototypes

// // End of function prototype section

// // Start of main function section

int main()
{
// 	// Rami: const arrays required for HangMan Game
// 	const int ALPHABET_LIMIT = 26;
// 	const int GUESS_LIMIT[] = { 5, 7, 10 };
// 	const string WORDS[3][9] = { {"actor", "ahead", "alive", "gazal", "namer", "slump", "folio", "jello", "libel"},
// 		{"quizzed", "zizzled", "wazzock", "buzzing", "palazzo", "dazzeled", "deliver", "dispute", "foreign"},
// 		{"maximizing", "jackhammer", "squeezable", "habitation", "iceboaters", "maccaronis", "obidences", "quadcopter", "sabertooth"} };

// 	char english_alphabet[ALPHABET_LIMIT]{};
// 	// Rami: End of const arrays for hangManGame

// 	// For true random can't be placed inside of functions
// 	srand(time(0)); // this allows us to use a seed so the random can actually be random each time of running the function. time(0) indicates the number of seconds start from january 1, 1970.

// 	// Variables to iterate wins
// 	int hangmanWins = 0;
// 	int pictionaryWins = 0;
// 	int boardGameWins = 0;

// 	// Boolean to quit game.
// 	bool quitProgram = false;

// 	readWins(hangmanWins, pictionaryWins, boardGameWins);
// 	mainHangManFunc(hangmanWins, WORDS, GUESS_LIMIT, english_alphabet, ALPHABET_LIMIT);
// 	writeWins(hangmanWins, pictionaryWins, boardGameWins);

	BoardGame();
}

// // End of main function section

// // Start of function definitions section

// // Everyone participated in the creation of the following functions

// // This function's primary purpose is to randomly generate a number. The developer chooses the range of numbers.

int randomResult(int randomMaxSize, int randomStart = 0)
{
	if (randomStart > 0)
	{
		return rand() % randomMaxSize + randomStart;
	}
	else
	{
		return rand() % randomMaxSize;
	}
}

// // The purpose of this function is to read the total wins. This was talked about and developed together at the Zoom meeting, since we all contributed to this information together.
// void readWins(int& firstGame, int& secondGame, int& thirdGame)
// {
// 	ifstream winningOutput; // Creates an input file stream variable to which we will write the wins.
// 	winningOutput.open("totalWins.txt"); // Opens the file
// 	if (winningOutput) // (filestreamvariable) checks if file exists (!filestreamvariable) checks if file stream variable file does not exist
// 	{
// 		string tempHolder; // Holds the total wins from each game and is deleted once it exits the scope
// 		int wins = 0; // Holds the read file wins
// 		int winsArray[3]{}; // Holds the wins from all three game to then be input later in the reference variables in array format
// 		int arrayControlVariable = 0; // Control the array element so it does not go out of scope

// 		// This section ensures that the file does not reach the end of the array and go out of scope
// 		while (!winningOutput.eof() && winningOutput >> tempHolder >> tempHolder >> wins && arrayControlVariable != 3)
// 		{
// 			if (wins <= 0)
// 			{
// 				wins = 0;
// 				winsArray[arrayControlVariable] = wins;

// 			}
// 			else
// 			{
// 				winsArray[arrayControlVariable] = wins;
// 			}

// 			arrayControlVariable++;
// 		}

// 		firstGame = winsArray[0];
// 		secondGame = winsArray[1];
// 		thirdGame = winsArray[2];

// 		//cout << firstGame << " " << secondGame << " " << thirdGame;
// 	}
// 	else
// 	{
// 		cout << "Save file does not exist and/or manipulated in some way. Resetting all Wins to 0";
// 		firstGame = 0;
// 		secondGame = 0;
// 		thirdGame = 0;
// 		// cout << firstGame << secondGame << thirdGame; used to check if wins are set to 0
// 	}

// 	winningOutput.close(); // to close the file after opening it of course.
// }


// // this was talked about and further elaborated on in the zoom meeting
// // purpose of this file is to write the wins of each game and the total number Wins to a text file and output it in a way thats legible to the end user. by using arrays we are are able to quickly access them 
// // through a loop and outputting the results which is then used in the setw portion of the work. we can we the for loop to iterate throughout each loop. we create an empty loop to then output the results.
// // we use .length method to get the amount of characters in the string (this was shown in one of the examples)
// // arrays allow us to be more flexible and a good way to use loop to contain a collection of data. (i love arrays)
// void writeWins(int& firstGame, int& secondGame, int& thirdGame)
// {

// 	string gameWriteArray[] = { "HangMan Wins:", "Pictionary Wins:", "BoardGame Wins:", "Total Wins:" };
// 	int holdLoopResults[4]{};

// 	for (int goingThroughArrayLoop = 0; goingThroughArrayLoop != 4; goingThroughArrayLoop++)
// 	{
// 		holdLoopResults[goingThroughArrayLoop] = 30 - gameWriteArray[goingThroughArrayLoop].length();
// 		if (holdLoopResults[goingThroughArrayLoop] <= 0)
// 		{
// 			holdLoopResults[goingThroughArrayLoop] = 1;
// 		}

// 	}

// 	ofstream writeToWinFile;
// 	writeToWinFile.open("totalWins.txt");

// 	if (writeToWinFile) // we use an if (writeToWinFile) to make sure it already exists else do not write to file
// 	{
// 		int totalWinsInt = firstGame + secondGame + thirdGame;
// 		writeToWinFile << gameWriteArray[0] << setw(holdLoopResults[0]) << firstGame << endl;
// 		writeToWinFile << gameWriteArray[1] << setw(holdLoopResults[1]) << secondGame << endl;
// 		writeToWinFile << gameWriteArray[2] << setw(holdLoopResults[2]) << thirdGame << endl;
// 		writeToWinFile << gameWriteArray[3] << setw(holdLoopResults[3]) << totalWinsInt << endl;
// 	}

// 	writeToWinFile.close();
// }

// // Start of Rami's function definitions

// /* This function has three different purposes:
// *
// Its first purpose is to ask the user for the difficulty and the difficulty choice will be used to manipulate the array to make a selection of words to be used, if no difficulty is chosen it is chosen by random.

// After this is done, the function(s) second purpose is activated if the user did not quit. if will an if else if and else to determine the amount of spaces that will be use to check if the user guess the correct word and to give the maximum amount of guesses available

// Its third use will return the difficulty used to output the results later on if you won or not and word chosen by using random to facilitate the randomization of the word chosen for that difficulty (up to nine) */
// int difficultyChoiceAndSpacingAndGuess(bool& quitVariable, string& actualWordChosen, const string stringArrayWord[][9], string& amountOfSpacesBasedUponDifficulty, const int guessArray[], int& max_guesses)
// {

// 	char difficultyChoiceChar = 0;
// 	int difficultyInInt = 0;
// 	cout << "Please choose between Three Difficulty Levels: Easy(e), Medium(m), or Hard(h) or Quit(q)." << endl;
// 	cout << "Please Enter Your Choice:";
// 	cin >> difficultyChoiceChar;

// 	switch (difficultyChoiceChar)
// 	{
// 	case 'e':
// 	case 'E':
// 		cout << "You have chosen Easy difficulty! Good Luck!" << endl;
// 		difficultyInInt = 0;
// 		break;
// 	case 'm':
// 	case 'M':
// 		cout << "You have chosen Normal difficulty! Good Luck, Academic!" << endl;
// 		difficultyInInt = 1;
// 		break;
// 	case 'h':
// 	case 'H':
// 		cout << "You have chosen Hard difficulty! Oh No!" << endl;
// 		difficultyInInt = 2;
// 		break;
// 	case 'q':
// 	case 'Q':
// 		quitVariable = true;
// 		break;
// 	default:
// 		cout << "You have pressed the wrong button and now as a bonus suprise, a difficulty will be randomly selected! Congradulations!" << endl;
// 		difficultyInInt = randomResult(3);
// 		break;
// 	}

// 	// if default is activated in the switch structure
// 	if (quitVariable == false)
// 	{
// 		if (difficultyInInt == 0)
// 		{
// 			amountOfSpacesBasedUponDifficulty = "     ";
// 			max_guesses = guessArray[difficultyInInt];

// 		}
// 		else if (difficultyInInt == 1)
// 		{
// 			amountOfSpacesBasedUponDifficulty = "       ";
// 			max_guesses = guessArray[difficultyInInt];

// 		}
// 		else
// 		{
// 			amountOfSpacesBasedUponDifficulty = "          ";
// 			max_guesses = guessArray[difficultyInInt];
// 		}

// 		actualWordChosen = stringArrayWord[difficultyInInt][randomResult(9)];
// 		return difficultyInInt;
// 	}
// }

// /* The primary purpose of this function is a quick way to get the index of the alphabet array and return as an int,
// it always has a check system to make sure*/
// int choosingALetter(char& charInputOfLetter, bool& quitter)
// {

// 	int choice = 0;
// 	switch (charInputOfLetter)
// 	{
// 	case 'A':
// 	case 'a':
// 		return 0;
// 	case 'B':
// 	case 'b':
// 		return 1;
// 	case 'C':
// 	case 'c':
// 		return 2;
// 	case 'D':
// 	case 'd':
// 		return 3;
// 	case 'E':
// 	case 'e':
// 		return 4;
// 	case 'F':
// 	case 'f':
// 		return 5;
// 	case 'G':
// 	case 'g':
// 		return 6;
// 	case 'H':
// 	case 'h':
// 		return 7;
// 	case 'I':
// 	case 'i':
// 		return 8;
// 	case 'J':
// 	case 'j':
// 		return 9;
// 	case 'K':
// 	case 'k':
// 		return 10;
// 	case 'L':
// 	case 'l':
// 		return 11;
// 	case 'M':
// 	case 'm':
// 		return 12;
// 	case 'N':
// 	case 'n':
// 		return 13;
// 	case 'O':
// 	case 'o':
// 		return 14;
// 	case 'P':
// 	case 'p':
// 		return 15;
// 	case 'Q':
// 	case 'q':
// 		cout << "Did you mean to quit(1) or do you mean the letter q(2):";
// 		cin >> choice;
// 		if (choice == 1)
// 		{
// 			quitter = true;
// 			break;
// 		}
// 		return 16;
// 	case 'R':
// 	case 'r':
// 		return 17;
// 	case 'S':
// 	case 's':
// 		return 18;
// 	case 'T':
// 	case 't':
// 		return 19;
// 	case 'U':
// 	case 'u':
// 		return 20;
// 	case 'V':
// 	case 'v':
// 		return 21;
// 	case 'W':
// 	case 'w':
// 		return 22;
// 	case 'X':
// 	case 'x':
// 		return 23;
// 	case 'Y':
// 	case 'y':
// 		return 24;
// 	case 'Z':
// 	case 'z':
// 		return 25;
// 	default:
// 		cout << "Choosing a letter by random" << endl;
// 		int letterChosen = randomResult(25);
// 		return letterChosen;
// 	}
// }

// /*This main function is in which every other function will be passed into and only this will will be called into main, thats what i thought at least, as far as I know so far I can not create arrays inside of functions
// the same reason we can use srand inside of function because of the scope. The hangman game will not work without multiple nested loops. This main function will also manipulate the empty array and add the alphabet to the array to the limit of alphalimit - 1 (<).*/
// void mainHangManFunc(int& gameOneIncrement, const string stringArrayWords[][9], const int guessArray[], char alphabet[], const int& alphaLimit)
// {
// 	bool wordGuessed = false;
// 	bool quitGame = false;
// 	int maxGuessInPlay;
// 	string wordAutoResult;
// 	string manualResult;

// 	cout << setw(10) << setfill('-') << "" << "Welcome to the Hangman Game" << setw(10) << setfill('-') << "" << endl;
// 	cout << endl;
// 	cout << "The rules are: keep guessing the word per letter until you run out of guesses or you quit!" << endl;

// 	// manipulates the char array to add the alphabet to it using the ascii table chart

// 	char alphabetAsciiStartsAt = 97; // ascii code for letters using char
// 	if (alphabet[0] != 'a')
// 	{

// 		for (int aThroughZ = 0; aThroughZ < alphaLimit; aThroughZ++)
// 		{
// 			alphabet[aThroughZ] = alphabetAsciiStartsAt++;
// 		}
// 	}

// 	do {


// 		difficultyChoiceAndSpacingAndGuess(quitGame, wordAutoResult, stringArrayWords, manualResult, guessArray, maxGuessInPlay);

// 		if (quitGame == true)
// 		{
// 			break;
// 		}

// 		int wordLength = wordAutoResult.length();


// 		for (int guesses = 0; guesses < maxGuessInPlay - 1 && manualResult != wordAutoResult && wordGuessed != true; guesses++)
// 		{
// 			char letterChoice = 0;
// 			if (manualResult != wordAutoResult && wordGuessed != true)
// 			{
// 				cout << "Please Choose a letter from the Alphabet:";
// 				cin >> letterChoice;
// 			}

// 			int trueChoice = choosingALetter(letterChoice, quitGame);

// 			if (quitGame == true)
// 			{
// 				break;
// 			}

// 			for (int letterLocation = 0; letterLocation <= wordLength; letterLocation++)
// 			{

// 				int indexHolder = -1;
// 				if (alphabet[trueChoice] == static_cast<char>(tolower(wordAutoResult[letterLocation])))
// 				{

// 					indexHolder = letterLocation;
// 					if (indexHolder >= 0 && indexHolder <= 10)
// 					{
// 						manualResult[indexHolder] = static_cast<char>(tolower(wordAutoResult[indexHolder]));
// 					}

// 				}
// 			}
// 			cout << "Current Progress on Your word is" << setw(15) << setfill('-') << "";
// 			for (int currentResultsOfGuessing = 0; currentResultsOfGuessing < wordLength; currentResultsOfGuessing++)
// 			{

// 				cout << manualResult[currentResultsOfGuessing];

// 			}

// 			cout << endl;
// 			if (manualResult == wordAutoResult)
// 			{
// 				break;
// 			}

// 		}


// 		// to check if the player has guessed correctly
// 		if (manualResult == wordAutoResult)
// 		{
// 			if (manualResult.length() == 5)
// 			{
// 				cout << endl;
// 				cout << "Congrats! PLUS ONE TO HANGMAN WINS" << endl;
// 				gameOneIncrement++;
// 				cout << endl;
// 				wordGuessed = true;
// 				cout << setw(47) << setfill('-') << "" << endl;
// 				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
// 			}
// 			else if (manualResult.length() == 7)
// 			{
// 				cout << endl;
// 				cout << "Congrats! PLUS TWO TO HANGMAN WINS" << endl;
// 				gameOneIncrement += 2;
// 				cout << endl;
// 				wordGuessed = true;
// 				cout << setw(47) << setfill('-') << "" << endl;
// 				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
// 			}
// 			else
// 			{
// 				cout << endl;
// 				cout << "Congrats! PLUS THREE TO HANGMAN WINS" << endl;
// 				gameOneIncrement += 3;
// 				cout << endl;
// 				wordGuessed = true;
// 				cout << setw(47) << setfill('-') << "" << endl;
// 				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
// 			}
// 		}
// 		else
// 		{
// 			cout << endl;
// 			cout << "You have lost the game, Going back to the top" << endl;
// 			cout << "The word was:" << wordAutoResult << endl;
// 			cout << endl;
// 			cout << setw(47) << setfill('-') << "" << endl;
// 			cin.ignore(); // to ignore that extra cin at the end that appears weirdly
// 		}

// 	} while (quitGame == false && wordGuessed != true);





// }

// // Hunter's Function Definitions

// Start of Emily's section: The board game

// Emily: This is the main board game function. Call this function to run the board game.
void BoardGame()
{
	ofstream outfile;
	outfile.open("BoardGameRecord.txt");
	// Call the function that will display a welcome message and tell the user the rules of the game.
	WelcomeAndRules();
	// Declare a variable to hold the number of players.
	int numberOfPlayers = 0;
	// Use a do...while loop to ask for the number of players until valid input is given.
	do
	{
		// Ask for the number of players.
		cout << "Enter the number of players, 1 to 4. If you choose 1, you will play against a CPU. " << endl;
		// Read the number of players.
		cin >> numberOfPlayers;
	} while (numberOfPlayers < 1 || numberOfPlayers > 4);
	// If they choose only 1 player, change it to 2 players. The second player will be the CPU.
	bool isPlayingCPU = false;
	if (numberOfPlayers == 1)
	{
		isPlayingCPU = true;
		numberOfPlayers++;
	}
	// Create an array of structures to hold each player's information.
	player arrayOfPlayers[numberOfPlayers];
	// Call the function that will set up each player's information.
	DeclarePlayers(numberOfPlayers, isPlayingCPU, arrayOfPlayers);
	// Call the function to have each player take their turn.
	bool win;
	do
	{
		for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++)
		{
			win = TakeTurn(playerNumber, arrayOfPlayers);
		}
	} while (!win);
	
	
}

// Emily: This function will display a welcome message and tell the user the rules of the game.
void WelcomeAndRules()

{
	// Print a blank line between the prior output and the welcome message.
	cout << endl;

	// Print the welcome message and rules.
	cout << "Welcome to Board Game Bonanza! This is a board game for 1 to 4 players. "
		<< "Players roll a die and advance that number of spaces. The first player "
		<< "to land on or pass the hundredth space wins. Watch out for those trick "
		<< "spaces! Trapdoors set you back, whereas secret passages give you a leg "
		<< "up on the competition. Let's play!" << endl << endl;
}

// Emily: This function will set up each player's inforamtion.
void DeclarePlayers(int numberOfPlayers, bool isPlayingCPU, player arrayOfPlayers[])

{
	if (numberOfPlayers > 1 && isPlayingCPU == false)
	{
		for (int playerNumber = 0; playerNumber < numberOfPlayers; playerNumber++)
		{
			// Ask each player for their name.
			cout << "Player " << playerNumber + 1 << "'s name: ";
			cin >> arrayOfPlayers[playerNumber].userName;
			// Ask each player to choose a game piece, like how you can be the thimble in Monopoly.
			cout << "Choose a game piece (type a keyboard character): ";
			cin >> arrayOfPlayers[playerNumber].gamePiece;
			// Start each player at the beginning of the board.
			arrayOfPlayers[playerNumber].currentSpace = 0;
		}
	}
	else
	{
			// Ask the solo player for their name.
			cout << "Player 1's name: ";
			cin >> arrayOfPlayers[0].userName;
			// Ask the solo player to choose a game piece, like how you can be the thimble in Monopoly.
			cout << "Choose a game piece (type a keyboard character): ";
			cin >> arrayOfPlayers[0].gamePiece;
			// Start the solo player at the beginning of the board.
			arrayOfPlayers[0].currentSpace = 0;
			// Create the CPU player.
			arrayOfPlayers[1].userName = "Mr. CPU";
			arrayOfPlayers[1].gamePiece = '?';
			arrayOfPlayers[1].currentSpace = 0;
	}
}

// Emily: This function will "roll a die" by generating a random number from 1 to 6.
int RollDie()
{
	// Randomly generate a number from 0 to 5, then add 1 to make it 1 through 6, like the faces of a die.
	int dieRoll = randomResult(5) + 1;
	return dieRoll;
}

// Emily: This function will simulate a user taking their turn. It will return a boolean value of true if someone wins.
bool TakeTurn(int playerNumber, player arrayOfPlayers[])
{
	// Say whose turn it is and have them roll the die.
	char roll = ' ';
	do
	{
		cout << arrayOfPlayers[playerNumber].userName << "'s turn! Type 'R' to roll the die..." << endl;
		cin >> roll;
	} while (roll != 'R' && roll != 'r');

	int rollResult = RollDie();
	// Show what the player rolled.
	cout << arrayOfPlayers[playerNumber].userName << " rolled a " << rollResult << endl;
	// Move the player's piece that number of spaces.
	cout << "Advancing " << rollResult << " spaces..." << endl;
	arrayOfPlayers[playerNumber].currentSpace += rollResult;
	// If the player lands on or passes the hundredth space, tell them they won, and break out of this function.
	if (arrayOfPlayers[playerNumber].currentSpace >= 100)
	{
		cout << arrayOfPlayers[playerNumber].userName << " wins!" << endl;
		return true;
	}
	// Handle trick spaces.
	switch (arrayOfPlayers[playerNumber].currentSpace)
	{
		case 7:
		case 14:
		case 27:
		case 31:
		case 45:
		case 53:
		case 68:
		case 79:
		case 82:
		case 96:
			arrayOfPlayers[playerNumber].currentSpace -= 3;
			cout << "You landed on a trapdoor! Go back 3 spaces. You are now on space " << arrayOfPlayers[playerNumber].currentSpace << endl;
			break;
		case 2:
		case 19:
		case 25:
		case 33:
		case 42:
		case 56:
		case 64:
		case 78:
		case 87:
		case 91:
			arrayOfPlayers[playerNumber].currentSpace += 4;
			cout << "You landed on a secret passage! Go forward 4 more spaces. You are now on space " << arrayOfPlayers[playerNumber].currentSpace << endl;
			break;
	}
	// Return false if the player made it through this turn without winning.s
	return false;
}

// End of Emily's section: The board game