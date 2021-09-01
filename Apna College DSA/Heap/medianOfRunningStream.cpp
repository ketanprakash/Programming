//Program to find median of a running stream
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, x; 
  cin >> n; 
  //brute force
  // vector<int> v;
  // for (int i = 0; i < n; i++){
  //   cin >> x;
  //   v.push_back(x);
  //   sort(v.begin(), v.end());
  //   if ((i + 1) % 2 == 0){
  //     cout << (float)(v[i / 2] + v[i / 2 + 1]) / 2; 
  //   }
  //   else cout << v[i / 2];
  // }
  priority_queue<int, vector<int> > mx;
  priority_queue<int, vector<int>, greater<int> > mn; 
  for (int i = 0; i < n; i++){
    cin >> x;
    if (mx.size() == 0 || x < mx.top()){
      mx.push(x);
    }
    else mn.push(x);
    if (mx.size() > mn.size() + 1) {
      mn.push(mx.top()); mx.pop();
    }
    else if (mn.size() > mx.size() + 1){
      mx.push(mn.top()); mn.pop();
    }
    if (mx.size() > mn.size()){
      cout << mx.top() << endl;
    }
    else if (mn.size() > mx.size()){
      cout << mn.top() << endl;
    }
    else {
      cout << (float)(mx.top() + mn.top()) / 2 << endl;
    }
  }
  return 0;
}