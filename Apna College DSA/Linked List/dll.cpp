//Program to create a doubly linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
  int data; 
  node *prev; 
  node *next;
  node(int data){
    this -> data = data; 
    this -> prev = NULL;
    this -> next = NULL;
  }
};

class doubly_linked_list{
  public:
  node* head; 
  int size;
  doubly_linked_list(){
    head = NULL; 
    size = 0;
  }

  void insertHead(int data){
    node* newnode = new node(data);
    newnode -> next = head;
    if (head != NULL) head -> prev = newnode; 
    head = newnode;
    size++;
  } 

  void insertTail(int data){
    if (head == NULL){
      insertHead(data);
    }
    else {
      node *trav = head; 
      while (trav -> next != NULL){
        trav = trav -> next;
      }
      trav -> next = new node(data);
      trav -> next -> prev = trav;
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
    else {
      node *temp = head, *newnode = new node(data); 
      for (int i = 0; i < idx - 1; i++){
        temp = temp -> next;
      }
      newnode -> next = temp -> next;
      newnode -> next -> prev = newnode;
      newnode -> prev = temp;
      temp -> next = newnode;
      size++; 
    }
  }

  void removeHead(){
    if (head != NULL){
      node* oldHead = head; 
      head = head -> next; 
      if (head != NULL) head -> prev = NULL; 
      delete oldHead;
      size--;
    }
    else {
      cout << "Empty List!!" << endl;
    }
  }

  void removeTail(){
    if (head != NULL){
      node* temp = head; 
      while (temp -> next -> next != NULL){
        temp = temp -> next;
      }
      delete temp -> next; 
      temp -> next = NULL;
      size--;
    }
    else {
      cout << "Empty List!!" << endl;
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
        node* temp = head;
        for (int i = 0; i < idx - 1; i++){
          temp = temp -> next;
        }
        temp -> next = temp -> next -> next; 
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
        size--;
      }
    }
    else {
      cout << "Empty List!!" << endl;
    }
  }

  void display(){
    cout << "NULL -> ";
    for (node* temp = head; temp != NULL; temp = temp -> next){
      cout << temp -> data << " -> ";
    }
    cout << "NULL" << endl;
  }

  void displayRev(){
    node* end = head; 
    while (end -> next != NULL){
      end = end -> next;
    }
    cout << "NULL <- ";
    for (auto i = end; i != NULL; i = i -> prev){
      cout << i -> data << " <- ";
    }
    cout << "NULL" << endl;
  }
};