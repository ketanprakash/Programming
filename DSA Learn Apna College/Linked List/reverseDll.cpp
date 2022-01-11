//Program to reverse a doubly linked list
#include <bits/stdc++.h>  
#include "dll.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void reverse(node* &head){
  node *curr = head, *next = head -> next; 
  while (curr != NULL){
    curr -> next = curr -> prev;
    curr -> prev = next;
    curr = next; 
    if (next != NULL) next = next -> next;
    if (curr != NULL && next == NULL) head = curr;
  }
}

int32_t main(){
  doubly_linked_list l; 
  int n, x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> x;
    l.insertTail(x);
  }
  l.display();
  reverse(l.head);
  l.display();
}