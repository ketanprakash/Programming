//Author: Ketan Prakash, Date:
//Program to find a number in a matrix which is sorted in asc left to right and asc top to bottom
#include <iostream> 
#include <algorithm>
using namespace std; 

int main(){
  int n, m; 
  cin >> n >> m; 
  int **arr = new int*[n];
  for (int i = 0; i < n; i++) arr[i] = new int[m];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  int key; 
  cin >> key;
  // brute force:
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (arr[i][j] == key){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  // o(nlogm)
  for (int i = 0; i < n; i++){
    if (binary_search(arr[i], arr[i] + m, key)){
      cout << i << " " << lower_bound(arr[i], arr[i] + n, key) - arr[i] << endl;
      break;
    }
  }
  // o(n + m) solution:
  bool flag = false;
  int i = 0, j = m - 1; 
  while (i < n && j >= 0){
    if (arr[i][j] == key){
      cout << i << " " << j << endl;
      flag = true;
      break;
    }
    else if (arr[i][j] < key){
      i++;
    }
    else {
      j--;
    }
  }
  if (!flag) cout << "Not Found" << endl;
  return 0;
}