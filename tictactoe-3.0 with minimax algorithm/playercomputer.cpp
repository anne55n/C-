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
#include "playercomputer.h"                   // including playercomputer header


using namespace std;

int playercomputer::minmaxAlg(int user) {          //playercomputer:: minimax clarifies the scope

                                                        //determines position for user, is his turn ?
    int winner = myGame.isWinner();
    if(winner != 0)
        return winner*user;

    int move = -1;
    int score = -2;                                   //Losing moves are preferred to no move
    for(int i = 0; i < 9; ++i) {                      //generate for loop for all moves
        if(cells[i] == 0) {                           //If cell is empty
            cells[i] = user;                          // can move
            int dScore = -minmaxAlg( user*-1);        //recursive calculating user moves
            if(dScore > score) {                      // if dScore > score
                score = dScore;                       //assign score to dScore
                move = i;
            }                                         //Pick the one that's worst for the opponent
            cells[i] = 0;                             //Reset board after try
        } }
    if(move == -1) return 0;
    return score;
}

void playercomputer::makeMove( board& aboard ,int mark ) {                     //computer move function with array cell size 9
    int move = -1;                                    //here we will use minimax algorithm . assign move to -1
    int score = -2;                                   //score to -2
    for(int i = 0; i < 9; ++i) {                      //create a for loop
        if(cells[i] == 0) {                           // if some cell ==0(empty)
            cells[i] = 1;                             // assign this cell to 1
            int tempScore = -minmaxAlg( -1);          //creating recursive function
            cells[i] = 0;                             //assign i cell to 0
            if(tempScore > score) {                   //compare tempscore with score
                score = tempScore;                    //if tempscore > score then our score will be = tempscore
                move = i;                             //and move =i that will generate the algorithm that blocks user's move
            }}}                                       //returns a score based on minimax tree at a given node.
    //cells[move] = playerO;
    aboard.receiveMove(playerO,move);
    }

