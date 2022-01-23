#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void printSubs(int arr[], int n, int i, vector<int> &v){
  if (i >= n){
    cout << "[ ";
    for (int &x : v) cout << x << " ";
    cout << "]";
    cout << endl;
    return;
  }
  printSubs(arr, n, i + 1, v);
  v.push_back(arr[i]);
  printSubs(arr, n, i + 1, v);
  v.pop_back();
}

int32_t main(){
  // Write your code
  int n;
  cin >> n; 
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> v;
  printSubs(arr, n, 0, v);
}