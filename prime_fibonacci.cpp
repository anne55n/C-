// Name: Anastassiya Neznanova
// ID: 1093
// MAC281, Section 3013
// Project 2, Part 1, number 4(iii)
// This program finds fibonacci prime numbers.
#include <iostream>
#include <cmath>
using namespace std;

long long int fibonacci(int n);
bool isPrime(long long int number);
int main()
{
    int n=83;
    cout<<"Prime Fibonacci Numbers: "<<endl;
    cout<<endl;
    for (int i = 0; i <= n; i++)
        if(isPrime(fibonacci(i))){//if the number is prime and fibonacci
            cout <<fibonacci(i) << " "<<endl;} //displays prime fibonaccy number
    cout << endl;
    
    return 0;
}
bool isPrime(long long int number)//function for finding prime numbers
{
    if (number < 2)//if n 1 or 0, this number is not prime
        return false;
    for (int i = 2; i <= sqrt(number); ++i)
        if (number % i == 0)//checks for other numbers(if n divisible by itself and 1, number is prime)
            return false;
    return true;
}
long long int fibonacci(int n) {// finds fibonacci numbers iteratively
    if (n <= 0) {
        return 0;
    }
    long long int first = 0;
    long long int second = 1;
    for (int i = 2; i <= n; i++) {
        long long int third=second + first;
        first=second ;
        second=third;
    }
    return second;
}

