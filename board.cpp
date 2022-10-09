#include "board.h"

using namespace std;

void board::makeBoard(string arr[][COLS])
{
	// fill board with '[ ]'
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = "[ ]";
		}
	}

}

void board::displayBoard(string arr[][COLS])
{
	// Create fancy header for the game.
	cout << "-------------------------------------\n";
	cout << " ####    #   ##### ##### #     #####\n";
	cout << " #   #  # #    #     #   #     #\n";
	cout << " ####  #####   #     #   #     ###\n";
	cout << " #   # #   #   #     #   #     #\n";
	cout << " ####  #   #   #     #   ##### #####\n";
	cout << "\n";
	cout << "        #### #   # ##### ####\n";
	cout << "       #     #   #   #   #   #\n";
	cout << "        ###  #####   #   ####\n";
	cout << "           # #   #   #   #\n";
	cout << "       ####  #   # ##### #\n";
	cout << "-------------------------------------\n";
	cout << "       Welcome to BATTLESHIP \n";
	cout << "-------------------------------------\n";
	cout << "     1  2  3  4  5  6  7  8  9  10\n";
	for (int x = 0; x < ROWS; x++)
	{
		cout << "  " << (char(x + 65)) << " ";
		for (int y = 0; y < COLS; y++)
		{
			cout << arr[x][y];
		}

		cout << endl;
	}
	
	// Display ship names and sizes to keep track during testing.
	bool displaySizes = false;
	if (displaySizes == true)
	{
		cout << endl;
		cout << "Ship names and sizes:\n";
		cout << "Frigate: 2\n";
		cout << "Sub 3\n";
		cout << "Destroyer 3\n";
		cout << "Battleship 4\n";
		cout << "Aircraft Carrier 5\n";

	}
}

// This function will recieve the gameboard and player input as a string
// Then interpret that input into a move, and pass on to the next
// function to determine a hit or miss.
void board::playerMove(string arr[][COLS], string str)
{
	// pulls characters from string to give as coordinates
	char playerCharA = toupper(str[0]);
	char playerCharB = toupper(str[1]);
	char playerCharC;
	if (str.length() == 3)
	{
		playerCharC = toupper(str[2]);
	}
	
	// attempts to validate inpupt if out of range
	// using ascii values
	if (playerCharA < 65 || playerCharA > 74)
	{
		cout << "-------------------------------\n";
		cout << "| Please enter a valid input. |\n";
		cout << "-------------------------------\n";
		cout << endl;
		return;
	}
	else if (str.length() == 3)
	{
		if (playerCharC != 48)
		{
			cout << "-------------------------------\n";
			cout << "| Please enter a valid input. |\n";
			cout << "-------------------------------\n";
			cout << endl;
			return;
		}
	}
	else
	{
		if (playerCharB < 49 || playerCharB > 57)
		{
			cout << "-------------------------------\n";
			cout << "| Please enter a valid input. |\n";
			cout << "-------------------------------\n";
			cout << endl;
			return;
		}
	}

	int playerRow = (int)playerCharA-65;
	int playerCol;
	if(str.length() == 2)
	{
		playerCol = (int)playerCharB-49;
	}
	else
	{
		playerCol = 9;
	}

	cout << endl;

	isHit(arr, playerRow, playerCol);
}

// Currently this only checks whether a space is open or not;
// anything that is open is automatically a miss, otherwise
// it is a hit. Nothing else is currently tracked.

// ##### ADD #######
// Validation check for whether or not the move has been made alread
// Ensure repeated moves don't count as a hit or a miss;
// Require new move instead.
// Count hits and misses.
// Tally ships destroyed?
void board::isHit(string arr[][COLS], int row, int col)
{
	if (arr[row][col] == "[ ]")
	{
		arr[row][col] = "[O]";
		cout << "--------\n";
		cout << "| MISS |\n";
		cout << "--------\n";
	}
	else
	{
		arr[row][col] = "[X]";
		cout << "--------\n";
		cout << "| HIT! |\n";
		cout << "--------\n";
	}
}