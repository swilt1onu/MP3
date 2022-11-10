/*
*File: MP3
*Name: Selby Wilt
*Date: 11/13/22
*
* Program that allows 2 people to play tic-tac-toe. Counts the number of wins each player has
* as well as the ties. Each turn the program will display the current board. The program also
* checks if a player has won and displays to the user, then resets to play again. 
* 
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

//funtion prototypes
int getPlayerInput(string playerName);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);
bool isGameTie(char board[]);

//global variable for the game board size
const int SIZE = 9;


int main(void) {

	int ties = 0;         //number of ties
	int player1Score = 0; //player 1 number of wins
	int player2Score = 0; //player 2 number of wins
	int numOfGames = 0;   //total number of games played
	bool turnNum = true; //bool variable to change who goes first
	char playAgain; // character for playing again or quitting.

	//strings to hold the player 1 and 2's names and char for their mark
	string player1Name;
	string player2Name;

	//characters to hold each player's symbol
	char playerMark1 = 'X';
	char playerMark2 = 'O';

	//temporary variables
	int location = 0;
	string playerName;
	char playerMark;

	//defining the board array
	char board[SIZE] = { '1','2','3','4','5','6','7','8','9' };
	
	//asks the user what the players names are
	cout << "Enter the name of player 1 (X): ";
	cin >> player1Name;
	cout << "Enter the name of player 2 (O) : ";
	cin >> player2Name;


	//while loop for the entire game
	while (true) {

		//while loop is true while the game is being played, once false the board is cleared and the game restarts
		while (true) {

			//if statement used 
			if (turnNum) {
				//player 1 turn, displays the board and tells the user its their turn
				displayBoard(board);
				cout << player1Name << "'s turn\n";
				playerName = player1Name;
				playerMark = 'X';

				//gets user input, checks if it is a valid move, then places the mark
				do {
					location = getPlayerInput(playerName);

				} while (!isLegalMove(board, location));

				placeMarkOnBoard(board, playerMark, location);

				//checks if there is 3 in a row and ends the round
				if (hasThreeInRow(board, playerMark) == true) {
					cout << player1Name << "\nhas won!\n";
					displayBoard(board);
					player1Score++;
					break;
				}

				//needs to check if there are no moves left
				if (isGameTie(board) == true) {
					cout << "Tie!";
					ties++;
					break;
				}

				turnNum = false;

			}
			
			else {

				//player 2 turn, displays the board and tells the user its their turn
				displayBoard(board);
				cout << player2Name << "'s turn\n";
				playerName = player2Name;
				playerMark = 'O';

				//gets user input, checks if it is a valid move, then places the mark
				do {
					location = getPlayerInput(playerName);

				} while (!isLegalMove(board, location));

				placeMarkOnBoard(board, playerMark, location);


				//checks if there is 3 in a row and ends the round
				if (hasThreeInRow(board, playerMark) == true) {
					cout << player1Name << "\nhas won!\n";
					displayBoard(board);
					player2Score++;
					break;
				}

				//needs to check if there are no moves left
				if (isGameTie(board) == true) {
					cout << "Tie!";
					ties++;
					break;
				}

				turnNum = true;
			}
		}

		//clears the board after someone wins, allows the game to be played more times
		displayGameStats(ties, player1Score, player2Score);
		numOfGames++;
		clearBoard(board);
		if (numOfGames % 2 == 0) {
			turnNum = true;
		}
		else {
			turnNum = false;
		}
		cout << "Press Q to quit or any key to keep playing: ";
		cin >> playAgain;
		if (playAgain == 'Q' || playAgain == 'q') {
			return 0;
		}

	}
}




int getPlayerInput(string playerName) {
	int playerInput = 0;
	cout << "Enter a number 1-9 to play on the board: ";
	cin >> playerInput;

	while(true) {
		while (playerInput < 0 || playerInput > 9) {
			cin.clear();
			cout << endl << "Unrecognised input try again: ";
			cin >> playerInput;
		}
		break;
	}

	playerInput--;
	return playerInput;
}


//checks that the user played the X or O on a legal space
bool isLegalMove(char board[], int location) {
	if (board[location] == 'X' || board[location] == 'O') {
		return false;
	}
	else {
		return true;
	}
}


void placeMarkOnBoard(char board[], char playerMark, int location) {
	board[location] = playerMark;
}


void clearBoard(char board[]) {
	for (int i = 0; i < SIZE; i++) {

		//using the askey value instead of the actual value
		board[i] = i + 49;
	}
}

//checks all possible winning combinations to see if there is a winner, if so returns true, else returns false
bool hasThreeInRow(char board[], char playerMark) {

	if (board[6] == playerMark && board[7] == playerMark && board[8] == playerMark)
		return true;
	if (board[3] == playerMark && board[4] == playerMark && board[5] == playerMark)
		return true;
	if (board[0] == playerMark && board[1] == playerMark && board[2] == playerMark)
		return true;
	if (board[6] == playerMark && board[3] == playerMark && board[0] == playerMark)
		return true;
	if (board[7] == playerMark && board[4] == playerMark && board[1] == playerMark)
		return true;
	if (board[8] == playerMark && board[5] == playerMark && board[2] == playerMark)
		return true;
	if (board[6] == playerMark && board[4] == playerMark && board[2] == playerMark)
		return true;
	if (board[8] == playerMark && board[4] == playerMark && board[0] == playerMark)
		return true;
	else{
		return false;
	}

}

//function that takes the array parameter variable and prints the board
void displayBoard(char board[]) {
	
	cout << endl << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
	cout << "---+---+---\n";
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
	cout << "---+---+---\n";
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n\n";
}

//takes the game stats and prints them out
void displayGameStats(int ties, int player1Score, int player2Score) {
	cout << endl << "-----------\n";
	cout << "Ties: " << ties <<endl;
	cout << "Player 1 score: " << player1Score << endl;
	cout << "Player 2 score: " << player2Score << endl;
	cout << "-----------\n";
}

//checks if the game ends in a tie
bool isGameTie(char board[]) {
	if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
		board[3] != '4' && board[4] != '5' && board[5] != '6' &&
		board[6] != '7' && board[7] != '8' && board[8] != '9') {
		return true;
	}
	else {
		return false;
	}
}
















