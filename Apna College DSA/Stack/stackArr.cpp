//Program to create a stack using array as an object
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define SIZE 10
#define endl '\n'
using namespace std; 

template <typename T>
class stackArr{
  T *STACK;
  int t;
  int capacity;
  public:
  stackArr(int size = SIZE){
    STACK = new T[size];
    t = -1;
    capacity = size;
  }

  bool empty() const{
    return t == -1;
  }

  T size() const{
    return t + 1;
  }

  bool full() const{
    return t == capacity - 1;
  }

  void extend(){
    T* newSTACK = new T[capacity * 2];
    for (int i = 0; i <= t; i++){
      newSTACK[i] = STACK[i];
    }
    delete [] STACK;
    STACK = newSTACK;
    capacity *= 2;
  }

  void push(T x){
    if (full()){
      extend();
    }
    STACK[++t] = x;
  }

  void pop(){
    if (!empty()) t--;
  }

  T top() const{
    if (!empty()) return STACK[t];
    else {
      cout << "error, no items in the stack" << endl;
      exit(0);
    }
  }

  void display() const{
    for (int i = t; i >= 0; i--){
      cout << STACK[i] << endl;
    }
  }
};