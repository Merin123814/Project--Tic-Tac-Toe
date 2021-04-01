// Preprocessor ----------------------------------------------------------------------------

// Libraries ---------------------------------------------------------------------------------
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>

#define rowValue 3
#define colValue 3

char com, row, col;
typedef struct game
{
	char board[rowValue][colValue];
	int turns;
	char count;
	int win;

}toe_t;
toe_t ttt687;

// Functions ---------------------------------------------------------------------------------
// ---Game Initialization ---
/*--- initGame ------------------------------------------------------------
Desc:		Initializes the game.
Input: 		Type and purpose of input arguments
Returns:	Type and purpose of returning argument
------------------------------------------------------------------------------*/
void initGame(void)
{
	ttt687.turns = 0;
	ttt687.count = 0;
	ttt687.win = 0;
	for (row = 0; row < rowValue; row++)
	{
		for (col = 0; col < colValue; col++)
		{
			ttt687.board[row][col] = ' ';
		}

	}


}


// --- Board Displaying ---
/*---Display  ------------------------------------------------------------
Desc:		Displays the gameboard.
Input: 		Type and purpose of input arguments
Returns:	Type and purpose of returning argument
------------------------------------------------------------------------------*/
void display(void)
{
	printf("\033[;H");
	printf("\n\r  *** TIC TAC TOE ***\n\n\r");
	printf("         0    1    2   Column\n\r");
	printf("Row");
	printf("\n0\t   %c|  %c  |%c\n\r", ttt687.board[0][0], ttt687.board[0][1], ttt687.board[0][2]);
	printf("\t-------------\n\r");
	printf("1\t   %c|  %c  |%c\n\r", ttt687.board[1][0], ttt687.board[1][1], ttt687.board[1][2]);
	printf("\t-------------\n\r");
	printf("2\t   %c|  %c  |%c\n\r", ttt687.board[2][0], ttt687.board[2][1], ttt687.board[2][2]);

}	// eo display::




// --- Function Header ---
/*--- functionName ------------------------------------------------------------
Desc:		Checks for the winning condition.
Input: 		Type and purpose of input arguments
Returns:	Type and purpose of returning argument
------------------------------------------------------------------------------*/
int winCheck(void)
{
	if (
		((ttt687.board[0][0] & ttt687.board[0][1] & ttt687.board[0][2]) == 'X') ||
		((ttt687.board[0][0] & ttt687.board[0][1] & ttt687.board[0][2]) == 'O') ||
		((ttt687.board[1][0] & ttt687.board[1][1] & ttt687.board[1][2]) == 'X') ||
		((ttt687.board[1][0] & ttt687.board[1][1] & ttt687.board[1][2]) == 'O') ||
		((ttt687.board[2][0] & ttt687.board[2][1] & ttt687.board[2][2]) == 'X') ||
		((ttt687.board[2][0] & ttt687.board[2][1] & ttt687.board[2][2]) == 'O') ||
		((ttt687.board[0][0] & ttt687.board[1][0] & ttt687.board[2][0]) == 'X') ||
		((ttt687.board[0][0] & ttt687.board[1][0] & ttt687.board[2][0]) == 'O') ||
		((ttt687.board[0][1] & ttt687.board[1][1] & ttt687.board[2][1]) == 'X') ||
		((ttt687.board[0][1] & ttt687.board[1][1] & ttt687.board[2][1]) == 'O') ||
		((ttt687.board[0][2] & ttt687.board[1][2] & ttt687.board[2][2]) == 'X') ||
		((ttt687.board[0][2] & ttt687.board[1][2] & ttt687.board[2][2]) == 'O') ||
		((ttt687.board[0][0] & ttt687.board[1][1] & ttt687.board[2][2]) == 'X') ||
		((ttt687.board[0][0] & ttt687.board[1][1] & ttt687.board[2][2]) == 'O') ||
		((ttt687.board[0][2] & ttt687.board[1][1] & ttt687.board[2][0]) == 'X') ||
		((ttt687.board[0][2] & ttt687.board[1][1] & ttt687.board[2][0]) == 'O'))
	{
		ttt687.win = 1;
	}
	else
	{
		ttt687.win = 0;
	}
	return ttt687.win;
}  // eo winCheck


/*--- MAIN FUNCTION --------------------------------------------------------------
----------------------------------------------------------------------------------*/

int main(void)
{
	initGame();
	system("color b1");
	printf("\n\r Do you want to play >> Y/N");
	com = _getch();
	while ((com == 'Y') || (com == 'y'))
	{

		winCheck();
		if (ttt687.win == 1)
		{
			printf("Its a win");
			com = '*';
			printf("\n\rpress enter to exit game");
		}
		if (ttt687.count == 9)
		{
			printf("Its a draw");
			com = '*';
			printf("\n\rpress enter to exit game");
		}


		if ((ttt687.turns % 2) == 0)
		{
			display();
			printf("Enter desired row and column for X\n\r");
			printf("Enter row value\n\r");
			row = _getch();
			printf("%c\n\r", row);
			printf("Enter col value\n\r");
			col = _getch();
			printf("%c\n\r", col);
			row = row - '0';
			col = col - '0';
			if (ttt687.board[row][col] == ' ')
			{
				ttt687.board[row][col] = 'X';
				ttt687.turns = ttt687.turns + 1;
			}
		}
		else
		{
			display();
			printf("Enter desired row and column for O\n\r");
			printf("Enter row value\n\r");
			row = _getch();
			printf("%c\n\r", row);
			printf("Enter col value\n\r");
			col = _getch();
			printf("%c\n\r", col);
			row = row - '0';
			col = col - '0';
			if (ttt687.board[row][col] == ' ')
			{
				ttt687.board[row][col] = 'O';
				ttt687.turns = ttt687.turns + 1;
			}
		}
		ttt687.count++;

	}


}
