//Program to find out nth catalan number
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int ct[1000] = {0};

int catalan(int n){
  if (n == 0 || n == 1) {
    ct[0] = ct[1] = 1;
    return 1; 
  }
  if (ct[n] == 0){
    for (int i = 0; i < n; i++){
      ct[n] += catalan(i) * catalan(n - i - 1);
    }
  }
  return ct[n];
}

int32_t main(){
  for (int i = 0; i <= 10; i++){
    cout << catalan(i) << " ";
  }
  cout << endl;
  return 0;
}