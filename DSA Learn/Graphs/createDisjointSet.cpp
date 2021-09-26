//Program to impelement a disjoint set
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int parentArray[10000];
int rankArray[10000];

void disjointSet(){
  for (int i = 0; i < 10000; i++){
    parentArray[i] = i; 
    rankArray[i] = 0;
  }
}

int findPar(int node){
  if (parentArray[node] == node) return node;
  return parentArray[node] = findPar(parentArray[node]);
}

void doUnion(int node1, int node2){
  node1 = findPar(node1);
  node2 = findPar(node2);
  if (rankArray[node1] > rankArray[node2]){
    parentArray[node2] = node1;
  }
  else if (rankArray[node1] < rankArray[node2]){
    parentArray[node1] = node2;
  }
  else {
    parentArray[node1] = node2;
    rankArray[node2]++;
  }
}

int32_t main(){
  disjointSet();
  int t, u, v; 
  cin >> t;
  while (t--){
    cin >> u >> v; 
    doUnion(u, v);
  }
  //if 2 and 3 are from the same component
  cout << (findPar(2) == findPar(3) ? "Same component" : "Not Same component") << endl;
  return 0;
}