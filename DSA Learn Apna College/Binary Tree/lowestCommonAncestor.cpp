//Program to find the lowest common ancestor or two nodes
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

queue<node*> path(node* root, node* givenNode, queue<node*> q = queue<node*>()){
  if (root == NULL){
    return queue<node*>();
  }
  if (root == givenNode){
    q.push(givenNode);
    return q;
  }
  
  q.push(root);
  queue<node*> pathLeft = path(root -> left, givenNode, q);
  queue<node*> pathRight = path(root -> right, givenNode, q);
  q = pathLeft.empty() ? pathRight : pathLeft;
  return q;
}

node* lowestCommonAncestor(node* root, node* givenNode1, node* givenNode2){
  queue<node*> pathNode1 = path(root, givenNode1);
  queue<node*> pathNode2 = path(root, givenNode2);
  node* lowestCommon = NULL;
  while (pathNode1.front() == pathNode2.front()){
    lowestCommon = pathNode1.front(); 
    pathNode1.pop(); 
    pathNode2.pop();
  }
  return lowestCommon;
}

node* LCA(node* root, int n1, int n2){
  if (root == NULL){
    return NULL;
  }

  if (root -> data == n1 || root -> data == n2){
    return root;
  }
  node* leftLCA = LCA(root -> left, n1, n2);
  node* rightLCA = LCA(root -> right, n1, n2);

  return ((leftLCA && rightLCA) ? root : ((leftLCA) ? leftLCA : rightLCA));
}

int32_t main(){
  binary_tree tree;
  (tree.root) = new node(1);

  (tree.root) -> left = new node(2);
  (tree.root) -> right = new node(3);

  (tree.root) -> left -> left = new node(4);
  (tree.root) -> right -> left = new node(5);
  (tree.root) -> right -> right = new node(6);

  (tree.root) -> right -> left -> left = new node(7);

  // cout << lowestCommonAncestor(tree.root, (tree.root) -> right -> right, (tree.root) -> right -> left -> left) -> data << endl;
  cout << LCA(tree.root, 6, 7) -> data;
  return 0;
}