//Program to solve the find the pair of numbers with given sum
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//O(NlogN) solution
bool twoSum(vector<int> v, int s, int e, int sum){
  sort(v.begin() + s, v.begin() + e + 1);
  while (s < e){
    if (v[s] + v[e] == sum){
      return true;
    } 
    else if (v[s] + v[e] < sum){
      s++;
    }
    else {
      e--;
    }
  }
  return false;
}

//O(N) solution
bool twoSumOptimised(vector<int> v, int s, int e, int sum){
  unordered_map<int, bool> m;
  for (int i = s; i <= e; i++){
    if (m.find(sum - v[i]) != m.end()) {
      return true;
    }
    m[v[i]] = i;
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
  cout << twoSumOptimised(v, 0, n - 1, sum);
  return 0;
}