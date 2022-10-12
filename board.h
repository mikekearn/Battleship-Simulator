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

public:
	// display summary at start of game
	void gameSummary();
	// creat the game board
	void makeBoard(string arr[][COLS]);
	// display the game board when needed
	void displayBoard(string arr[][COLS]);
	// handle player moves
	void playerMove(string arr[][COLS], string str);
	// calculate hits or misses
	void isHit(string arr[][COLS], int row, int col);
	// main gameplay loop
	void keepPlaying(string arr[][COLS]);
	int showHits();
	int showMisses();
	int showMoves();
};

#endif // !board_h