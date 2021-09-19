//Program to peform preorder, inorder and postorder traversal without recursion
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void preOrder(node* root){
  if (root == NULL) return;
  cout << root -> data << " ";
  preOrder(root -> left);
  preOrder(root -> right);
}

void inOrder(node* root){
  if (root == NULL) return;
  inOrder(root -> left);
  cout << root -> data << " ";
  inOrder(root -> right);
}

void postOrder(node* root){
  if (root == NULL) return; 
  postOrder(root -> left);
  postOrder(root -> right);
  cout << root -> data << " ";
}

void preOrderStack(node* root){
  stack<node*> st;
  st.push(root);
  while (!st.empty()){
    node* curr = st.top();
    st.pop();
    cout << curr -> data << " ";
    if (curr -> right != NULL) st.push(curr -> right);
    if (curr -> left != NULL) st.push(curr -> left);
  }
}

void inOrderStack(node* root){
  stack<node*> st;
  node* temp = root;
  st.push(temp);
  while (temp -> left != NULL) {
    st.push(temp -> left);
    temp = temp -> left;
  }
  while (!st.empty()){
    temp = st.top(); 
    st.pop();
    cout << temp -> data << " ";
    if (temp -> right != NULL){
      temp = temp -> right; 
      st.push(temp);
      while (temp -> left != NULL) {
        st.push(temp -> left);
        temp = temp -> left;
      }
    }
  }
}

void postOrderStack(node* root){
  stack<node*> st;
  unordered_set<node*> v; 
  st.push(root);
  while (!st.empty()){
    node* curr = st.top();
    if (v.find(curr) == v.end()){
      if (curr -> right != NULL) st.push(curr -> right);
      if (curr -> left != NULL) st.push(curr -> left);
      v.insert(curr);
    }
    else {
      cout << curr -> data << " ";
      st.pop();
    }
  }
}

int32_t main(){
  binary_tree tree;
  (tree.root) = new node(1);

  (tree.root) -> left = new node(2);
  (tree.root) -> right = new node(3);
  
  (tree.root) -> left -> left = new node(4);
  (tree.root) -> right -> left = new node(6);
  (tree.root) -> left -> right = new node(5);
  (tree.root) -> right -> right = new node(7);
  tree.print(); 
  cout << endl;
  cout << "Preorder: ";
  preOrder(tree.root);
  cout << endl;
  cout << "Inorder: ";
  inOrder(tree.root);
  cout << endl;
  cout << "PostOrder: ";
  postOrder(tree.root);
  cout << endl;
  cout << "Preorder Stack: ";
  preOrderStack(tree.root);
  cout << endl;
  cout << "Inorder Stack: ";
  inOrderStack(tree.root);
  cout << endl;
  cout << "Postorder Stack: ";
  postOrderStack(tree.root);
  cout << endl;
  return 0;
}