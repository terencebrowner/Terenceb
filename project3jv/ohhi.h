/***
 * ohhi.h
 *
 * EECS 183, Fall 2015
 * Project 3: 0h h1
 *
 * 0h h1 (http://www.0hh1.com/) is a sudoku-like logic puzzle.
 * This program allows a user to play and solve an 0h h1 board.
 * This file declares all the functions in ohhi.cpp.
 */

#ifndef _OHHI_H_
#define _OHHI_H_

#include <string>
#include "utility.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// STUDENT-IMPLEMENTED UTILITY FUNCTIONS                            //
// -------------------------------------                            //
// You will need to implemente these.                               //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: Nothing.
 * Effects : Returns number of squares in board that are UNKNOWN.
 * Used In : solve(), gameplay functions
 */
int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size);


//////////////////////////////////////////////////////////////////////
// VALIDITY CHECKS                                                  //
// ---------------                                                  //
// You will need to implemente these.                               //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row && row < size.
 * Modifies: Nothing.
 * Effects : Returns true if and only if the row at index row does not contain
 *           three or more consecutive tiles of the specified color.
 * Used In : board_has_no_threes()
 */
bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size.
 * Modifies: Nothing.
 * Effects : Returns true if and only if the column at index col does not
 *           contain three or more consecutive tiles of the specified color.
 * Used In : board_has_no_threes()
 */
bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: Nothing.
 * Effects : Returns true if and only if no row or column of the board contains
 *           three or more consecutive red or blue squares.
 * Used In : board_is_valid()
 */
bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row1 && row1 < size, 0 <= row2 && row2 < size.
 * Modifies: Nothing.
 * Effects : Returns true if either
 *           * row1 or row2 contains an UNKNOWN, or
 *           * row1 and row2 have different squares.
 *
 *           Example: rows_are_different should return false for rows 0 and 1:
 *                    XOOX
 *                    XOOX
 *                    ----
 *                    ----
 *
 *           Example: rows_are_different should return true for rows 0 and 1:
 *                    XOOX
 *                    XXOO
 *                    ----
 *                    ----
 *
 *           Example: rows_are_different should return true for rows 0 and 1:
 *                    XO-X
 *                    XOOX
 *                    ----
 *                    ----
 *
 *           Example: rows_are_different should return true for rows 3 and 4:
 *                    XO-X
 *                    XOOX
 *                    ----
 *                    ----
 *
 *           Example: rows_are_different should return true for rows 0 and 1:
 *                    XO-X
 *                    XO-X
 *                    ----
 *                    ----
 *
 * Used In : board_has_no_duplicates()
 */
bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col1 && col1 < size, 0 <= col2 && col2 < size.
 * Modifies: Nothing.
 * Effects : Returns true if either
 *           * col1 or col2 contains an UNKNOWN, or
 *           * col1 and col2 have different squares.
 *
 *           Example: columns_are_different should return false for columns 0
 *                    and 1:
 *                    XX--
 *                    OO--
 *                    OO--
 *                    XX--
 *
 *           Example: columns_are_different should return true for columns 0
 *                    and 1:
 *                    XX--
 *                    OX--
 *                    OO--
 *                    XO--
 *
 *           Example: columns_are_different should return true for columns 0
 *                    and 1:
 *                    XX--
 *                    OO--
 *                    -O--
 *                    XX--
 *
 *           Example: columns_are_different should return true for columns 3
 *                    and 4:
 *                    XX--
 *                    OO--
 *                    -O--
 *                    XX--
 *
 *           Example: columns_are_different should return true for columns 0
 *                    and 1:
 *                    XX--
 *                    OO--
 *                    ----
 *                    XX--
 *
 * Used In : board_has_no_duplicates()
 */
bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: Nothing.
 * Effects : Returns true if and only if no two rows or columns of the board
 *           are identical.
 * Used In : board_is_valid()
 */
bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size);


//////////////////////////////////////////////////////////////////////
// SOLVING FUNCTIONS                                                //
// -----------------                                                //
// You will need to implemente these.                               //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row && row < size. The board must be valid.
 * Modifies: board, cout
 * Effects : This function writes the opposite color in UNKNOWN squares in row:
 *           * on both ends of two consecutive tiles (example 1) in row, and
 *           * in the middle between two tiles of the same color in row
 *             (example 2)
 *           If announce is true, prints out a message for each square
 *           that is modified.
 *
 *           Example:  ----              ----
 *                     XX--   becomes    XXO-
 *                     -XX-              OXXO
 *                     --X-              --X-
 *
 *           Example:  ----              ----
 *                     X-X-   becomes    XOX-
 *                     ----              ----
 *                     --X-              --X-
 * Note    : You MUST use mark_square_as() to assign a color to a square.
 *           It will take care of printing out the appropriate message.
 * Used In : solve()
 */
