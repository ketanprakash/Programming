//Program to perform bfs traversal of graphs
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void bfs(vector<int> *adj, int n){
  queue<int> q; 
  vector<int> v(n + 1, 0);
  for (int i = 1; i < n + 1; i++){
    if (!v[i]){
      q.push(i);
      v[i] = 1;
      while (!q.empty()){
        int j = q.front(); 
        cout << j << " ";
        q.pop(); 
        for (int x : adj[j]){
          if (!v[x]){
            q.push(x);
            v[x] = 1;
          }
        }
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
  bfs(adj, n);
  return 0;
}