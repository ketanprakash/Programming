#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//print all subsequences
void printKSubs(int arr[], int n, int k, vector<int> &v, int idx = 0, int sum = 0){
  if (idx == n){
    if (sum == k){
      cout << "[ ";
      for (int &x : v){
        cout << x << " ";
      }
      cout << ']';
      cout << endl;
    }
    return;
  }
  printKSubs(arr, n, k, v, idx + 1, sum);
  v.push_back(arr[idx]);
  printKSubs(arr, n, k, v, idx + 1, sum + arr[idx]);
  v.pop_back();
}

//print only one such subsequence
bool printK1Subs(int arr[], int n, int k, vector<int> &v, int idx = 0, int sum = 0){
  if (idx == n){
    if (sum == k){
      cout << "[ ";
      for (int &x : v){
        cout << x << " ";
      }
      cout << ']';
      cout << endl;
      return true;
    }
    return false;
  }

  if(printK1Subs(arr, n, k, v, idx + 1, sum)) return true;
  v.push_back(arr[idx]);
  if(printK1Subs(arr, n, k, v, idx + 1, sum + arr[idx])) return true;;
  v.pop_back();
  return false;
}

//count of these subs
int getKSubsNo(int arr[], int n, int k, int i = 0, int sum = 0){
  if (i == n){
    if (sum == k) return 1;
    return 0;
  }
  //without adding current element
  int c1 = getKSubsNo(arr, n, k, i + 1, sum);
  //adding current element
  int c2 = getKSubsNo(arr, n, k, i + 1, sum + arr[i]);
  return c1 + c2;
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
  // printKSubs(arr, n, k, v);
  cout << getKSubsNo(arr, n, k);
}