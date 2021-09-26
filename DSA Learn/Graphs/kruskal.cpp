//Program to implement Kruskal's algo
#include <bits/stdc++.h> 
#include "disjointSet.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  vector<pair<int, pair<int, int> > > graph;
  vector<pair<int, pair<int, int> > > mst;
  disjointSet dset;
  int u, v, wt;
  for (int i = 0; i < e; i++){
    cin >> u >> v >> wt;
    graph.push_back({wt, {u, v}});
  }
  sort(graph.begin(), graph.end());
  for (uint i = 0; i < graph.size(); i++){
    int wt = graph[i].first, u = graph[i].second.first, v = graph[i].second.second;
    if (dset.findPar(u) != dset.findPar(v)){
      dset.doUnion(u, v);
      mst.push_back({wt, {u, v}});
    }
  }
  cout << "Edges: " << endl;
  for (uint i = 0; i < mst.size(); i++){
    cout << mst[i].second.first << " " << mst[i].second.second << " " << mst[i].first << endl;
  }
  return 0;
}