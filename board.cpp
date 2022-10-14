#include "board.h"

using namespace std;

void board::gameSummary()
{
	//cout << endl;
	//cout << "   -------------------------------------\n";
	cout << "   You are the commander on the cruise\n";
	cout << "   missile destroyer USS John Paul Jones\n";
	cout << "   and you must destroy the enemy fleet!\n";
	//cout << endl;
	cout << "   Satellites are down, but your sonar\n";
	cout << "   still works. The enemy has a Frigate,\n";
	cout << "   Submarine, Destroyer, Battleship, and\n";
	cout << "   Aircraft Carrier. Can you destroy\n";
	cout << "   them all before they find and destroy\n";
	cout << "   YOU?\n";
	cout << "   -------------------------------------\n";
	//cout << "    HOW TO PLAY:\n";
	//cout << endl;
	cout << "   Enter coordinates to try to HIT the\n";
	cout << "   locations of enemy ships. Destroy\n";
	cout << "   all enemy ships and you win! But if\n";
	cout << "   you MISS 15 times in a row, the enemy\n";
	cout << "   will find your location and you lose.\n";
	//cout << endl;
	//cout << "    Ready to play?\n";
	cout << "   -------------------------------------\n";
	cout << endl;
}

void board::displayHeader()
{
	// Create fancy header for the game.
	// Split into own function for display purposes
	cout << endl;
	cout << "   -------------------------------------\n";
	cout << "    ####    #   ##### ##### #     ##### \n";
	cout << "    #   #  # #    #     #   #     #     \n";
	cout << "    ####  #####   #     #   #     ###   \n";
	cout << "    #   # #   #   #     #   #     #     \n";
	cout << "    ####  #   #   #     #   ##### ##### \n";
	cout << "                                        \n";
	cout << "           #### #   # ##### ####        \n";
	cout << "          #     #   #   #   #   #       \n";
	cout << "           ###  #####   #   ####        \n";
	cout << "              # #   #   #   #           \n";
	cout << "          ####  #   # ##### #           \n";
	cout << "   -------------------------------------\n";
	//cout << "   |      Welcome to BATTLESHIP        |\n";
	//cout << "   -------------------------------------\n";

}

void board::makeBoard(string arr[][ROWS])
{
	// fill board with '[ ]'
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			arr[i][j] = "[ ]";
		}
	}

}

