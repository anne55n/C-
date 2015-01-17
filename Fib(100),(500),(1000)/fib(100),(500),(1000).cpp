// Name: Anastassiya Neznanova
// ID: 1093
// MAC281, Section 3013
// Project 2, Part 1, number 4(i)
// This program finds the exact value of f(100), f(500), f(1000). To calculate this values, BigInt library was used.

#include <iostream>
#include "bigint.h"
using namespace std;
BigInt fibonacci ( int n);
int main()
{

 //Displays t the screen
    
     cout << "Fib(100) is: \n" << fibonacci(100) << endl << endl;
     cout << "Fib(500) is: \n" << fibonacci(500) <<endl << endl;
     cout << "Fib(1000) is: \n" << fibonacci(1000) <<endl << endl;
    
    return 0;
}


BigInt fibonacci(int n) {// finds fibonacci numbers iteratively
    if (n <= 0) {
        return 0;
    }
    BigInt first = 0;
    BigInt second = 1;
    for (int i = 2; i <= n; i++) {
        BigInt third=second + first;
        first=second ;
        second=third;
    }
    return second;
}


