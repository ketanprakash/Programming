//Program to reverse a circular linked list
#include <bits/stdc++.h>  
#include "cll.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void reverse(node* &head){
  if (head != NULL && head -> next != NULL){
    node* temp = head; 
    while (temp -> next != head){
      temp = temp -> next;
    }
    temp -> next = NULL;
    node *prev = NULL, *curr = head, *next = head -> next;
    while (curr != NULL){
      curr -> next = prev; 
      prev = curr; 
      curr = next; 
      if (next != NULL) next = next -> next;
    }
    head -> next = prev;
    head = prev; 
  }
}

int32_t main(){
  int n; cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  circular_linked_list list(arr, n);
  list.display();
  reverse(list.head);
  list.display();
  return 0;
}