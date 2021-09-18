//Program to solve three sum problem
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//O(N) solution
bool twoSumOptimised(vector<int> v, int s, int e, int sum){
  unordered_map<int, bool> m;
  for (int i = s; i <= e; i++){
    if (m.find(sum - v[i]) != m.end()) {
      cout << sum - v[i] << " " << v[i] << " ";
      return true;
    }
    m[v[i]] = i;
  }
  return false;
}

bool threeSum(vector<int> v, int s, int e, int sum){
  for (int i = s; i <= e; i++){
    if (twoSumOptimised(v, i + 1, e, sum - v[i])) {
      cout << v[i] << endl;
      return true;
    }
  }
  return false;
}

int32_t main(){
  int n; 
  cin >> n; 
  vector<int> v(n); 
  for (int &x : v) cin >> x; 
  int sum; 
  cin >> sum;
  cout << threeSum(v, 0, n - 1, sum);
  return 0;
}