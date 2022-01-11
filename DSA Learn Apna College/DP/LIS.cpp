//Program to find lis
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int dp[1000] = {0};
int lis_ending(int *arr, int i, int &ans){
  int mlength = 0;
  if (dp[i]) return dp[i];
  for (int j = 0; j < i; j++){
    if (arr[j] < arr[i]){
      mlength = max(mlength, lis_ending(arr, j, ans));
    }
  }
  mlength++;
  ans = max(ans, mlength);
  return dp[i] = mlength;
}

int lis(int *arr, int n){
  int ans = 0;
  lis_ending(arr, n - 1, ans);
  return ans;
}

int32_t main(){
  int n; 
  cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << lis(arr, n) << endl;
  return 0;
}