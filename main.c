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

void displayOneRow(char s1, char s2, char s3); //display a single row

void displayHorizontalLine();                  // just draw a horizontal line.

int rowIsWinner(char s1, char s2, char s3);    // check whether this pattern is winner or not.

void displayTTTBoards();                       // display the board with numbers in it.

void playerturn(char board[3][3]);             // executes the player's turn.

void computerturn(char board[3][3]);           // executes the computer's turn.

int winner(char board[3][3]);                  // checks whether anyone win yet or not.

int boardisfull(char board[3][3]);             // check if board is full or not.

void gameplay(char board[3][3]);               // its runs the gameplay of tic tac toe(includes turns and checks win, board full).




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

    int numgame = TRUE;

    while (numgame){  // setting up the loop so that user can play again and again.
        char board[3][3]; // creating an array 3*3.
        initializeBoard(board);  // making the board by filling the 2D array with empty spaces.
        printf("LETS BEGIN!\n\n");
        gameplay(board);  // calling the function gameplay
        while(TRUE){ // one more loopt to get the right input fromt the user.
            printf("lets have another game?(Y/N)"); // asking player for another round.
            char playerwish;
            scanf(" %c", &playerwish);  // store the value in the playerwish.
            if ((playerwish == 'Y') || (playerwish == 'y')){ // if player says y.
                numgame = TRUE; // set numgame to true.
                break;   // exit the loop
            }else if ((playerwish == 'N') || (playerwish == 'n')){ // if player says n .
                numgame = FALSE; // set numgame to false.
                break; // exit the loop.
            }else{
                printf("WRONG INPUT. choose Y or N\n"); // otherwise its wrong imput.
            }
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
	if ((s1 == s2)&& (s2 == s3)&& (s1 != ' ')){ // if all three character are equal and not one is empty.
        return TRUE; // then return true and exit the function.
	}else{
	return FALSE;  // otherwise return false and exit the funciton.
    }
}


/* This function displays one of the horizontal line in a TTT board.
 PRE: the output marker is at the start of a new line.
 POST: A horizontal line has been drawn on the screen.
*/
void displayHorizontalLine()
{
    for(int i = 0;i< 10;++i){ // loop 10 times.
	printf("%c", '_'); // make a horizontal line.
    }
    printf("\n");
}



/* This function displays one row of a TTT board with squares s1, s2 and s3
 PRE: the output marker is at the start of a new line.
 POST: A row of the TTT board is drawn on the screen.
*/
void displayOneRow(char s1, char s2, char s3)
{
	printf(" %c | %c | %c\n", s1, s2, s3); // this display the each square in the row and line between them.
}

/* This function uses the two output functions display a few of TTT boards
   PRE: none.
   POST: three TTT boards have been drawn on the output stream.
*/
void displayTTTBoards(){
	printf("\nA numbered TTT board is been displayed below to help you to choose the square:\n");
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
    for (int i = 0; i < 3; ++i) { //loop from 0 to 2.
        displayOneRow(board[i][0], board[i][1], board[i][2]); // display the row.
        if (i < 2){ // if i is less than 2
            displayHorizontalLine(); // dispay the horizontal line.
        }
    }
}


/* This function implemetns theplayers turn on the board.
    PRE: 'board' is a 3x3 array containing game symbols.
    POST: Prompts the user for input, updates 'board' if the move is valid.*/
void playerturn(char board[3][3]){
    int square;
    printf("\n\nYOUR TURN\n\n");
    do{

        printf("Please enter a number associated with a square in which u wanna place 'O' between 0 to 8: ");
        scanf("%d", &square); // asking user a number between 0-8 which is associated with each square of the tic-tac-toe.
        if (square >= 0 && square <= 8){ // if its between the 0-8.
            if (board[square/3][square%3] == EMPTY){//converting the number to the row and column for the aray which is 3*3. if that square is empty.
                board[square/3][square%3] = USER; // make that square user.
                break; //break the loop.
            }else{
                printf("The square is already OCCUPIED. select another one.\n"); //else it is occupied
            }
        }else{
            printf("Enter the WRONG number.\n"); // number is not between 0-8.
        }
    }while(TRUE); // in case of else go through loop again. ask the user for the number again.
}



/*   This function implements the computer's turn on the board.
     PRE: 'board' is a 3x3 array containing game symbols.
     POST: Chooses a random valid move for the computer and updates 'board'.*/
void computerturn(char board[3][3]){

    printf("\n\nCOMPUTER's TURN\n\n");
    printf("Let my processor think!\n");
    sleep(2);   // make computer wait so it look the computer is thinking its move.

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (board[i][j] == EMPTY){
                board[i][j] = COMPUTER;  // if that square is computer.
                if (winner(board)){  //can computer win?
                    return; //  if yes  found a winning move exit the function.
                } else {
                    board[i][j] = EMPTY; // else undo the move.
                }
                                // if computer cant win in next turn can user?
                board[i][j] = USER;  // is that square is user.
                if (winner(board)){  // can user win?
                    board[i][j] = COMPUTER; //if yes block that square
                    return; // Found a blocking move exit the function.
                } else {
                    board[i][j] = EMPTY; // else undo the move
                }
            }
        }
    }

    if (board[1][1]== EMPTY){ // if center square is empty
        board[1][1]= COMPUTER; // occupy it first
        return;
    }



    do{                         // if none of the above is the condition go this.
        int row = rand() % 3;
        int col = rand() % 3;   // choose random number that divide it by 3 and get the remainder
        if (board[row][col] == EMPTY){ // if that square is empty
            board[row][col] = COMPUTER;  // fill it with computer.
            return;  // exit the function
        }
    }while(TRUE); // do it until we find the empty random square.
}



