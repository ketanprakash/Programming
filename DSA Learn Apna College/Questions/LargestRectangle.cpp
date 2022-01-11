//Program to find largest rectangle in a histogram
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  //brute force solution
  int n, maxarea = 0; 
  cin >> n; 
  vector<int> v(n); 
  for (int &x : v){
    cin >> x;
  }
  // int minh;
  // maxarea = 2 * min(v[0], v[1]);
  // for (int i = 0; i < n; i++){
  //   minh = v[i];
  //   for (int j = i + 1; j < n; j++){
  //     minh = min(minh, v[j]);
  //     maxarea = max(maxarea, minh * (j - i + 1));
  //   }
  // }
  // cout << maxarea << endl;
  //brute force solution
  // for (int i = 0; i < n; i++){
  //   int left_smaller = i - 1;
  //   while (left_smaller >= 0 && v[left_smaller] >= v[i]){
  //     left_smaller--;
  //   }
  //   int right_smaller = i + 1;
  //   while (left_smaller <= n - 1 && v[right_smaller] >= v[i]){
  //     right_smaller++;
  //   }
  //   int l = right_smaller - left_smaller - 1;
  //   maxarea = max(maxarea, l * v[i]);
  // }
  // cout << maxarea << endl;
  //optimised solution using next greater element concept
  // stack<int> st; 
  // vector<int> left_small(n), right_small(n);
  // for (int i = 0; i < n; i++){
  //   while (!st.empty() && v[st.top()] >= v[i]){
  //     st.pop();
  //   }
  //   if (st.empty()) {
  //     left_small[i] = -1;
  //   }
  //   else {
  //     left_small[i] = st.top();
  //   }
  //   st.push(i);
  // }
  // while (!st.empty()) st.pop();
  // for (int i = n - 1; i >= 0; i--){
  //   while (!st.empty() && v[st.top()] >= v[i]){
  //     st.pop();
  //   }
  //   if (st.empty()) {
  //     right_small[i] = n;
  //   }
  //   else {
  //     right_small[i] = st.top();
  //   }
  //   st.push(i);
  // }
  // for (int i = 0; i < n; i++){
  //   maxarea = max(maxarea, (right_small[i] - left_small[i] - 1) * v[i]);
  // }
  // cout << maxarea;
  //most optimised solution with only 1 pass
  stack<int> st; 
  int leftSmaller = -1, rightSmaller = n, x;
  for (int i = 0; i <= n; i++){
    while (!st.empty() && (i == n || v[st.top()] > v[i])){
      x = v[st.top()];
      st.pop();
      if (st.empty()) leftSmaller = -1;
      else leftSmaller = st.top();
      rightSmaller = i;
      maxarea = max(maxarea, (rightSmaller - leftSmaller - 1) * x);
    }
    if (i != n) st.push(i);
  }
  cout << maxarea;
  return 0;
}