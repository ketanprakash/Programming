//Program to create a linear queue
#include <bits/stdc++.h>  
#define SIZE 10
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int QUEUE[SIZE];
int front = -1; 
int rear = -1;

bool empty(){
  return front == -1;
}

bool full(){
  return rear == SIZE - 1;
}

void enqueue(int x){
  if (!full()){
    if (empty()){
      front++; rear++; 
      QUEUE[rear] = x;
    }
    else {
      rear++; 
      QUEUE[rear] = x;
    }
  }
  else {
    cout << "Queue full! Cannot add elements";
  }
}

void dequeue(){
  if (!empty()){
    front++;
  }
  else {
    cout << "Queue Empty! Cannot remove item";
  }
}

int Front(){
  return QUEUE[front];
}

int Rear(){
  return QUEUE[rear];
}

void display(){
  for (int i = front; i != rear; i++){
    cout << QUEUE[i] << " ";
  }
  cout << QUEUE[rear] << endl;
}

int32_t main(){
  int n, x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> x;
    enqueue(x);
  } 
  dequeue();
  dequeue();
  display();
  return 0;
}