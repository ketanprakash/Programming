//Program to detect a cycle in graph using bfs algo
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std;

bool cycleBfs(vector<int> *adj, int n){
  vector<int> v(n + 1, 0);
  queue<pair<int, int> > q; 
  for (int i = 1; i < n + 1; i++){
    if (v[i]) continue;
    q.push(pair<int, int>(i, -1));
    v[i] = 1;
    while (!q.empty()){
      auto p = q.front();
      // cout << p.first << " ";
      q.pop();
      for (int x : adj[p.first]){
        if (!v[x]){
          q.push(pair<int, int>(x, p.first));
          v[x] = 1;
        }
        else if (p.second != x){
          return true;
        }
      }
    }
  }
  return false;
}

bool cycleDfs(vector<int> *adj, int n){
  vector<int> v(n + 1, 0);
  stack<pair<int, int> > st;
  for (int i = 1; i < n + 1; i++){
    if (v[i]) continue;
    st.push(pair<int, int>(i, -1));
    v[i] = 1; 
    while (!st.empty()){
      auto p = st.top(); 
      st.pop(); 
      for (int j = adj[p.first].size() - 1; j >= 0; j--){
        if (!v[adj[p.first][j]]){
          st.push(pair<int, int>(adj[p.first][j], p.first));
          v[adj[p.first][j]] = 1;
        }
        else if (p.second != adj[p.first][j]){
          return true;
        }
      }
    }
  }
  return false;
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
  cout << cycleBfs(adj, n) << endl;
  cout << cycleDfs(adj, n) << endl;
  return 0;
}
