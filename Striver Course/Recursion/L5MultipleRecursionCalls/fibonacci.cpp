#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int fib(int n){
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}

int32_t main(){
  // Write your code
  int n;
  cin >> n; 
  for (int i = 0; i < n; i++) cout << fib(i) << " ";
}