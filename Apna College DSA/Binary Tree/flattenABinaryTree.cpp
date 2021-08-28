//Program to flatten a binary tree
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void flatten(node* root){
  if (root == NULL){
    return;
  }
  if (root -> left != NULL){
    flatten(root -> left);
    node* temp = root -> right;
    root -> right = root -> left;
    root -> left = NULL;

    node* t = root -> right;
    while (t -> right != NULL){
      t = t -> right;
    }
    t -> right = temp;
  }
  flatten(root -> right);
}

int32_t main(){
  binary_tree tree;
  (tree.root) = new node(1);
  
  (tree.root) -> left = new node(2);
  (tree.root) -> right = new node(2);

  (tree.root) -> left -> left = new node(3);
  (tree.root) -> right -> left = new node(3);
  (tree.root) -> left -> right = new node(3);
  (tree.root) -> right -> right = new node(3);

  (tree.root) -> left -> left -> left = new node(4);
  (tree.root) -> right -> left -> left = new node(4);
  (tree.root) -> left -> right -> left = new node(4);
  (tree.root) -> right -> right -> left = new node(4);
  (tree.root) -> left -> left -> right = new node(4);
  (tree.root) -> right -> left -> right = new node(4);
  (tree.root) -> left -> right -> right = new node(4);
  (tree.root) -> right -> right -> right = new node(4);

  tree.print();
  cout << endl;
  tree.preOrder();
  flatten(tree.root);
  cout << endl;
  tree.print();
  return 0;
}