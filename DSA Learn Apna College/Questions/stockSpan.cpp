//Program to find stock span
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  //using previous greater element concept
  int n; 
  cin >> n; 
  vector<int> prices(n), span(n);
  for (int &x : prices) cin >> x; 
  stack<int> st; 
  int leftGreater;
  for (int i = 0; i < n; i++){
    while (!st.empty() && prices[st.top()] < prices[i]){
      st.pop(); 
    }
    if (st.empty()) leftGreater = -1; 
    else leftGreater = st.top();
    span[i] = i - leftGreater; 
    st.push(i);
  }
  for (int x : span) cout << x << " ";
  cout << endl;
  return 0;
}