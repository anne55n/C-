// © copyright 2013 MAC 125 GROUP4 All Rights Reserved.                                             //
// Author: Anastassiya Neznanova, Wei Zheng, Denis Radoncic,Emmy Guerrero                           //
// Date: 12 DEC 2013                                                                                //
// Contact: EMAILS: anastassiya.neznanova@live.lagcc.cuny.edu, denis.radoncic@live.lagcc.cuny.edu,  //
// wei.zheng@live.lagcc.cuny.edu, emmy.guerrero@live.lagcc.cuny.edu                                 //
// Description: Tic Tac Toe Third Edition! Using virtual functions and multiple headers!            //
//              User against computer.                                                              //
//              And Player vs Player.                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"         //including global header
#include "game.h"           //including game header

class board;                //calling class board
class player{               //define class player

public:                     // public data
    virtual void makeMove(board& aboard,int) ; // virtual function makemove

protected:                           //protected data
    static const int blank = 0;      // assign value to blank
    static const int playerX = -1;   // assign value to player X if X win return -1
    static const int playerO = 1;    // asign value to player O if O wins return 1


};
#endif // PLAYER_H
