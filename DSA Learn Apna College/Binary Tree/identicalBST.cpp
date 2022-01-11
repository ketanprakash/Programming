//Program to find if two binary search trees are identical
#include "binarySearchTree.cpp"  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool identical(node* root1, node* root2){
  if (root1 == NULL && root2 == NULL) return true;
  bool flag = false;
  if ((root1 != NULL && root2 != NULL) && (root1 -> data == root2 -> data)){
    flag = true;
  }
  return flag && identical(root1 -> left, root2 -> left) && identical(root1 -> right, root2 -> right);
}

int32_t main(){
  binary_search_tree tree1, tree2;
  tree1.insert(1);
  tree1.insert(3);
  tree1.insert(2);
  tree1.insert(8);
  tree2.insert(1);
  tree2.insert(3);
  tree2.insert(2);
  tree2.insert(5);
  cout << identical(tree1.root, tree1.root) << endl;
  return 0;
}