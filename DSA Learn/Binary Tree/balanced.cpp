//Program to check if binary tree is balanced
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool balanced(node *root, int &height){
  if (root == NULL){
    height = -1; 
    return true;
  }
  int lHeight, rHeight;
  if (!balanced(root -> left, lHeight)) return false;
  if (!balanced(root -> right, rHeight)) return false;
  height = max(lHeight, rHeight) + 1;
  return abs(lHeight - rHeight) <= 1 ? true : false;
}

int32_t main(){
  binary_tree tree;
  int height; 
  (tree.root) = new node(10);

  (tree.root) -> left = new node(10);
  (tree.root) -> right = new node(10);

  (tree.root) -> left -> left = new node(10);
  cout << balanced(tree.root, height);
  return 0;
}