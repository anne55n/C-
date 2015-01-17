// Name: Anastassiya Neznanova
// ID: 1093
// MAC281, Section 3013
// Project 2, Part 1, number 4(ii)
// This program finds the smallest fibonacci number greater than 1,000,000 and greater than 1,000,000,000.

#include <iostream>
using namespace std;
int fibonacci(int n);
int main()
{
    int n=50;
    for (int i = 0; i < n; i++){// looks for the smallest fibonacci number greater than 1,000,000
        if(fibonacci(i)>1000000){
            cout<<"The smallest fibonacci greater than 1,000,000: ";
            cout << fibonacci(i) << " ";
            cout<<endl;
            cout<<endl;
            break;
        }
    }
    for (int i = 0; i < n; i++){// looks for the smallest fibonacci number greater than 1,000,000,000
        if(fibonacci(i)>1000000000){
            cout<<"The smallest fibonacci greater than 1,000,000,000: ";
            cout << fibonacci(i) << " ";
            cout<<endl;
            break;
        }
    }
    return 0;
}

int fibonacci(int n) {//iterative fibonacci function
    if (n <= 0) {
        return 0;
    }
    int first = 0;
    int second = 1;
    for (int i = 2; i < n; i++) {
        int third=second + first;
        first=second ;
        second=third;
    }
    return second;
}