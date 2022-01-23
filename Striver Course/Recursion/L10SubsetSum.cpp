//Given a list of N integers print sums of all subsets in it. Output should be printed in increasing order of sums
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//using pick and not pick method
void allSubsetSum(int arr[], int n, vector<int> &sums, int sum = 0, int idx = 0){
  if (idx == n){
    sums.push_back(sum);
    return;
  }
  //pick 
  allSubsetSum(arr, n, sums, sum + arr[idx], idx + 1);
  //not pick 
  allSubsetSum(arr, n, sums, sum, idx + 1);
}

int32_t main(){
  // Write your code
  int n; 
  cin >> n; 
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> sums;
  allSubsetSum(arr, n, sums);
  sort(sums.begin(), sums.end());
  for (int &x : sums) cout << x << " ";
  cout << endl;
}