//Program to create a heap from Array
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int* maxPtr(int *p1, int *p2){
  if (p1 == NULL && p2 == NULL) return NULL; 
  else if (p1 == NULL) return p2; 
  else if (p2 == NULL) return p1;
  else if (*p1 > *p2) return p1;
  else return p2;
}

class heap{
  public:
  int* HEAP;
  int heapSize;
  int capacity;

  heap(int size = 10){
    HEAP = new int[size];
    heapSize = 0;
    capacity = size;
  }

  int* parent(int* curr){
    int idx = curr - HEAP;
    idx = (idx - 1) / 2;
    if (idx < 0) return NULL;
    return HEAP + idx;
  }

  int* left(int *curr){
    int idx = curr - HEAP;
    idx = 2 * idx + 1;
    if (idx >= heapSize) return NULL;
    return HEAP + idx;
  }

  int* right(int *curr){
    int idx = curr - HEAP;
    idx = 2 * (idx + 1);
    if (idx >= heapSize) return NULL;
    return HEAP + idx;
  }

  bool empty(){
    return heapSize == 0;
  }

  bool full(){
    return heapSize == capacity;
  }

  void extend(){
    int *newHEAP = new int[2 * capacity];
    for (int i = 0; i < capacity; i++){
      newHEAP[i] = HEAP[i];
    }
    capacity = 2 * capacity;
    delete [] HEAP; 
    HEAP = newHEAP;
  }

  void insert(int val){
    if (full()){
      extend();
    }
    int i = heapSize;
    HEAP[i] = val;
    heapSize++;
    int *curr = HEAP + i;
    while (parent(curr) != NULL){
      if (*parent(curr) < *curr) {
        swap(*curr, *parent(curr));
        curr = parent(curr);
      }
      else break;
    }
  }

  void remove(){
    if (empty()){
      return;
    }
    swap(HEAP[0], HEAP[heapSize - 1]);
    heapSize--;
    int* curr = HEAP;
    while (true){
      if (left(curr) == NULL && right(curr) == NULL){
        return;
      }
      else if (right(curr) == NULL){
        if (*left(curr) > *curr){
          swap(*left(curr), *curr);
          curr = left(curr);
        }
        else {
          return;
        }
      }
      else{
        if (*maxPtr(left(curr), right(curr)) > *curr){
          swap(*maxPtr(left(curr), right(curr)), *curr);
          curr = maxPtr(left(curr), right(curr));
        }
        else return;
      }
    }
  }

  int top(){
    return HEAP[0];
  }

  void print(int* curr){
    if (curr == NULL) {
      cout << "NULL";
      return;
    }
    if (left(curr) == NULL && right(curr) == NULL){
      cout << *curr;
      return;
    }
    cout << *curr << " : (";
    print(left(curr));
    cout << ", ";
    print(right(curr));
    cout << ")";
  }

  void print(){
    print(HEAP);
  }
};

// int32_t main(){
//   heap heap1;
//   int n; 
//   cin >> n;
//   int* arr = new int[n];
//   for (int i = 0; i < n; i++){
//     cin >> arr[i];
//   }

//   heapify(heap1, arr, n);
//   // for (int i = 0; i < n; i++){
//   //   heap1.insert(arr[i]);
//   // }
//   heap1.print();
//   return 0;
// }