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
#include "playerhuman.h"                      //including playerhuman header

using namespace std;


void playerhuman::makeMove(board& aboard,int mark) {    //The playerhuman:: makemove clarifies the scope

    int move ;                            //define move
    do{                                   // do while loop beginning
        cout<<"\tPlease input a correct number from 0 to 8 : "; //display the message
        cin>>move;                        //input from the user
    }while(!aboard.isLegal(move));        //end of the do while loop
    aboard.receiveMove(mark,move);         // function call returns the receiveMove value stored in aboard
    
}
