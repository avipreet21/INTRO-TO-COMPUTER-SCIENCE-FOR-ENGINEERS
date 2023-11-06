/*
 Author	 : Avipreet Singh
 Date		 : 2023 - 11-04

 File: Project1 complete

------------------------------------------------------
 Comp120 Project 1 -  A program that allows a person to play tic-tac-toe
 against the computer(if you don't know tic-tac-toe, see game rules below).

 The Rules of Tic-Tac-Toe:

  1) The game board is a three by three square grid of symbols, which is initially empty.
   The squares are numbered as in the above image.
  2) There are two players, named Player X and Player O. Player O goes first.
  3) A player moves by selecting an empty square on the board.
  4) A symbol representing that player (i.e., an X or an O) is placed on the selected square,
   and it becomes the other player's turn.
  5) The game is won if one player gets three symbols in a row (horizontally, vertically, or diagonally).
  6) The game is a draw if all the squares become occupied; yet no player has won.
-------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<ctype.h>

/* Constants for TTT game board symbols. */
#define EMPTY  ' '
#define USER 'O'
#define COMPUTER 'X'

#define TRUE 1
#define FALSE 0



/* function prototypes. */
int *CreateStructure();
void displayOneRow(char s1, char s2, char s3);
void displayHorizontalLine();
int rowIsWinner(char s1, char s2, char s3);
void displayTTTBoards();
void playerturn(char board[3][3]);
void computerturn(char board[3][3]);
int winner(char board[3][3]);
void gameplay(char board[3][3]);
int boardisfull(char board[3][3]);



/* Function to initialize the game board with empty spaces
 PRE: 'board' is a 3x3 array.
 P)ST: Initializes all elements of 'board' to EMPTY.*/
void initializeBoard(char board[3][3]) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

/* function main. */
int main() {

    printf("WELCOME TO TIC-TAC-TOE\nHere are the rules of the game:\n");

    /* puting the rules for the user */
    printf("1) The game board is a three by three square grid of symbols, which is initially empty.\n");
    printf("   The squares are numbered as in the above image.\n");
    printf("2) There are two players, named Player X and Player O. Player O goes first.\n");
    printf("3) A player moves by selecting an empty square on the board.\n");
    printf("4) A symbol representing that player (i.e., an X or an O) is placed on the selected square,\n");
    printf("   and it becomes the other player's turn.\n");
    printf("5) The game is won if one player gets three symbols in a row (horizontally, vertically, or diagonally).\n");
    printf("6) The game is a draw if all the squares become occupied; yet no player has won.\n");
    printf("7) To make a legal move, the user must select an empty square on the board by entering an integer between 0 - 8,\n");
    printf("representing the 9 board squares.\n\n");

    int numgame;

    while (numgame){
        numgame = FALSE;
        char board[3][3];
        initializeBoard(board);
        printf("LETS BEGIN!\n\n");
        gameplay(board);
        printf("lets have another game?(Y/N)");
        char playerwish;
        scanf(" %c", &playerwish);
        if ((playerwish == 'Y') || (playerwish == 'y')){
            numgame = TRUE;
        }
    }
    printf("THANK YOU!");

    return 0;
}


/* functions. */

/* This function determines if a row of tic-tac-toe squares is a winning row.
 PRE: s1, s2, and s3 are defined
 POST: returns true if a row (horizontal, vertical, or diagonal) on
		 a tic-tac-toe board containing [s1, s2, s3],
		 is a winning row, and false otherwise.
*/
int rowIsWinner(char s1, char s2, char s3)
{
	if ((s1 == s2)&& (s2 == s3)&& (s1 != ' ')){
        return TRUE;
	}else{
	return FALSE;
    }
}


/* This function displays one of the horizontal line in a TTT board.
 PRE: the output marker is at the start of a new line.
 POST: A horizontal line has been drawn on the screen.
*/
void displayHorizontalLine()
{
    int i;
    for(int i = 0;i< 10;++i){
	printf("%c", '_');
    }
    printf("\n");
}



