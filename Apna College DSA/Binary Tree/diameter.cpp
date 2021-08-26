//Program to find the diameter of a node
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int calcDiameter(node* root, int &nodesHeight){
  if (root == NULL){
    nodesHeight = 0;
    return 0;
  }
  int leftNodesHeight = 0, rightNodesHeight = 0;
  int rightDiameter = calcDiameter(root -> right, leftNodesHeight);
  int leftDiameter = calcDiameter(root -> left, rightNodesHeight);

  nodesHeight = max(leftNodesHeight, rightNodesHeight) + 1;
  return max(leftDiameter, max(rightDiameter, leftNodesHeight + rightNodesHeight + 1));
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
  
  int nodesHeight = 0; 
  cout << calcDiameter(tree.root, nodesHeight) << endl;
  cout << nodesHeight << endl;
  return 0;
}