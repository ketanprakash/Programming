#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool isSafe1(vector<vector<int>> &board, int row, int col){
  int dupcol = col, duprow = row;
  //left
  while (col >= 0){
    if (board[row][col] == 1) return false;
    col--;
  }

  //diag1
  col = dupcol; row = duprow;
  while (col >= 0 && row >= 0){
    if (board[row][col] == 1) return false;
    row--; col--;
  }

  //diag2
  col = dupcol; row = duprow;
  while (col >= 0 && row < board.size()){
    if (board[row][col] == 1) return false;
    row++; col--;
  }

  return true;
}

void fill(vector<vector<int>> &board, int col, vector<vector<vector<int>>> &ans){
  if (col == board.size()) {
    ans.push_back(board);
    return;
  }
  for (int row = 0; row < board.size(); row++){
    if (isSafe1(board, row, col)){
      board[row][col] = 1;
      fill(board, col + 1, ans);
      board[row][col] = 0;
    }
  }
}

int32_t main(){
  // Write your code
  int n;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n, 0));
  vector<vector<vector<int>>> ans;
  fill(board, 0, ans);
  for (auto vv : ans){
    for (auto v : vv){
      for (auto x : v) cout << x << " ";
      cout << endl;
    }
    cout << endl;
  }
}