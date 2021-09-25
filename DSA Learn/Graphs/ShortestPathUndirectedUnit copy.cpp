//Program to find shortest distance in undirected graph with unit weights
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<int> findDistance(vector<int> *adj, int n, int src){
  vector<int> dist(n, INT_MAX);
  queue<int> q; 
  q.push(src);
  dist[src] = 0;
  while (!q.empty()){
    int node = q.front(); 
    q.pop();
    for (int x : adj[node]){
      if ((dist[node] + 1) < dist[x]){
        dist[x] = dist[node] + 1;
        q.push(x);
      }
    }
  }
  return dist;
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
  int src, dist; 
  cin >> src >> dist;
  vector<int> distArray = findDistance(adj, n, 0);
  for (int i = 0; i < n; i++){
    cout << i << " : " << distArray[i] << endl;
  }
  return 0;
}