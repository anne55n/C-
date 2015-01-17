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
#include <stdlib.h>
//#include <windows.h>

#include "game.h"                            //include game header
#include "playerhuman.h"                     //include playerhuman header
#include "playercomputer.h"                  //include playercomputer header

using namespace std;

int mode;                                      //declare the mode
const int game::wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};//possible winning blocks

void game::init(){                                                                // game init;

   // SetConsoleTitle( "TIC-TAC-TOE Third Edition by Group 4" );
    cout << "\t-- Tic Tac Toe Third Edition by Group 4 -- " << endl;                        // display message
    cout << endl;
    cout << "\t\t>-----|-----|-----<"<< endl;
    cout << "\t\t|  0  |  1  |  2  |"<< endl;
    cout << "\t\t|-----+-----+-----|"<< endl;
    cout << "\t\t|  3  |  4  |  5  |"<< endl;
    cout << "\t\t|-----+-----+-----|"<< endl;
    cout << "\t\t|  6  |  7  |  8  |"<< endl;
    cout << "\t\t>-----|-----|-----<"<< endl;
    cout << endl;
    cout << "\t--  Press Numbers to Put Mark in Board "<< endl;            // display message

    myBoard.resetBoard();                                                  // reset the board
    chooseMode();                                                           // call to choose mode
                                                                  
}

void game::chooseMode(){                                                   //class game call the function chooseMode

    cout << "\t--  In Mode 1&2 , Computer Will Play O " << endl;           // display the message
    cout << "\t--  In Mode 3 , Player X will go first \n" << endl;
    cout << "\t--  Choose Your Game Mode: \n" << endl;
    cout << "\t\t1. Player vs Computer " << endl;
    cout << "\t\t2. Computer vs Player " << endl;
    cout << "\t\t3. Player vs Player   " << endl;
    cout << "\t\t4. Enter else to QUIT \n" << endl;

    char choice;                                                     //declare a new char choice
    cout << "\tEnter your choice : ";                               // display the message
    cin >> choice;                                                  //user input
                                                               
    if (choice == '1'){                                  // if user choose 1
        mode = userFirstVsComp;                          //mode user goes first with X
        p1 = new playerhuman();                         //computer goes second with O
        p2 = new playercomputer();
    }                                                
    else if (choice == '2'){                           // if choice is 2
        mode = compFirstVsUser;                        // in this mode comp goes first with X
        p1 = new playerhuman();                       // user goes second with X
        p2 = new playercomputer();
    }                                           
    else if (choice == '3'){                         //if choice is 3
        mode = userVsuser;                           //user plays again another user
        p1 = new playerhuman();
        p2 = new playerhuman();
    }                                          
    else exit(0);                                    // to exit press any other values

}
bool game::playAgain(){                                        // to check if user wants or not to continue playing the game
    cout << "\tDo you want to continue playing?"<<endl;       //display the message
    cout << "\tYES = 1, NO = else ." <<endl;
    char choice;
    cin>>choice;                                                     //input from the user
    if(choice == '1'){
        system("cls");
        return true;}                                                 //choice = 1 continue game
    else
        return false;                                                 //else exit the game
}

int game::isWinner() {
    for(int i = 0; i < 8; ++i) {                                                        //instead of cheaking every row and column assign it to row to i(to safe time)
        if(cells[wins[i][0]] != 0 && cells[wins[i][0]] == cells[wins[i][1]] &&          // if [row][column](0,1,2=x or o)
           cells[wins[i][0]] == cells[wins[i][2]])                                      //determines the winner
            return cells[wins[i][2]]; }                                                     //return winner
    return 0;                                                                           //return 0
}
void game::showWinner(){
    switch(isWinner()) {                                    //the winner is
        case playerX:                                            // user wins
            myBoard.display();                                          // displays the final 'x' in the cell
            if(mode == 3)                                         //pvp,player x win
                cout<<"\tplayer X wins!"<<endl;
            else cout<<"\tWow! You won the game! Congratulations! "<<endl;    //display message
            break;                                               //break out of the case -1
        case draw:                                               // a draw
            myBoard.display();                                           //displays the final 'o' or 'x' in the cell
            cout<<"\tNobody won this game! "<<endl;                //display message
            break;                                               //break out of the case 0
        case playerO:                                                 // computer wins
            myBoard.display();                                          //displays tle final 'o' in the cell
            if (mode == 3)
                cout<<"\tPlayer O wins!"<<endl;                       //pvp, player o win
            else cout<<"\tSorry, you lost the game! "<<endl;                 //display message
            break;                                              //break out of the case 1
    }
}

void game::playGame(){                                             // game calls the function playGame

    for(int turn = 0; turn < 9 && isWinner() == 0; turn++)         //if turn =0, and not=to end(9) and no winner turn+1;
    {
        if((mode+turn) % 2 == 0) {                                     //if turn+ user(1or2)%2==0
                myBoard.display();
                p2->makeMove(myBoard,playerO);
                 }                                     // then computer makes his move
        else {                                                        // otherwise
                myBoard.display();
                p1->makeMove(myBoard,playerX);
                }                                       //user makes his move
    }showWinner();                                       //display the winner
}


