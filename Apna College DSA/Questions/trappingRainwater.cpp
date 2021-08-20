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
  int l = 0, leftMax = INT_MIN, r = n - 1, rightMax = INT_MIN, area = 0;
  while (l <= r){
    if (v[l] <= v[r]){
      leftMax = max(leftMax, v[l]);
      area += leftMax - v[l];
      l++;
    }
    else {
      rightMax = max(rightMax, v[r]);
      area += rightMax - v[r];
      r--;
    }
  }
  cout << area << endl;
  return 0;
}