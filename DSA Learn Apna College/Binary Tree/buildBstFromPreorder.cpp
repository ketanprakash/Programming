//Program to build a bst from preorder
#include "binarySearchTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

node* constructBST(node* root, int* preOrder, int n, int &idx, int min = INT_MIN, int max = INT_MAX){
  if (idx >= n){
    return NULL;
  }
  if (preOrder[idx] > min && preOrder[idx] < max){
    root = new node(preOrder[idx]);
    idx++;
    
    root -> left = constructBST(root -> left, preOrder, n, idx, min, root -> data);

    root -> right = constructBST(root -> right, preOrder, n, idx, root -> data, max);
  }
  return root;
}

int32_t main(){
  binary_search_tree tree; 
  int preOrder[] = {10, 2, 1, 13, 11};
  int idx = 0;
  tree.root = constructBST(tree.root, preOrder, sizeof(preOrder)/sizeof(preOrder[00]), idx);
  tree.print();
  return 0;
}