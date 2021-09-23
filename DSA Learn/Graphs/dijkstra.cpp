//Program to implement djisktra's algo to find shortest path in undirected graph
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<int> findDist(vector<pair<int, int> > *adj, int src, int n){
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minheap;
  vector<int> dist(n + 1, INT_MAX);
  dist[src] = 0;
  minheap.push({0, src});
  while (!minheap.empty()){
    pair<int, int> nodePair = minheap.top(); 
    minheap.pop();
    int node = nodePair.second;
    for (auto xPair : adj[node]){
      int x = xPair.first, wt = xPair.second;
      if (dist[node] + wt < dist[x]){
        dist[x] = dist[node] + wt;
        minheap.push({dist[x], x});
      }
    }
  }
  return dist;
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<pair<int, int> > *adj = new vector<pair<int, int> >[n + 1];
  int u, v, wt;
  for (int i = 0; i < e; i++){
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  int src; 
  cin >> src;
  vector<int> dist = findDist(adj, src, n);
  for (int i = 1; i < n + 1; i++){
    cout << i << " : " << dist[i] << endl;
  }
  return 0;
}