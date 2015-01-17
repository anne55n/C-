#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

const int UniformTicker = 1225;
const int ShortFundName = 1225;
const int CurrentShares = 1225;
const int columns = 3;

string shares[CurrentShares][columns];
string CName;

int result = 0;
int resultt = 0;
int resulttt = 0;
int sum = 0;
int summ = 0;
int total = 0;
int totall = 0;

int main ()
{
    ifstream my_file("//Users//anastassiyaneznanova//Desktop//dif_stuff//filetoEnter.csv"); // get the input file
    string line; // place holder for the string; hold the rows
    
    
    int row = 0;    // set rows to zero
    int column = 0; // set columns to zero
    
    
    while (getline(my_file, line)) // this while loop takes the source file; this one gives a line
    {
        stringstream linestream(line); // convert
        string item_string; // convert
        
        column = 0; // set column to zero each time to loop again
        
        while (getline(linestream, item_string, ','))  // this while loop gives a number
        {
            string data = item_string.c_str(); // atoi function converts the array from a string to an integer
            shares[row][column] = data; //  place value number into the array
            column++;  // left to right  top to bottom
        }
        
        row++;
    }
    
    string companyName;
	cout << "Enter company name" << endl;
	getline(cin, companyName);
	
	if(companyName.length() > 3)
		CName = companyName.substr(0,4);
	
	cout << endl << endl;
	
	bool found = false;
    
    // Prints Company's Name
	for(int i = 0; i < UniformTicker && !found; i++)
	{
		for(int j = 0; j < 3;j++)
		{
			if(CName.compare(shares[i][0].substr(0,4)) == 0)
			{
				cout << "\t" << shares[i][0] << endl;
				found = true;
				break;
			}
        }
	}
    
    
	/*
     Prints all
    for(int i = 0; i < UniformTicker; i++)
	{
			if(CName.compare(shares[i][0].substr(0,4)) == 0)
                cout << "\t" << shares[i][1] << "\t" << shares[i][2] << endl;
	}*/
    
    cout << endl;
    bool founded = false;
    bool f = false;
    bool fa = false;
    bool fal = false;
    bool fo = false;
    bool fon = false;
    bool fou = false;
    
    for(int i = 0; i < UniformTicker; i++)
	{
        if(CName.compare(shares[i][0].substr(0,4)) == 0)
        {
            if(shares[i][1] == "LG" )
            {
                f = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                result += value;
            }
            
            if(shares[i][1] == "AED")
            {
                fa = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                resultt += value;
            }
            
            if(shares[i][1] == "WIC" )
            {
                founded = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                resulttt +=value;
            }
            
            if(shares[i][1] == "CAM")
            {
                fal = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                sum +=value;
            }
           
            
            if(shares[i][1] == "TAF")
            {
                fo = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                summ +=value;
            }
            
            if(shares[i][1] == "ARB")
            {
                fon = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                total += value;
            }
            
            if(shares[i][1] == "TACO" )
            {
                fou = true;
                string fafa = shares[i][2];
                int value = atoi(fafa.c_str());
                totall += value;
            }
       }
    }
    
    if(f)
        cout << "\t" << "LG  " << "\t" << result << endl;
    if(fa)
        cout << "\t" << "AED " << "\t" << resultt << endl;
    if(founded)
        cout << "\t" << "WIC " << "\t" << resulttt << endl;
    if(fal)
        cout << "\t" << "CAM " << "\t" << sum << endl;
    if(fo)
        cout << "\t" << "TAF " << "\t" << summ << endl;
    if(fon)
        cout << "\t" << "ARB " << "\t" << total << endl;
    if(fou)
        cout << "\t" << "TACO " << "\t" << totall << endl;
    
    return 0;
}
        
  

