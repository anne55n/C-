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
#include "tictactoe.h"                        //include tictactoe header

using namespace std;


void tictactoe::init(){                                                // The tictactoe:: init clarifies the scope 
    
    cout<<"Tic Tac Toe Second Edition BY Group 4!"<<endl;                        // display message
    cout<<endl;
    cout<<">-----|-----|-----<"<<endl;
    cout<<"|  0  |  1  |  2  |"<<endl;
    cout<<"|-----+-----+-----|"<<endl;
    cout<<"|  3  |  4  |  5  |"<<endl;
    cout<<"|-----+-----+-----|"<<endl;
    cout<<"|  6  |  7  |  8  |"<<endl;
    cout<<">-----|-----|-----<"<<endl;
    
    resetBoard();                                                  //reset the board
    
    cout<<endl;
    cout<<"Press numbers to put MARK in board as shown in table!"<<endl;            // display message
    cout<<"In Player vs Computer or Computer vs Player mode, Computer Will Play 'O'!"<<endl;
    cout<<"In Player vs Pplayer mode, Player X will go first!"<<endl;
    cout<<"MODE: Player vs Computer = 1 , Computer vs Player = 2 , Player vs Player = 3, QUIT = else "<<endl;
    char choice;
    cin>>choice;                                                                    //user input
    if (choice =='1'){ mode = 1; }                                                  //1 = User against computer, and user go fist
    else if (choice == '2'){ mode = 2; }                                            //2 = User go second
    else if (choice == '3'){ mode = 3; }                                            //player against player
    else exit(0);                                                                   // else exit
}

void tictactoe::resetBoard(){                                                                //reset the board
    for(int i = 0;i<9;i++)
        cells[i] = blank;
}

bool tictactoe::playAgain(){                                         // to check if user wants or not to continue playing the game
    cout<<"Do you want to continue playing?"<<endl;                  //display the message
    cout<<"YES = 1, NO = else ." <<endl;
    char choice;
    cin>>choice;                                                     //input from the user
    if(choice == '1'){
        system("cls");
        return true;}                                                 //choice = 1 continue game
    else
        return false;                                                 //else exit the game
}

bool tictactoe::isOccupy(int n){            //to check  if the cell is occpuied (prevent user from the wrong input)
    if ( cells[n] != blank ){               //checks if the cell is empty or not
        cout<< "This cell is alreday been occupied, Please choose the other one!"<< endl; //display message
        return true;}
    else
        return false;
}

char tictactoe::defineChar(int n) {         //define char
    switch(n) {                             //using switch statemnt
        case playerX:                       //in X case
            return 'X';                     //it will return x
        case blank:                         // in BLANK case
            return ' ';                     // it will return space
        case playerO:                       // in case O
            return 'O';                     //it will return o
    }
}

void tictactoe::display() {                                                // tictactoe calls function display
    
    system("cls");
    
    cout<<"Tic Tac Toe BY Group 4!"<<endl;                                                                                   // display message
    cout<<endl;
    cout<<">-----|-----|-----<"<<endl;                                                                                       //draws the board
    cout<<"|  "<<defineChar(cells[0])<<"  |  "<<defineChar(cells[1])<<"  |  "<<defineChar(cells[2])<<"  |"<<endl;            //assigns value to every cell
    cout<<"|-----+-----+-----|"<<endl;                                                                                       // draw the board
    cout<<"|  "<<defineChar(cells[3])<<"  |  "<<defineChar(cells[4])<<"  |  "<<defineChar(cells[5])<<"  |"<<endl;            //assigns value to every cell
    cout<<"|-----+-----+-----|"<<endl;                                                                                       //draw the board
    cout<<"|  "<<defineChar(cells[6])<<"  |  "<<defineChar(cells[7])<<"  |  "<<defineChar(cells[8])<<"  |"<<endl;            //assigns value to every cell
    cout<<">-----|-----|-----<"<<endl;
    cout<<endl;
}

int tictactoe::isWinner() {
    for(int i = 0; i < 8; ++i) {                                                        //instead of cheaking every row and column assign it to row to i(to safe time)
        if(cells[wins[i][0]] != 0 && cells[wins[i][0]] == cells[wins[i][1]] &&          // if [row][column](0,1,2=x or o)
           cells[wins[i][0]] == cells[wins[i][2]])                                      //determines the winner
            return cells[wins[i][2]]; }                                                     //return winner
    return 0;                                                                           //return 0
}

int tictactoe::minmaxAlg( int user) {
                                                       //determines position for user, is his turn ?
    int winner = isWinner();
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

void tictactoe::computerMove( ) {                     //The tictactoe:: computerMove clarifies the scope 
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
    cells[move] = playerO;
}

void tictactoe::userMove(int mark ) {                                    // The tictactoe:: userMove clarifies the scope 
    unsigned int n ;
    while(cin.fail() || n >=9 ||  isOccupy(n)){                         // cin.fail() when cin failure
        cin.clear();                                                    // clear cin
        cin.sync();                                                     // ignores anything that could be left in cin
        if(mode == 3){
            if(mark == playerX)
                cout<<"Player X, please input a correct number from 0 to 8 : ";
            else cout<<"Player O, please input a correct number form 0 to 8 :";
        }
        else cout<<"Please input a correct number from 0 to 8 : ";
        cin>>n;                 // ask user for a coorect number when entering WRONG NUMBER OR CARACTER;
    }
    cells[n]= mark;
}
void tictactoe::showWinner(){
    switch(isWinner()) {                                    //The tictactoe:: showWinnerclarifies the scope 
        case playerX:                                            // user wins
            display();                                          // displays the final 'x' in the cell
            if(mode == 3)                                         //pvp,player x win
                cout<<"player X wins!"<<endl;
            else cout<<"Wow! You won the game! Congratulations! "<<endl;    //display message
            break;                                               //break out of the case -1
        case draw:                                               // a draw
            display();                                           //displays the final 'o' or 'x' in the cell
            cout<<"Nobody won this game! "<<endl;                //display message
            break;                                               //break out of the case 0
        case playerO:                                                 // computer wins
            display();                                          //displays tle final 'o' in the cell
            if (mode == 3)
                cout<<"Player O wins!"<<endl;                       //pvp, player o win
            else cout<<"Sorry, you lost the game! "<<endl;                 //display message
            break;                                              //break out of the case 1
    }
}

void tictactoe::playGame(){                                        //The tictactoe:: playgame clarifies the scope 
    for(int turn = 0; turn < 9 && isWinner() == 0; ++turn)         //if turn =0, and not=to end(9) and no winner turn+1;
    {
        if((mode+turn) % 2 == 0) {                                     //if turn+ user(1or2)%2==0
            if(mode == 3){                                             //and if in pvp mode, player o makes move
                display();
                userMove(playerO);}
            else
                computerMove(); }                                     // then computer makes his move
        else {                                                        // otherwise
            display();
            userMove(playerX);}                                       //user makes his move
    }showWinner();
}
