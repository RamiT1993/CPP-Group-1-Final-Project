/*
	Program Name: Carnival
	Program Group Leader: Rami Toma
	Program Group Members: Emily Burley and Hunter Donovan
	Rami's Portion of Work Final Revision Date: December 3rd, 2022
	Emily's Portion of Work Final Revision Date: December 16th, 2022
	Hunter's Portion of Work Final Revision Date: December 6th, 2022
	Final Program Revision Date: December 16th, 2022

	Small Summary Of Program:
		You choose a game to play or at random if not chosen a game to play it will be selected randomly and you play a small mini-game in which you follow a set of rules to play the game.

	You must give ample description for each function you create

*/


/*
	PreProcessor Directives Section Start
*/
#include <iostream> // for input and output default stream use
#include <fstream> // for reading and writing files to a file stored on the secondary storage device
#include <iomanip> // output manipulation
#include <string> // for string data type use
#include <cctype> // useful for changing a character tolower but remember it changes to an int
#include <cstdlib> // for random use
#include <ctime> // to truly be random



/*
	PreProcessor Directives Section End
*/

/*
	Function Prototype section put the function you created inside of your section
*/

// Every One Participated in the creation of these functions
int randomResult(int, int);
void readWins(int&, int&, int&);
void writeWins(int&, int&, int&);


using namespace std; // so we dont have to constantly use std:: prefix
// Rami's Function Prototypes.----------------------------------------------------------------- 
void difficultyChoiceAndSpacingAndGuess(bool&, string& actualWordChosen, const string stringArrayWord[][9], string& amountOfSpacesBasedUponDifficulty, const int guessArrayes[], int&);
void choosingALetter(char&, bool&, int&);
void mainHangManFunc(int&, const string stringArrayWords[][9], const int guessArray[], char alphabet[], const int&);


// Emily's Function Prototypes + Structure-----------------------------------------------------------------

/* This structure stores each players's information during the board game. */
struct player
{
	string userName;
	char gamePiece;
	int currentSpace;
};

void BoardGame(int&);
void WelcomeAndRules();
void DeclarePlayers(player arrayOfPlayers[]);;
bool TakeTurn(ofstream& outfile, int playerNumber, int& boardGameWins, player arrayOfPlayers[]);




// Hunter's Function Prototypes-----------------------------------------------------------------
void Pictionary(int&);

/*
	Function ProtoType Section End
*/




/*
	Main Function Start
*/
int main()
{

	// const arrays required for HangMan Game
	const int ALPHABET_LIMIT = 26;
	const int GUESS_LIMIT[] = { 7, 8, 9 };
	const string WORDS[3][9] = { {"actor", "ahead", "alive", "gazal", "namer", "slump", "folio", "jello", "libel"},
		{"quizzed", "zizzled", "wazzock", "buzzing", "palazzo", "dazzels", "deliver", "dispute", "foreign"},
		{"maximizing", "jackhammer", "squeezable", "habitation", "iceboaters", "maccaronis", "suggestion", "quadcopter", "sabertooth"} };


	char english_alphabet[ALPHABET_LIMIT];
	// const array for hangManGame End

	// for true random can't be placed inside of functions
	srand(time(0)); // this allows us to use a seed so the random can actually be random each time of running the function. time(0) indicates the number of seconds start from january 1, 1970.


	// variables to iterate wins
	int hangmanWins = 0;
	int pictionaryWins = 0;
	int banazaWins = 0;



	//readWins(hangmanWins, pictionaryWins, boardGameWins);



	// bool to quit game.
	bool quitMainProgram = false;


	cout << setw(57) << setfill('-') << "" << endl;
	cout << "Welcome to the Carnival Game." << endl;
	cout << "This game covers up to three mini-games." << endl;
	cout << "These MiniGames are Hangman, Pictionary, and A Board Game" << endl;
	cout << "Their is a save system of sorts to keep your \nscores from the previous time you played." << endl;
	cout << "When You Quit From the main choice screen,\nIt shows the scoreboard \nand saves your file so you can use it next time" << endl;
	cout << setw(57) << setfill('-') << "" << endl;

	readWins(hangmanWins, pictionaryWins, banazaWins);



	char charHolder = 'g';
	do
	{
		// game option are between 0-4

		cout << setw(52) << setfill('-') << "" << endl;
		cout << "Game Option 1: Hangman" << endl;
		cout << "Game Option 2: Pictionary" << endl;
		cout << "Game Option 3: BoardGame" << endl;
		cout << "Game Option 0: Scoreboard/Update Save File/Quit Game" << endl;

		cout << "Which game option have you decided upon:";
		cin >> charHolder;

		cout << endl;


		switch (charHolder)
		{
		case '3':
			BoardGame(banazaWins);
			break;
		case '2':
			Pictionary(pictionaryWins); // calling the pictionary function
			break;
		case '1':
			mainHangManFunc(hangmanWins, WORDS, GUESS_LIMIT, english_alphabet, ALPHABET_LIMIT); // calling the main hangman Function
			break;
		case '0':
			writeWins(hangmanWins, pictionaryWins, banazaWins); // writing to file and writing the scoreboard
			quitMainProgram = true; // to quit out of the program
			break;
		default:
			break;

		}





		cout << setw(52) << setfill('-') << "" << endl;


	} while (quitMainProgram != true);

	system("pause"); // so you can see the score board





}
/*
	Main Function End
*/


