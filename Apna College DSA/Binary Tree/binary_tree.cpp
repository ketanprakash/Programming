//Program to create a binary tree
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
  int data; 
  node *right; 
  node *left; 
  node(int data){
    this -> data = data; 
    this -> left = NULL;
    this -> right = NULL; 
  }
};

class binary_tree{
  public:
  node *root; 
  binary_tree(){
    root = NULL;
  }
};

void preorder(node *root){
  if (root == NULL){
    return;
  }
  preorder(root -> left);
  cout << root -> data << " ";
  preorder(root -> right);
}

void inorder(node *root){
  if (root == NULL){
    return;
  }
  cout << root -> data << " ";
  inorder(root -> left);
  inorder(root -> right);
}

void postorder(node *root){
  if (root == NULL){
    return;
  }
  postorder(root -> right);
  cout << root -> data << " ";
  postorder(root -> left);
}

void print(node *root){
  if (root == NULL) {
    cout << "NULL";
    return;
  }
  else if (root -> left == NULL && root -> right == NULL){
    cout << root -> data;
  }
  else {
    cout << root -> data;
    cout << " : (";
    print(root -> left);
    cout << ", ";
    print(root -> right);
    cout << ")";
  }
}

void print(binary_tree &tree){
  print(tree.root);
}

int32_t main(){
  binary_tree tree1; 
  tree1.root = new node(10);
  (tree1.root) -> left = new node(20);
  (tree1.root) -> right = new node(30);
  (tree1.root) -> left -> left = new node(40);
  (tree1.root) -> left -> right = new node(50);
  print(tree1);
  cout << endl;
  preorder(tree1.root);
  cout << endl;
  inorder(tree1.root);
  cout << endl;
  postorder(tree1.root);
  cout << endl;
  return 0;
}