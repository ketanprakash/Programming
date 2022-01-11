//Program to perform Topological Sort in DFS
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

stack<int> st; 
vector<bool> vis;
void topoDfs(vector<int>* adj, int i){
  for (int x : adj[i]){
    if (!vis[x]) {
      topoDfs(adj, x);
      vis[x] = 1;
    }
  }
  st.push(i);
}

vector<int> topoSort(vector<int>* adj, int n){
  for (int i = 0; i < n; i++){
    if (!vis[i]){
      topoDfs(adj, i);
      vis[i] = 1;
    }
  }
  vector<int> v;
  while (!st.empty()){
    v.push_back(st.top());
    st.pop();
  }
  return v;
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
  vis = vector<bool>(n);
  vector<int> sorted = topoSort(adj, n);
  for (int x : sorted) cout << x << " ";
  cout << endl;
  return 0;
}