//Program to create a circular queue
#include <bits/stdc++.h>  
#define SIZE 10
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

template <class t>
class circularQueueArr{
  public:
  t *QUEUE;
  int f; 
  int r;
  int capacity;

  circularQueueArr(int size = SIZE){
    capacity = size;
    QUEUE = new t[capacity];
    f = r = -1;
  }

  bool empty(){
    return f == -1;
  }

  bool full(){
    return f % capacity == (r + 1) % capacity;
  }

  void extend(){
    capacity *= 2;
    t *newQUEUE = new t[capacity];
    int j = 0;
    for (int i = f; i != r; i = (i + 1) % (capacity/2)){
      newQUEUE[j] = QUEUE[i]; 
      j++;
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
      f = (f + 1) % capacity; r = (r + 1) % capacity; 
      QUEUE[r] = x;
    }
    else {
      r = (r + 1) % capacity; 
      QUEUE[r] = x;
    }
  }

  void dequeue(){
    if (!empty()){
      if (f == r){
        f = r = -1;
      }
      else {
        f = (f + 1) % capacity;
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
      for (int i = f; i != r; i = (i + 1) % capacity){
        cout << QUEUE[i] << " ";
      }
      cout << QUEUE[r] << endl;
    }
  }
};