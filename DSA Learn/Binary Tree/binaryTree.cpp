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

class binary_tree{
  public: 
  node *root;
  
  private:
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

  node* search(node* root, int data){
    if (root == NULL){
      return root;
    }
    if (root -> data == data){
      return root;
    }
    node* leftResult = search(root -> left, data);
    node* rightResult = search(root -> right, data);
    return leftResult ? leftResult : rightResult;
  }

  public:
  binary_tree(){
    root = NULL;
  }
  
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

  node* search(int data){
    return search(root, data);
  }

  void print(){
    print(root);
  }

  void preOrder(){
    preOrder(root);
  }

  void inOrder(){
    inOrder(root);
  }

  void postOrder(){
    postOrder(root);
  }
};
