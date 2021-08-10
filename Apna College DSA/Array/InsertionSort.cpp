//Author: Ketan Prakash, Date:
//Program to sort an array using an insertion sort algorithm
#include <iostream> 
using namespace std; 

void insertion_sort(int arr[], int n){
  int tmp;
  for (int i = 1; i < n; i++){
    for (int j = i; j > 0; j--){
      if (arr[j - 1] > arr[j]){
        tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp; 
      }
      else break;
    }
  }
}

int main(){
  int n; 
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  insertion_sort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}

/*
9 8 7 6 5 4 3 2 1 
8 9 7 6 5 4 3 2 1
*/