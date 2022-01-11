//Program to create a stack using a linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
  int data; 
  node *next; 
  node(int data){
    this -> data = data;
    this -> next = NULL;
  }
};

node *topnode = NULL;

bool empty(){
  return topnode == NULL;
}

void push(int data){
  node *newnode = new node(data);
  newnode -> next = topnode; 
  topnode = newnode;
}

void pop(){
  if (!empty()){
    node *toDelete = topnode;
    topnode = topnode -> next;
    delete toDelete;
  }
}

int top(){
  return topnode -> data;
}

int32_t main(){
  int n, x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> x;
    push(x);
  }
  while (!empty()){
    cout << top() << endl;
    pop();
  }
  return 0;
}