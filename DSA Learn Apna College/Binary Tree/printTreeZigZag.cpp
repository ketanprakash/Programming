//Program to print zig-zag traversal of a binary tree
#include "binarySearchTree.cpp"  

#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void zigZag(node* root){
  if (root == NULL) return;
  queue<node*> q; 
  stack<node*> s;
  int level = 0;
  q.push(root);
  q.push(NULL);
  while (!q.empty()){
    node* temp = q.front(); 
    q.pop();
    if (temp == NULL){
      if (!q.empty()){
        cout << endl;
        q.push(NULL);
        level++;
        if (level % 2 != 0){
          while (q.front() != NULL){
            s.push(q.front());
            if (q.front() -> left != NULL) q.push(q.front() -> left);
            if (q.front() -> right != NULL) q.push(q.front() -> right);
            q.pop();
          }
          while (!s.empty()){
            cout << s.top() -> data << " ";
            s.pop();
          }
        }
      }
    }
    else {
      cout << temp -> data << " ";

      if (temp -> left != NULL) q.push(temp -> left);
      if (temp -> right != NULL) q.push(temp -> right);
    }
  }
}

int32_t main(){
  binary_tree tree; 
  (tree.root) = new node(1);

  (tree.root) -> left = new node(2);
  (tree.root) -> right = new node(3);

  (tree.root) -> left -> right = new node(4);
  (tree.root) -> right -> right = new node(5);

  (tree.root) -> left -> right -> left = new node(6);
  (tree.root) -> left -> right -> right = new node(7);
  zigZag(tree.root);
  return 0;
}