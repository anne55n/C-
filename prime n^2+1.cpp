//Name: Anastassiya Neznanova
//ID: 1093
//MAC281, Section 3013
//Project 1, Part 1, Problem 3
//This program finds as many primes of the form n^2+1, where n is a positive integer.

#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

bool isPrime(long number);//function declaration

int main(){

	int max = 150;
	long number;
	
	for(int p=1; p<max; p++){
        number = pow(p, 2) + 1; //num equal p^2+1
		if (isPrime(number))//if num is prime, than print this number  number in form of n^2+1
                cout<<p<<setw(2)<<" --> "<<setw(2)<<number<<endl;
        
    }

	system("pause");
	return 0;
}
bool isPrime(long number){//checks if the number is prime or not
	if (number < 2)
    return false;
	for (int i = 2; i < sqrt(number); i++){
		if (number % i == 0)
            return false;
	}
	return true;
}




