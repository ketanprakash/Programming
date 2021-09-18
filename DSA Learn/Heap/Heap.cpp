//Program to to build a HEAP
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

class maxHeap{
  int* HEAP = new int[10]; 
  int capacity = 10;
  int heapSize = 0;
  
  void heapifyUp(int idx){
    int parent = (idx - 1) / 2; 
    if (parent >= 0 && HEAP[parent] < HEAP[idx]){
      swap(HEAP[parent], HEAP[idx]);
      heapifyUp(parent);
    }
  }

  void heapifyDown(int idx){
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
    int largest = idx;
    if (left < heapSize && HEAP[left] > HEAP[largest]) largest = left;
    if (right < heapSize && HEAP[right] > HEAP[largest]) largest = right;
    if (largest != idx){
      swap(HEAP[idx], HEAP[largest]);
      heapifyDown(largest);
    }
  }

  public:
  maxHeap(int size = 10){
    HEAP = new int[size];
    capacity = size;
    heapSize = 0;
  }

  maxHeap(int* arr, int n){
    HEAP = arr; 
    heapSize = n;
    capacity = n;
    for (int i = n / 2 - 1; i >= 0; i--){
      heapifyDown(i);
    }
  }

  int size(){
    return heapSize;
  }

  bool empty(){
    return heapSize == 0;
  }

  bool full(){
    return heapSize == capacity;
  }

  void extend(){
    int* newHeap = new int[capacity * 2];
    for (int i = 0; i < capacity; i++){
      newHeap[i] = HEAP[i];
    }
    delete [] HEAP;
    capacity *= 2;
    HEAP = newHeap;
  }

  void insert(int val){
    if (full()){
      extend();
    }
    HEAP[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
  }

  int top(){
    return HEAP[0];
  }

  void remove(){
    HEAP[0] = HEAP[heapSize - 1];
    heapifyDown(0);
  }

  void print(int i = 0){
    if (i >= heapSize){
      cout << "NULL";
      return;
    }
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l >= heapSize && r >= heapSize){
      cout << HEAP[i];
      return;
    }
    cout << HEAP[i]; 
    cout << " : (";
    print(l);
    cout << ", ";
    print(r);
    cout << ")";
  }
};

class minHeap{
  int* HEAP = new int[10]; 
  int capacity = 10;
  int heapSize = 0;
  
  void heapifyUp(int idx){
    int parent = (idx - 1) / 2; 
    if (parent >= 0 && HEAP[parent] > HEAP[idx]){
      swap(HEAP[parent], HEAP[idx]);
      heapifyUp(parent);
    }
  }

  void heapifyDown(int idx){
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
    int largest = idx;
    if (left < heapSize && HEAP[left] < HEAP[largest]) largest = left;
    if (right < heapSize && HEAP[right] < HEAP[largest]) largest = right;
    if (largest != idx){
      swap(HEAP[idx], HEAP[largest]);
      heapifyDown(largest);
    }
  }

  public:
  minHeap(int size = 10){
    HEAP = new int[size];
    capacity = size;
    heapSize = 0;
  }

  minHeap(int* arr, int n){
    HEAP = arr; 
    heapSize = n;
    capacity = n;
    for (int i = n / 2 - 1; i >= 0; i--){
      heapifyDown(i);
    }
  }

  int size(){
    return heapSize;
  }

  bool empty(){
    return heapSize == 0;
  }

  bool full(){
    return heapSize == capacity;
  }

  void extend(){
    int* newHeap = new int[capacity * 2];
    for (int i = 0; i < capacity; i++){
      newHeap[i] = HEAP[i];
    }
    delete [] HEAP;
    capacity *= 2;
    HEAP = newHeap;
  }

  void insert(int val){
    if (full()){
      extend();
    }
    HEAP[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
  }

  int top(){
    return HEAP[0];
  }

  void remove(){
    HEAP[0] = HEAP[heapSize - 1];
    heapifyDown(0);
  }

  void print(int i = 0){
    if (i >= heapSize){
      cout << "NULL";
      return;
    }
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l >= heapSize && r >= heapSize){
      cout << HEAP[i];
      return;
    }
    cout << HEAP[i]; 
    cout << " : (";
    print(l);
    cout << ", ";
    print(r);
    cout << ")";
  }
};