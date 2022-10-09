#ifndef board_h
#define board_h

#include <string>
#include <iostream>
#include <cctype>

using namespace std;


class board
{
private:
	static const int ROWS = 10;
	static const int COLS = 10;


public:
	void makeBoard(string arr[][COLS]);
	void displayBoard(string arr[][COLS]);
	void playerMove(string arr[][COLS], string str);
	void isHit(string arr[][COLS], int row, int col);
};

#endif // !board_h