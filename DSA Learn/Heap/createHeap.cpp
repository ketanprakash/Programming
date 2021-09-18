//Program to to build a heap
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int* heap = new int[10]; 
int capacity = 10;
int heapSize = 0;

void heapifyUp(int idx){
  int parent = (idx - 1) / 2; 
  if (parent >= 0 && heap[parent] < heap[idx]){
    swap(heap[parent], heap[idx]);
    heapifyUp(parent);
  }
}

void heapifyDown(int idx){
  int left = 2 * idx + 1; 
  int right = 2 * idx + 2; 
  int largest = idx;
  if (left < heapSize && heap[left] > heap[largest]) largest = left;
  if (right < heapSize && heap[right] > heap[largest]) largest = right;
  if (largest != idx){
    swap(heap[idx], heap[largest]);
    heapifyDown(largest);
  }
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
    newHeap[i] = heap[i];
  }
  delete [] heap;
  capacity *= 2;
  heap = newHeap;
}

void insert(int val){
  if (full()){
    extend();
  }
  heap[heapSize] = val;
  heapSize++;
  heapifyUp(heapSize - 1);
}

int top(){
  return heap[0];
}

void remove(){
  heap[0] = heap[heapSize - 1];
  heapifyDown(0);
}

void buildHeap(int* arr, int n){
  delete [] heap;
  heap = arr; 
  heapSize = n;
  capacity = n;
  for (int i = n / 2 - 1; i >= 0; i--){
    heapifyDown(i);
  }
}

void printHeap(int i = 0){
  if (i >= heapSize){
    cout << "NULL";
    return;
  }
  int l = 2 * i + 1, r = 2 * i + 2;
  if (l >= heapSize && r >= heapSize){
    cout << heap[i];
    return;
  }
  cout << heap[i]; 
  cout << ": (";
  printHeap(l);
  cout << ", ";
  printHeap(r);
  cout << ")";
}

int32_t main(){
  int n; 
  cin >> n; 
  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  buildHeap(arr, n);
  printHeap();
  cout << endl;
  insert(10);
  printHeap();
  cout << endl;
  insert(12);
  printHeap();
  cout << endl;
  insert(15);
  printHeap();
  return 0;
}