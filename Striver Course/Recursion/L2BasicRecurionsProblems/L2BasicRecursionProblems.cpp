#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void print1ToN(int n){
  if (n == 0) return;
  print1ToN(n - 1);
  cout << n << endl;
}

void print1toN2(int n, int i = 1){
  if (i > n) return;
  cout << i << endl;
  print1toN2(n, i + 1);
}

void printNto1(int n){
  if (n == 0) return;
  cout << n << endl;
  printNto1(n - 1);
}

void printNto1_2(int n, int i = 1){
  if (i > n) return;
  printNto1_2(n, i + 1);
  cout << i << endl;
}

int32_t main(){
  // Write your code
  
  //print 1 to n
  // print1ToN(10);
  // print1toN2(10);
  //print n to 1
  // printNto1(10);
  // printNto1_2(10); 
  
  return 0;
}