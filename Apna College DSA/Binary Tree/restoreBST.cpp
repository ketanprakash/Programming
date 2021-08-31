//Program to restore the correct bst if two nodes of bst are swapped
#include "binarySearchTree.cpp"  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void inOrder(node* root, vector<int> &v){
  if (root == NULL){
    return;
  }
  inOrder(root -> left, v);
  v.push_back(root -> data);
  inOrder(root -> right, v);
}

bool isBST(node* root){
  if (root == NULL){
    return true;
  }
  return isBST(root -> left) && isBST(root -> right) && ((root -> left == NULL || root -> left -> data < root -> data) && ((root -> right == NULL) || root -> right -> data > root -> data));
}
//using property that inorder of a bst is sorted 
int32_t main(){
  binary_tree tree;
  (tree.root) = new node(6);

  (tree.root) -> left = new node(4);
  (tree.root) -> right = new node(9);
  
  (tree.root) -> left -> left = new node(1);
  (tree.root) -> left -> right = new node(3);
  (tree.root) -> right -> right = new node(13);
  tree.print(); 
  cout << endl;
  vector<int> v; 
  inOrder(tree.root, v);
  int first = 0, mid = 0, last = v.size();
  int count = 0;
  for (int i = 1; i < v.size(); i++){
    if (v[i] < v[i - 1]){
      if (count == 0){
        first = i - 1; 
        mid = i;
        count++;
      }
      else{
        last = i;
      }
    }
  }
  if (last != v.size()) swap(last, mid);
  swap(tree.search(v[first]) -> data, tree.search(v[mid]) -> data);
  tree.print(); 
  cout << endl;
  cout << isBST(tree.root);
  return 0;
}