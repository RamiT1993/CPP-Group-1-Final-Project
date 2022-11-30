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
#include <cctype> // useful for changing a character tolower but remember it changes to an int

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



//void mainLoop(int&, int&, int&); maybe like this


using namespace std; // so we dont have to constantly use std:: prefix
// Rami's Function Prototypes

void hangManIntroduction();
int difficultyChoice(bool& quitVariable);
string choosingTheWord(const string stringArrayWord[][3], const int& intDifficulty, string& returnToThis);
int maxGuesses(const int guessArray[], const int& intDifficulty);
int choosingALetter(char& charInputOfLetter, bool& quitter);
void mainHangManFunc(int& gameOneIncrement, const string stringArrayWords[][3], const int guessArray[], const char alphabet[], const int&m);



// Emily's Function Prototypes

// Hunter's Function Prototypes

/*
	Function ProtoType Section End
*/




/*
	Main Function Start
*/
int main()
{

	// for true random can't be placed inside of functions
	srand(time(0)); // this allows us to use a seed so the random can actually be random each time of running the function. time(0) indicates the number of seconds start from january 1, 1970.

	// const arrays required for HangMan Game
	const int ALPHABET_LIMIT = 26;
	const char ENGLISH_ALPHABET[ALPHABET_LIMIT] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	const int GUESS_LIMIT[] = { 5, 7, 10 };
	const string WORDS[3][3] = { {"actor", "ahead", "alive"},
		{"quizzed", "zizzled", "wazzock"},
		{"maximizing", "jackhammer", "squeezable"} };

	// const array for hangManGame End

	// variables
	int hangmanWins = 0;
	int pictionaryWins = 0;
	int boardGameWins = 0;

	// bool controlled and flag controlled variables
	bool quitProgram = false;


	readWins(hangmanWins, pictionaryWins, boardGameWins);
	cout << endl;
	mainHangManFunc(hangmanWins, WORDS, GUESS_LIMIT, ENGLISH_ALPHABET, ALPHABET_LIMIT);



	writeWins(hangmanWins, pictionaryWins, boardGameWins);







}
/*
	Main Function End
*/


/*
	Function Definition(s) Start
*/

// Every One Participated in the creation of these functions


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
		int totalWinsInt = firstGame + secondGame + thirdGame;
		writeToWinFile << gameWriteArray[0] << setw(holdLoopResults[0]) << firstGame << endl;
		writeToWinFile << gameWriteArray[1] << setw(holdLoopResults[1]) << secondGame << endl;
		writeToWinFile << gameWriteArray[2] << setw(holdLoopResults[2]) << thirdGame << endl;
		writeToWinFile << gameWriteArray[3] << setw(holdLoopResults[3]) << totalWinsInt << endl;
	}

	writeToWinFile.close();
}


// Rami's Function Definitions

/*This is used to display the introduction of the HangMan Game with some iomanip separtors*/
void hangManIntroduction()
{
	cout << setw(10) << setfill('-') << "" << "Welcome to the Hangman Game" << setw(10) << setfill('-') << "" << endl;
	cout << endl;
	cout << "The rules are: keep guessing the word per letter until you run out of guesses or you quit!" << endl;
}


/* The purpose of this function is to tell the user to input a difficulty choice, which will then be used to determine the difficulty of the word, that will be used
, and theirs also a fail safe system implemented that will be used to make sure the user is able to quit and a random default is implement so that if the user does not
choose and it will choose the difficulty randomly*/
int difficultyChoice(bool& quitVariable)
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
		return difficultyInInt;
		break;
	case 'm':
	case 'M':
		cout << "You have chosen Normal difficulty! Good Luck, Academic!" << endl;
		difficultyInInt = 1;
		return difficultyInInt;
		break;
	case 'h':
	case 'H':
		cout << "You have chosen Hard difficulty! Oh No!" << endl;
		difficultyInInt = 2;
		return difficultyInInt;
		break;
	case 'q':
	case 'Q':
		quitVariable = true;
		break;
	default:
		cout << "You have pressed the wrong button and now as a bonus suprise, a difficulty will be randomly selected! Congradulations!" << endl;
		difficultyInInt = randomResult(3);
		return difficultyInInt;
		break;
	}
}

/*This function's purpose will use the variable that is passed by reference by difficultyChoice,
the randomresult function from 0-3 which will allow us to gain the word from the 2d array, that will be used in the hangman game and since we don't want the number to change through the scope
we add const in front of it. I also used this to create the spacing that will act kinda like pseudo array, that can be used inside of another function using the strVar[index] method.
I primarly did it this way because I don't know how to create a new array inside the */
string choosingTheWord(const string stringArrayWord[][3], const int& intDifficulty, string& returnToThis)
{

	returnToThis = stringArrayWord[intDifficulty][randomResult(3)];

	string spacing;

	if (intDifficulty == 0)
	{
		spacing = "     ";
		return spacing;
	}
	else if (intDifficulty == 1)
	{
		spacing = "       ";
		return spacing;
	}
	else
	{
		spacing = "          ";
		return spacing;
	}




}

