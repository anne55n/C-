//Name: Anastassiya Neznanova
//ID: 1093
//MAC281, Section 3013
//Project 1, Part 1, Problem 2
//This program determines whether 2^p-1 is prime for each of the primes not exceeding 100.

#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

bool isPrime(long number);//function declaration

int main(){
    
	int max = 100;  
	long number;
	
	for(int p=2; p<max; p++){
		if (isPrime(p)){//checks if num is prime
             number = pow(2, p) - 1; //if num is prime, num equal 2^p-1
        if(isPrime(number))//if num in form 2^p-1 is prime, than print this number in form of 2^p-1
            cout<<setw(2)<<p<<" --> "<<setw(2)<<number<<endl;
        }}
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




