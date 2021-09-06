//Program to use hash_map
#include <bits/stdc++.h> 
#include <unordered_map> 
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  unordered_map<int, int> um; 
  um[1] = 100;
  um[200] = 50;
  um[10] = 40;
  cout << um[1] << " " << um[200] << " " << um[10] << endl;
  map<int, int> m;
  m[1] = 100;
  m[200] = 50;
  m[10] = 40;
  cout << m[1] << " " << m[200] << " " << m[10] << endl;
  return 0;
}