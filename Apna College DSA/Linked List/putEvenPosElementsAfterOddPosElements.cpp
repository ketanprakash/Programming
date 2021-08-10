//Program to put even position nodes after odd position nodes
#include <bits/stdc++.h>  
#include "ll.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void evenAfterOdd(node* &head){
  if (head != NULL){
    node *headEven = new node(INT_MIN), *headOdd = new node(INT_MIN);
    node *temp = head, *t1 = headEven, *t2 = headOdd; 
    int count = 0; 
    while (temp != NULL){
      if (count % 2 == 0){
        t1 -> next = temp;
        t1 = t1 -> next;
      }
      else {
        t2 -> next = temp; 
        t2 = t2 -> next;
      }
      temp = temp -> next; count++;
    }
    t2 -> next = headEven -> next;
    t1 -> next = NULL;
    head = headOdd -> next; 
    delete headEven; delete headOdd;
  }
}

void evenAfterOdd2(node* &head){
  if (head != NULL){
    node *oddStart = head -> next, *even = head, *odd = head -> next;
    int count = 0; 
    while (odd -> next != NULL && even -> next != NULL){
      if (count % 2 == 0) {
        even -> next = odd -> next;
        even = even -> next;
      } 
      else {
        odd -> next = even -> next;
        odd = odd -> next; 
      }
      count++;
    }
    if (odd -> next == NULL){
      even -> next = NULL; 
      odd -> next = head; 
      head = oddStart;
    }
    else if (even -> next == NULL){
      odd -> next = head; 
      head = oddStart;
    }
  }
}

int32_t main(){
  int n; 
  cin >> n; 
  int* arr = new int[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  linked_list list(arr, n);
  list.display();
  evenAfterOdd2(list.head);
  // cout << list.head -> data;
  list.display(); 
  return 0;
}