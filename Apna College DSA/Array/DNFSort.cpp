//Author: Ketan Prakash, Date:
//Program to sort array of 0, 1, 2
#include <iostream> 
#include <vector>
using namespace std; 

void dnf_sort(int* arr, int n){
  int low = -1, mid = 0, high = n;

  while (mid < high){
    if (arr[mid] == 0){
      swap(arr[mid], arr[++low]); mid++;
    }
    else if (arr[mid] == 1){
      mid++;
    }
    else if (arr[mid] == 2){
      swap(arr[mid], arr[--high]);
    }
  }
}

int main(){
  int n; 
  cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  dnf_sort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}