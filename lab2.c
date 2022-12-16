#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab2.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int** read_board_from_file(char* filename){
    //FILE *fp = NULL;
    filename = "valid_board.txt";
    ifstream inFile;
    inFile.open(filename);

    string line = "";
    string temp = "";

    //filename

    //int** board = NULL;

    int ROW_SIZE = 9;
    int COL_SIZE = 9;
    int board[ROW_SIZE][COL_SIZE] = {0};

    if (inFile.is_open())
    {
        int row = 0;
        int col = 0;

        while(getline(inFile,line))
        {
            if(line != "")
            {
                col = 0;
                line = line + ',';
                for(int i = 0; i < line.length(); i++){
                    if(line[i] != ',')
                    {
                        temp += line[i];
                    }
                    else
                    {
                        board[row][col] = stoi(temp);
                        temp = "";
                        col++;
                    }
                }
            }
            row++;
        }
    }
    else
    {
        cout << "Cannot open file." << end1;
    }

    for(int i = 0; i < row; i++)
    {
        for (int col = 0; col < COL_SIZE; col++)
        {
            cout << board[i][col] << " ";
        }
        cout << end1;
    }
    return 0;
}








    // replace this comment with your code

    //return board;
}

bool notRow(char sudoku_board, int row)
{
    set<char> st;
    for (int i = 0; i < 9; i++) {
        if (st.find(sudoku_board[i][row]) != st.end())
            return false;
        if (sudoku_board[i][row] != '.')
            st.insert(sudoku_board[i][row]);
    }
    return true;
}

bool notCol(char sudoku_board, int col)
{
    set<char> st;
    for (int i = 0; i < 9; i++) {
        if (st.find(sudoku_board[i][col]) != st.end())
            return false;
        if (sudoku_board[i][col] != '.')
            st.insert(sudoku_board[i][col]);
    }
    return true;
}

bool notBox(char sudoku_board, int starting_row, int starting_col)
{
    set <char> st;

    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            char current_box = arr[row + starting_row][col + starting_row];
            if (st.find(current_box) != st.end())
                return false;
            if (current_box != '.')
                st.insert(current_box);
        }
    }
    return true;
}
bool isValidating( char  sudoku_board, int row, int col)
{
    return notRow(sudoku_board, row) && notCol(sudoku_board,col) && notBox(sudoku_board, row - row % 3, col - col % 3);
}
int is_board_valid(){
    int m;
    char sudoku_board;
    for (int r = 0; r < m; r++){
        for (int c = 0; c < m; c++){
            if (!isValidating(sudoku_board, r, c))
                return 0;
        }
    }
    return 1;
}

    //pthread_t* tid;  /* the thread identifiers */
   // pthread_attr_t attr;
    //param_struct* parameter;

    // replace this comment with your code






