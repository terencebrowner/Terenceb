/**
 * test.cpp
 *
 * EECS 183, Fall 2015
 * Project 3: 0h h1 Test Suite
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_rows_are_different();
void test_cols_are_different(); 
void check_valid_input() ;

// declare more test functions here

int main() {
    test_count_unknown_squares();
    test_rows_are_different() ;

    // add calls to test functions here

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

     // test case 2
    string test_board_2[] = {"-OX---",
                             "OO--X-",
                             "X-----",
                             "-O--OO",
                             "X-----",
                             "------"};

         int size_2 = 6;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;                        


    // add more tests here
}
void test_rows_are_different(){
 int board[MAX_SIZE][MAX_SIZE];
 int row1 = 0 ;
 int row2 = 1 ;


    // test case 1
    string test_board_3[] = {"OOOX",
                             "OO--",
                             "XX--",
                             "OO--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_3, size_1);
    cout << rows_are_different(board, size_1, row1, row2) << endl;
cout << "hello world" << endl;

}
 



