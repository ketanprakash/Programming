//Program to 
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 
vector<vector<int>> dp; 

int lcs(string &s1, int n, string &s2, int m){
  if (n == 0 || m == 0) return 0;
  if (dp[n][m] != -1) return dp[n][m];
  if (s1[n - 1] == s2[m - 1]){
    return dp[n][m] = 1 + lcs(s1, n - 1, s2, m - 1);
  }
  else return dp[n][m] = max(lcs(s1, n - 1, s2, m), lcs(s1, n, s2, m - 1)); 
}

int32_t main(){
  string s1, s2;
  cin >> s1 >> s2; 
  int n = s1.size(), m = s2.size();
  dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
  cout << lcs(s1, n, s2, m) << endl;
  return 0;
}