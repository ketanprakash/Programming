//Program to find the height of a binary tree
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int height(node* root){
  if (root == NULL) return -1; 
  return max(height(root -> left), height(root -> right)) + 1;
}

int height(const binary_tree &tree){
  return height(tree.root);
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
  cout << height(tree) << endl;
  return 0;
}