#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void print1toN(int n){
  if (n == 0) return;
  print1toN(n - 1);
  cout << n << endl;
}

void print1toN2(int n, int i = 1){
  if (i > n) return;
  cout << i << endl;
  print1toN2(n, i + 1);
}

int32_t main(){
  // Write your code

  //print 1 to n
  print1toN(10);
  print1toN2(10); 
  
  return 0;
}