/*  Function helps to find whether or not someone win yet.
    PRE: 'board' is a 3x3 array containing game symbols.
    POST: Returns TRUE if there is a winner, FALSE otherwise.*/
int winner(char board[3][3]){
    for(int i = 0; i < 3; i++){
        if(rowIsWinner(board[0][i], board[1][i], board[2][i])){ // if any vertical pattern is formed.
            return TRUE;                   //if yes return true and exit the function.
        }else if(rowIsWinner(board[i][0], board[i][1], board[i][2])){ // if any horizontal pattern is formed.
            return TRUE;                    //if yes return true and exit the function.
        }
    }if((rowIsWinner(board[0][0],board[1][1],board[2][2]))||(rowIsWinner(board[0][2],board[1][1],board[2][0]))){ // if any daignol pattern is formed.
        return TRUE;                        //if yes return true and exit the function.
    }
    return FALSE;       //if not a singel pattern is formed return false and exit the function.
}
/*  Function helps to find out that board is full or not.
    PRE: 'board' is a 3x3 array containing game symbols.
    POST: Returns TRUE if board is full, FALSE otherwise.*/

int boardisfull(char board[3][3]){
    for(int i =0; i< 9; ++i){   // go through number 0 to 9.
        if(board[i/3][i%3] == EMPTY){ // if square i/3(column) and i%3(row) is empty.
            return FALSE;  // then return false.exit the fuction.
        }
    }
    return TRUE; // else not a single square is empty mean the table is full. return true and exit the fumction.
}


/*This function runs the gameplay.*/
void gameplay(char board[3][3]){
    while(TRUE){
        displayTTTBoards(); // display the numbered board to help the player choose right square.
        printf("\n\n");
        displayBoard(board); // display the real status of the board.

        playerturn(board);   // execute the player's turn.
        if (winner(board)){  // check if player is win or not?
            printf("\nCongratulation YOU WIN!\n");
            displayBoard(board);
            break;  // if yes break the loop.
        }else if(boardisfull(board)){  // check whether board is full.
            printf("NO ONE WIN!\n");
            break;   // if yes break the loop.
        }


        computerturn(board);  // execute the computer turn.
        if (winner(board)){  // check if computer win or not?
            printf("\nPLAYED WELL\ncomputer WIN!\n");
            displayBoard(board);
            break;  // if yes break the loop.
        }else if(boardisfull(board)){  // check if board is full.
            printf("NO ONE WIN!\n");
            break;  // if yes break the loop
        }
    }
}
