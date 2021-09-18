//Program to print all nodes with distance n to a given node
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void inSubtree(node* Node, int k){
  if (k < 0){
    return;
  }
  if (Node == NULL){
    return;
  }
  if (k == 0){
    cout << Node -> data << " ";
    return;
  }
  inSubtree(Node -> left, k - 1);
  inSubtree(Node -> right, k - 1);
}

bool path(node* root, node* Node, vector<node*> &pathVector){
  if (root == NULL){
    return false;
  }
  if (root == Node){
    pathVector.push_back(Node);
    return true;
  }
  if (path(root -> left, Node, pathVector) || path(root -> right, Node, pathVector)){
    pathVector.push_back(root);
    return true;
  }
  return false;
}

void printNodesWithDistK(node* root, node *Node, int k){
  vector<node*> pathA;
  path(root, Node, pathA);  //O(n)
  inSubtree(pathA[0], k);
  for (int i = 1; i < pathA.size(); i++){
    if (k - i < 0) break;
    if (k - i == 0){
      cout << pathA[i] -> data << " ";
    }
    else if (pathA[i] -> left == pathA[i - 1]){
      inSubtree(pathA[i] -> right, k - i - 1);
    }
    else {
      inSubtree(pathA[i] -> right, k - i - 1);
    }
  }
}

int32_t main(){
  binary_tree tree; 
  (tree.root) = new node(1);

  (tree.root) -> left = new node(5);
  (tree.root) -> right = new node(2);

  (tree.root) -> left -> left = new node(6);
  (tree.root) -> right -> left = new node(3);
  (tree.root) -> right -> right = new node(4);

  (tree.root) -> left -> left -> right = new node(7);

  (tree.root) -> left -> left -> right -> left = new node(8);
  (tree.root) -> left -> left -> right -> right = new node(9);

  printNodesWithDistK(tree.root, (tree.root) -> left, 3);
  return 0;
}