//Program to create a stack using a linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

template<typename T>
struct node{
  T data; 
  node *next; 
  node(T data){
    this -> data = data;
    this -> next = NULL;
  }
};

template<typename T> 
class stackLL{
  node<T> *topnode;
  public:
  stackLL(){
    topnode = NULL;
  }
  stackLL(const stackLL<T> &s){
    if (!s.empty()){
      topnode = new node<T>((s.topnode) -> data);
      node<T> *temp = topnode, *temp1 = s.topnode;
      while (temp1 -> next != NULL){
        temp -> next = new node<T>(temp1 -> next -> data);
        temp = temp -> next; temp1 = temp1 -> next;
      }
    }
  }  
  bool empty() const{
    return topnode == NULL;
  }

  void push(T data){
    node<T> *newnode = new node<T>(data);
    newnode -> next = topnode; 
    topnode = newnode;
  }

  void pop(){
    if (!empty()){
      node<T> *toDelete = topnode;
      topnode = topnode -> next;
      delete toDelete;
    }
  }

  T top() const{
    return topnode -> data;
  }

  void display() const{
    for (auto i = topnode; i != NULL; i = i -> next){
      cout << i -> data << endl;
    }
  }
};

int32_t main(){
  stackLL<char> s;
  int n;
  char x; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> ws >> x;
    s.push(x);
  }
  // while (!s.empty()){
  //   cout << s.top() << endl;
  //   s.pop();
  // }
  s.display();
  stackLL<char> s1 = s;
  s1.display();
  return 0;
}