/* This function displays one row of a TTT board with squares s1, s2 and s3
 PRE: the output marker is at the start of a new line.
 POST: A row of the TTT board is drawn on the screen.
*/
void displayOneRow(char s1, char s2, char s3)
{
	printf(" %c | %c | %c\n", s1, s2, s3);
}

/* This function uses the two output functions display a few of TTT boards
   PRE: none.
   POST: three TTT boards have been drawn on the output stream.
*/
void displayTTTBoards(){
	printf("\nA numbered TTT board in play should be drawn below:\n");
	displayOneRow('0','1','2');
	displayHorizontalLine();
	displayOneRow('3','4','5');
	displayHorizontalLine();
	displayOneRow('6','7','8');

}

/* Function to display the Tic-Tac-Toe board
    PRE 'board' is a 3x3 array containing game symbols.
    POST: Outputs the current state of the TTT board to the console.*/
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        displayOneRow(board[i][0], board[i][1], board[i][2]);
        if (i < 2) displayHorizontalLine();
    }
}

/* This function implemetns theplayers turn on the board.
    PRE: 'board' is a 3x3 array containing game symbols.
    POST: Prompts the user for input, updates 'board' if the move is valid.*/
void playerturn(char board[3][3]){
    int square;
    do{
    printf("Please enter a number between 0 to 8: ");
    scanf("%d", &square);
    if (square >= 0 && square <= 8){
        if (board[square/3][square%3] == EMPTY){
                board[square/3][square%3] = USER;
                break;
        }else{
            printf("The square is already OCCUPIED. select another one.\n");
        }
    }else{
        printf("Enter the WRONG number.\n");
    }
 }while(TRUE);
}
/*   This function implements the computer's turn on the board.
     PRE: 'board' is a 3x3 array containing game symbols.
     POST: Chooses a random valid move for the computer and updates 'board'.*/
void computerturn(char board[3][3]){
    do{
    int row = rand() % 3;
    int col = rand() % 3;
    if (board[row][col] == EMPTY){
            board[row][col] = COMPUTER;
            break;
    }
    }while(TRUE);
}
/*  Function helps to find whether or not someone win yet.
    PRE: 'board' is a 3x3 array containing game symbols.
    POST: Returns TRUE if there is a winner, FALSE otherwise.*/
int winner(char board[3][3]){
    for(int i = 0; i < 3; i++){
        if(rowIsWinner(board[0][i], board[1][i], board[2][i])){
            return TRUE;
        }else if(rowIsWinner(board[i][0], board[i][1], board[i][2])){
            return TRUE;
        }
    }if((rowIsWinner(board[0][0],board[1][1],board[2][2]))||(rowIsWinner(board[0][2],board[1][1],board[2][0]))){
        return TRUE;
    }
    return FALSE;
}
/*  Function helps to find out that board is full or not.
    PRE: 'board' is a 3x3 array containing game symbols.
    POST: Returns TRUE if board is full, FALSE otherwise.*/

int boardisfull(char board[3][3]){
    for(int i =0; i< 9; ++i){
        if(board[i/3][i%3] == EMPTY){
            return FALSE;
        }
    }
    return TRUE;
}


/*This function runs the gameplay.*/
void gameplay(char board[3][3]){
    while(TRUE){
    /* displaying the board  with numbers to help player select the square and then then real positions*/
    displayTTTBoards();
    printf("\n\n");
    displayBoard(board);

    playerturn(board);
    if (winner(board)){
        printf("Congratulation YOU WIN!\n");
        break;
    }else if(boardisfull(board)){
        printf("NO ONE WIN!\n");
        break;
    }
    computerturn(board);
    if (winner(board)){
        printf("Sorry computer WIN!\n");
        break;
    }else if(boardisfull(board)){
        printf("NO ONE WIN!\n");
        break;
    }
    }
}
