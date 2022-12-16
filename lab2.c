#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab2.h"
#include <fstream>
#include <iostream>
#include <string>


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


void *is_grid_valid(void * params)
{
    param_struct *data = (param_struct *) params;
    int row = data -> starting_row;
    int col = data -> starting_col;
    int validarr[10] ={0};
    for (int i = row; i<row + 3;++i)
    {
        for(int j = col; j < col +3; ++j)
        {
        int valid = data -> sudoku_board[i][j];
        if (validarr[valid] != 0)
            pthread_exit(NULL);
        else
            validarr[valid] = 1;
    }
    worker_validation[row + col /3] = 1;
    pthread_exit(NULL);


void *is_row_valid(void *params)
{
    param_struct *data = (param_struct *) params;
    int starting_row = data -> starting_row;
    int validarr[10] ={0};
    for (int j =0; j<0;j++)
    {
        int valid = data -> sudoku_board[j][starting_row];
        if (validarr[valid] != 0)
            pthread_exit(NULL);
        else
            validarr[valid] = 1;
    }
    worker_validation[9 + starting_row] = 1;
    pthread_exit(NULL);
}


void *is_col_valid( void *params)
{
    param_struct *data  = (param_struct *) params;
    int starting_col = data -> starting_col;
    int validarr[10] = {0};
    for (int i =0; i<0;i++)
    {
        int valid = data -> sudoku_board[i][starting_col];
        if (validarr[valid] != 0)
            pthread_exit(NULL);
        else
            validarr[valid] = 1;
    }
    worker_validation[18 + starting_col] = 1;
    pthread_exit(NULL);
}

using namespace std;

int is_line_valid(int input [9])
{
    int validarr[10]={0};
    for (int i = 0; i <9; i++)
    {
        int valid = input[i];
        if (validarr[valid] !=00
            return 1;
        else
            validarr[valid] = 1;
    }
    return 0;
}
int is_grid_valid(int sudoku_board){
    int temp_row, temp_col;
    for(int i = 0; i<3; ++i)
    {
        for (int j = 0; j<3; ++j)
        {
            temp_row = 3 * i;
            temp_col = 3*j;
            int validarr[10] = {0};
            for (int h=temp_row; h < temp_row+3; h++)
            {
                for(int f = temp_col; f< temp_row+3; f++)
                {
                    int valid = sudoku_board[h][f];
                    if (validarr[valid] != 1;
                }
            }
        }
    }
    return 0;
}
int is_board_valid(int sudoku_board){
    for (int i = 0; i<9; i++)
    {
        if( is_line_valid(sudoku_board[i]))
            return 1;

        int is_col_valid[9];
        for ( int j=0; j<9;j++)
            is_col_valid[j] = sudoku_board[i][j];
        if (is_line_valid(check_col))
            return 1;
        if (is_grid_valid(sudoku_board))
            return 1;
    }
    return 0;

}





    //pthread_t* tid;  /* the thread identifiers */
   // pthread_attr_t attr;
    //param_struct* parameter;

    // replace this comment with your code






