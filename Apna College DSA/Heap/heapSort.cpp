//Program to to perform heapsort
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//all functions are for max heap

// void heapifyUp(int* heap, int i, int n){
//   int parent = (i - 1)/2;
//   if (parent >= 0 && heap[parent] < heap[i]){
//     swap(heap[parent], heap[i]);
//     heapifyUp(heap, parent, n);
//   }
// }

void heapifyDown(int *heap, int i, int n){
  int left = 2 * i + 1, right = 2 * i + 2;
  int largest = i;
  if (left < n && heap[left] > heap[largest]){
    largest = left;
  }
  if (right < n && heap[right] > heap[largest]){
    largest = right;
  }
  if (largest != i){
    swap(heap[largest], heap[i]);
    heapifyDown(heap, largest, n);
  }
}

// void printHeap(int* heap, int size, int i = 0){
//   if (i >= size){
//     cout << "NULL";
//     return;
//   }
//   int left = 2 * i + 1, right = 2 * i + 2;
//   if (left >= size && right >= size){
//     cout << heap[i];
//     return;
//   }
//   cout << heap[i];
//   cout << " : (";
//   printHeap(heap, size, left);
//   cout << ", ";
//   printHeap(heap, size, right);
//   cout << ")";
// }

void heapSort(int *arr, int n){
  for (int i = ((n - 1) - 1) / 2; i >= 0; i--){
    heapifyDown(arr, i, n);
  }

  for (int i = n - 1; i >= 0; i--){
    swap(arr[0], arr[i]);
    heapifyDown(arr, 0, i);
  }
}

int32_t main(){
  int n; 
  cin >> n;
  int *arr = new int[n]; 
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  heapSort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}