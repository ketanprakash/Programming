#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//sum of first n numbers
void sumNP(int i, int sum = 0){
  if (i == 0){
    cout << sum << endl;
    return;
  }
  sumNP(i - 1, sum + i);
}

int sumNF(int n){
  if (n == 0) return 0;
  return n + sumNF(n - 1);
}

int factorial(int n){
  if (n == 0) return 1;
  return n * factorial(n - 1);
}

int32_t main(){
  // Write your code
  int n;
  cin >> n;
  // sumNP(n);
  // cout << sumNF(10) << endl;
  cout << factorial(n) << endl;
}