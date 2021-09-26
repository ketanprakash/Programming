//Program to implement disjoint set
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

class disjointSet{
  vector<int> rank;
  vector<int> parent;
  public:
  disjointSet(){
    rank = vector<int>(1000);
    parent = vector<int>(1000);
    for (int i = 0; i < 1000; i++){
      rank[i] = 0;
      parent[i] = i;
    }
  }

  int findPar(int u){
    if (parent[u] == u){
      return u;
    }
    return parent[u] = findPar(parent[u]);
  }

  void doUnion(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if (rank[u] > rank[v]){
      parent[v] = u;
    }
    else if (rank[v] > rank[u]){
      parent[u] = v;
    }
    else {
      parent[v] = u;
      rank[u]++;
    }
  }
};