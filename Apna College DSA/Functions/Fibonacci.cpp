//Author: Ketan Prakash, Date:
//Program to print fibonacci sequence
#include <iostream> 
using namespace std; 

void fibonacci(int num){
  long long int a = 1, b = 1; 
  for (int i = 0; i < num; i++){
    cout << a << " ";
    long long int x = a + b; 
    a = b; 
    b = x;
  }
}

int arr[100];

long long int fibR(int num){
  if (num == 0 || num == 1){
    return num;
  }
  else if (arr[num] != 0){
    return arr[num];
  }
  long long fib = fibR(num - 2) + fibR(num - 1);
  arr[num] = fib;
  return fib;
}

int main(){
  int number; 
  cin >> number;
  for (int i = 0; i < number; i++) cout << fibR(i) << endl;
  return 0;
}