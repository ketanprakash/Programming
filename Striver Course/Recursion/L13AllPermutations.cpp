#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void allPermutations(int arr[], int n, int idx = 0){
  if (idx == n){
    for (int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  for (int i = idx; i < n; i++){
    swap(arr[idx], arr[i]);
    allPermutations(arr, n, idx + 1);
    swap(arr[idx], arr[i]);
  }
}

int32_t main(){
  // Write your code
  int n; 
  cin >> n; 
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  allPermutations(arr, n);
}