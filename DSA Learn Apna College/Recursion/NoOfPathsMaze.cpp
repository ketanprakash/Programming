#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int noOfPathsMaze(int x1, int y1, int x2, int y2){
  if (x1 == x2 && y1 == y2){
    return 1;
  }
  if (x1 > x2 || y1 > y2){
    return 0;
  }
  return noOfPathsMaze(x1 + 1, y1, x2, y2) + noOfPathsMaze(x1, y1 + 1, x2, y2);
}

int32_t main(){
  int n; 
  cin >> n; 
  cout << noOfPathsMaze(0, 0, n - 1, n - 1);
  return 0;
}