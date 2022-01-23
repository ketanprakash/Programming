#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

// does not work as does not provide unique subsequence
// void combinationWithKSumUnique(int arr[], int n, int k, vector<int> &v, int i = 0){
//   if (i == n){
//     if (k == 0){
//       for (int &x : v) cout << x << " ";
//       cout << endl;
//     }
//     return;
//   }
//   //not picking current
//   combinationWithKSumUnique(arr, n, k, v, i + 1);
//   //picking current
//   v.push_back(arr[i]);
//   combinationWithKSumUnique(arr, n, k - arr[i], v, i + 1);
//   v.pop_back();
// }

void combinationWithKSumUnique(int arr[], int n, int k, int idx, vector<int> &v, int sum){
  if (sum == k){
    for (int &x : v) cout << x << " ";
    cout << endl;
    return;
  }
  if (idx == n) return;
  int h = INT_MIN;
  for (int i = idx; i < n; i++){
    if (h != arr[i]){
      v.push_back(arr[i]);
      combinationWithKSumUnique(arr, n, k, i + 1, v, sum + arr[i]);
      v.pop_back();
      h = arr[i];
    }
  }
}

int32_t main(){
  // Write your code
  int n; 
  cin >> n; 
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int k;
  cin >> k;
  vector<int> v;
  sort(arr, arr + n);
  int sum = 0;
  combinationWithKSumUnique(arr, n, k, 0, v, sum);
}