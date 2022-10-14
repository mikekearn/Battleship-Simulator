#ifndef board_h
#define board_h

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// Create the board class
class board
{
private:
	// Used for making the game board
	static const int ROWS = 10;
	static const int COLS = 10;
	// Tracking moves
	int totalHits = 0;
	int totalMisses = 0;
	int totalMoves = 0;
	// Tracking ship specific hits
	// Frigate, Sub, Destroyer, Battleship, Aircraft Carrier
	int frigateHits = 0;
	int subHits = 0;
	int destroyerHits = 0;
	int battleshipHits = 0;
	int aircraftCarrierHits = 0;
	// Used for main gameplay loop
	bool keepPlayingBool = true;
	// Used to show summary only at first loop
	bool firstLoop = true;

public:
	// display summary at start of game
	void gameSummary();
	// split header into new function
	void displayHeader();
	// create the game board
	void makeBoard(string arr[][ROWS]);
	// display the game board when needed
	void displayBoard(string arr[][ROWS]);
	// handle player moves
	void playerMove(string arr[][ROWS], string str);
	// calculate hits or misses
	void isHit(string arr[][ROWS], int row, int col);
	// main gameplay loop
	void keepPlaying(string arr[][ROWS]);
	int showHits();
	int showMisses();
	int showMoves();
};

#endif // !board_h