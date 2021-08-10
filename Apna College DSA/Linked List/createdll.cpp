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

int size(node *head){
  int c = 0; 
  node* temp = head; 
  while (temp != NULL){
    temp = temp -> next; 
    c++;
  }
  return c;
}

void insertHead(node* &head, int data){
  node* newnode = new node(data);
  newnode -> next = head;
  if (head != NULL) head -> prev = newnode; 
  head = newnode;
} 

void insertTail(node* &head, int data){
  if (head == NULL){
    insertHead(head, data);
  }
  else {
    node *trav = head; 
    while (trav -> next != NULL){
      trav = trav -> next;
    }
    trav -> next = new node(data);
    trav -> next -> prev = trav;
  }
}

void insert(node* &head, int idx, int data){
  if (idx == 0){
    insertHead(head, data);
  }
  else if (idx == size(head)){
    insertTail(head, data);
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
  }
}

void removeHead(node* &head){
  if (head != NULL){
  node* oldHead = head; 
  head = head -> next; 
  if (head != NULL) head -> prev = NULL; 
    delete oldHead;
  }
  else {
    cout << "Empty List!!" << endl;
  }
}

void removeTail(node* &head){
  if (head != NULL){
    node* temp = head; 
    while (temp -> next -> next != NULL){
      temp = temp -> next;
    }
    delete temp -> next; 
    temp -> next = NULL;
  }
  else {
    cout << "Empty List!!" << endl;
  }
}

void remove(node* &head, int idx){
  if (head != NULL){
    if (idx == 0){
      removeHead(head);
    }
    else if (idx == size(head) - 1){
      removeTail(head);
    }
    else {
      node* temp = head;
      for (int i = 0; i < idx - 1; i++){
          temp = temp -> next;
      }
      temp -> next = temp -> next -> next; 
      delete temp -> next -> prev;
      temp -> next -> prev = temp;
    }
  }
  else {
    cout << "Empty List!!" << endl;
  }
}

void reverse(node *&head){
  node *curr = head, *next = head -> next; 
  while (curr != NULL){
    curr -> next = curr -> prev;
    curr -> prev = next;
    curr = next; 
    if (next != NULL) next = next -> next;
    if (curr != NULL && next == NULL) head = curr;
  }
}

void display(node* head){
  cout << "NULL -> ";
  for (node* temp = head; temp != NULL; temp = temp -> next){
    cout << temp -> data << " -> ";
  }
  cout << "NULL" << endl;
}

void displayRev(node* head){
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

int32_t main(){
  node* head = NULL;
  int n, x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> x;
    insertTail(head, x);
  }
  display(head);
  displayRev(head);
  remove(head, 3);
  display(head);
  displayRev(head);
  reverse(head);
  display(head);
  displayRev(head);
  return 0;
}