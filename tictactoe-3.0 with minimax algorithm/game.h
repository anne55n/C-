// © copyright 2013 MAC 125 GROUP4 All Rights Reserved.                                             //
// Author: Anastassiya Neznanova, Wei Zheng, Denis Radoncic,Emmy Guerrero                           //
// Date: 12 DEC 2013                                                                                //
// Contact: EMAILS: anastassiya.neznanova@live.lagcc.cuny.edu, denis.radoncic@live.lagcc.cuny.edu,  //
// wei.zheng@live.lagcc.cuny.edu, emmy.guerrero@live.lagcc.cuny.edu                                 //
// Description: Tic Tac Toe Third Edition! Using virtual functions and multiple headers!            //
//              User against computer.                                                              //
//              And Player vs Player.                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_H
#define GAME_H

#include "global.h"                              //including global.h
#include "board.h"                               //including board.h

class player;                                     // calling class player

class game{                                       //player class

public:                                           //public data
    void chooseMode();                            //asks to choose the mode
    int isWinner();                               //shows who is the winner
    void playGame();                              //play game
    void init();                                  //game init
    bool playAgain();                             //asks user to continue or quit the game
    void showWinner();                            //show who is winner

private:                                          //private variables
    board myBoard;                                 // default constructor called
    player* p1;                                    //// point p1 object.
    player* p2;                                    // points p2 object
    const int userFirstVsComp=1;                   // const variable define mode user goes first
    const int compFirstVsUser=2;                   //const variable define mode comp goes first
    const int userVsuser=3;                        //const variable define mode user vs user
    //static numbers
    static const int playerX = -1;                   // assign value to player X if X win return -1
    static const int draw = 0;                       // assign value to draw if nobody wins return 0
    static const int playerO = 1;                    // asign value to player O if O wins return 1
    static const int wins[8][3];                     //possible blocks for winning

};
#endif // GAME_H
