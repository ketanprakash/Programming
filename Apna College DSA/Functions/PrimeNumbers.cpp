//Author: Ketan Prakash, Date:
//Program to print all prime numbers between 2 given numbers
#include <iostream> 
#include <cmath> 
using namespace std; 

bool isPrime(int num){
    bool primeFlag = 1; 
    for (int i = 2; i <= sqrt(num); i++){
        if (num % i == 0) primeFlag = 0;
    }
    return primeFlag;
}

void printPrime(int num1, int num2){
    if (num1 > num2){
        int x = num2; 
        num2 = num1; 
        num1 = x; 
    }
    for (int i = num1 + 1; i < num2; i++){
        if (isPrime(i)) cout << i << " ";
    }
}

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    printPrime(num1, num2);
    return 0;
}