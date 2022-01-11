//Program to find power using binary exponentiation o(logn)
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int power(int x, int p){
  //to find x ** p
  if (p == 0) return 1;
  if (p == 1) return x;
  int pow = power(x, p / 2);
  pow *= pow;
  if (p % 2 != 0) pow *= x;
  return pow;
}

int32_t main(){
  // Write your code
  int n, p;
  cin >> n >> p;
  cout << power(n, p) << endl;
  return 0;
}