//Program to find subarrays with sum 0
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<pair<int, int> > findSubarray(int* arr, int n, int target){
  vector<pair<int, int> > vp;
  unordered_map<int, int> um; 
  int sum = 0; 
  for (int i = 0; i < n; i++){
    sum += arr[i];
    if (sum == target){
      vp.push_back(pair<int, int>(0, i));
    }
    if (um.find(sum - target) != um.end()){
      vp.push_back(pair<int, int>(um[sum - target] + 1, i));
    }
    um[sum] = i;
  }
  return vp;
}

int32_t main(){
  int n; 
  cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<pair<int, int> > vp = findSubarray(arr, n, 0);
  cout << "Subarrays: " << endl;
  for (auto p : vp){
    for (int i = p.first; i <= p.second; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  return 0;
}