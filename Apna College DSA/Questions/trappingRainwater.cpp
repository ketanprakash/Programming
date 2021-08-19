//Program solving trapping rainwater problem
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n; 
  cin >> n; 
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  int l = 0, leftMax = v[l], r = n - 1, rightMax = v[r], res = 0;
  while (l <= r){
    if (v[l] <= v[r]){
      res += leftMax - v[l];
      l++;
      leftMax = max(leftMax, v[l]);
    }
    else {
      res += rightMax - v[r];
      r--;
      rightMax = max(rightMax, v[r]);
    }
  }
  cout << res << endl;
  return 0;
}