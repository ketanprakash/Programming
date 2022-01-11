//Program to find if a graph is a bipartite graph
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool checkBipartiteBfs(vector<int> *adj, int n){
  vector<int> color(n, -1);
  queue<int> q;
  q.push(1);
  color[1] = 0;
  while (!q.empty()){
    int i = q.front(); 
    q.pop(); 
    for (int x : adj[i]){
      if (color[x] == -1){
        q.push(x);
        color[x] = color[i] ? 0 : 1;
      }
      else if (color[x] == color[i]){
        return false;
      }
    }
  }
  return true;
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
  cout << checkBipartiteBfs(adj, n) << endl;
  return 0;
}