void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size. The board must be valid.
 * Modifies: board, cout
 * Effects : This function writes the opposite color in UNKNOWN squares in col:
 *           * on both ends of two consecutive tiles (example 1) in col, and
 *           * in the middle between two tiles of the same color in col
 *             (example 2)
 *           If announce is true, prints out a message for each square
 *           that is modified.
 *
 *           Example:  ----              -O--
 *                     XX--   becomes    XXO-
 *                     -XX-              -XX-
 *                     --X-              -OX-
 *
 *           Example:  ----              ----
 *                     X-X-   becomes    X-X-
 *                     ----              --O-
 *                     --X-              --X-
 * Note    : You MUST use mark_square_as() to assign a color to a square.
 *           It will take care of printing out the appropriate message.
 * Used In : solve()
 */
void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row && row < size. The board must be valid.
 * Modifies: board, cout
 * Effects : If either BLUE or RED tiles occupy exactly half the tiles
 *           of row, this function will color all remaining UNKNOWN
 *           tiles the opposite color.
 *           If announce is true, prints out a message for each square
 *           that is modified.
 *
 *           Example:  ----              ----
 *                     XX--   becomes    XXOO
 *                     -XX-              OXXO
 *                     --X-              --X-
 * Note    : You MUST use mark_square_as() to assign a color to a square.
 *           It will take care of printing out the appropriate message.
 * Used In : solve()
 */
void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size. The board must be valid.
 * Modifies: board, cout
 * Effects : If either BLUE or RED tiles occupy exactly half the tiles
 *           of col, this function will color all remaining UNKNOWN
 *           tiles the opposite color.
 *           If announce is true, prints out a message for each square
 *           that is modified.
 *
 *           Example:  ----              -OO-
 *                     XX--   becomes    XXO-
 *                     -XX-              -XX-
 *                     --X-              -OX-
 * Note    : You MUST use mark_square_as() to assign a color to a square.
 *           It will take care of printing out the appropriate message.
 * Used In : solve()
 */
void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce);


//////////////////////////////////////////////////////////////////////
// GAMEPLAY FUNCTIONS                                               //
// ------------------                                               //
// You will need to implemente these.                               //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: Nothing.
 * Effects : Returns true if and only if the board has been solved,
 *           i.e. all squares are RED or BLUE and the board does not
 *           violate any of the rules of 0hh1.
 * Used In : play_board()
 */
bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: Nothing.
 * Modifies: cout, row, col
 * Effects : Checks if the input was valid: row_input is between 1 and
 *           size inclusive, col_input is between A and (A + size - 1)
 *           inclusive, and color_char is one of (X, O, x, o, -).
 *           If input is invalid, prints an error message and returns
 *           false.
 *           Otherwise translates row_input and col_input to 0-indexed
 *           row and column numbers, assigns them to row and col, and
 *           returns true.
 * Used In : make_move()
 * Note    : The following message is printed as appropriate:
 *           "Sorry, that's not a valid input."
 */
bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row && row < size && 0 <= col && col < size.
 * Modifies: cout
 * Effects : Returns true if and only if the specified square was not
 *           set in the original board, and placing the given color in
 *           the given square of the current board does not create an
 *           invalid board. Prints messages informing the user that
 *           original squares cannot be changed or that a move violates
 *           a rule, as appropriate.
 * Used In : make_move()
 * Note    : The following messages are printed as appropriate:
 *           "Sorry, original squares cannot be changed."
 *           "Sorry, that move violates a rule."
 */
bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color);


//////////////////////////////////////////////////////////////////////
// S'MORE FUNCTIONS                                                 //
// ----------------                                                 //
// You will need to implemente these for the S'more version of the  //
// project.                                                         //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size. The board must be valid.
 * Modifies: board, cout
 * Effects : Attempts to make progress on a row through proof-by-contradiction.
 *           If the row has (size / 2) - 1 of one color, this function tries to
 *           assign that color to each UNKNOWN square to see if rules will be
 *           violated. If so, that square MUST be the opposite color.
 *           If a square is written and announce is true, prints out a message
 *           note indicating how the square is written.
 * Note    : You MUST use mark_square_as() to assign a color to a square.
 *           It will take care of printing out the appropriate message.
 * Used In : main()
 */
void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size. The board must be valid.
 * Modifies: board, cout
 * Effects : Attempts to make progress on a row through proof-by-contradiction.
 *           If the column has (size / 2) - 1 of one color, this function tries
 *           to assign that color to each UNKNOWN square to see if rules will
 *           be violated. If so, that square MUST be the opposite color.
 *           If a square is written and announce is true, prints out a message
 *           note indicating how the square is written.
 * Note    : You MUST use mark_square_as() to assign a color to a square.
 *           It will take care of printing out the appropriate message.
 * Used In : main()
 */
void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce);


#endif // _OHHI_H_
