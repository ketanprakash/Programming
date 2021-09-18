//Program to implement queue using stacks
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//method1: making the dequeue operation costly
template <class t>
class queue1{
  stack<t> queueStore, queueRemove;
  public: 
  void enqueue(int x){
    queueStore.push(x);
  }

  void dequeue(){
    if (queueRemove.empty()){
      while (!queueStore.empty()){
        queueRemove.push(queueStore.top());
        queueStore.pop();
      }
    }
    queueRemove.pop();
  }

  t front(){
    if (queueRemove.empty()){
      while (!queueStore.empty()){
        queueRemove.push(queueStore.top());
        queueStore.pop();
      }
    }
    return queueRemove.top();
  }

  bool empty(){
    return queueStore.empty() && queueRemove.empty();
  }
};

//method2: making the enqueue operation costly
template <class t> 
class queue2{
  stack<t> queueStore, queueInsert;
  public:
  void enqueue(int x){
    while (!queueStore.empty()){
      queueInsert.push(queueStore.top());
      queueStore.pop();
    }
    queueInsert.push(x);
    while (!queueInsert.empty()){
      queueStore.push(queueInsert.top());
      queueInsert.pop();
    }
  }

  void dequeue(){
    queueStore.pop();
  }

  t front(){
    return queueStore.top(); 
  }

  bool empty(){
    return queueStore.empty();
  }
};

int32_t main(){
  queue1<int> q; 
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
10 9 8 7 6 
1 2 3 4 5
*/