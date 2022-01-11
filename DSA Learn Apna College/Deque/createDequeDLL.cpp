//Program to create a deque using a doubly linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
  int data; 
  node *prev;
  node *next;
  node(int data = 0){
    this -> data = data;
    this -> prev = NULL;
    this -> next = NULL;
  }
};

node *front = NULL; 
node *rear = NULL;

bool empty(){
  return front == NULL; 
}

void push_back(int x){
  if (empty()){
    front = rear = new node(x);
  }
  else {
    rear -> next = new node(x);
    rear -> next -> prev = rear;
    rear = rear -> next;
  }
}

void push_front(int x){
  if (empty()){
    front = rear = new node(x);
  }
  else {
    front -> prev = new node(x);
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
    node *toDelete = front; 
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
    node *toDelete = rear; 
    rear = rear -> prev;
    rear -> next = NULL;
    delete toDelete;
  }
}

int Front(){
  return front -> data;
}

int Rear(){
  return rear -> data;
}

int32_t main(){
  int n, x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> x; 
    push_front(x);
  }
  while (!empty()){
    cout << Front() << endl;
    pop_front();
  }
  return 0;
}