/* The purpose of this function is to return the maximum number of guesses available */
int maxGuesses(const int guessArray[], const int& intDifficulty)
{
	int MAX_GUESSES;
	switch (intDifficulty)
	{
	case 0:
		MAX_GUESSES = guessArray[intDifficulty];
		return MAX_GUESSES;
		break;
	case 1:
		MAX_GUESSES = guessArray[intDifficulty];
		return MAX_GUESSES;
		break;
	case 2:
		MAX_GUESSES = guessArray[intDifficulty];
		return MAX_GUESSES;
		break;
	}
}


/* The primary purpose of this function is a quick way to get the index of the alphabet array and return as an int,
it always has a check system to make sure*/
int choosingALetter(char& charInputOfLetter, bool& quitter)
{

	int choice = 0;
	switch (charInputOfLetter)
	{
	case 'A':
	case 'a':
		return 0;
	case 'B':
	case 'b':
		return 1;
	case 'C':
	case 'c':
		return 2;
	case 'D':
	case 'd':
		return 3;
	case 'E':
	case 'e':
		return 4;
	case 'F':
	case 'f':
		return 5;
	case 'G':
	case 'g':
		return 6;
	case 'H':
	case 'h':
		return 7;
	case 'I':
	case 'i':
		return 8;
	case 'J':
	case 'j':
		return 9;
	case 'K':
	case 'k':
		return 10;
	case 'L':
	case 'l':
		return 11;
	case 'M':
	case 'm':
		return 12;
	case 'N':
	case 'n':
		return 13;
	case 'O':
	case 'o':
		return 14;
	case 'P':
	case 'p':
		return 15;
	case 'Q':
	case 'q':
		cout << "Did you mean to quit(1) or do you mean the letter q(2):";
		cin >> choice;
		if (choice == 1)
		{
			quitter = true;
			break;
		}
		return 16;
	case 'R':
	case 'r':
		return 17;
	case 'S':
	case 's':
		return 18;
	case 'T':
	case 't':
		return 19;
	case 'U':
	case 'u':
		return 20;
	case 'V':
	case 'v':
		return 21;
	case 'W':
	case 'w':
		return 22;
	case 'X':
	case 'x':
		return 23;
	case 'Y':
	case 'y':
		return 24;
	case 'Z':
	case 'z':
		return 25;
	default:
		cout << "Choosing a letter by random" << endl;
		int letterChosen = randomResult(25);
		return letterChosen;
	}
}



/*This main function is in which every other function will be passed into and only this will will be called into main, thats what i thought at least, as far as I know so far I can not create arrays inside of functions
the same reason we can use srand inside of function because of the scope. The hangman game will not work without multiple nested loops.*/
void mainHangManFunc(int& gameOneIncrement, const string stringArrayWords[][3], const int guessArray[], const char alphabet[], const int& alphaLimit)
{
	bool wordGuessed = false;
	bool quitGame = false;
	do {


		hangManIntroduction();

		int difficultyChoiceIntVariable = difficultyChoice(quitGame);

		if (quitGame == true)
		{
			break;
		}

		string wordAutoResult;
		string manualResult = choosingTheWord(stringArrayWords, difficultyChoiceIntVariable, wordAutoResult);

		int wordLength = wordAutoResult.length();

		const int MAX_GUESSESS = maxGuesses(guessArray, difficultyChoiceIntVariable);



		for (int guesses = 0; guesses < MAX_GUESSESS - 1 && manualResult != wordAutoResult && wordGuessed != true; guesses++)
		{
			char letterChoice = 0;
			if (manualResult != wordAutoResult && wordGuessed != true)
			{
				cout << "Please Choose a letter from the Alphabet:";
				cin >> letterChoice;
			}

			int trueChoice = choosingALetter(letterChoice, quitGame);

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
				break;
			}

		}


		// to check if the player has guessed correctly
		if (manualResult == wordAutoResult)
		{
			if (difficultyChoiceIntVariable == 0)
			{
				cout << endl;
				cout << "Congrats! PLUS ONE TO HANGMAN WINS" << endl;
				gameOneIncrement++;
				cout << endl;
				wordGuessed = true;
				cout << setw(47) << setfill('-') << "" << endl;
				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
			}
			else if (difficultyChoiceIntVariable == 1)
			{
				cout << endl;
				cout << "Congrats! PLUS TWO TO HANGMAN WINS" << endl;
				gameOneIncrement += 2;
				cout << endl;
				wordGuessed = true;
				cout << setw(47) << setfill('-') << "" << endl;
				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
			}
			else
			{
				cout << endl;
				cout << "Congrats! PLUS THREE TO HANGMAN WINS" << endl;
				gameOneIncrement += 3;
				cout << endl;
				wordGuessed = true;
				cout << setw(47) << setfill('-') << "" << endl;
				cin.ignore(); // to ignore that extra cin at the end that appears weirdly
			}
		}
		else
		{
			cout << endl;
			cout << "You have lost the game, Going back to the top" << endl;
			cout << endl;
			cout << setw(47) << setfill('-') << "" << endl;
			cin.ignore(); // to ignore that extra cin at the end that appears weirdly
		}

	} while (quitGame == false && wordGuessed != true);





}

// Emily's Function Definitions

// Hunter's Function Definitions


/*
	Function Definition End
*/