/*
	Function Definition(s) Start
*/

//-- Every One Participated in the creation of these functions--


//This Function primary purpose is to as a random generator where the developer chooses up to what random number and what number the random number starts at		
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


// purpose of this function is to read up to the total wins, this was talked about and developed together at the zoom meeting, since we all inputted on this information together we decided that board game wins should instead be games played
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




		//cout << firstGame << " " << secondGame;


	}
	else
	{
		cout << "Save file does not exist and/or manipulated in some way. Resetting all played amount to 0" << endl;
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
// arrays allow us to be more flexible and a good way to use loop to contain a collection of data.
// also in this section a score board is created
void writeWins(int& firstGame, int& secondGame, int& thirdGame)
{

	string gameWriteArray[] = { "HangMan Wins:", "Pictionary Wins:", "Banaza Wins:", "Total Wins:" };
	int holdLoopResults[4]{};

	for (int goingThroughArrayLoop = 0; goingThroughArrayLoop != 4; goingThroughArrayLoop++)
	{
		holdLoopResults[goingThroughArrayLoop] = 30 - gameWriteArray[goingThroughArrayLoop].length();
		if (holdLoopResults[goingThroughArrayLoop] <= 0)
		{
			holdLoopResults[goingThroughArrayLoop] = 1;
		}

	}

	ofstream writeToWinFile;
	writeToWinFile.open("totalWins.txt");

	if (writeToWinFile) // we use an if (writeToWinFile) to make sure it already exists else do not write to file
	{
		cout << endl;
		cout << setw(10) << setfill('-') << "" << "Score Sheet" << setw(9) << setfill('-') << "" << endl;
		int totalWinsInt = firstGame + secondGame + thirdGame;

		cout << gameWriteArray[0] << setw(holdLoopResults[0]) << firstGame << endl;
		writeToWinFile << gameWriteArray[0] << setw(holdLoopResults[0]) << firstGame << endl;

		cout << gameWriteArray[1] << setw(holdLoopResults[1]) << secondGame << endl;
		writeToWinFile << gameWriteArray[1] << setw(holdLoopResults[1]) << secondGame << endl;

		cout << gameWriteArray[2] << setw(holdLoopResults[2]) << thirdGame << endl;
		writeToWinFile << gameWriteArray[2] << setw(holdLoopResults[2]) << thirdGame << endl;

		cout << gameWriteArray[3] << setw(holdLoopResults[3]) << totalWinsInt << endl;
		writeToWinFile << gameWriteArray[3] << setw(holdLoopResults[3]) << totalWinsInt << endl;
		cout << setw(10) << setfill('-') << "" << "Score Sheet" << setw(9) << setfill('-') << "" << endl;
	}



	writeToWinFile.close();
}






//--Rami's Function Definitions-----------------------------------------------------------------

/* This function has three different purposes:
*
Its first purpose is to ask the user for the difficulty and the difficulty choice will be used to manipulate the array to make a selection of words to be used, if no difficulty is chosen it is chosen by random.

After this is done, the function(s) second purpose is activated if the user did not quit. if will an if else if and else to determine the amount of spaces that will be use to check if the user guess the correct word and to give the maximum amount of guesses available

It’s third use will be used return the difficulty used to output the results later on if you won or not and word chosen by using random to facilitate the randomization of the word chosen for that difficulty (up to nine) */
void difficultyChoiceAndSpacingAndGuess(bool& quitVariable, string& actualWordChosen, const string stringArrayWord[][9], string& amountOfSpacesBasedUponDifficulty, const int guessArray[], int& max_guesses)
{

	char difficultyChoiceChar = 0;
	int difficultyInInt = 0;
	cout << "Please choose between Three Difficulty Levels: Easy(e), Medium(m), or Hard(h) or Quit(q)." << endl;
	cout << "Please Enter Your Choice:";
	cin >> difficultyChoiceChar;

	switch (difficultyChoiceChar)
	{
	case 'e':
	case 'E':
		cout << "You have chosen Easy difficulty! Good Luck!" << endl;
		difficultyInInt = 0;
		break;
	case 'm':
	case 'M':
		cout << "You have chosen Normal difficulty! Good Luck, Academic!" << endl;
		difficultyInInt = 1;
		break;
	case 'h':
	case 'H':
		cout << "You have chosen Hard difficulty! Oh No!" << endl;
		difficultyInInt = 2;
		break;
	case 'q':
	case 'Q':
		quitVariable = true;
		break;
	default:
		cout << "You have pressed the wrong button and now as a bonus suprise, a difficulty will be randomly selected! Congradulations!" << endl;
		difficultyInInt = randomResult(3);
		break;
	}

	// if default is activated in the switch structure
	if (quitVariable == false)
	{

		if (difficultyInInt == 0)
		{
			amountOfSpacesBasedUponDifficulty = "     ";
			max_guesses = guessArray[difficultyInInt];

		}
		else if (difficultyInInt == 1)
		{
			amountOfSpacesBasedUponDifficulty = "       ";
			max_guesses = guessArray[difficultyInInt];

		}
		else
		{
			amountOfSpacesBasedUponDifficulty = "          ";
			max_guesses = guessArray[difficultyInInt];
		}

		actualWordChosen = stringArrayWord[difficultyInInt][randomResult(9)];
	}





}

/* The primary purpose of this function is a quick way to get the index of the alphabet array and return to the reference variable resultOfChoice,
it always has a check system to make sure if the use chose to quit to chose the letter*/
void choosingALetter(char& charInputOfLetter, bool& quitter, int& resultOfChoice)
{

	int choice = 0;
	switch (charInputOfLetter)
	{
	case 'A':
	case 'a':
		resultOfChoice = 0;
		break;
	case 'B':
	case 'b':
		resultOfChoice = 1;
		break;
	case 'C':
	case 'c':
		resultOfChoice = 2;
		break;
	case 'D':
	case 'd':
		resultOfChoice = 3;
		break;
	case 'E':
	case 'e':
		resultOfChoice = 4;
		break;
	case 'F':
	case 'f':
		resultOfChoice = 5;
		break;
	case 'G':
	case 'g':
		resultOfChoice = 6;
		break;
	case 'H':
	case 'h':
		resultOfChoice = 7;
		break;
	case 'I':
	case 'i':
		resultOfChoice = 8;
		break;
	case 'J':
	case 'j':
		resultOfChoice = 9;
		break;
	case 'K':
	case 'k':
		resultOfChoice = 10;
		break;
	case 'L':
	case 'l':
		resultOfChoice = 11;
		break;
	case 'M':
	case 'm':
		resultOfChoice = 12;
		break;
	case 'N':
	case 'n':
		resultOfChoice = 13;
		break;
	case 'O':
	case 'o':
		resultOfChoice = 14;
		break;
	case 'P':
	case 'p':
		resultOfChoice = 15;
		break;
	case 'Q':
	case 'q':
		cout << "Did you mean to quit(1) or do you mean the letter q(2):";
		cin >> choice;
		if (choice == 1)
		{
			quitter = true;
			break;
		}
		resultOfChoice = 16;
		break;
	case 'R':
	case 'r':
		resultOfChoice = 17;
		break;
	case 'S':
	case 's':
		resultOfChoice = 18;
		break;
	case 'T':
	case 't':
		resultOfChoice = 19;
		break;
	case 'U':
	case 'u':
		resultOfChoice = 20;
		break;
	case 'V':
	case 'v':
		resultOfChoice = 21;
		break;
	case 'W':
	case 'w':
		resultOfChoice = 22;
		break;
	case 'X':
	case 'x':
		resultOfChoice = 23;
		break;
	case 'Y':
	case 'y':
		resultOfChoice = 24;
		break;
	case 'Z':
	case 'z':
		resultOfChoice = 25;
		break;
	default:
		cout << "Choosing a letter by random" << endl;
		int letterChosen = randomResult(25);
		cin.clear();
		resultOfChoice = letterChosen;
		break;
	}

}

/*This main function is in which every other function will be passed into and only this will will be called into mai.
 create some variables that will later be manipulates. welcome the user to the game.
 then populate the alphabet array using the for loop. It is used this way instead of creating a const array to save time and manually inputting it.
 use a do while to make sure it runs at least once.
 call the difficulty function with the parameters required to get the difficulty choice, spacing, and lastly guess amount.
 also make sure the user does not want to quit this specific mini-game.
 get the length of word that is chosen then we use a nested loop, to go through until word chosen or user runs out of guess.
 going the nested loop we match the actual word letter with the alphabet letter because its char then we match it with the player selected char variable choice
 use tolower(this changes it to a int number) we use static_cast<char> to change it to a char to make.
 if the player goes back to the top whether win or lose, in case of win increments +1 if won on easy, +2 on normal, +3 on hard

*/
void mainHangManFunc(int& gameOneIncrement, const string stringArrayWords[][9], const int guessArray[], char alphabet[], const int& alphaLimit)
{

	bool wordGuessed = false;
	bool quitGame = false;
	int maxGuessInPlay;
	string wordAutoResult;
	string manualResult;

	cout << "Welcome to the Hangman Game" << endl;
	cout << endl;
	cout << "The rules are: keep guessing the word per letter until you run out of guesses or you quit!" << endl;

	// manipulates the char array to add the alphabet to it using the ascii table chart

	char alphabetAsciiStartsAt = 97; // ascii code for letters using char
	if (alphabet[0] != 'a') // making sure it doesn't loop through twice for no reason to
	{

		for (int aThroughZ = 0; aThroughZ < alphaLimit; aThroughZ++)
		{
			alphabet[aThroughZ] = alphabetAsciiStartsAt++;
		}
	}

	do {


		difficultyChoiceAndSpacingAndGuess(quitGame, wordAutoResult, stringArrayWords, manualResult, guessArray, maxGuessInPlay);

		if (quitGame == true)
		{
			break;
		}

		int wordLength = wordAutoResult.length();


		for (int guesses = 0; guesses < maxGuessInPlay && manualResult != wordAutoResult && wordGuessed != true; guesses++)
		{
			char letterChoice = 0;
			if (manualResult != wordAutoResult && wordGuessed != true)
			{
				cout << "Please Choose a letter from the Alphabet:";
				cin >> letterChoice;
			}
			int trueChoice = 0;

			choosingALetter(letterChoice, quitGame, trueChoice);

			if (quitGame == true)
			{
				break;
			}




			for (int letterLocation = 0; letterLocation <= wordLength; letterLocation++)
			{

				int indexHolder = -1;
				if (alphabet[trueChoice] == static_cast<char>(tolower(wordAutoResult[letterLocation])))
				{

					indexHolder = letterLocation;
					if (indexHolder >= 0 && indexHolder <= 10)
					{
						manualResult[indexHolder] = static_cast<char>(tolower(wordAutoResult[indexHolder]));
					}

				}
			}
			cout << "Current Progress on Your word is" << setw(15) << setfill('-') << "";
			for (int currentResultsOfGuessing = 0; currentResultsOfGuessing < wordLength; currentResultsOfGuessing++)
			{

				cout << manualResult[currentResultsOfGuessing];

			}

			cout << endl;
			if (manualResult == wordAutoResult)
			{
				cout << "correct";
				break;
			}

		}


		// to check if the player has guessed correctly
		if (manualResult == wordAutoResult)
		{
			if (manualResult.length() == 5)
			{
				gameOneIncrement++;
				cout << endl;
				cout << "Congrats! PLUS ONE TO HANGMAN WINS" << endl;
				cout << endl;
				wordGuessed = true;

				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
			}
			else if (manualResult.length() == 7)
			{
				gameOneIncrement += 2;

				cout << endl;
				cout << "Congrats! PLUS TWO TO HANGMAN WINS" << endl;
				cout << endl;
				wordGuessed = true;

				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
			}
			else
			{
				gameOneIncrement += 3;

				cout << endl;
				cout << "Congrats! PLUS THREE TO HANGMAN WINS" << endl;
				cout << endl;
				wordGuessed = true;

				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
			}
		}
		else
		{
			cout << endl;
			cout << "You have lost this game." << endl;
			cout << "The word was:" << wordAutoResult << endl;
			quitGame = true;
			cout << endl;
			cin.ignore(); // to ignore that extra cin at the end that appears weirdly
		}

	} while (quitGame == false && wordGuessed != true);





}



//--Emily's Function Definitions-----------------------------------------------------------------

/* This is the main board game function. Call this function to run the board game */
void BoardGame(int& boardGameWins)
{
	ofstream outfile;
	outfile.open("BoardGameRecord.txt");
	// Call the function that will display a welcome message and tell the user the rules of the game.
	WelcomeAndRules();
	// Declare a variable to hold the number of players.
	const int NUMBER_OF_PLAYERS = 2;
	// Create an array of structures to hold each player's information.
	player arrayOfPlayers[NUMBER_OF_PLAYERS];
	// Call the function that will set up each player's information.
	DeclarePlayers(arrayOfPlayers);
	cout << endl;
	// Call the function to have each player take their turn.
	bool win = false;
	do
	{
		for (int playerNumber = 0; playerNumber < NUMBER_OF_PLAYERS; playerNumber++)
		{
			if (win == true)
			{
				break;
			}
			win = TakeTurn(outfile, playerNumber, boardGameWins, arrayOfPlayers);
		}
	} while (win != true);
	cout << "The history of board game moves has been printed to the file \"BoardGameRecord.txt\"." << endl;
}

// Emily: This function will display a welcome message and tell the user the rules of the game.
void WelcomeAndRules()
{
	// Print a blank line between the prior output and the welcome message.
	cout << endl;

	// Print the welcome message and rules.
	cout << "Welcome to Board Game Bonanza! This is a board game played against a CPU. "
		<< "Players roll a die and advance that number of spaces. The first player "
		<< "to land on or pass the hundredth space wins. Watch out for those trick "
		<< "spaces! Trapdoors set you back, whereas secret passages give you a leg "
		<< "up on the competition. Let's play!" << endl << endl;
}

// Emily: This function will set up each player's inforamtion.
void DeclarePlayers(player arrayOfPlayers[])
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

// Emily: This function will simulate a user taking their turn. It will return a boolean value of true if someone wins.
bool TakeTurn(ofstream& outfile, int playerNumber, int& boardGameWins, player arrayOfPlayers[])
{
	// Say whose turn it is and have them roll the die.
	char roll = ' ';
	bool someoneWon = false;
	do
	{
		cout << arrayOfPlayers[playerNumber].userName << "'s turn! Type 'R' to roll the die..." << endl;
		outfile << arrayOfPlayers[playerNumber].userName << "'s turn! Type 'R' to roll the die..." << endl;
		cin >> roll;
	} while (roll != 'R' && roll != 'r' && someoneWon != true);

	int rollResult = randomResult(6, 1);
	// Show what the player rolled.
	cout << arrayOfPlayers[playerNumber].userName << " rolled a " << rollResult << endl;
	outfile << arrayOfPlayers[playerNumber].userName << " rolled a " << rollResult << endl;
	// Move the player's piece that number of spaces.
	cout << "Advancing " << rollResult << " spaces..." << endl;
	outfile << "Advancing " << rollResult << " spaces..." << endl;
	arrayOfPlayers[playerNumber].currentSpace += rollResult;
	// If the player lands on or passes the hundredth space, tell them they won, and break out of this function.
	if (arrayOfPlayers[playerNumber].currentSpace >= 100)
	{
		someoneWon = true;
		cout << arrayOfPlayers[playerNumber].userName << " wins!" << endl;
		outfile << arrayOfPlayers[playerNumber].userName << " wins!" << endl;
		if (arrayOfPlayers[0].currentSpace == arrayOfPlayers[playerNumber].currentSpace)
		{
			boardGameWins++;
		}
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
		cout << "You landed on a trapdoor! Go back 3 spaces. Your " << arrayOfPlayers[playerNumber].gamePiece << " is now on space " << arrayOfPlayers[playerNumber].currentSpace << "." << endl << endl;
		outfile << "You landed on a trapdoor! Go back 3 spaces. Your " << arrayOfPlayers[playerNumber].gamePiece << " is now on space " << arrayOfPlayers[playerNumber].currentSpace << "." << endl << endl;
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
		cout << "You landed on a secret passage! Go forward 4 more spaces. Your " << arrayOfPlayers[playerNumber].gamePiece << " is now on space " << arrayOfPlayers[playerNumber].currentSpace << "." << endl << endl;
		outfile << "You landed on a secret passage! Go forward 4 more spaces. Your " << arrayOfPlayers[playerNumber].gamePiece << " is now on space " << arrayOfPlayers[playerNumber].currentSpace << "." << endl << endl;
		break;
	default:
		cout << "Your " << arrayOfPlayers[playerNumber].gamePiece << " is now on space " << arrayOfPlayers[playerNumber].currentSpace << "." << endl << endl;
		outfile << "Your " << arrayOfPlayers[playerNumber].gamePiece << " is now on space " << arrayOfPlayers[playerNumber].currentSpace << "." << endl << endl;
		break;
	}
	// Return false if the player made it through this turn without winning.s
	return false;
}

// End of Emily's section: The board game







//--Hunter's Function Definitions-----------------------------------------------------------------

/* This function is the game Pictionary or at least a simplified version of it.It first starts out
by outputting the instructions and asking for a input from the user this input is a value 1 - 3 which
picks one of the 3 photos loaded in the program.then depending on the choice the player makes it slowly
reveal more and more of the photo based on the number of guesses the player has used. while in this part
they only have 5 guesses to get the picture correctly. they are prompted to see if they'd like to play again.
if the user is to lose they also receive the play again prompt.*/
void Pictionary(int& wins)
{

	int selection = 0;
	int counter = 6;
	string guess;
	int increment = 1;
	int i = 0;
	char response = ' ';
	bool playagain = true;

	cout << "!!!!!INSTRUCTIONS!!!!!" << endl << "In this game the objective is to guess what the photo you select is" << endl << "The more wrong guesses you have the easier it will be to guess the photo you have 5 guesses for each photo." << endl;
	while (playagain == true) {
		while (selection != 1 && selection != 2 && selection != 3) {
			cout << "Pick a number 1 to 3 (Input as 1,2, or 3) to pick the photo you would like to guess: ";
			std::cin >> selection;
			cout << endl << "You have selected photo number " << selection << " you will have 5 guesses to figure out the photo or you will lose." << endl;
			if (selection == 1 || selection == 2 || selection == 3) {
				break;
			}
			cin.clear();
			cin.ignore();

		}
		if (selection == 1 && playagain != false)
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
						cout << "You got it the answer is horse" << endl;
						guess = "horse";
						wins++;

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
						cout << "You got it the answer is horse" << endl;
						guess = "horse";
						wins++;

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
						cout << "You got it the answer is horse" << endl;
						guess = "horse";
						wins++;

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
						cout << "You got it the answer is horse" << endl;
						guess = "horse";
						wins++;

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
						cout << "You got it the answer is horse" << endl;
						guess = "horse";
						wins++;

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
		else if (selection == 2 && playagain != false)
		{

			while (guess != "turtle" && playagain != false)
			{

				i++;
				switch (i) {
				case '1':
					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "Please enter your 1st guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << "You got it the answer is turtle" << endl;
						guess = "turtle";
						wins++;

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
						cout << "You got it the answer is turtle" << endl;
						guess = "turtle";
						wins++;

					}
					break;
				case '3':

					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "$$_$$_$$$_$$$_$$$_$$$_$$$_$$$_$$$" << endl << "$______$_$$_$$$_$$$_$$$_$$$_$$$_$$$__$$" << endl;
					cout << "Please enter your 3rd guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << "You got it the answer is turtle" << endl;
						guess = "turtle";
						wins++;

					}
					break;
				case '4':

					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "$$_$$_$$$_$$$_$$$_$$$_$$$_$$$_$$$" << endl << "$______$_$$_$$$_$$$_$$$_$$$_$$$_$$$__$$" << endl;
					cout << "_$_$__$__$$$$_$$$_$$$_$$$_$$$_$$$$$$_$$" << endl << "__$$$_$$$$$$$$$$$$$$$$$_$$$$$$$$$$$$$" << endl;
					cout << "Please enter your 4th guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << "You got it the answer is turtle" << endl;
						guess = "turtle";
						wins++;

					}
					break;
				case '5':

					cout << "__________________$$$$$$$$" << endl << "________________$$$_$$$$$_$$" << endl << "______________$$$$$$$$$_$$$$$$" << endl;
					cout << "____________$$$$$_$$$_$$$_$$$$$" << endl << "_$$$$$$____$$$$_$$$_$$$_$$$_$$$$" << endl;
					cout << "$$_$$_$$$_$$$_$$$_$$$_$$$_$$$_$$$" << endl << "$______$_$$_$$$_$$$_$$$_$$$_$$$_$$$__$$" << endl;
					cout << "_$_$__$__$$$$_$$$_$$$_$$$_$$$_$$$$$$_$$" << endl << "__$$$_$$$$$$$$$$$$$$$$$_$$$$$$$$$$$$$" << endl;
					cout << "___________$$$$$$$_$$$$$$$_$_$$$$" << endl << "_________$$_$___$$_$____$$_$___$_$" << endl << "________$$$$$__$$$$$___$$$$$__$$$$$" << endl;
					cout << "Please enter your 5th and final guess: " << endl;
					cin >> guess;
					cout << endl;
					if (guess == "turtle" || guess == "Turtle")
					{
						cout << "You got it the answer is turtle" << endl;
						guess = "turtle";
						wins++;

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
		else if (selection == 3 && playagain != false)
		{
			while (guess != "crab" && playagain != false)
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
						cout << "You got it the answer is crab" << endl;
						guess = "crab";
						wins++;

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
						cout << "You got it the answer is crab" << endl;
						guess = "crab";
						wins++;

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
						cout << "You got it the answer is crab" << endl;
						guess = "crab";
						wins++;

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
						cout << "You got it the answer is crab" << endl;
						guess = "crab";
						wins++;

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
						cout << "You got it the answer is crab" << endl;
						guess = "crab";
						wins++;

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
	Function Definition End
*/