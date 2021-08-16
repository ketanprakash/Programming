//Program to create a deque using circular array
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define SIZE 10
#define endl '\n'
using namespace std; 

int DEQUE[10];
int front = -1; 
int rear = -1;

bool empty(){
  return front == -1;
}

bool full(){
  return front == (rear + 1) % SIZE;
}

void push_back(int x){
  if (full()){
    return;
  }
  if (empty()){
    front = (front + 1) % SIZE;
    rear = (rear + 1) % SIZE;
    DEQUE[rear] = x;
  }
  else{
    rear = (rear + 1) % SIZE;
    DEQUE[rear] = x;
  }
}

void push_front(int x){
  if (full()){
    return;
  }
  if (empty()){
    front = (front + 1) % SIZE;
    rear = (rear + 1) % SIZE;
    DEQUE[rear] = x;
  }
  else{
    front = (front - 1) % SIZE;
    if (front < 0) front += SIZE;
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
    front = (front + 1) % SIZE;
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
    rear = (rear - 1) % SIZE;
    if (rear < 0) rear += SIZE;
  }
}

int Front(){
  return DEQUE[front];
}

int Rear(){
  return DEQUE[rear];
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