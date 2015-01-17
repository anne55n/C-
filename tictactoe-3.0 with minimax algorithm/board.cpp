// © copyright 2013 MAC 125 GROUP4 All Rights Reserved.                                             //
// Author: Anastassiya Neznanova, Wei Zheng, Denis Radoncic,Emmy Guerrero                           //
// Date: 12 DEC 2013                                                                                //
// Contact: EMAILS: anastassiya.neznanova@live.lagcc.cuny.edu, denis.radoncic@live.lagcc.cuny.edu,  //
// wei.zheng@live.lagcc.cuny.edu, emmy.guerrero@live.lagcc.cuny.edu                                 //
// Description: Tic Tac Toe Third Edition! Using virtual functions and multiple headers!            //
//              User against computer.                                                              //
//              And Player vs Player.                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>                            //iostream library
#include <stdlib.h>                           //stdlib library
#include "board.h"                        //include board header

using namespace std;

int cells[9];                              // here we declare object without extern

board::board(){                           // constructor defined outside of the declaration
    resetBoard();                         // reset the board
}
void board::receiveMove(int piece, int move){ // call receive the mode
    cells[move] = piece;
    }

void board::resetBoard(){                 //board::reset the board
    for(int i = 0;i<9;i++)
        cells[i] = blank;
}

bool board::isLegal(int n){                //to check  if the cell is occpuied (prevent user from the wrong input)
    return (n>=0 && n<9 && cells[n]==blank);
}

char board::defineChar(int n) {             //define char
    switch(n) {                             //using switch statemnt
        case playerX:                       //in X case
            return 'X';                     //it will return x
        case blank:                         // in BLANK case
            return ' ';                     // it will return space
        case playerO:                       // in case O
            return 'O';                     //it will return o
    }
}
void board::display() {                      // 

    system("cls");

    cout << "\t-- Tic Tac Toe Third Edition by Group 4 -- " << endl;                                                                                     // display message
    cout << endl;
    cout << "\t\t>-----|-----|-----<"<<endl;                                                                                       //draws the board
    cout << "\t\t|  "<<defineChar(cells[0])<<"  |  "<<defineChar(cells[1])<<"  |  "<<defineChar(cells[2])<<"  |"<<endl;            //assigns value to every cell
    cout << "\t\t|-----+-----+-----|"<<endl;                                                                                       // draw the board
    cout << "\t\t|  "<<defineChar(cells[3])<<"  |  "<<defineChar(cells[4])<<"  |  "<<defineChar(cells[5])<<"  |"<<endl;            //assigns value to every cell
    cout << "\t\t|-----+-----+-----|"<<endl;                                                                                       //draw the board
    cout << "\t\t|  "<<defineChar(cells[6])<<"  |  "<<defineChar(cells[7])<<"  |  "<<defineChar(cells[8])<<"  |"<<endl;            //assigns value to every cell
    cout << "\t\t>-----|-----|-----<"<<endl;
    cout << endl;
}
