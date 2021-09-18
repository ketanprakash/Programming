//Program to find the next greater element
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n; 
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  stack<int> st; 
  vector<int> nge(n);
  for (int i = n - 1; i >= 0; i--){
    while (!st.empty() && st.top() <= v[i]){
      st.pop();
    }
    if (st.empty()) nge[i] = -1; 
    else nge[i] = st.top();
    st.push(v[i]);
  }
  for (int i = 0; i < n; i++){
    cout << nge[i] << " ";
  }
  cout << endl;
  return 0;
}