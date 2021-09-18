//Author: Ketan Prakash, Date:
//Program to spiral traverse a 2d array
#include <iostream> 
using namespace std; 

int main(){
  int n, m;
  cin >> n >> m; 
  int **arr = new int*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  int row_first = 0, row_last = n - 1, col_first = 0, col_last = m - 1;
  while (row_first <= row_last && col_first <= col_last){
    for (int i = col_first; i <= col_last; i++){
      cout << arr[row_first][i] << endl;
    }
    row_first++;
    for (int i = row_first; i <= row_last; i++){
      cout << arr[i][col_last] << endl;
    }
    col_last--;
    for (int i = col_last; i >= col_first; i--){
      cout << arr[row_last][i] << endl;
    }
    row_last--;
    for (int i = row_last; i >= row_first; i--){
      cout << arr[i][col_first] << endl;
    }
    col_first++;
  }
  return 0;
}