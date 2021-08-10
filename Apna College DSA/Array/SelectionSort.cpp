#include <iostream> 
using namespace std; 

int min_index(int* arr, int s, int e){
  int min_idx = s;
  for (int i = s + 1; i <= e; i++){
    if (arr[i] < arr[min_idx]){
      min_idx = i;
    }
  }
  return min_idx;
}

void selection_sort(int *arr, int n){
  for (int i = 0; i < n - 1; i++){
    swap(arr[min_index(arr, i, n - 1)], arr[i]);
  }
}

int main(){
  int n; 
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  selection_sort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}