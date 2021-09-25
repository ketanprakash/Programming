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
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minheap;
  int *key = new int[n];
  int *parent = new int[n];
  int *mst = new int[n];
  for (int i = 0; i < n; i++){
    key[i] = INT_MAX; parent[i] = -1; mst[i] = false;
  }
  key[0] = 0;
  minheap.push({0, 0});
  for (int count = 0; count < n - 1; count++){
    int node = minheap.top().second;
    minheap.pop();
    mst[node] = true;
    for (auto childPair : adj[node]){
      int child = childPair.first, wt = childPair.second;
      if (wt < key[child] && !mst[child]){
        key[child] = wt;
        parent[child] = node;
        minheap.push({wt, child});
      }
    }
  }
  cout << "Edges: " << endl;
  for (int i = 1; i < n; i++){
    cout << parent[i] << " " << i << " " << key[i] << endl;
  }
  return 0;
}