void board::displayBoard(string arr[][ROWS])
{
	// ~~Create fancy header for the game.~~
	// Split off header into own function displayHeader();
	if (firstLoop)
	{
		firstLoop = false;
	}
	else
	{
		displayHeader();
	}

	//cout << "     1  2  3  4  5  6  7  8  9  10\n";
	// Must swap numbers and letters.
	cout << "        A  B  C  D  E  F  G  H  I  J \n";
	for (int x = 0; x < COLS; x++)
	{
		//cout << "  " << (char(x + 65)) << " ";
		// Swapping letters for numbers below
		// Must add additional code to account for
		// the 10 being 2 digits wide
		if (x < 9)
		{
			cout << "    " << (x + 1) << "  ";
		}
		else
			cout << "    " << (x + 1) << " ";
		for (int y = 0; y < ROWS; y++)
		{
			cout << arr[x][y];
		}

		cout << endl;
	}

	// Scoreboard v1
	cout << endl;
	// cout << "  Total hits: " << showHits() << endl;
	// Don't need total his
	
	cout << "     Total consecutive misses: " << showMisses() << endl;
	// ADDED: CONSECUTIVE misses
	cout << "     Total moves played: " << showMoves() << endl;
	// Leaving in for now, seems useful maybe?

	// Display ship names and sizes to keep track during testing.
	bool displaySizes = false;
	if (displaySizes == true)
	{
		cout << endl;
		cout << "     Ship names and sizes:\n";
		cout << "     Frigate: 2\n";
		cout << "     Sub 3\n";
		cout << "     Destroyer 3\n";
		cout << "     Battleship 4\n";
		cout << "     Aircraft Carrier 5\n";

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
		cout << "      -------------------------------\n";
		cout << "      | Please enter a valid input. |\n";
		cout << "      -------------------------------\n";
		cout << endl;
		return;
	}
	else if (str.length() == 3)
	{
		if (playerCharC != 48)
		{
			displayBoard(arr);
			cout << endl;
			cout << "      -------------------------------\n";
			cout << "      | Please enter a valid input. |\n";
			cout << "      -------------------------------\n";
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
			cout << "      -------------------------------\n";
			cout << "      | Please enter a valid input. |\n";
			cout << "      -------------------------------\n";
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

	isHit(arr, playerCol, playerRow);
}

// Added checks on whether space is open or not
// Added checks for repeat hits
// Added hit and miss counts, and total moves
// Added ship specific messages for destruction

// ~~~~Swapped all references of 'row' and 'col' after swapping
// ~~~~letter and number columns and rows.
void board::isHit(string arr[][COLS], int col, int row)
{
	if (arr[col][row] == "[ ]")
	{
		arr[col][row] = "[O]";
		totalMisses++;
		totalMoves++;
		displayBoard(arr);
		cout << endl;
		cout << "                 --------\n";
		cout << "                 | MISS |\n";
		cout << "                 --------\n";
		//cout << endl;
	}
	else if (arr[col][row] == "[F]" || arr[col][row] == "[S]" || arr[col][row] == "[D]" || arr[col][row] == "[B]" || arr[col][row] == "[A]")
	// Account for whether the "hit" is actually a ship F S D B A for
	// Frigate, Sub, Destroyer, Battleship, and Aircraft Carrier
	{
		// Count ship specific hits
		if (arr[col][row] == "[F]")
		{
			frigateHits++;
		}
		else if (arr[col][row] == "[S]")
		{
			subHits++;
		}
		else if (arr[col][row] == "[D]")
		{
			destroyerHits++;
		}
		else if (arr[col][row] == "[B]")
		{
			battleshipHits++;
		}
		else if (arr[col][row] == "[A]")
		{
			aircraftCarrierHits++;
		}
		// After counting, indicate a hit
		arr[col][row] = "[X]";

		// count total hits and total moves
		totalHits++;
		totalMoves++;

		// display the game board again with any specific messages
		// ADDED: Reset miss counter - 15 CONSECUTIVE misses
		//        equals a loss, not 15 TOTAL misses
		totalMisses = 0;
		displayBoard(arr);
		cout << endl;
		cout << "                 --------\n";
		cout << "                 | HIT! |\n";
		cout << "                 --------\n";
		//cout << endl;

		// Speific messages for sinking Frigate 2, Sub 3, Destroyer 3, Battleship 4, and Aircraft Carrier 5
		if (frigateHits == 2)
		{
			cout << "       ---------------------------\n";
			cout << "       | You sank their Frigate! |\n";
			cout << "       ---------------------------\n";
			//cout << endl;
			frigateHits++;
		}
		else if (subHits == 3)
		{	
			cout << "         -----------------------\n";
			cout << "         | You sank their Sub! |\n";
			cout << "         -----------------------\n";
			//cout << endl;
			subHits++;
		}
		else if (destroyerHits == 3)
		{
			cout << "      -----------------------------\n";
			cout << "      | You sank their Destroyer! |\n";
			cout << "      -----------------------------\n";
			//cout << endl;
			destroyerHits++;
		}
		else if (battleshipHits == 4)
		{
			cout << "      ------------------------------\n";
			cout << "      | You sank their Battleship! |\n";
			cout << "      ------------------------------\n";
			//cout << endl;
			battleshipHits++;
		}if (aircraftCarrierHits == 5)
		{
			cout << "   ------------------------------------\n";
			cout << "   | You sank their Aircraft Carrier! |\n";
			cout << "   ------------------------------------\n";
			//cout << endl;
			aircraftCarrierHits++;
		}
	}
	else
	// IF not a miss or a hit on a ship, retry
	{
		displayBoard(arr);
		cout << endl;
		cout << "      -------------------------------\n";
		cout << "      | Please enter a valid input. |\n";
		cout << "      -------------------------------\n";
		//cout << endl;
	}

}

void board::keepPlaying(string arr[][COLS])
{
	while (keepPlayingBool)
	{
		if (totalHits == 17)
		{
			keepPlayingBool = false;
			firstLoop = true;
			cout << endl;
			cout << "      -----------------------------\n";
			cout << "      | Congratulations, you WIN! |\n";
			cout << "      | You sank all their ships. |\n";
			cout << "      -----------------------------\n";
			//cout << endl;
			break;
		}
		else if (totalMisses == 15)
		{
			keepPlayingBool = false;
			firstLoop = true;
			cout << endl;
			cout << "      -------------------------------\n";
			cout << "      | Oh no, the enemy found you! |\n";
			cout << "      |    You LOSE, game over!     |\n";
			cout << "      -------------------------------\n";
			//cout << endl;
			break;
		}

		string nextMove;

		cout << endl;
		cout << "     Please enter a position to\n     fire upon, such as 'A1'\n";
		cout << "     (Or enter -1 to quit)\n";
		cout << "     Player move: ";
		cin >> nextMove;

		if (nextMove.length() > 3 || nextMove.length() < 2)
		{
			displayBoard(arr);
			cout << endl;
			cout << "     -------------------------------\n";
			cout << "     | Please enter a valid input. |\n";
			cout << "     -------------------------------\n";
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