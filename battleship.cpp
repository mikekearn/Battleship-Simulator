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

	bool keepPlaying = true;

	while (keepPlaying)
	{
		newGame.displayBoard(gameBoard);

		string nextMove;

		cout << "Please enter a position to\nfire upon, such as 'A1'\n";
		cout << "(Or enter -1 to quit)\n";
		cout << "Player move: ";
		cin >> nextMove;

		if (nextMove.length() > 3 || nextMove.length() < 2)
		{
			cout << "-------------------------------\n";
			cout << "| Please enter a valid input. |\n";
			cout << "-------------------------------\n";
			cout << endl;
			continue;
		}
		else if (nextMove == "-1")
		{
			keepPlaying = false;
		}
		else
		{
			newGame.playerMove(gameBoard, nextMove);
		}
	}

	cout << endl;
	cout << "Thanks for playing BATTLESHIP.\n";

	return 0;
}