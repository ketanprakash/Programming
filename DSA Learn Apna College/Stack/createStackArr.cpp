//Program to create a stack using an array
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define SIZE 10
#define endl '\n'
using namespace std; 

int STACK[SIZE];
int top = -1; 

bool empty(){
  return top == -1;
}

bool full(){
  return top == SIZE - 1;
}

void push(int x){
  if (!full()){
    STACK[++top] = x;
  }
}

void pop(){
  if (!empty()) top--;
}

int Top(){
  if (!empty()) return STACK[top];
  return -1;
}

int32_t main(){
  int n, x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> x; 
    push(x);
  }
  while (!empty()){
    cout << Top() << endl;
    pop();
  }
  return 0;
}