//Program to sort an array using heapsort algo
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void heapify(int* arr, int n, int idx){
  if (idx >= n){
    return;
  }
  int l = 2 * idx + 1, r = 2 * idx + 2;
  int largest = idx;
  if (l < n && arr[l] > arr[largest]) largest = l; 
  if (r < n && arr[r] > arr[largest]) largest = r;
  
  if (largest != idx){
    swap(arr[largest], arr[idx]);
    heapify(arr, n, largest);
  }
}

void heapSort(int* arr, int n){
  //converting the array into a max heap 
  //O(n)
  for (int i = n / 2 - 1; i >= 0; i--){
    heapify(arr, n, i);
  }

  //converting it back to array by removing items and swapping them
  //O(nlogn)
  for (int i = n - 1; i >= 0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int32_t main(){
  int n; 
  cin >> n; 
  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  heapSort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}