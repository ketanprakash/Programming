//Program to 
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int maxPathSum(node* root, node* curr, int &ans){
  int nodeValue = curr -> data; 
  if (curr -> left == NULL && curr -> right == NULL){
    ans = max(ans, nodeValue);
    return (curr == root ? ans : nodeValue);
  }
  else if (curr -> right == NULL){
    int maxLeft = maxPathSum(root, curr -> left, ans) + nodeValue;
    ans = max(ans, max(nodeValue, maxLeft));
    return (curr == root ? ans : max(nodeValue, maxLeft));
  }
  else if (curr -> left == NULL){
    int maxRight = maxPathSum(root, curr -> right, ans) + nodeValue;
    ans = max(ans, max(nodeValue, maxRight));
    return (curr == root ? ans : max(nodeValue, maxRight));
  } 
  else{
    int maxLeft = maxPathSum(root, curr -> left, ans) + nodeValue;
    int maxRight = maxPathSum(root, curr -> right, ans) + nodeValue;
    int maxCirSum = maxLeft + maxRight - nodeValue;
    ans = max(ans, max(maxLeft, max(maxRight, max(maxCirSum, nodeValue))));
    return (curr == root ? ans : max(nodeValue, max(maxRight, maxLeft)));
  }
}

int32_t main(){
  binary_tree tree; 
  (tree.root) = new node(-100000);
  (tree.root) -> left = new node(-12);
  (tree.root) -> right = new node(-1000);
  (tree.root) -> left -> left = new node(-1000);
  (tree.root) -> right -> left = new node(-1000);
  (tree.root) -> right -> right = new node(-1000);
  tree.print();
  int dummy = INT_MIN;
  cout << endl << maxPathSum(tree.root, tree.root, dummy);
  return 0;
}