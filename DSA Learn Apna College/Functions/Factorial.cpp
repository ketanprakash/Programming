//Author: Ketan Prakash, Date:
//Program to program to find factorial
#include <iostream> 
using namespace std; 

long long int factArr[100];

long long int factorial(int num){
  long long int fact = 1;
  if (factArr[num] != 0) return factArr[num];
  for (int i = 1; i <= num; i++){
    fact = fact * i; 
  }
  factArr[num] = fact;
  return fact;
}

long long factorialR(int num){
  if (num == 0) return 1;
  return factorialR(num - 1) * num;
}

int main(){
  int num; 
  cin >> num;
  for (int i = 0; i <= num; i++) cout << factorialR(i) << " ";
  return 0;
}