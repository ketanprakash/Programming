//Author: Ketan Prakash, Date:
//Program to sort an array using merge sort
#include <iostream> 
using namespace std; 

void merge(int arr[], int s, int m, int e){
  int *arr1 = new int[e - s + 1];
  for (int i = s; i <= e; i++){
    arr1[i - s] = arr[i];
  }
  int i = s, j = s, k = m + 1;

  while(j <= m && k <= e){
    if (arr1[j - s] < arr1[k - s]){
        arr[i] = arr1[j - s];
        i++; j++;
    }
    else {
        arr[i] = arr1[k - s];
        i++; k++;
    }
  }

  while (j <= m){
    arr[i] = arr1[j - s];
    i++; j++;
  }

  while (k <= e){
    arr[i] = arr1[k - s];
    i++; k++;
  }
}

void merge_sort(int *arr, int s, int e){
  if (s >= e) return;
  int m;
  m = s + (e - s)/2;
  merge_sort(arr, s, m);
  merge_sort(arr, m + 1, e);
  merge(arr, s, m, e);
}

int main(){
  int n; 
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}

/*
9 8 7 6 5 4 3 2 1 0 

9 8 7 6 5 

6 5  8 79 
5 6 
9 

8 7 

8  7 

7 8 

7 8 9 
5 6 7 8 9 
*/