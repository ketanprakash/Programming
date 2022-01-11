//Program to find fibonacci numbers
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int dp[1000];

int fib(int n){
  if (dp[n] != 0) return dp[n]; 
  if (n == 0 || n == 1) return dp[n] = n;
  return dp[n] = fib(n - 1) + fib(n - 2);
}

int32_t main(){
  // Write your code
  int n; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cout << fib(i) << " ";
  }
  return 0;
}