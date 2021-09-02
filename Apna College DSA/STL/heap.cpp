//Program to use stl priority queue
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  priority_queue<int, vector<int>, greater<int> > q;
  int n, x; 
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    q.push(x);
  }
  while (!q.empty()){
    cout << q.top() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}