//Program to represent a graph in adjecency matrix
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, e; 
  cin >> n >> e;
  //0 based indexing
  // int **adj = new int*[n];
  // for (int i = 0; i < n; i++) adj[i] = new int[n];
  // 1 based indexing
  int **adj = new int*[n + 1];
  for (int i = 0; i < n + 1; i++) adj[i] = new int[n + 1];
  int u, v;
  for (int i = 0; i < e; i++){
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}