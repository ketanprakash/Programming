//Program to create a circular linked list
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

class circular_linked_list{
  public:
  node *head; 
  int size;
  circular_linked_list(){
    head = NULL; 
    size = 0;
  }
  circular_linked_list(node* head, int n){
    if (head == NULL){
      this -> head = NULL; 
      this -> size = 0;
    }
    else {
      this -> head = head; 
      this -> size = 1; 
      node *temp = head -> next; 
      while (temp != head){
        temp = temp -> next; 
        (this -> size)++;
      }
    }
  }
  circular_linked_list(int *arr, int n){
    this -> head = 0; 
    this -> size = n; 
    insert(arr, n);
  }

  void insert(int *arr, int n){
    if (head == NULL){
      head = new node(arr[0]);
      head -> next = head;
      node *temp = head; 
      for (int i = 1; i < n; i++){
        temp -> next = new node(arr[i]);
        temp -> next -> next = head;
        temp = temp -> next; 
      }
    }
    else {
      node *temp = head; 
      while (temp -> next != head){
        temp = temp -> next;
      }
      for (int i = 0; i < n; i++){
        temp -> next = new node(arr[i]);
        temp -> next -> next = head;
        temp = temp -> next;
      }
    }
    this -> size += n;
  }

  void insertHead(int data){
    if (head == NULL){
      head = new node(data);
      head -> next = head;
    }
    else {
      node *newhead = new node(data), *temp = head;
      newhead -> next = head; 
      while (temp -> next != head){
          temp = temp -> next;
      }
      temp -> next = newhead;
      head = newhead;
    }
    (this -> size)++;
  }

  void insertTail(int data){
    if (head == NULL){
      insertHead(data);
    }
    else {
      node *temp = head; 
      while (temp -> next != head){
          temp = temp -> next;
      }
      temp -> next = new node(data);
      temp -> next -> next = head;
      (this -> size)++;
    }
  }

  void insert(int idx, int data){
    if (head == NULL || idx == 0){
      insertHead(data);
    }
    else if (idx == this -> size){
      insertTail(data);
    }
    else{
      node *temp = head, *newnode = new node(data);
      for (int i = 0; i < idx - 1; i++){
          temp = temp -> next;
      }
      newnode -> next = temp -> next;
      temp -> next = newnode;
      (this -> size)++;
    }
  }

  void removeHead(){
    if (head != NULL){
      node *end = head, *oldhead = head; 
      while (end -> next != head){
        end = end -> next;
      }
      head = head -> next;
      end -> next = head; 
      delete oldhead;   
      (this -> size)--;
    }
  }

  void removeTail(){
    if (head != NULL){
      if (head -> next == NULL){
        delete head; 
        head = NULL;
      }
      else {
        node* temp = head; 
        while (temp -> next -> next != head){
            temp = temp -> next;
        }
        delete temp -> next; 
        temp -> next = head;
      }
      (this -> size)--;
    }
  }

  void remove(int idx){
    if (head != NULL){
      if (idx == 0){
          removeHead();
      }
      else if (idx == this -> size - 1){
        removeTail();
      }
      else{
        node *temp = head; 
        for (int i = 0; i < idx - 1; i++){
            temp = temp -> next;
        }
        node *toDelete = temp -> next; 
        temp -> next = temp -> next -> next;
        delete toDelete;
        (this -> size)--;
      }
    }
  }

  void display(){
    auto i = head;
    for (i = head; i -> next != head; i = i -> next){
      cout << i -> data << " -> ";
    }
    cout << i -> data << " -> " << i -> next -> data << "(head)";
    cout << endl;
  }
};