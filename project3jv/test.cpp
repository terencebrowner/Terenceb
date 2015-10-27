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
void test_row_has_no_threes_of_color();

// declare more test functions here

int main() {
    test_row_has_no_threes_of_color();

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

    // add more tests here
}
void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"OOOX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1,0,2) << endl;


void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"OOOX",
                             "XXX0",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1,1,1) << endl;
}



// define more test functions here

// this is also a test
