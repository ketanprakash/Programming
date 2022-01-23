#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//Functional recursion
void printNto1(int n){
  if (n == 0) return;
  cout << n << endl;
  printNto1(n - 1);
}

//Parameterised recursion
void printNto1_2(int n, int i = 1){
  if (i > n) return;
  printNto1_2(n, i + 1);
  cout << i << endl;
}

int32_t main(){
  // Write your code
    
  // print n to 1
  printNto1(10);
  printNto1_2(10);
}