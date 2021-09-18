//Program to create a queue using linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
  public:
  node *next; 
  int data;
  node(int x){
    data = x;
    next = NULL;
  }
};

class queueLL{
  node *frontnode, *rearnode; 
  public:
  queueLL(){
    frontnode = rearnode = NULL;
  }
  bool empty(){
    return frontnode == NULL;
  }

  void enqueue(int x){
    if (empty()){
      frontnode = rearnode = new node(x);
    }
    else {
      rearnode -> next = new node(x);
      rearnode = rearnode -> next;
    }
  }

  void dequeue(){
    if (frontnode == rearnode){
      delete frontnode; 
      frontnode = rearnode = NULL;
      return;
    }
    node *toDelete = frontnode;
    frontnode = frontnode -> next; 
    delete toDelete;
  }

  int front(){
    return frontnode -> data;
  }
};

// int32_t main(){
//   queueLL q;
//   int n, x; 
//   cin >> n;
//   for (int i = 0; i < n; i++){
//     cin >> x; 
//     q.enqueue(x);
//   }

//   while (!q.empty()){
//     cout << q.front() << " ";
//     q.dequeue();
//   }
//   cout << endl;
//   return 0;
// }