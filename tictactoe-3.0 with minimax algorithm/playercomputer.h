// © copyright 2013 MAC 125 GROUP4 All Rights Reserved.                                             //
// Author: Anastassiya Neznanova, Wei Zheng, Denis Radoncic,Emmy Guerrero                           //
// Date: 12 DEC 2013                                                                                //
// Contact: EMAILS: anastassiya.neznanova@live.lagcc.cuny.edu, denis.radoncic@live.lagcc.cuny.edu,  //
// wei.zheng@live.lagcc.cuny.edu, emmy.guerrero@live.lagcc.cuny.edu                                 //
// Description: Tic Tac Toe Third Edition! Using virtual functions and multiple headers!            //
//              User against computer.                                                              //
//              And Player vs Player.                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PLAYERCOMPUTER_H
#define PLAYERCOMPUTER_H

#include "player.h"  //including player header

class board;    //calling board class

class playercomputer : public player   //playercomputer access public variables from player
{
public:                      //public data
    game myGame;             //constructors
    int minmaxAlg(int );
    virtual void makeMove(board& aboard,int);
};

#endif // PLAYERCOMPUTER_H
