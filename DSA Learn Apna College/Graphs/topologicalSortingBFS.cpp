//Program to perform topological sorting using bfs algo(Kahn's algo)
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<int> topoSort(vector<int> *adj, int n){
  vector<int> indegree(n, 0);
  vector<int> topo;
  queue<int> q;
  for (int i = 0; i < n; i++){
    for (int j : adj[i]) indegree[j]++;
  }
  
  for (int i = 0; i < n; i++){
    if (indegree[i] == 0){
      q.push(i);
    }
  }

  while (!q.empty()){
    int node = q.front(); 
    q.pop(); 
    topo.push_back(node);
    for (int x : adj[node]){
      indegree[x]--;
      if (indegree[x] == 0){
        q.push(x);
      }
    }
  }
  return topo;
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
  vector<int> sorted = topoSort(adj, n);
  for (int x : sorted){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}