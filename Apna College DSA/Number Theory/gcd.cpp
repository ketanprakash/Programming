//Author: Ketan Prakash, Date:
//Program to find gcd using euclid division algorithm
#include <iostream> 
using namespace std; 

int gcd(int a, int b){
  int x;
  while (b){
    x = a % b; 
    a = b; 
    b = x;
  }
  return a; 
}

int lcm(int a, int b){
  int larger, smaller; 
  larger = a > b ? a : b;
  smaller = a + b - larger;
  int i = 1;
  int l;
  while (true){
    if ((larger * i) % smaller == 0){
      l =  larger * i;
      break;
    }
    i++;
  }
  return l;
}

int main(){
  int a, b; 
  cin >> a >> b; 
  cout << lcm(a, b) << endl;
  return 0;
}