//Program to find top k most frequent elements
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, k; cin >> n >> k; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  unordered_map<int, int> freq;
  map<int, int, greater<int> > m;
  for (int i = 0; i < n; i++){
    freq[arr[i]]++;
  }
  for (auto p : freq){
    m[p.second] = p.first;
  }
  int count = 0;
  for (auto p : m){
    cout << p.second << endl;
    count++;
    if (count == k) break;
  }
  return 0;
}