//Program to find distance between two nodes in binary tree
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

node* LCA(node* root, int n1, int n2){
  if (root == NULL){
    return NULL;
  }
  if (root -> data == n1 || root -> data == n2){
    return root; 
  }

  node* leftLCA = LCA(root -> left, n1, n2);
  node* rightLCA = LCA(root -> right, n1, n2);

  return ((leftLCA) && (rightLCA) ? root : (leftLCA ? leftLCA : rightLCA));
}

int dist(node* root, int n){
  if (root == NULL){
    return -1;
  }

  if (root -> data == n){
    return 0;
  }

  int distLeft = dist(root -> left, n);
  int distRight = dist(root -> right, n);

  return (distRight == -1 && distLeft == -1 ? -1 : (distLeft == -1 ? distRight + 1 : distLeft + 1));
}

int minDistance(node* root, int n1, int n2){
  node* lca = LCA(root, n1, n2);
  return dist(lca, n1) + dist(lca, n2);
}

int32_t main(){
  binary_tree tree; 
  tree.root = new node(1); 

  (tree.root) -> left = new node(2); 
  (tree.root) -> right = new node(3); 

  (tree.root) -> left -> left = new node(4); 
  (tree.root) -> right -> left = new node(5); 
  (tree.root) -> right -> right = new node(6); 

  cout << minDistance(tree.root, 1, 6);
  return 0;
}