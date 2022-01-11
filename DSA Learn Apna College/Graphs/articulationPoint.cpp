//Program to find articulation points in a graph
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int timer;
vector<int> vis, tin, low;
unordered_set<int> artPoints;

void dfs(vector<int> *adj, int node, int par = -1){
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
      if (tin[node] <= low[child]){
        artPoints.insert(node);
      }
    }
  }
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<int> *adj = new vector<int>[n + 1];
  vis = vector<int>(n + 1, 0);
  tin = vector<int>(n + 1, 0);
  low = vector<int>(n + 1, 0);
  int u, v;
  for (int i = 0; i < e; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vis[1] = 1;
  dfs(adj, 1);
  for (int node : artPoints) cout << node << endl;
  return 0;
}