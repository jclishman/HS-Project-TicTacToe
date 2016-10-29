// Jack Lishman
// Tic-Tac-Toe Program

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Functions
void drawTiles();
void noPlayer();
void win();
int repeat();

// Variable Declaration
int players = -1;
int tileSelection;
int turn = 0;
string tiles[10] {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"};
string currentTurn = "X";
string score = "1";
string playAgain = "Y";
int randomNum;

int main()
{
	system("title Tic-Tac-Toe");
	system("CLS");
	
	cout << "Choose number of players (0, 1, or 2): ";
	cin >> players;
	
	// 0 Players
	if (players == 0)
	{
		system("CLS");
		cout << "The only winning move is not to play..." << endl;
		system("PING 1.1.1.1 -n 1 -w 5000 >NUL");
		noPlayer();
	}

	// 1 Player
	else if (players == 1)
	{	
		while (score == "1")
		{
			system("title Tic-Tac-Toe");
			system("CLS");

			cout << "Welcome To Tic-Tac-Toe" << endl << endl << "It Is [" << currentTurn << "]'s turn " << endl << endl;
			drawTiles();

			if (currentTurn == "X")
			{
				cout << "Enter a number between 1-9 to choose a tile: ";
				cin >> tileSelection;
			}

			srand(time(NULL));
			randomNum = rand() % 9 + 1;

			// Inputs the selected tile and alternates turns
			if (currentTurn == "X" && tiles[tileSelection] != "O")
			{
				tiles[tileSelection] = "X";
				turn++;
				currentTurn = "O";
			}
			else if (currentTurn == "X" && tiles[tileSelection] != "#")
			{
				cout << "That tile is already occupied" << endl;
				system("PING 1.1.1.1 -n 1 -w 1500 >NUL");
			}
			else if (currentTurn == "O" && tiles[randomNum] != "X" && tiles[randomNum] != "O")
			{
				tiles[randomNum] = "O";
				turn++;
				currentTurn = "X";
			}
			
			win();
			drawTiles();
		}

		system("CLS");
		cout << "Welcome To Tic-Tac-Toe" << endl << endl << "It Is [" << currentTurn << "]'s turn " << endl << endl;
		drawTiles();
		cout << score << " wins!" << endl;

		cout << "Play Again? (Y/N): ";
		cin >> playAgain;
		repeat();
	}

	// 2 Players
	else if (players == 2)
	{
		while (score == "1")
		{
			system("title Tic-Tac-Toe");
			system("CLS");

			cout << "Welcome To Tic-Tac-Toe" << endl << endl << "It Is [" << currentTurn << "]'s turn " << endl << endl;
			drawTiles();

			cout << "Enter a number between 1-9 to choose a tile: ";
			cin >> tileSelection;

			// Inputs the selected tile and alternates turns
			if (currentTurn == "X" && tiles[tileSelection] != "O")
			{
				tiles[tileSelection] = "X";
				turn++;
				currentTurn = "O";
			}
			else if (currentTurn == "X" && tiles[tileSelection] == "O")
			{
				cout << "That tile is already occupied" << endl;
				system("PING 1.1.1.1 -n 1 -w 1500 >NUL");
			}
			else if (currentTurn == "O" && tiles[tileSelection] != "X")
			{
				tiles[tileSelection] = "O";\
				turn++;
				currentTurn = "X";
			}
			else if (currentTurn == "O" && tiles[tileSelection] == "X")
			{
				cout << "That tile is already occupied" << endl;
				system("PING 1.1.1.1 -n 1 -w 1500 >NUL");
			}

			
			win();
			drawTiles();
		}

		system("CLS");
		cout << "Welcome To Tic-Tac-Toe" << endl << endl << "It Is [" << currentTurn << "]'s turn " << endl << endl;
		drawTiles();
		cout << score << " wins!" << endl;

		cout << "Play Again? (Y/N): ";
		cin >> playAgain;
		repeat();
	}

}

// 0 Players
void noPlayer()
{	
	int i = 0;
	while (true)
	{
		
		system("title Tic-Tac-Toe");
		system("CLS");
		drawTiles();

		srand(time(NULL));

		// Inputs the selected tile and alternates turns
		if (currentTurn == "X" && tiles[randomNum] != "O")
		{
			randomNum = rand() % 9 + 1;
			tiles[randomNum] = "X";
			currentTurn = "O";
		}
		else if (currentTurn == "X" && tiles[randomNum] == "O")
		{
			randomNum = rand() % 9 + 1;
			currentTurn = "X";
		}
		else if (currentTurn == "O" && tiles[randomNum] != "X")
		{
			randomNum = rand() % 9 + 1;
			tiles[randomNum] = "O";
			currentTurn = "X";
		}
		else if (currentTurn == "O" && tiles[randomNum] == "X")
		{
			randomNum = rand() % 9 + 1;
			currentTurn = "O";
		}

		system("CLS");
		drawTiles();

		i++;
		if (i == 35)
		{
			tiles[1] = "#"; tiles[2] = "#"; tiles[3] = "#"; tiles[4] = "#"; tiles[5] = "#"; tiles[6] = "#"; tiles[7] = "#"; tiles[8] = "#"; tiles[9] = "#";
			i = 0;
		}
	}
}
// Displays the game board
void drawTiles()
{
	cout << tiles[1] << "  " << tiles[2] << "  " << tiles[3] << "  " << endl;
	cout << tiles[4] << "  " << tiles[5] << "  " << tiles[6] << "  " << endl;
	cout << tiles[7] << "  " << tiles[8] << "  " << tiles[9] << "  " << endl << endl;
}

// Win detection

void win()
{
	// Row 1
	if (tiles[1] == tiles[2] && tiles[2] == tiles[3] && tiles[1] == "X") score = "X";
	if (tiles[1] == tiles[2] && tiles[2] == tiles[3] && tiles[1] == "O") score = "O";
	// Row 2
	if (tiles[4] == tiles[5] && tiles[5] == tiles[6] && tiles[4] == "X") score = "X";
	if (tiles[4] == tiles[5] && tiles[5] == tiles[6] && tiles[4] == "O") score = "O";
	// Row 3
	if (tiles[7] == tiles[8] && tiles[8] == tiles[9] && tiles[7] == "X") score = "X";
	if (tiles[7] == tiles[8] && tiles[8] == tiles[9] && tiles[7] == "O") score = "O";

	// Column 1
	if (tiles[1] == tiles[4] && tiles[4] == tiles[7] && tiles[1] == "X") score = "X";
	if (tiles[1] == tiles[4] && tiles[4] == tiles[7] && tiles[1] == "O") score = "O";

	// Column 2
	if (tiles[2] == tiles[5] && tiles[5] == tiles[8] && tiles[2] == "X") score = "X";
	if (tiles[2] == tiles[5] && tiles[5] == tiles[8] && tiles[2] == "O") score = "O";

	// Column 3
	if (tiles[3] == tiles[6] && tiles[6] == tiles[9] && tiles[3] == "X") score = "X";
	if (tiles[3] == tiles[6] && tiles[6] == tiles[9] && tiles[3] == "O") score = "O";

	// Right Diagonal
	if (tiles[1] == tiles[5] && tiles[5] == tiles[9] && tiles[1] == "X") score = "X";
	if (tiles[1] == tiles[5] && tiles[5] == tiles[9] && tiles[1] == "O") score = "O";

	// Left Diagonal
	if (tiles[3] == tiles[5] && tiles[5] == tiles[7] && tiles[3] == "X") score = "X";
	if (tiles[3] == tiles[5] && tiles[5] == tiles[7] && tiles[3] == "O") score = "O";

	if (turn == 9 && score != "X" && score != "O" && players == 2) score = "Nobody";
	system("CLS");
}

// Reboot
int repeat()
{
	if (playAgain == "Y")
	{
		turn = 0;
		for (int i = 10; i > 0; i--) tiles[i] = "#";
		currentTurn = "X";
		score = "1";
		return main();
	}
	else return 0;
}