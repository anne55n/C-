// © copyright 2013 MAC 125 GROUP4 All Rights Reserved.                                             //
// Author: Anastassiya Neznanova, Wei Zheng, Denis Radoncic,Emmy Guerrero                           //
// Date: 12 DEC 2013                                                                                //
// Contact: EMAILS: anastassiya.neznanova@live.lagcc.cuny.edu, denis.radoncic@live.lagcc.cuny.edu,  //
// wei.zheng@live.lagcc.cuny.edu, emmy.guerrero@live.lagcc.cuny.edu                                 //
// Description: Tic Tac Toe Third Edition! Using virtual functions and multiple headers!            //
//              User against computer.                                                              //
//              And Player vs Player.                                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _TICTACTOE_
#define _TICTACTOE_

class tictactoe{                                  //define taitactoe class

public:                                           //public data
   
    int isWinner();                               //who is the winner
    void playGame();                              //play game
    void init();                                  //game init
    bool playAgain();                             //asks user to continue or quit the game
    void showWinner();                            //show who is winner
    char defineChar(int);                         //defines characters to case -1=x, 0=' ', 1=o
    bool isOccupy(int);                           //check if cell is empty to move
    void resetBoard();                            //reset the board
    void display();                               //display the board
    void userMove(int);                           //user's moves
    void computerMove( );                         //computer's move
    int minmaxAlg(int);                           //smart algorithm(blocking user from winning)

private:                                          //private data
    //static numbers
    static const int blank = 0;                   // assign value to blank
    static const int playerX = -1;               // assign value to player X if X win return -1
    static const int draw = 0;                   // assign value to draw if nobody wins return 0
    static const int playerO = 1;                 // asign value to player O if O wins return 1

    int cells[9];                                  //assign array with size 9
    int mode;                                      //mode
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};            //possible blocks for winning

};


#endif                                                // _TICTACTOE_
