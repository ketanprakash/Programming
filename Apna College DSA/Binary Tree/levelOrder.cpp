//Program to print tree in level order
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void levelOrder(const binary_tree &tree){
  queue<node*> q;
  q.push(tree.root);
  q.push(NULL);
  while (!q.empty()){
    node* temp = q.front(); 
    q.pop();
    if (temp != NULL){
      cout << temp -> data << " ";
      if (temp -> left != NULL) q.push(temp -> left);
      if (temp -> right != NULL) q.push(temp -> right);
    }
    else if (!q.empty()){
      q.push(NULL);
    }
  }
}

int kLevelSum(const binary_tree &tree, int k){
  queue<node*> q;
  int level = 0;
  int sum = 0;
  q.push(tree.root);
  q.push(NULL);
  while (!q.empty()){
    node* temp = q.front(); 
    q.pop();
    if (temp != NULL){
      if (level == k){
        sum += temp -> data;
      }
      if (temp -> left != NULL) q.push(temp -> left);
      if (temp -> right != NULL) q.push(temp -> right);
    }
    else if (!q.empty()){
      q.push(NULL);
      level++;
    }
  }
  return sum;
}

int32_t main(){
  binary_tree tree; 
  (tree.root) = new node(0);
  (tree.root) -> left = new node(1);
  (tree.root) -> right = new node(1);
  (tree.root) -> left -> left = new node(2);
  (tree.root) -> left -> right = new node(2);
  (tree.root) -> right -> left = new node(2);
  (tree.root) -> right -> right = new node(2);
  (tree.root) -> left -> left -> left = new node(3);
  (tree.root) -> left -> left -> right  = new node(3);
  (tree.root) -> left -> right -> left = new node(3);
  (tree.root) -> left -> right -> right  = new node(3);
  (tree.root) -> right -> left -> left = new node(3);
  (tree.root) -> right -> left -> right = new node(3);
  (tree.root) -> right -> right -> left = new node(3);
  (tree.root) -> right -> right -> right  = new node(3);
  (tree.root) -> left -> left -> left -> left = new node(4);
  (tree.root) -> left -> left -> right -> left  = new node(4);
  (tree.root) -> left -> right -> left -> left = new node(4);
  (tree.root) -> left -> right -> right -> left  = new node(4);
  (tree.root) -> right -> left -> left -> left = new node(4);
  (tree.root) -> right -> left -> right -> left = new node(4);
  (tree.root) -> right -> right -> left -> left = new node(4);
  (tree.root) -> right -> right -> right -> left  = new node(4);
  (tree.root) -> left -> left -> left -> right = new node(4);
  (tree.root) -> left -> left -> right -> right  = new node(4);
  (tree.root) -> left -> right -> left -> right = new node(4);
  (tree.root) -> left -> right -> right -> right  = new node(4);
  (tree.root) -> right -> left -> left -> right = new node(4);
  (tree.root) -> right -> left -> right -> right = new node(4);
  (tree.root) -> right -> right -> left -> right = new node(4);
  (tree.root) -> right -> right -> right -> right = new node(4);
  
  (tree.root) -> left -> left -> left -> left -> left = new node(5);
  (tree.root) -> left -> left -> right -> left -> left  = new node(5);
  (tree.root) -> left -> right -> left -> left -> left = new node(5);
  (tree.root) -> left -> right -> right -> left -> left  = new node(5);
  (tree.root) -> right -> left -> left -> left -> left = new node(5);
  (tree.root) -> right -> left -> right -> left -> left = new node(5);
  (tree.root) -> right -> right -> left -> left -> left = new node(5);
  (tree.root) -> right -> right -> right -> left -> left  = new node(5);
  (tree.root) -> left -> left -> left -> right -> left = new node(5);
  (tree.root) -> left -> left -> right -> right -> left  = new node(5);
  (tree.root) -> left -> right -> left -> right -> left = new node(5);
  (tree.root) -> left -> right -> right -> right -> left  = new node(5);
  (tree.root) -> right -> left -> left -> right -> left = new node(5);
  (tree.root) -> right -> left -> right -> right -> left = new node(5);
  (tree.root) -> right -> right -> left -> right -> left = new node(5);
  (tree.root) -> right -> right -> right -> right -> left = new node(5);

  (tree.root) -> left -> left -> left -> left -> right = new node(5);
  (tree.root) -> left -> left -> right -> left -> right  = new node(5);
  (tree.root) -> left -> right -> left -> left -> right = new node(5);
  (tree.root) -> left -> right -> right -> left -> right  = new node(5);
  (tree.root) -> right -> left -> left -> left -> right = new node(5);
  (tree.root) -> right -> left -> right -> left -> right = new node(5);
  (tree.root) -> right -> right -> left -> left -> right = new node(5);
  (tree.root) -> right -> right -> right -> left -> right  = new node(5);
  (tree.root) -> left -> left -> left -> right -> right = new node(5);
  (tree.root) -> left -> left -> right -> right -> right  = new node(5);
  (tree.root) -> left -> right -> left -> right -> right = new node(5);
  (tree.root) -> left -> right -> right -> right -> right  = new node(5);
  (tree.root) -> right -> left -> left -> right -> right = new node(5);
  (tree.root) -> right -> left -> right -> right -> right = new node(5);
  (tree.root) -> right -> right -> left -> right -> right = new node(5);
  (tree.root) -> right -> right -> right -> right -> right = new node(5);
  
  levelOrder(tree);
  cout << endl << kLevelSum(tree, 5) << endl;
  return 0;
}