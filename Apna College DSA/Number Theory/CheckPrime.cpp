#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

bool isprime(uint n){
  uint sq = sqrt(n);
  bool prime = 1;
  for (uint i = 2; i <= sq; i++){
    if (n % i == 0) prime = 0;
  }
  return prime;
}

int32_t main(){
  uint x; 
  cin >> x; 
  cout << (isprime(x) ? "Prime\n" : "Not prime\n");
  return 0;
}