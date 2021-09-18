//Program to to create a binary tree
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
  int data; 
  node *left;
  node *right;
  node(int data){
    this -> data = data; 
    this -> left = NULL;
    this -> right = NULL;
  }
};

node *root = NULL;

void print(node *root){
  if (root == NULL){
    cout << "NULL";
  }
  else if (root -> right == NULL && root -> left == NULL){
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

void preOrder(node *root){
  if (root == NULL){
    return;
  }
  cout << root -> data << " ";
  preOrder(root -> left);
  preOrder(root -> right);
}

void inOrder(node *root){
  if (root == NULL){
    return;
  }
  inOrder(root -> left);
  cout << root -> data << " ";
  inOrder(root -> right);
}

void postOrder(node *root){
  if (root == NULL){
    return;
  }
  postOrder(root -> left);
  postOrder(root -> right);
  cout << root -> data << " ";
}

int32_t main(){
  root = new node(10);
  root -> left = new node(20);
  root -> right = new node(30);
  root -> left -> left = new node(40);
  root -> left -> right = new node(50);
  print(root);
  cout << endl;
  preOrder(root);
  cout << endl;
  inOrder(root);
  cout << endl;
  postOrder(root);
  return 0;
}