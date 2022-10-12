#include <iostream>
#include <string>
#include <ctime>
#include "board.h"
#include "ship.h"

using namespace std;

int main()
{
	// random number generator seed
	srand(time(NULL));

	// define size of board
	// use constants here in for readability
	// and in case of any future change
	static const int ROWS = 10;
	static const int COLS = 10;

	// 2d array for game board
	string gameBoard[ROWS][COLS];

	bool playAgain = false;
	do
	{
	
		// new game board object
		board newGame;

		// create the game board
		newGame.makeBoard(gameBoard);
		// newGame.displayBoard(gameBoard);
		// Wait to display after ships are added for now.


		// create ship objects
		// followed by adding attributes

		ship frigate;			// size 2
		ship sub;				// size 3
		ship destroyer;			// size 3 as well
		ship battleship;		// size 4
		ship aircraftCarrier;	// size 5

		frigate.makeShip("Frigate", 2);
		sub.makeShip("Sub", 3);
		destroyer.makeShip("Destroyer", 3);
		battleship.makeShip("Battleship", 4);
		aircraftCarrier.makeShip("Aircraft carrier", 5);

		frigate.placeShip(gameBoard);
		sub.placeShip(gameBoard);
		destroyer.placeShip(gameBoard);
		battleship.placeShip(gameBoard);
		aircraftCarrier.placeShip(gameBoard);


		// Display game board to start game.
		newGame.displayBoard(gameBoard);

		// Display the rules first round.
		newGame.gameSummary();

		// continue game
		newGame.keepPlaying(gameBoard);

		string yesOrNo;
		cout << endl;
		cout << endl;
		cout << "Would you like to play again? (Y/N): ";
		cin >> yesOrNo;

		if (yesOrNo == "Y" || yesOrNo == "y")
		{
			playAgain = true;
		}
		else
		{
			break;
		}

	} while (playAgain);

	// cleaning code, moved all to board class, got too big.

	cout << endl;
	cout << "  Thanks for playing BATTLESHIP.\n";

	

	return 0;
}