#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool check(vector<vector<int>> &sudoku, int num, int row, int col){
  for (int i = 0; i < 9; i++){
    if (sudoku[row][i] == num) return false;
  }

  for (int i = 0; i < 9; i++){
    if (sudoku[i][col] == num) return false;
  }

  col = (col / 3) * 3;
  row = (row / 3) * 3;
  for (int i = row; i < row + 3; i++){
    for (int j = col; j < col + 3; j++){
      if (sudoku[i][j] == num){
        return false;
      }
    }
  } 
  return true;
}

//all valid sudoku boards

void solve(vector<vector<int>> &sudoku, int row = 0, int col = 0){
  if (row == 9){
    for (int i = 0; i < 9; i++){
      for (int j = 0; j < 9; j++){
        cout << sudoku[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    return;
  }
  while (sudoku[row][col] != 0 && col < 9) col++;
  if (col == 9) solve(sudoku, row + 1, 0);
  else {
    for (int i = 1; i <= 9; i++){
      if (check(sudoku, i, row, col)){
        sudoku[row][col] = i; 
        solve(sudoku, row, col + 1);
        sudoku[row][col] = 0;
      }
    }
  }
}

//one valid sudoku board

bool solve1(vector<vector<int>> &sudoku){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (sudoku[i][j] == 0){
        for (int x = 1; x <= 9; x++){
          if (check(sudoku, x, i, j)) {
            sudoku[i][j] = x;
            if (solve1(sudoku)) return true;
            else {
              sudoku[i][j] = 0;
            }
          } 
        }
        return false;
      }
    }
  }
  return true;
}

int32_t main(){
  // Write your code
  vector<vector<int>> sudoku(9, vector<int>(9, 0)); 
  for (auto &v : sudoku){
    for (int &x : v) cin >> x;
  }
  cout << endl << endl;
  solve1(sudoku);
  for (auto &v : sudoku){
    for (int &x : v) cout << x << " ";
    cout << endl;
  }
}