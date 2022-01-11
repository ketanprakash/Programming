//Program to queue using stack and recursion
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

template <class t> 
class queueR{
  stack<t> st;

  public:
  void enqueue(int x){
    if (st.empty()){
      st.push(x);
      return;
    }
    int y = st.top();
    st.pop();
    enqueue(x);
    st.push(y);
  }

  void dequeue(){
    st.pop();
  }

  t front(){
    return st.top();
  }

  bool empty(){
    return st.empty();
  }
};

int32_t main(){
  queueR<int> q; 
  int n, x; 
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    q.enqueue(x);
  }

  while (!q.empty()){
    cout << q.front() << " ";
    q.dequeue();
  }
  return 0;
}

/*
1 2 3 4 5

5
4
3
2
*/