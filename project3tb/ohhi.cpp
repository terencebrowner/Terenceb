/**
 * ohhi.cpp
 *
 * EECS 183, Fall 2015
 * Project 3: 0h h1
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"
#include <cstdlib>


///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
  // count for unknowns
  int unknownCount = 0;
  //must be less than max size and even interger 
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (board[i][j] == 0) {
          unknownCount++;
      }
    }
  }

    return unknownCount;
}



///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    // your code here
    return false;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    // your code here
    return false;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int row1 = 0 ;
    int row2 = 0 ;
    for (int i = 0; i < size; i++ ){
        if ( !row_has_no_threes_of_color(board, size, i, RED) or 
             !row_has_no_threes_of_color(board, size, i, BLUE) or
             !col_has_no_threes_of_color(board, size, i, RED) or 
             !col_has_no_threes_of_color(board, size, i , BLUE)){
          return false;
        }
      }
          {
            return true;
            }
          }
        
    

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
  for (int column = 0; column < size; column++){
    if (board[row1][column] == board[row2][column]) { 
      return false; 
    }
  }
  return true ;
}

  

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
      for (int i = 0; i < size; i++){
    if (board[i][col1] == board[i][col2]) { 
      return false; 
    }
  }
  return true ;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int row1;
    int row2; 
    int col1; 
    int col2;
        if ((rows_are_different(board, size, row1, row2) == true) &&
            (cols_are_different(board, size, col1, col2) == true))
        {
            return true;
        }
    return false;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    // your code here
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    // your code here
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    // your code here
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    // your code here
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if (board_has_no_threes(board, size)== true 
      && board_has_no_duplicates(board, size) == true 
      && count_unknown_squares(board, size) == 0){
      return true ;

    }
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
 string columnLetterInput ;
 string columnLetters = "ABCDEFGH" ;
 string columnLettersLowercase = "abcdefh" ;
 string colorCharInput = "XO-" ;
  // Is the column input valid              
  for (int i = 0; i < size; i++) {
  columnLetterInput.push_back(columnLetters.at(i)) ;

  }

  for (int i = 0; i < size; i++) {
  columnLetterInput.push_back(columnLettersLowercase.at(i)) ;

  }
// if not return false
  if (!columnLetterInput.find(col_input)) {
  cout << "Cant find Letter " 
       << columnLetterInput.find(col_input) << endl ; //TURN TO RETURN FALSE
  }


// Is the row input valid
  if (row_input < 1 or row_input > size) {     
  return false ;
  }
// Is the color input valid
  if (!color_char == x or o or X or O or -) {
    return false;
    cout << " there is a color problem " << endl ;
  }
if (columnLetterInput.find(col_input) 
   && row_input > 1 && row_input < size) {
  
}
  return true ;
}



bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // your code here
    return false;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
