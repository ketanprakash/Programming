//Program to create a binary search tree
#include "binaryTree.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

class binary_search_tree : public binary_tree{
  node* insert(node* root, int val){
    if (root == NULL){
      root = new node(val);
    }
    else if (val < root -> data){
      if (root -> left == NULL) root -> left = new node(val);
      else root -> left = insert(root -> left, val);
    }
    else if (val > root -> data){
      if (root -> right == NULL) root -> right = new node(val);
      else root -> right = insert(root -> right, val);
    }
    return root;
  }

  node* search(node* root, int val){
    if (root == NULL){
      return NULL;
    }
    if (root -> data == val){
      return root; 
    }
    else if (val < root -> data){
      return search(root -> left, val);
    }
    else{
      return search(root -> right, val);
    }
  }

  node* maxNode(node* root){
    if (root -> right == NULL) return root; 
    return maxNode(root -> right);
  }

  node* remove(node* root, int val){
    if (root == NULL){
      return NULL;
    }
    if (val == root -> data){
      if (root -> left == NULL && root -> right == NULL){
        delete root; 
        root = NULL; 
      }
      else if (root -> left == NULL){
        node* toDelete = root; 
        root = root -> right; 
        delete toDelete; 
        return root;
      }
      else if (root -> right == NULL){
        node* toDelete = root; 
        root = root -> left; 
        delete toDelete; 
        return root;
      }
      else{
        node* toDelete = maxNode(root -> left);
        root -> data = toDelete -> data;
        root -> left = remove(root -> left, toDelete -> data);
      }
    }
    else if (val < root -> data){
      root -> left = remove(root -> left, val);
    }
    else{
      root -> right = remove(root -> right, val);
    }
    return root;
  }

  public: 
  void insert(int val){
    root = insert(root, val);
  }

  bool search(int val){
    return search(root, val);
  }

  void remove(int val){
    root = remove(root, val);
  }
};