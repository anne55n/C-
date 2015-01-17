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
#include "game.h"                             //include tictactoe header

int main( ) {                                 //main

    game ttt;
    do{
        ttt.init();               //game init : show board, choose mode
        ttt.playGame();          //play games!
    }while(ttt.playAgain());     // while playAgain return true, NEW GAME!
    return 0;
}

