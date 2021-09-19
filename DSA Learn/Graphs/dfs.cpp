//Program to perform depth first search of graphs
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

vector<bool> v;

void dfs(vector<int>* &adj, int i){
  cout << i << " ";
  v[i] = 1;
  for (int x : adj[i]){
    if (!v[x]) dfs(adj, x);
  }
}

void dfsStack(vector<int>* &adj, int i){
  stack<int> st;
  st.push(i);
  v[i] = 1;
  while (!st.empty()){
    int j = st.top(); 
    cout << j << " ";
    st.pop(); 
    for (int k = adj[j].size() - 1; k >= 0; k--){
      if (!v[adj[j][k]]) {
        st.push(adj[j][k]);
        v[adj[j][k]] = 1;
      }
    }
  }
}

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<int> *adj = new vector<int>[n + 1];
  int a, b; 
  for (int i = 0; i < e; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  v = vector<bool>(n + 1, 0);
  for (int i = 1; i < n + 1; i++){
    if (!v[i]) dfsStack(adj, i);
  }
  return 0;
}