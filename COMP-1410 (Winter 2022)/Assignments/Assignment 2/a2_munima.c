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

    if (row == 0 && (board[row][column] == 'X' || board[row][column] == 'O'))
    {
        printf("Illegal move. Select another column\n");
        return false;
    } // checks to see if an illegal move was made


    while (board[row][column] != 'X' && board[row][column] != 'O') // Goes down each column of the board (kind of like in real life when you drop a piece xD)
    {      
        if (board[row+1][column] == 'X' || board[row+1][column] == 'O') // Checks to see if the next level is occupied
        {
            board[row][column] = player;
            return true;
        }

        else
            row++; // increments row which brings you lower down in the column 

        if (row == 5) // if the column had no pieces
        {
            board[row][column] = player;            
            return true;  
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

//----------------------------------------------- QUESTION 2 --------------------------------------------------//

// first_capital(str, n) returns the first capital letter in str;
//   returns 0 if str contains no capital letters
// requires: str is a string of length n
//           str contains only lower-case and upper-case letters
//           all lower-case letters appear before upper-case letters
char first_capital(const char str[], int n)
{
    int begin = 0;
    int end = n - 1;
    int mid;

    if (n == 1 && (str[0] >= 65 && str[0] <= 90))
        return str[0];
        

    while (begin <= end) // BINARY SEARCH FTW
    {
        mid = (begin+end) / 2;

        if (mid == 0 && (str[mid] >= 65 && str[mid] <= 90)) // When there's only one element in the char array and it's a capital letter
            return str[mid];

        if (str[mid] >= 65 && str[mid] <= 90) // checks whether the middle element is a capital letter or not
        {
            if (str[mid - 1] >= 97) // if the preceding element is a lower case letter
                return str[mid];
            else
                end = mid - 1; // If the above statement isn't true, then the first capital letter has to come way before
        }

        else
        {
            if (str[mid + 1] >= 65 && str[mid] <= 90) // If the succeeding element is a capital letter
                return str[mid + 1]; // it has to be the first capital letter if the middle element is a lowercase letter
            else
                begin = mid + 1; // if the above statement is false, then the first captial has to come way after
        }
    }

    return 0;
}

//----------------------------------------------- QUESTION 3 --------------------------------------------------//

// deepest_substring(str, out) updates out to be the deepest substring of
//   str; the first is used if multiple possibilities exist
// requires:
//   str is a string with balanced parenthesis
//   out points to enough memory to store the deepest substring of str
void deepest_substring(const char str[], char out[])
{
    // two variables below to find the depth of the left bracket in the string
    int currentLeftBracket = 0; 
    int deepestLeftBracket = 0; 
    int position = 0; // will be used to get the index of the deepest left bracker
    int hasBracket = 0;
    
    for (int i = 0; i < strlen(str); i++) // iterates over the original string 
    {
        if (str[i] == '(')
        {
            hasBracket = 1;
            currentLeftBracket++; // 1 level deeper
            if (currentLeftBracket > deepestLeftBracket) // if the current level is deeper...
            {
                deepestLeftBracket = currentLeftBracket;
                position = i; // index of that bracket is set
            }
        }

        else if (str[i] == ')') // got out of current depth
            currentLeftBracket--;

    }

    int strLength = 0;
    if (hasBracket == 1)
    {
        int k = 1;
        while(*(str+position+k) != ')') // gets length of deepest substring starting at the first character after the deepest left bracket
        {
            strLength++; k++;
        }

        strncpy(out, str+position+1, strLength); // copies deepest substring
    }

    else
    {
        int k = 0;
        while(*(str+position+k) != ')') // gets length of deepest substring starting at the first character after the deepest left bracket
        {
            strLength++; k++;
        }

        strncpy(out, str+position, strLength); // copies deepest substring
    }
 
    out[strLength] = '\0'; // adds null character as last element to make it a string
}

int main(void)
{
//-------------------------------------------- QUESTION 1 TESTS -------------------------------------------//    
    
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

    printf("All question 1 tests passed successfully!\n");

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
        do
        {
            printf("Enter a column you want to input your piece: ");
            if (scanf("%d", &colSelection) != 1 || (colSelection > 7 || colSelection < 1))
                break;        
        } while (make_move(game_board, colSelection - 1, player) == false);
        
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

//-------------------------------------------- QUESTION 2 TESTS -------------------------------------------//  

    char str_q2[10] = "abZNJFKSF";
    assert(first_capital(str_q2, 9) == 'Z');

    char str2_q2[9] = "sfsdFSFA";
    assert(first_capital(str2_q2, 8) == 'F');

    char str3_q2[2] = "a";
    assert(first_capital(str3_q2, 1) == 0);

    char str4_q2[2] = "H";
    assert(first_capital(str4_q2, 1) == 'H');

    char str5_q2[7] = "DKSDAW";
    assert(first_capital(str5_q2, 6) == 'D');

    printf("All question 2 tests passed successfully!\n");

//-------------------------------------------- QUESTION 3 TESTS -------------------------------------------//

    char str4_q3[15] = "(Hello(World))";
    char out4_q3[7];
    deepest_substring(str4_q3, out4_q3);
    assert(strcmp(out4_q3, "World") == 0);

    char str5_q3[10] = "(Welcome)";
    char out5_q3[9];
    deepest_substring(str5_q3, out5_q3);
    assert(strcmp(out5_q3, "Welcome") == 0);

    char str1_q3[12] = "a+((b+c)+d)";
    char out1_q3[5];
    deepest_substring(str1_q3, out1_q3);
    assert(strcmp(out1_q3, "b+c") == 0);

    char str6_q3[22] = "(abc((de(f))hi(jkl)))";
    char out6_q3[2];
    deepest_substring(str6_q3, out6_q3);
    assert(strcmp(out6_q3, "f") == 0);

    char str7_q3[22] = "(abc((def)hi(jk(l))))";
    char out7_q3[2];
    deepest_substring(str7_q3, out7_q3);
    assert(strcmp(out7_q3, "l") == 0);

    char str2_q3[5] = "(())";
    char out2_q3[1];
    deepest_substring(str2_q3, out2_q3);
    assert(strcmp(out2_q3, "") == 0); 

    char str3_q3[7] = "(ss())";
    char out3_q3[1];
    deepest_substring(str3_q3, out3_q3);
    assert(strcmp(out3_q3, "") == 0);

    char str8_q3[10] = "Python>>>";
    char out8_q3[10];
    deepest_substring(str8_q3, out8_q3);
    assert(strcmp(out8_q3, "Python>>>") == 0);

    printf("All question 3 tests passed successfully!\n");
    return 0;
}