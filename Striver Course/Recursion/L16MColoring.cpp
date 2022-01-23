#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool check(vector<int> graph[], vector<int> &colors, int node, int color){
  for (int &x : graph[node]){
    if (colors[x] == color) return false;
  }
  return true;
}

bool mColoring(vector<int> graph[], int n, int e, vector<int> &colors, int m, int node = 0){
  if (node == n) return true;
  for (int i = 1; i <= m; i++){
    if (check(graph, colors,  node, i)){
      colors[node] = i;
      if (mColoring(graph, n, e, colors, m, node + 1)) return true;
      colors[node] = 0;
    }
  }
  return false;
}

int32_t main(){
  // Write your code
  int n, e; 
  cin >> n >> e;
  vector<int> graph[n];
  vector<int> colors(n);
  int u, v; 
  for (int i = 0; i < e; i++){
    cin >> u >> v; 
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int m; 
  cin >> m;
  cout << mColoring(graph, n, e, colors, m);
}