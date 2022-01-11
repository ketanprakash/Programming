//Program to find frequency of elements using hashing
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n; cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++){
    freq[arr[i]]++;
  }
  for (auto p : freq){
    cout << p.first << " : " << p.second << endl;
  }
  return 0;
}