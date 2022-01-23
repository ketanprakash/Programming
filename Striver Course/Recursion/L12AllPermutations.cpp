#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void allPermutations1(int arr[], int n, vector<int> &p, unordered_map<int, bool> &m, int idx = 0){
  if (idx == n){
    for (int x : p) cout << x << " ";
    cout << endl;
  }
  for (int i = 0; i < n; i++){
    if (!m[i]){
      p.push_back(arr[i]);
      m[i] = 1;
      allPermutations1(arr, n, p, m, idx + 1);
      p.pop_back();
      m[i] = 0;
    }
  } 
}

int32_t main(){
  // Write your code
  int n;
  cin >> n; 
  int arr[n];
  for (int &x : arr) cin >> x; 
  unordered_map<int, bool> m;
  for (int i = 0; i < n; i++) m[i] = 0;
  vector<int> p;
  allPermutations1(arr, n, p, m);
}