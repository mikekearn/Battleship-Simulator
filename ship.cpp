#include "ship.h"

void ship::makeShip(string str, int size)
{
	shipClass = str;
	shipSize = size;
}

void ship::placeShip(string arr[][COLS])
{
	bool generating = true;

	while (generating)
	{
		// Randomise starting position
		int row = rand() % (10 - shipSize);
		int col = rand() % (10);
		
		// Randomise verticle or not
		int horizontal = rand() % 2;

		// check if random spot selected is open
		if (horizontal == 0)
		{
			bool openSpot = true;
			for (int a = 0; a < shipSize; a++)
			{
				if	(arr[a + row][col] != "[ ]") // if spot doesn't have '[ ]' then it's not free
				{
					openSpot = false;
					break; // if starting spot isn't free, try again.
				}
			}

			// if spot isn't open, try again
			if (!openSpot)
			{
				continue;
			}

			// Fill ship space with letters for step 03 display purposes
			// *** REMOVE WHEN NO LONGER DISPLAYING THE SHIPS ***
			char shipLetter = shipClass.at(0);
			string shipLetStr;
			shipLetStr = shipLetter;
			for (int b = 0; b < shipSize; b++)
			{
				arr[b + row][col] = "[" + shipLetStr + "]";
			}
			break;
		}
		else
		{
			swap(col, row);

			bool openSpot = true;
			for (int a = 0; a < shipSize; a++)
			{
				if (arr[row][a + col] != "[ ]") // if spot doesn't have '[ ]' then it's not free
				{
					openSpot = false;
					break; //
				}
			}
			if (!openSpot)
			{
				continue;
			}

			// Fill ship space with letters for step 03 display purposes
			// *** REMOVE WHEN NO LONGER DISPLAYING THE SHIPS ***
			char shipLetter = shipClass.at(0);
			string shipLetStr;
			shipLetStr = shipLetter;
			for (int b = 0; b < shipSize; b++)
			{
				arr[row][b + col] = "[" + shipLetStr + "]";
			}
			break;
		}


		break;
	}
}
