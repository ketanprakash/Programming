//Program to detect a cycle in directed graph using DFS
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<bool> vis;
vector<bool> dfsVis;

bool cycleDfs(vector<int>* &adj, int i){
  for (int x : adj[i]){
    if (!vis[x]){
      vis[x] = 1; dfsVis[x] = 1;
      if (cycleDfs(adj, x)) return true;
    }
    else if (dfsVis[x]) return true;
  }
  dfsVis[i] = 0;
  return false;
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<int> *adj = new vector<int>[n + 1];
  int u, v;
  for (int i = 0; i < e; i++){
    cin >> u >> v;
    adj[u].push_back(v);
  }
  vis = vector<bool>(n + 1, 0);
  dfsVis = vector<bool>(n + 1, 0);
  bool flag = 0;
  for (int i = 1; i < n + 1; i++){
    if (!vis[i]) {
      vis[i] = 1;
      dfsVis[i] = 1;
      if (cycleDfs(adj, i)) {
        flag = 1;
        cout << true << endl;
        break;
      }
    }
  }
  if (!flag) cout << false << endl;
  return 0;
}
 
