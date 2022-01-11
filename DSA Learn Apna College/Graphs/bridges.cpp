//Program to find bridges in the given graphs
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int timer; 
vector<int> vis, tin, low;

void dfs(vector<int>* adj, int node, int par = -1){
  tin[node] = low[node] = ++timer;
  for (int child : adj[node]){
    if (child == par) continue;
    if (vis[child]){
      //back edge
      low[node] = min(low[node], low[child]);
    }
    else{
      //forward edge
      vis[child] = 1;
      dfs(adj, child, node);
      low[node] = min(low[node], low[child]);
      if (tin[node] < low[child]){
        cout << node << " - " << child << " edge is a bridge" << endl;
      }
    }
  }
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<int> *adj = new vector<int>[n + 1];
  int u, v;
  for (int i = 0; i < e; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vis = vector<int>(n + 1, 0);
  tin = vector<int>(n + 1, 0);
  low = vector<int>(n + 1, 0);
  vis[1] = 1;
  dfs(adj, 1);
  return 0;
}