//Program to solve fractional knapsack problem
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  vector<vector<int> > v; 
  int n; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    int value, weight; 
    cin >> value >> weight;
    v.push_back({value, weight});
  }
  int capacity, val = 0; 
  cin >> capacity;
  sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
    return a[0]/a[1] > b[0]/b[1];
  });
  for (int i = 0; i < n && capacity > 0; i++){
    val += v[i][0] / v[i][1] * min(capacity, v[i][1]);
    capacity -= min(capacity, v[i][1]);
  }
  cout << val << endl;
  return 0;
}