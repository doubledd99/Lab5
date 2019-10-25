#include <iostream> //These are the libraries needed to run the program
#include <stdlib.h>
#include <time.h>

using namespace std; // Namespace needed to run the program

int function();                     //These are function prototypes that are defined later
int randomNumberGenerator();
int randomMessageNumberGenerator();

int main() {						//Entry point for the program to run
	srand(unsigned int(time(NULL)));//Seeds the random number generator one time
	function();	//Calls the function() function

	return 0;
}

int function() { //This function's existence is only because the program broke if I tried to move everything to main()
	int count=20;			//Starts a count where count==number of guesses remaining
	bool correct = false;	//True or false value if player guessed correct
	int playerGuess;		//INput stream for player input
	bool playAgain=false;	//True or false value if player wants to play again
	char playAgainInput;	//Stores player inputted value for playing again
	int randomNumber;		//Stores the randomly generated number the computer comes up with that user will guess
	int wins = 0;			//keeps track of number of wins by user
	int losses = 0;			//keeps track of number of losses by user
	int messageNumber;		//Is a random number between 0-10
	do { //exterior do while loop to run whole program multiple times
		randomNumber = randomNumberGenerator(); // assigns local variable to a random number generated by external function
		correct = false; //resets correct to false to prevent it assuming user was correct again on next run thru
		do { //Nested do while loop for each guess attempt
			//cout << randomNumber << endl; //Outputs # for testing purposes
			cout << "Enter an integer from 0 to 100 \n"; //user interaction to guess
			cin >> playerGuess; // inputs user's guess
			if (!cin || playerGuess > 100 || playerGuess < 0) { //if input is not valid
				cout << "That is not a valid number, please enter an integer from 0 to 100 \n"; //User interaction telling them to re-guess
				count++; //adds one to the # of guesses so that invalid guesses dont -1 from guess count
				cin.clear(); //restores cin input state
				cin.ignore(100, '\n'); //restores cin input state
			}
			if (playerGuess == randomNumber) {//if user guessed right
				correct = true; //sets correct to true so that game kicks to outside loop to run that loop again
				cout << endl; //new line
				messageNumber = randomMessageNumberGenerator();//grabs another random 1-10 number for switch statement
				switch (messageNumber) { //switch statement with random 1-10 value
				case 1: cout << "WINNING";						//All of these are messages that display to the user if they win
					break;
				case 2: cout << "You won!";
					break;
				case 3: cout << "I guess you won, you must've cheated..";
					break;
				case 4: cout << "Winner Winner lets have chicken for dinner.";
					break;
				case 5: cout << "Hoopla, you have won!";
					break;
				case 6: cout << "Sweet Sweet Sweet victory yeah";
					break;
				case 7: cout << "We got a good guesser, you won!";
					break;
				case 8: cout << "it's about time you won, geez";
					break;
				case 9: cout << "You should quit your day job and play the lottery, you won!";
					break;
				case 10: cout << "All you do is win win win no matter what";
					break;
				}
				cout << endl;//new line
				wins++; //+1 to the wins total
			}
			count--;//makes guesses -1 because user guessed one time
			cout << "Number of guesses remaining: " << count << endl; //tells user number of guesses remaining
		} while (count > 0 && correct == false); //while the user guesses <20 times they are allowed to guess again and as long as they didnt guess correctly
		if (count == 0 && correct == false) { //if the user exausted guesses and didnt get it wright this displays lost messages
			messageNumber = randomMessageNumberGenerator(); // new random number 1-10 for switch statement
			cout << endl;//newline
			switch (messageNumber) { //switch statement with 1-10 random number
			case 1: cout << "You LOST";			//All of these are messages that display to the user if they lose
				break;
			case 2: cout << "Pathetic...";
				break;
			case 3: cout << "Lost, like someone learning manual.";
				break;
			case 4: cout << "You got it.... WRONG";
				break;
			case 5: cout << "Anotha one bites tha dustaaa";
				break;
			case 6: cout << "Hate the player not the game";
				break;
			case 7: cout << "There's a winner and a loser... actually just a loser..";
				break;
			case 8: cout << "You should try harder next time";
				break;
			case 9: cout << "Close but no cigar";
				break;
			case 10: cout << "Close, but if you aren't first you're last";
				break;
			}
			cout << endl;//new line
			losses++; //adds one to the lost tally
		}
		cout <<"The correct number was: " << randomNumber << endl << "Wins: " << wins << " Losses: "<< losses << endl; //tells user what they should have guessed and the total wins, losses
		messageNumber = randomMessageNumberGenerator(); //grabs new random number 1-10
		switch (messageNumber) {//switch statement with 1-10 random number
		case 1: cout << "Would you like to play again?";		//All of these are messages that display to the user if they finish the game and asks to play again
			break;
		case 2: cout << "Would you like to try again?";
			break;
		case 3: cout << "Run it back?";
			break;
		case 4: cout << "Lets go again?";
			break;
		case 5: cout << "Try again?";
			break;
		case 6: cout << "Run program again?";
			break;
		case 7: cout << "Play again? or are you a quitter...";
			break;
		case 8: cout << "Lets try that again okay?";
			break;
		case 9: cout << "More guesses?";
			break;
		case 10: cout << "More guesses? it'll be a different number though!";
			break;
		}
		cout << " (y/n) "; // tells the user what to input to play again
		cin >> playAgainInput; // inputs user input
		if (playAgainInput == 'y' || playAgainInput == 'Y') { //evaluates if user would like to play again by looking if they typed in Y or y
			playAgain = true; // if this is true the main loop will go thru again starting a new game
			count = 20; // resets the number of guesses to 20
		}
		else
			playAgain = false; // if user inputs 'no' they dont want to play again it exits program
	} while (playAgain==true); // as long as user would like to play again the loop that runs the whole game runs again
	return 0; //returns success parameter
}

int randomNumberGenerator() { // function definition for making a random number 0-100
	int randomNumber; //creates a spot for the random number to be stored
	randomNumber = rand() % 100 + 1; //assigns a random number from 0-100 to local variable
	return randomNumber; // returns the random number so that it can be used when assigning the return value of this function in do while loops above
}

int randomMessageNumberGenerator() { // function definition for making a random number between 0-10
	int randomNumber; // creates a spot for the random number to be stored
	randomNumber = rand() % 10 + 1; // assigns a random number from 0-10 to local variable
	return randomNumber; // returns the random number so that it can be used when assigning the return value of this function in do while loops above
}