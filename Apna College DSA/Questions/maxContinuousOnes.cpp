//Program to find max subarray of only 1s if we can change k zeros to 1s
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n; 
  cin >> n; 
  vector<int> v(n);
  for (int &x : v) cin >> x; 
  int k; 
  cin >> k;
  int start = 0;
  int zerocnt = 0;
  int maxsize = 0;
  if (v[start] == 0) zerocnt = 1;
  for (int i = 1; i < n; i++){
    if (v[i] == 0){
      zerocnt++;
    }
    while (zerocnt > k){
      if (v[start] == 0){
        zerocnt--;
      }
      start++;
    }
    maxsize = max(maxsize, i - start + 1);
  }
  cout << maxsize << endl;
  return 0;
}