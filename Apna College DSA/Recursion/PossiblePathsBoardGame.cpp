#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int numberOfPaths(int s, int e){
  if (s == e){
    return 1; 
  }
  if (s > e){
    return 0;
  }
  int paths = 0;
  for (int i = s + 1; (i <= s + 6); i++){
    paths += numberOfPaths(i, e);
  }
  return paths;
}

int32_t main(){
  int n; 
  cin >> n;
  cout << numberOfPaths(0, n);
  return 0;
}