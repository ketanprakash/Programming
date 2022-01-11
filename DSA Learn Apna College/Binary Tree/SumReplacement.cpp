//Program to replace each node with sum of all its subtree nodes + itself
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void replaceSum(node* root){
  if (root == NULL){
    return;
  }
  replaceSum(root -> left);
  replaceSum(root -> right);
  root -> data += root -> left ? root -> left -> data : 0;
  root -> data += root -> right ? root -> right -> data : 0;
}

void replaceSum(binary_tree tree){
  replaceSum(tree.root);
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
  tree.print();
  // replaceSum(tree.root);
  replaceSum(tree);
  cout << endl;
  tree.print();
  return 0;
}