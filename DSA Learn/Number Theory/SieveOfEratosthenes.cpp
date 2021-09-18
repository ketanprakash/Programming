#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define n 999999
using namespace std;

vector<bool> sieve(){
  vector<bool> isprime(n + 1, 1);
  isprime[0] = isprime[1] = 0;
  for (uint i = 2; i <= n; i++){
    if (isprime[i]){
      for (uint j = i * i; j <= n; j += i){
        if (isprime[j]){
          isprime[j] = 0;
        }
      }
    }
  }
  return isprime;
}

int32_t main(){
  vector<bool> isprime = sieve();
  int t; 
  cin >> t;
  uint x; 
  cin >> x; 
  for (uint i = 0; i <= x; i++){
    if (isprime[i]) cout << i << " ";
  }
  cout << endl;
  return 0;
}