//Program to implement stack using queue
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

/*
1 2 3 4 5
*/

//method1: making push operation costly
template <class t>
class stack1{
  queue<t> stackStore, stackInsert;

  public:
  void push(int x){
    stackInsert.push(x);
    while (!stackStore.empty()){
      stackInsert.push(stackStore.front());
      stackStore.pop();
    }
    queue<t> tmp = stackStore;
    stackStore = stackInsert;
    stackInsert = tmp;
  }

  void pop(){
    stackStore.pop();
  }

  t top(){
    return stackStore.front();
  }

  bool empty(){
    return stackStore.empty() && stackInsert.empty();
  }
};

//method2: making pop operation costly
template <class t>
class stack2{
  queue<t> stackStore, stackRemove;

  public:
  void push(int x){
    if (!stackRemove.empty()){
      stackStore.push(stackRemove.front());
      stackRemove.pop();
    }
    stackRemove.push(x);
  }

  void pop(){
    if (stackRemove.empty()){
      int x = stackStore.front();
      stackStore.pop();
      while (!stackStore.empty()){
        stackRemove.push(x);
        x = stackStore.front();
        stackStore.pop();
      }
      stackStore.push(x);
      queue<t> tmp = stackStore;
      stackStore = stackRemove;
      stackRemove = tmp;
    }
    stackRemove.pop();
  }

  t top(){
    if (stackRemove.empty()){
      int x = stackStore.front();
      stackStore.pop();
      while (!stackStore.empty()){
        stackRemove.push(x);
        x = stackStore.front();
        stackStore.pop();
      }
      stackStore.push(x);
      queue<t> tmp = stackStore;
      stackStore = stackRemove;
      stackRemove = tmp;
    }
    return stackRemove.front();
  }

  bool empty(){
    return stackRemove.empty() && stackStore.empty();
  }
};

int32_t main(){
  stack2<int> st;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    st.push(x);
  }
  while (!st.empty()){
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}

/*
q1: 5 4 3 2 1
q2: 
*/