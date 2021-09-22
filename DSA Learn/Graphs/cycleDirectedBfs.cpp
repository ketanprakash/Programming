//Program to detect cycle in directed graph using bfs
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool cyclic(vector<int> *adj, int n){
  vector<int> indegree(n, 0);
  queue<int> q;
  int count = 0;
  for (int i = 0; i < n; i++){
    for (int j : adj[i]){
      indegree[j]++;
    }
  }

  for (int i = 0; i < n; i++){
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()){
    int i = q.front(); 
    q.pop(); 
    count++;
    for (int x : adj[i]){
      indegree[x]--;
      if (indegree[x] == 0) q.push(x);
    }
  }
  if (count == n) return false;
  return true;
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<int> *adj = new vector<int>[n];
  int u, v;
  for (int i = 0; i < e; i++){
    cin >> u >> v;
    adj[u].push_back(v);
  }
  cout << (cyclic(adj, n) ? "Cyclic" : "Not Cyclic") << endl;
  return 0;
}