//Author: Ketan Prakash, Date:
//Program to find sum of first n numbers
#include <iostream> 
using namespace std; 

long long int SumOfNatural(int num){
  long long sum = 0; 
  for (int i = 1; i <= num; i++) sum += i;
  return sum;
}

long long int SumOfNaturalf(int num){
  long long sum = num * (num + 1) / 2; 
  return sum; 
}

int main(){
  int num; 
  cin >> num; 
  cout << SumOfNatural(num) << endl;
  cout << SumOfNaturalf(num);
  return 0;
}