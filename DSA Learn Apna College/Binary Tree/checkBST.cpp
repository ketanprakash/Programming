//Program to check if give tree is a bst
#include "binarySearchTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool checkBST(node* root){
  if (root == NULL){
    return true;
  }
  bool thisNode = (root -> left ? (root -> data > root -> left -> data) : true);
  thisNode = thisNode && (root -> right ? (root -> data < root -> right -> data) : true);
  return thisNode && checkBST(root -> left) && checkBST(root -> right);
}

int32_t main(){
  binary_tree tree; 
  (tree.root) = new node(3);

  (tree.root) -> left = new node(2);
  (tree.root) -> right = new node(7);

  (tree.root) -> left -> left = new node(1);
  (tree.root) -> right -> left = new node(8);
  (tree.root) -> right -> right = new node(5); 
  tree.print();
  cout << endl << checkBST(tree.root);
  return 0;
}