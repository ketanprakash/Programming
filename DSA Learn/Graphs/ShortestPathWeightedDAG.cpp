//Program to find shortest path in a DAG
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<int> vis;
void topoSort(vector<pair<int, int> > *adj, int i, stack<int> &st){
  for (auto p : adj[i]){
    int x = p.first;
    if (vis[x]) continue;
    topoSort(adj, x, st);
  }
  st.push(i);
}

vector<int> findDist(vector<pair<int, int> > *adj, int src, int n){
  vis[src] = 0;
  vector<int> dist(n, INT_MAX);
  stack<int> topo;
  topoSort(adj, src, topo);
  dist[src] = 0;
  while (!topo.empty()){
    int node = topo.top(); 
    topo.pop();
    if (dist[node] != INT_MAX){
      for (pair<int, int> p : adj[node]){
        int x = p.first, wt = p.second;
        if (dist[node] + wt < dist[x]) dist[x] = dist[node] + wt;
      }
    }
  }
  return dist;
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<pair<int, int> > *adj = new vector<pair<int, int> >[n];
  int u, v, wt;
  for (int i = 0; i < e; i++){
  cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
  }
  vis = vector<int>(n, 0);
  vector<int> dist = findDist(adj, 0, n);
  for (int i = 0; i < n; i++){
    cout << i << " : " << dist[i] << endl;
  }
  return 0;
}