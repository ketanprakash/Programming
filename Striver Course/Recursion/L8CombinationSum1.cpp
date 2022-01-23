#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//one element can be taken many times

void combinationWithSumK(int arr[], int n, int k, int i, vector<int> &v){
  if (k < 0) return;
  if (i >= n){
    if (k == 0){
      for (int &x : v) cout << x << " ";
      cout << endl;
    }
    return;
  }
  //not picked
  combinationWithSumK(arr, n, k, i + 1, v);

  //picked
  v.push_back(arr[i]);
  combinationWithSumK(arr, n, k - arr[i], i, v);
  v.pop_back();
}

int32_t main(){
  // Write your code
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> v;
  int k; 
  cin >> k;
  combinationWithSumK(arr, n, k, 0, v);
}