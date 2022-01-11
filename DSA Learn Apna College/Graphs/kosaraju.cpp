//Program to implement Kosaraju's algo for scc
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<int> vis;
vector<vector<int> > scc;
void topoSortDfs(vector<int> *adj, int i, stack<int> &st){
  for (int child : adj[i]){
    if (!vis[child]) {
      vis[child] = 1;
      topoSortDfs(adj, child, st);
    }
  }
  st.push(i);
}

void revDfs(vector<int> *adj, int i, vector<int> &v){
  v.push_back(i);
  for (int child : adj[i]){
    if (!vis[child]){
      vis[child] = 1;
      revDfs(adj, child, v);
    }
  }
}

void kosaraju(vector<int> *adj, int n){
  stack<int> topo;
  for (int i = 1; i < n + 1; i++){
    if (!vis[i]) {
      vis[i] = 1;
      topoSortDfs(adj, i, topo);
    }
  }
  vis = vector<int>(n + 1, 0);
  vector<int>* transpose = new vector<int>[n + 1];
  for (int node = 0; node < n + 1; node++){
    for (int child : adj[node]){
      transpose[child].push_back(node);
    }
  }
  while (!topo.empty()){
    int node = topo.top(); 
    topo.pop(); 
    if (!vis[node]){
      scc.push_back({});
      vis[node] = 1;
      revDfs(transpose, node, *(scc.end() - 1));
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
  }
  vis = vector<int>(n + 1, 0);
  kosaraju(adj, n);
  cout << "SCC: " << endl;
  for (auto v : scc){
    for (int x : v){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}