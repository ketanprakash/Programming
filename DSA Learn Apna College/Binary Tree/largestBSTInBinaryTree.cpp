//Program to find largest binary search tree in a binary tree
#include "binarySearchTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct info{
  int size; 
  int max;
  int min; 
  int ans;
  bool isBST;
};

info sizeOfMaxBST(node* root){
  if (root == NULL){
    return {0, INT_MIN, INT_MAX, 0, true};
  }
  if (root -> left == NULL && root -> right == NULL){
    return {1, root -> data, root -> data, 1, true};
  }

  info leftInfo = sizeOfMaxBST(root -> left);
  info rightInfo = sizeOfMaxBST(root -> right);

  info curr; 
  curr.size = (1 + leftInfo.size + rightInfo.size);
  if (leftInfo.isBST && rightInfo.isBST && (leftInfo.max < root -> data) && (rightInfo.min > root -> data)){
    curr.min = min(leftInfo.min, min(rightInfo.min, root -> data));
    curr.max = max(leftInfo.max, max(rightInfo.max, root -> data));

    curr.ans = curr.size;
    curr.isBST = true;
    return curr;
  }

  curr.ans = max(leftInfo.ans, rightInfo.ans);
  curr.isBST = false;
  return curr;
}

int32_t main(){
  binary_tree tree; 
  tree.root = new node(15);

  (tree.root) -> left = new node(16);
  (tree.root) -> right = new node(30);

  (tree.root) -> left -> left = new node(5);

  cout << sizeOfMaxBST(tree.root).ans << endl;
  return 0;
}