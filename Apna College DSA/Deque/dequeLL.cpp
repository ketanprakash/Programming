//Program to create a deque using a doubly linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

template <class t>
struct node{
  int data; 
  node<t> *prev;
  node<t> *next;
  node(int data = 0){
    this -> data = data;
    this -> prev = NULL;
    this -> next = NULL;
  }
};

template <class t> 
class DequeLL{
  node<t> *front = NULL; 
  node<t> *rear = NULL;

  public:
  bool empty(){
    return front == NULL; 
  }

  void push_back(t x){
    if (empty()){
      front = rear = new node<t>(x);
    }
    else {
      rear -> next = new node<t>(x);
      rear -> next -> prev = rear;
      rear = rear -> next;
    }
  }

  void push_front(t x){
    if (empty()){
      front = rear = new node<t>(x);
    }
    else {
      front -> prev = new node<t>(x);
      front -> prev -> next = front;
      front = front -> prev;
    }
  }

  void pop_front(){
    if (empty()){
      return;
    }
    if (front == rear){
      delete front; 
      front = rear = NULL;
    }
    else {
      node<t> *toDelete = front; 
      front = front -> next;
      front -> prev = NULL;
      delete toDelete;
    }
  }

  void pop_back(){
    if (empty()){
      return;
    }
    if (front == rear){
      delete front; 
      front = rear = NULL;
    }
    else {
      node<t> *toDelete = rear; 
      rear = rear -> prev;
      rear -> next = NULL;
      delete toDelete;
    }
  }

  t Front(){
    return front -> data;
  }

  t Rear(){
    return rear -> data;
  }
};