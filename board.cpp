#include "board.h"

using namespace std;

void board::gameSummary()
{
	cout << endl;
	cout << "-------------------------------------\n";
	cout << " Enter coordinates to try to HIT the\n";
	cout << " locations of enemy ships. Destroy\n";
	cout << " all enemy ships and you win! But if\n";
	cout << " you MISS 15 times, the enemy will\n";
	cout << " find your location and you lose.\n";
	cout << endl;
	cout << " Ready to play?\n";
	cout << "-------------------------------------\n";
	cout << endl;
}

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
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
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
	cout << "|      Welcome to BATTLESHIP        |\n";
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

	// Scoreboard v1
	cout << endl;
	cout << "  Total hits: " << showHits() << endl;
	cout << "  Total misses: " << showMisses() << endl;
	cout << "  Total moves played: " << showMoves() << endl;
	
	// Display ship names and sizes to keep track during testing.
	bool displaySizes = false;
	if (displaySizes == true)
	{
		cout << endl;
		cout << "  Ship names and sizes:\n";
		cout << "  Frigate: 2\n";
		cout << "  Sub 3\n";
		cout << "  Destroyer 3\n";
		cout << "  Battleship 4\n";
		cout << "  Aircraft Carrier 5\n";

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
	char playerCharC = NULL;
	if (str.length() == 3)
	{
		playerCharC = toupper(str[2]);
	}
	
	// attempts to validate inpupt if out of range
	// using ascii values
	if (playerCharA < 65 || playerCharA > 74)
	{
		displayBoard(arr);
		cout << endl;
		cout << "   -------------------------------\n";
		cout << "   | Please enter a valid input. |\n";
		cout << "   -------------------------------\n";
		cout << endl;
		return;
	}
	else if (str.length() == 3)
	{
		if (playerCharC != 48)
		{
			displayBoard(arr);
			cout << endl;
			cout << "   -------------------------------\n";
			cout << "   | Please enter a valid input. |\n";
			cout << "   -------------------------------\n";
			cout << endl;
			return;
		}
	}
	else
	{
		if (playerCharB < 49 || playerCharB > 57)
		{
			displayBoard(arr);
			cout << endl;
			cout << "   -------------------------------\n";
			cout << "   | Please enter a valid input. |\n";
			cout << "   -------------------------------\n";
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

// Added checks on whether space is open or not
// Added checks for repeat hits
// Added hit and miss counts, and total moves
// Added ship specific messages for destruction
void board::isHit(string arr[][COLS], int row, int col)
{
	if (arr[row][col] == "[ ]")
	{
		arr[row][col] = "[O]";
		totalMisses++;
		totalMoves++;
		displayBoard(arr);
		cout << endl;
		cout << "              --------\n";
		cout << "              | MISS |\n";
		cout << "              --------\n";
		cout << endl;
	}
	else if (arr[row][col] == "[F]" || arr[row][col] == "[S]" || arr[row][col] == "[D]" || arr[row][col] == "[B]" || arr[row][col] == "[A]")
	// Account for whether the "hit" is actually a ship F S D B A for
	// Frigate, Sub, Destroyer, Battleship, and Aircraft Carrier
	{
		// Count ship specific hits
		if (arr[row][col] == "[F]")
		{
			frigateHits++;
		}
		else if (arr[row][col] == "[S]")
		{
			subHits++;
		}
		else if (arr[row][col] == "[D]")
		{
			destroyerHits++;
		}
		else if (arr[row][col] == "[B]")
		{
			battleshipHits++;
		}
		else if (arr[row][col] == "[A]")
		{
			aircraftCarrierHits++;
		}
		// After counting, indicate a hit
		arr[row][col] = "[X]";

		// count total hits and total moves
		totalHits++;
		totalMoves++;

		// display the game board again with any specific messages
		displayBoard(arr);
		cout << endl;
		cout << "              --------\n";
		cout << "              | HIT! |\n";
		cout << "              --------\n";
		cout << endl;

		// Speific messages for sinking Frigate 2, Sub 3, Destroyer 3, Battleship 4, and Aircraft Carrier 5
		if (frigateHits == 2)
		{
			cout << "    ---------------------------\n";
			cout << "    | You sank their Frigate! |\n";
			cout << "    ---------------------------\n";
			cout << endl;
			frigateHits++;
		}
		else if (subHits == 3)
		{	
			cout << "      -----------------------\n";
			cout << "      | You sank their Sub! |\n";
			cout << "      -----------------------\n";
			cout << endl;
			subHits++;
		}
		else if (destroyerHits == 3)
		{
			cout << "   -----------------------------\n";
			cout << "   | You sank their Destroyer! |\n";
			cout << "   -----------------------------\n";
			cout << endl;
			destroyerHits++;
		}
		else if (battleshipHits == 4)
		{
			cout << "   ------------------------------\n";
			cout << "   | You sank their Battleship! |\n";
			cout << "   ------------------------------\n";
			cout << endl;
			battleshipHits++;
		}if (aircraftCarrierHits == 5)
		{
			cout << "------------------------------------\n";
			cout << "| You sank their Aircraft Carrier! |\n";
			cout << "------------------------------------\n";
			cout << endl;
			aircraftCarrierHits++;
		}
	}
	else
	// IF not a miss or a hit on a ship, retry
	{
		displayBoard(arr);
		cout << endl;
		cout << "   -------------------------------\n";
		cout << "   | Please enter a valid input. |\n";
		cout << "   -------------------------------\n";
		cout << endl;
	}

}

void board::keepPlaying(string arr[][COLS])
{
	while (keepPlayingBool)
	{
		string nextMove;

		cout << "  Please enter a position to\n  fire upon, such as 'A1'\n";
		cout << "  (Or enter -1 to quit)\n";
		cout << "  Player move: ";
		cin >> nextMove;

		if (nextMove.length() > 3 || nextMove.length() < 2)
		{
			displayBoard(arr);
			cout << endl;
			cout << "  -------------------------------\n";
			cout << "  | Please enter a valid input. |\n";
			cout << "  -------------------------------\n";
			cout << endl;
			continue;
		}
		else if (nextMove == "-1")
		{
			keepPlayingBool = false;
		}
		else
		{
			playerMove(arr, nextMove);
		}
	}
}


int board::showHits()
{
	return totalHits;
}

int board::showMisses()
{
	return totalMisses;
}
int board::showMoves()
{
	return totalMoves;
}