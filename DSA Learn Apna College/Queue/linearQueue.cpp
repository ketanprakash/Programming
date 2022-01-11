//Program to create a linear queue
#include <bits/stdc++.h>  
#define SIZE 10
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

template <class t>
class linearQueueArr{
  t *QUEUE;
  int f; 
  int r;
  int capacity;

  public:
  linearQueueArr(int size = SIZE){
    capacity = size;
    QUEUE = new t[capacity];
    f = r = -1;
  }

  bool empty(){
    return f == -1;
  }

  bool full(){
    return r == capacity - 1;
  }

  void extend(){
    capacity *= 2;
    t *newQUEUE = new t[capacity];
    int j = 0;
    for (int i = f; i != r; i++, j++){
      newQUEUE[j] = QUEUE[i]; 
    }
    newQUEUE[j] = QUEUE[r];
    f = 0; r = j;
    delete [] QUEUE;
    QUEUE = newQUEUE;
  }

  void enqueue(t x){
    if (full()){
      extend();
    }
    if (empty()){
      f++; r++; 
      QUEUE[r] = x;
    }
    else {
      r++; 
      QUEUE[r] = x;
    }
  }

  void dequeue(){
    if (!empty()){
      if (f == r){
        f = r = -1;
      }
      else {
        f++;
      }
    }
    else {
      cout << "Queue Empty! Cannot remove item" << endl;
    }
  }

  t front(){
    return QUEUE[f];
  }

  t rear(){
    return QUEUE[r];
  }

  void display(){
    if (!empty()){
      for (int i = f; i != r; i++){
        cout << QUEUE[i] << " ";
      }
      cout << QUEUE[r] << endl;
    }
  }
};