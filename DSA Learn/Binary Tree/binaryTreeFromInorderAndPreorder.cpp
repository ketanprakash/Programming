//Program to buildPreOrderInOrder a binary tree from traversals
#include <bits/stdc++.h>  
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int search(int* arr, int s, int e, int key){
  for (int i = s; i <= e; i++){
    if (arr[i] == key) return i;
  }
  return -1;
}

int buildPreOrderInOrder(node *&root, int* preOrder, int pCurr, int* inOrder, int iS, int iE){
  if (iS > iE) return pCurr;
  int rootData = preOrder[pCurr];
  pCurr++;
  root = new node(rootData);
  int iPos = search(inOrder, iS, iE, rootData);
  pCurr = buildPreOrderInOrder(root -> left, preOrder, pCurr, inOrder, iS, iPos - 1);
  pCurr = buildPreOrderInOrder(root -> right, preOrder, pCurr, inOrder, iPos + 1, iE);  
  return pCurr;
}

int buildPostOrderInOrder(node *&root, int* postOrder, int pCurr, int* inOrder, int iS, int iE){
  if (iS > iE) return pCurr;
  int rootData = postOrder[pCurr];
  pCurr--;
  root = new node(rootData);
  int iPos = search(inOrder, iS, iE, rootData);
  pCurr = buildPostOrderInOrder(root -> right, postOrder, pCurr, inOrder, iPos + 1, iE);  
  pCurr = buildPostOrderInOrder(root -> left, postOrder, pCurr, inOrder, iS, iPos - 1);
  return pCurr;
}

void buildPreOrderInOrder(binary_tree &tree, int* postOrder, int pCurr, int *inOrder, int iS, int iE){
  buildPreOrderInOrder(tree.root, postOrder, pCurr, inOrder, iS, iE);
}

void buildPostOrderInOrder(binary_tree &tree, int* postOrder, int pCurr, int *inOrder, int iS, int iE){
  buildPostOrderInOrder(tree.root, postOrder, pCurr, inOrder, iS, iE);
}

int32_t main(){
  binary_tree tree;
  int preOrder[] = {1, 2, 4, 3, 5};
  int inOrder[] = {4, 2, 1, 5, 3};
  int postOrder[] = {4, 2, 5, 3, 1};
  int nI = sizeof(inOrder)/sizeof(inOrder[0]);
  buildPreOrderInOrder(tree, preOrder, 0, inOrder, 0, nI - 1);
  // buildPostOrderInOrder(tree, postOrder, nI - 1, inOrder, 0, nI - 1);
  tree.preOrder();
  cout << endl;
  tree.inOrder();
  cout << endl;
  tree.postOrder();
  cout << endl;
  return 0;
}