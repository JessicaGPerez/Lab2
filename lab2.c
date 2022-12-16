#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab2.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int** read_board_from_file(/*char* filename*/){
    //FILE *fp = NULL;
    string file = "valid_board.txt";
    ifstream inFile;
    inFile.open(file);

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


int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;

    // replace this comment with your code

}




