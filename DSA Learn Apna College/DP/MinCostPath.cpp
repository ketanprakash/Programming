//Program to find the minimum cost path
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int cost[3][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
int minPath[3][3];

int path(int x1, int y1, int x2, int y2){
  if (minPath[x1][y1] != 0) return minPath[x1][y1];
  if (x1 > x2 || y1 > y2) return INT_MAX;

  if (x1 == x2 && y1 == y2){
    return minPath[x1][y1] = cost[x2][y2];
  }

  int x = min(path(x1 + 1, y1, x2, y2), min(path(x1 + 1, y1 + 1, x2, y2), path(x1, y1 + 1, x2, y2)));
  return minPath[x1][y1] = (x != INT_MAX ? cost[x1][y1] + x : x);
}

int32_t main(){
  cout << path(0, 0, 2, 2);
  return 0;
}