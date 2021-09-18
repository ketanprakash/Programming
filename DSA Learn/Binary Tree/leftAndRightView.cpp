//Program to find the right view of binary tree
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void rightView(const binary_tree &tree){
  queue<node*> q;
  q.push(tree.root);
  q.push(NULL);
  while (!q.empty()){
    node* temp = q.front(); 
    q.pop();
    if (temp != NULL){
      if (q.front() == NULL){
        cout << temp -> data << " ";
      }
      if (temp -> left != NULL) q.push(temp -> left);
      if (temp -> right != NULL) q.push(temp -> right);
    }
    else{
      if (!q.empty()){
        q.push(NULL);
      }
    }
  }
}

void leftView(const binary_tree &tree){
  queue<node*> q;
  q.push(tree.root);
  q.push(NULL);
  cout << (tree.root) -> data << " ";
  while (!q.empty()){
    node* temp = q.front(); 
    q.pop();
    if (temp != NULL){
      if (temp -> left != NULL) q.push(temp -> left);
      if (temp -> right != NULL) q.push(temp -> right);
    }
    else{
      if (!q.empty()){
        cout << (q.front()) -> data << " ";
        q.push(NULL);
      }
    }
  }
}

int32_t main(){
  binary_tree tree;
  (tree.root) = new node(1);

  (tree.root) -> left = new node(2);
  (tree.root) -> right = new node(3);

  (tree.root) -> left -> left = new node(4);
  (tree.root) -> right -> left = new node(6);

  (tree.root) -> left -> right = new node(5);
  (tree.root) -> right -> right = new node(7);

  (tree.root) -> left -> left -> left = new node(10);
  (tree.root) -> left -> left -> right = new node(20);

  tree.print(); 
  cout << endl;
  // rightView(tree);
  leftView(tree);
  return 0;
}