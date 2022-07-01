/* ===========================================================================
COMP-1410 Assignment 2
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//----------------------------------------------- QUESTION 1 --------------------------------------------------//

// print_board(board) prints the game board before and after the player's turn with 'X' or 'O' wherever
// the player inputted their piece
void print_board(char board[6][7])
{
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            printf(" %c |\t", board[row][col]);

            if (col == 6)
            {
                printf("\n");
                for (int i = 0; i < 7; i++)
                    printf("---\t");
                printf("\n");
            }
        }       
    }
    printf("\n");
}

// make_move(board, column, player) updates the board following a move
//   by the given player in the given column; returns false if the move
//   was illegal because the column was full
// requires: 0 <= column < 7
//           player is either 'X' or 'O'
bool make_move(char board[6][7], int column, char player)
{
    int row = 0;

    if (row == 0 && (board[row][column] == 'X' || board[row][column] == 'O')) // checks to see if an illegal move was made
        printf("Illegal move. Select another column\n");

    while (board[row][column] != 'X' && board[row][column] != 'O') // Goes down each column of the board (kind of like in real life when you drop a piece xD)
    {      
        if (board[row+1][column] == 'X' || board[row+1][column] == 'O') // Checks to see if the next level is occupied
        {
            board[row][column] = player;
            break;
        }

        else
            row++; // increments row which brings you lower down in the column 

        if (row == 5) // if the column had no pieces
        {
            board[row][column] = player;            
            break;  
        }
    } 
}

// check_win(board) returns true if the given player has 4 connected
//   pieces on the board
bool check_win(char board[6][7], char player)
{
    int in_a_row = 0;
    for (int row = 0; row < 6; row++) // checks for 4 in a row horizontally
    {
        for (int col = 1; col < 7; col++)
        {
            if ((board[row][col-1] != 'X' && board[row][col-1] != 'O') || // 
                (board[row][col] != 'X' && board[row][col] != 'O'))
                in_a_row = 0;
            
            else if (board[row][col-1] == board[row][col]) // 2 consecutive pieces in a row 
                in_a_row++;
            
            else
                in_a_row = 0;
            
            if (in_a_row == 3) // 4 in a row
            {
                printf("Player %c wins!\n", player);
                return true;
            }
        }
    }

    int in_a_col = 0;
    for (int col = 0; col < 7; col++) // checks for 4 in a row vertically
    {
        for (int row = 1; row < 6; row++)
        {
            if ((board[row-1][col] != 'X' && board[row-1][col] != 'O') || 
                (board[row][col] != 'X' && board[row][col] != 'O'))
                in_a_col = 0;
            
            else if (board[row-1][col] == board[row][col])
                in_a_col++;
            
            else
                in_a_col = 0;
            
            if (in_a_col == 3)
            {
                printf("Player %c wins!\n", player);
                return true;
            }            
        }
    }

    int in_a_right_diagonal = 0;
    int i = 1;

    for (int row = 0; row < 3; row++) // checks 4 in a row diagonally to the right
    {
        for (int col = 0; col < 4; col++)
        {
            while (i <= 3)
            {
                if ((board[row][col] == board[row+i][col+i]) && (board[row][col] != ' ' || board[row+i][col+i] != ' ')) // checks value of adjecent diagonal piece
                {
                    in_a_right_diagonal++;
                    i++;
                }

                else
                {
                    in_a_right_diagonal = 0;
                    break;
                }                                
            }

            if (i == 4)
            {
                i = 0;
                
                if (in_a_right_diagonal == 3) // 4 in a row diagonally
                {
                    printf("Player %c wins!\n", player);
                    return true;
                }

                else
                    in_a_right_diagonal = 0;                
            }        
        }
    }

    i = 1;
    int in_a_left_diagonal = 0;

    for (int row = 0; row < 3; row++) // checks 4 in a row diagonally to the left
    {
        for (int col = 6; col >= 3; col--)
        {
            while (i <= 3)
            {
                if ((board[row][col] == board[row+i][col-i]) && (board[row][col] != ' ' || board[row+i][col-i] != ' '))
                {
                    in_a_left_diagonal++;
                    i++;
                }

                else
                {
                    in_a_left_diagonal = 0;
                    break;
                }                                
            }

            if (i == 4)
            {
                i = 0;
                
                if (in_a_left_diagonal == 3)
                {
                    printf("Player %c wins!\n", player);
                    return true;
                }

                else
                    in_a_left_diagonal = 0;                
            }        
        }
    }   
    return false;
}

int main(void)
{

    // TEST 1 // 

    char game_board1[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', 'X', ' ', ' ', ' '},
                              {' ', ' ', ' ', 'X', ' ', ' ', ' '},
                              {' ', ' ', ' ', 'X', ' ', ' ', ' '},
                              {' ', ' ', ' ', 'X', ' ', ' ', ' '},
                              {' ', ' ', ' ', 'X', ' ', ' ', ' '}};

    assert(check_win(game_board1, 'X') == true);

    // TEST 2 //

    char game_board2[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', 'O', ' ', ' '},
                              {' ', ' ', ' ', 'O', ' ', ' ', ' '},
                              {' ', ' ', 'O', ' ', ' ', ' ', ' '},
                              {' ', 'O', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board2, 'O') == true);

    // TEST 3 //

    char game_board3[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {'X', ' ', ' ', ' ', ' ', ' ', ' '},
                              {'X', 'X', 'X', ' ', ' ', ' ', ' '},
                              {'X', 'X', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', 'X', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board3, 'X') == false); 

    // TEST 4 //   

    char game_board4[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', 'X', 'X', 'X', 'X', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board4, 'X') == true);

    // TEST 5 //

    char game_board5[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'O', 'O', 'O', 'O', 'O', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board5, 'O') == true);

    // TEST 6 //

    char game_board6[6][7] = {{' ', 'X', 'X', 'X', 'X', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board6, 'X') == true); 

    // TEST 7 //

    char game_board7[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'O', 'X', 'O', 'X', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board7, 'O') == false);

    // TEST 8 //

    char game_board8[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'X', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'O', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'X', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'O', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    assert(check_win(game_board8, 'X') == false);    

    printf("All tests passed successfully\n");

    // ACTUAL GAME //

    printf("Welcome to Connect 4!\n");
    char game_board[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    
    
    print_board(game_board);
    int player = 'X';
    int colSelection;
    int numberOfTurns = 0;

    while (1)
    {
        printf("Enter a column you want to input your piece: ");
        if (scanf("%d", &colSelection) != 1 || (colSelection > 7 || colSelection < 1))
            break;
        
        make_move(game_board, colSelection - 1, player);
        numberOfTurns++;
        print_board(game_board);
        
        if (player == 'X')
        {
            if (check_win(game_board, player) == true)
                break;
            player = 'O';
        }

        else
        {
            if (check_win(game_board, player) == true)
                break; 
            player = 'X';           
        }

        if (numberOfTurns == 42)
        {
            printf("It's a tie");
            break;
        }
    }
    return 0;
}