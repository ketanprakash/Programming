#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//reverse an array
void rev(int arr[], int i, int n){
  if (i >= n/2) return;
  swap(arr[i], arr[n - i - 1]);
  rev(arr, i + 1, n);
}

int32_t main(){
  // Write your code
  int n; 
  cin >> n; 
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  rev(arr, 0, n);
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
}