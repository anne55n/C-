// © copyright 2013 MAC 125 GROUP4 All Rights Reserved.                                             //
// Author: Anastassiya Neznanova, Wei Zheng, Denis Radoncic,Emmy Guerrero                           //
// Date: 12 DEC 2013                                                                                //
// Contact: EMAILS: anastassiya.neznanova@live.lagcc.cuny.edu, denis.radoncic@live.lagcc.cuny.edu,  //
// wei.zheng@live.lagcc.cuny.edu, emmy.guerrero@live.lagcc.cuny.edu                                 //
// Description: Tic Tac Toe Third Edition! Using virtual functions and multiple headers!            //
//              User against computer.                                                              //
//              And Player vs Player.                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef BOARD_H
#define BOARD_H

#include "global.h"                             // including global header

class board{                                     // define the class board

public:                                          // member functions
    board();
    void receiveMove(int,int);
    char defineChar(int);                         //defines characters to case -1=x, 0=' ', 1=o
    bool isLegal(int);
    void resetBoard();                            //reset the board
    void display();                               //display the board

private:                                          // data members (private)
    static const int blank = 0;               // assign value to blank
    static const int playerX = -1;           // assign value to player X if X win return -1
    static const int playerO = 1;            // asign value to player O if O wins return 1
    static const int wins[8][3];           //possible blocks for winning
};
#endif // BOARD_H
