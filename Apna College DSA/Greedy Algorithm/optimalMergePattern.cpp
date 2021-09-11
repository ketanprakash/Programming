//Program to 
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, cost = 0; 
  cin >> n; 
  priority_queue<int, vector<int>, greater<int> > mi;
  int x;
  for (int i = 0; i < n; i++){
    cin >> x; 
    mi.push(x);
  }
  int f, s;
  while (mi.size() > 1){
    f = mi.top(); 
    mi.pop();
    s = mi.top();
    mi.pop();
    cost += f + s;
    mi.push(f + s);
  }
  cout << cost << endl;
  return 0;
}