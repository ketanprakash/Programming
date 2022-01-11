//Program to reverse a stackArr
#include <bits/stdc++.h>  
#include "stackArr.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//reversing a stack by storing elements into different stack and changing name of stack O(n)
template<class T> 
void revStack(stackArr<T> &stack1){
  stackArr<T> s; 
  while (!stack1.empty()){
    s.push(stack1.top());
    stack1.pop();
  }
  stack1 = s;
}

//reverse stack using recursion o(n ** 2)
template<class T> 
void insertBottom(stackArr<T> &stack1, T x){
  if (stack1.empty()){
    stack1.push(x);
    return;
  }
  T thisTop = stack1.top();
  stack1.pop();
  insertBottom(stack1, x);
  stack1.push(thisTop);
}

template<class T> 
void reverse(stackArr<T> &stack1){
  if (stack1.empty() || stack1.size() == 1){
    return;
  }
  T x = stack1.top();
  stack1.pop();
  reverse<T>(stack1);
  insertBottom<T>(stack1, x);
}

int32_t main(){
  int n, x; 
  cin >> n;
  stackArr<int> st; 
  for (int i = 0; i < n; i++){
    cin >> x;
    st.push(x);
  }
  st.display();
  revStack<int>(st);
  cout << endl;
  st.display();
  return 0;
}