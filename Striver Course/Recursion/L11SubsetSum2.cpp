//Given an integer array that may contain duplicates return all possible subsets. The solution must not contain duplicate subsets
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//using the select subsequence method
void allSubsets(int arr[], int n, vector<int> &v, vector<vector<int>> &subsets, int idx = 0){
  subsets.push_back(v);
  if (idx >= n) return;
  int h = INT_MIN;
  for (int i = idx; i < n; i++){
    if (h != arr[i]){
      v.push_back(arr[i]);
      allSubsets(arr, n, v, subsets, i + 1);
      v.pop_back();
      h = arr[i];
    }
  }
}

int32_t main(){
  // Write your code
  int n; 
  cin >> n;
  int arr[n];
  for (int &x : arr) cin >> x; 
  sort(arr, arr + n);
  vector<int> v;
  vector<vector<int>> subsets;
  allSubsets(arr, n, v, subsets);
  for (auto &subset: subsets){
    cout << "[ ";
    for (auto &x : subset) cout << x << " ";
    cout << "]";
    cout << endl;
  }
}