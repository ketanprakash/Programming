//Program to store a graph in an adjecency list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, e; 
  cin >> n >> e; 
  //0 based indexing
  // vector<int> *adj = new vector<int>[n];
  //1 based indexing
  vector<int> *adj = new vector<int>[n + 1];
  int u, v;
  for (int i = 0; i < e; i++){
    cin >> u >> v; 
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i < n + 1; i++){
    cout << i << " : ";
    for (int x : adj[i]){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}