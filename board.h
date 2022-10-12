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



public:
	void gameSummary();
	void makeBoard(string arr[][COLS]);
	void displayBoard(string arr[][COLS]);
	void playerMove(string arr[][COLS], string str);
	void isHit(string arr[][COLS], int row, int col);
	int showHits();
	int showMisses();
	int showMoves();
};

#endif // !board_h