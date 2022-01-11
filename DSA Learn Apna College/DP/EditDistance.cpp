//Program to find the min number of steps taken to convert str1 to str2 using three operations
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<vector<int>> dp;

int minEdits(string &s1, int n, string &s2, int m){
  if (n == 0){
    return m;
  }
  if (m == 0){
    return n;
  }

  if (dp[n][m] != -1) return dp[n][m];

  if (s1[n - 1] == s2[m - 1]) return minEdits(s1, n - 1, s2, m - 1);
  else {
    //for inserting : n, m - 1
    //for removing: n - 1, m
    //for replacement: n - 1, m - 1
    return dp[n][m] = 1 + min(min(minEdits(s1, n, s2, m - 1), minEdits(s1, n - 1, s2, m - 1)), minEdits(s1, n - 1, s2, m));
  }
}

int32_t main(){
  string s1, s2; 
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
  cout << minEdits(s1, n, s2, m) << endl;
  return 0;
}