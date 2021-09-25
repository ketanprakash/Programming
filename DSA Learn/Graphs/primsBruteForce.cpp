//Program to implement prims algo brute force
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<pair<int, int> > *adj = new vector<pair<int, int> >[n];
  int u, v, wt;
  for (int i = 0; i < e; i++){
  cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  int *key = new int[n];
  bool *mst = new bool[n];
  int *parent = new int[n];
  for (int i = 0; i < n; i++){
    key[i] = INT_MAX; mst[i] = false; parent[i] = -1;
  }
  key[0] = 0;
  for (int count = 0; count < n - 1; count++){
    int mn = INT_MAX, mn_idx = -1;
    for (int i = 0; i < n; i++){
      if (mn > key[i] && !mst[i]){
        mn = key[i];
        mn_idx = i;
        mst[i] = true;
      }
    }
    int node = mn_idx;
    for (auto childPair : adj[node]){
      int child = childPair.first, wt = childPair.second;
      if (wt < key[child]){
        key[child] = wt;
        parent[child] = node;
      }
    }
  }
  cout << "Edges: " << endl;
  for (int i = 1; i < n; i++){
    cout << parent[i] << " " << i << " " << key[i] << endl;
  }
  return 0;
}