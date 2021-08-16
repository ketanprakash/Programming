//Program to create a deque using circular array
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define SIZE 10
#define endl '\n'
using namespace std; 

template <class t>
class DequeArr{
  t *DEQUE;
  int front; 
  int rear;
  public:
  int capacity;
  DequeArr(int size = SIZE){
    capacity = size;
    DEQUE = new t[capacity];
    front = rear = -1;
  }
  bool empty(){
    return front == -1;
  }

  bool full(){
    return front == (rear + 1) % capacity;
  }

  void extend(){
    t* newDEQUE = new t[capacity * 2];
    int j = 0;
    for (int i = front; i != rear; i = (i + 1) % capacity){
      newDEQUE[j] = DEQUE[i];
      j++;
    }
    newDEQUE[j] = DEQUE[rear];
    delete [] DEQUE;
    DEQUE = newDEQUE;
    front = 0; 
    rear = j;
    capacity *= 2;
  }

  void push_back(t x){
    if (full()){
      extend();
    }
    if (empty()){
      front = (front + 1) % capacity;
      rear = (rear + 1) % capacity;
      DEQUE[rear] = x;
    }
    else{
      rear = (rear + 1) % capacity;
      DEQUE[rear] = x;
    }
  }

  void push_front(t x){
    if (full()){
      extend();
    }
    if (empty()){
      front = (front + 1) % capacity;
      rear = (rear + 1) % capacity;
      DEQUE[rear] = x;
    }
    else{
      front = (front - 1) % capacity;
      if (front < 0) front += capacity;
      DEQUE[front] = x;
    }
  }

  void pop_front(){
    if (empty()){
      return;
    }
    if (front == rear){
      front = rear = -1;
    }
    else {
      front = (front + 1) % capacity;
    }
  }

  void pop_back(){
    if (empty()){
      return;
    }
    if (front == rear){
      front = rear = -1;
    }
    else {
      rear = (rear - 1) % capacity;
      if (rear < 0) rear += capacity;
    }
  }

  t Front(){
    return DEQUE[front];
  }

  t Rear(){
    return DEQUE[rear];
  }
};
