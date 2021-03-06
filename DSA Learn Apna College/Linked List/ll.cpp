//Program to create a linked list
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

class linked_list{
  public:
  node *head; 
  int size;
  linked_list(){
    head = NULL;
    size = 0;
  }
  linked_list(int *arr, int n){
    head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < n; i++){
      temp -> next = new node(arr[i]);
      temp = temp -> next;
    }
    size = n;
  }
  linked_list(node* head){
    this -> head = head; 
    node* temp = head; size = 0;
    while (temp != NULL){
      temp = temp -> next;
      size++;
    }
  }

  void insert(int *arr, int n){
    if (head == NULL){
      head = new node(arr[0]);
      node *temp = head;
      for (int i = 1; i < n; i++){
        temp -> next = new node(arr[i]);
        temp = temp -> next;
      }
    }
    else {
      node *temp = head; 
      while (temp -> next != NULL){
        temp = temp -> next;
      }
      for (int i = 0; i < n; i++){
        temp -> next = new node(arr[i]);
        temp = temp -> next;
      }
    }
    size += n;
  }
  void insertHead(int data){
    node *newnode = new node(data);
    newnode -> next = head;
    head = newnode;
    size++;
  }

  void insertTail(int data){
    if (head == NULL){
      insertHead(data);
    }
    else{
      node *temp = head;
      while (temp -> next != NULL){
          temp = temp -> next;
      }
      temp -> next = new node(data);
      size++;
    }
  }

  void insert(int idx, int data){
    if (idx == 0){
      insertHead(data);
    }
    else if (idx == size){
      insertTail(data);
    }
    else if (idx < size){
      node *temp = head, *newnode = new node(data);
      for (int i = 0; i < idx - 1; i++){
        temp = temp -> next;
      }
      newnode -> next = temp -> next;
      temp -> next = newnode;
      size++;
    }
    else {
      cout << "Invalid Index" << endl;
    }
  }

  void removeHead(){
    if (head != NULL){
      node *oldHead = head; 
      head = head -> next;
      delete oldHead;
      size--;
    }
    else {
      cout << "No Item in the List" << endl;
    }
  }

  void removeTail(){
    if (head != NULL){
      node *trav = head; 
      while (trav -> next -> next != NULL){
        trav = trav -> next;
      }
      delete trav -> next; 
      trav -> next = NULL; 
      size--;
    }
    else {
      cout << "No item in the list" << endl;
    }
  }

  void remove(int idx){
    if (head != NULL){
      if (idx == 0){
        removeHead();
      }
      else if (idx == size - 1){
        removeTail();
      }
      else {
        node *temp = head;
        for (int i = 0; i < idx - 1; i++){
          temp = temp -> next;
        }
        node* nodeToDelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete nodeToDelete;
        size--;
      }
    }
    else {
      cout << "No Item in the List" << endl;
    }
  }

  bool search(int key){
    for (auto i = head; i != NULL; i = i -> next){
      if (key == i -> data) return true;
    }
    return false;
  }

  void display(){
    for (auto i = head; i != NULL; i = i -> next){
      cout << i -> data << " -> ";
    }
    cout << "NULL" << endl;
  }
};