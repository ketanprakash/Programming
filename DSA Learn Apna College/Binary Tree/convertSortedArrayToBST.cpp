//Program to create bst from a sorted array
#include "binarySearchTree.cpp"  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

node* sortedArrayToBST(node* root, int* arr, int s, int e){
  if (s > e) return NULL;
  int m = s + (e - s)/2;
  root = new node(arr[m]);
  root -> left = sortedArrayToBST(root -> left, arr, s, m - 1);
  root -> right = sortedArrayToBST(root -> right, arr, m + 1, e);
  return root;
}

int32_t main(){
  binary_search_tree tree; 
  int arr[] = {1, 2, 3, 4, 5};
  tree.root = sortedArrayToBST(tree.root, arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
  tree.print();
  return 0;
}