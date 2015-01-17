//author: Anastassiya Neznanova
//date: 12/01/2013
//department of computer science
//MAC-283
//contact email: anastassiya.neznanova@lagcc.cuny.edu
//Project description: Virtual calculator ((assembler) read the prompt from the file)


#include <windows.h>
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
// INSTRUCTION SET (or Assembler Language)
// instruction = machine code [operand]
const int CLR    = 1;  // step 2: acc= 0
const int ADD    = 2;  // step 3: ADD 60, acc = acc +60 step 5:ADD 6, acc=acc+6
const int MUL    = 3; // step 4:mul 4,  acc = acc x 4
const int BNZ    = 4; //
const int OUTPUT = 5; // step 8:output,  cout << acc;
const int HALT   = 6; // step 9:Halt,  exit program
const int SUB    = 7;  // step 7:sub 9, acc = acc-4
const int NOP    = 0;   // step 1:do nothing. step 6:do nothing
const int LOAD   = 8;
const int AD     = 9;
// VIRTUAL COMPUTER
int main()
{
    // Simulating a single Register (accumulator) system
    int opcode, operand; // IR register
    int step = 0;        // PC register
    int acc = 0;         // single accumulator
    string fileName;
    int code=0;
    int table[30];
    string word;
    SetConsoleTitleA(" A Simple Virtual Machine");//displaying the title of our console
    
    cout<<"Enter the name of the file ";//prompting the user to enter the filename.
    cin>>fileName;
    ifstream myFile(fileName);//getting the file
    if(!myFile.good()){//if cannot be opened
        cerr << "File not found" << endl;// display the message
        system("pause");
        return 0;
    }
    else if(myFile.good()){// if file can be opened
        cout<<" file is opening"<<endl;
        while( myFile>>word )// get line from a file
        {//decoding the string and initializing the int value to int line.
            if (word=="CLR")    code= 1;  // step 2: acc= 0
            if (word=="ADD")    code= 2;  // step 3: ADD 60, acc = acc +60 step 5:ADD 6, acc=acc+6
            if (word=="MUL")    code= 3; // step 4:mul 4,  acc = acc x 4
            if (word=="BNZ")    code= 4; //
            if (word=="OUTPUT") code= 5; // step 8:output,  cout << acc;
            if (word=="HALT")   code= 6; // step 9:Halt,  exit program
            if (word=="SUB")    code= 7;  // step 7:sub 9, acc = acc-4
            if (word=="NOP")    code= 0;   // step 1:do nothing. step 6:do nothing
            if (word=="LOAD")   code= 8;
            if (word=="AD")     code= 9;
            else {
                istringstream istr(word);// convert string to int
                istr>>code;
                table[step] = code;// put int in the table array
                step++;
            }
        }
    }
    step=0;//to start the instructions from first array
    do{
        opcode = table[step];   // fetch an instruction
        
        switch (opcode) {  // very simple decoding of instruction
            case NOP:
                step++;
                break;
            case CLR:
                acc =0;     // clear the accumulator
                step++;     // get next instruction address
                break;
            case ADD:
                operand= table[++step];  // fetch needed operation from next location
                acc += operand;          // add operard to accumulator
                step++;                  // get next instruction address
                break;
            case AD:
                operand= table[++step];  // fetch needed operation from next location
                acc +=   table[operand];  // fetch datum
                step++;                  // get next instruction address
                break;
            case LOAD:
                operand= table[++step];  // fetch needed operation from next location
                acc  =   table[operand];  // fetch datum
                step++;                  // get next instruction address
                break;
            case MUL:
                operand= table[++step]; // fetch needed operation from next location
                acc *= operand;         // mult accumulator by operand
                step++;                 // get next instruction address
                break;
            case OUTPUT:
                cout << "The answer:" << acc << endl;
                step++;
                break;
            case SUB:
                operand= table[++step];
                acc -= operand;
                step++;
                break;
            case BNZ: // need a jump, and other branch instructions
                operand= table[++step];
                if (acc!=0) {
                    step = operand;   // get next instruction address from operand.
                }
                else
                    step++;           // get next instruction address
                break;
                // increment counter
                
            default:
                cout<< " illegal OpCode " << opcode << endl;
                system("pause");
                // must be a safer way to handle this
        }
        opcode = table[step];//to check the HALT
    }while ( opcode !=HALT ) ;// EXECUTE the INSTRUCTION 
    cout << "\n computer shutting down..\n\n ";
    system("pause");
    return 0;
}