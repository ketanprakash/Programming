//Program to find fibonacci using matrix exponentiation
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void multiply(uint F[2][2], uint M[2][2]){
  int x, y, z, t;
  x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
  y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
  z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
  t = F[1][0] * M[0][1] + F[1][1] * M[1][1];
  F[0][0] = x; F[0][1] = y; F[1][0] = z; F[1][1] = t;
}

void power(uint F[2][2], uint n){
  if (n == 1) return; 
  uint M[2][2];
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++) M[i][j] = F[i][j];
  }
  power(F, n / 2);
  multiply(F, F);
  if (n % 2 != 0) multiply(F, M);
}

uint fibonacci(int n){
  if (n == 0 || n == 1) return n;
  uint F[2][2] = {{1, 1}, {1, 0}};
  power(F, n);
  return F[0][1];
}

int32_t main(){
  uint n; 
  cin >> n; 
  for (uint i = 0; i < n; i++){
    cout << fibonacci(i) << " ";
  }
  return 0;
}