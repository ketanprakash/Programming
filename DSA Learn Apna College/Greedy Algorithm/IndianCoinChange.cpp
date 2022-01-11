//You are given an array of Denominations and a value X. You need to find the minimum number of coins required to make value X. Note: We have infinite coins
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  vector<int> den{2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  sort(den.begin(), den.end(), greater<int>());
  int val; 
  cin >> val;
  int count = 0;
  for (int i = 0; i < den.size() && val > 0; i++){
    count += val / den[i];
    val = val % den[i];
  }
  cout << endl << count << endl;
  return 0;
}