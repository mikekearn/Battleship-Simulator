#ifndef ship_h
#define ship_h

#include <string>
#include <iostream>

using namespace std;

class ship
{
private:
	static const int ROWS = 10;
	static const int COLS = 10;
	string shipClass;
	int shipSize;

public:
	void makeShip(string str, int size);
	void placeShip(string arr[][COLS]);
};

#endif // !ship_h