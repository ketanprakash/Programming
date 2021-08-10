//Author: Ketan Prakash, Date:
//Program to create 2d array, 2d vector and 2d array with dynamic memory allocation
#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std; 

int main(){
  // int arr[10][10];
  // for (int i = 0; i < 10; i++){
  //   for (int j = 0; j < 10; j++){
  //     arr[i][j] = i * j;
  //   }
  // }
  // for (int i = 0; i < 10; i++) {
  //   for (int j = 0; j < 10; j++){
  //     cout << setw(3) << arr[i][j] << " ";
  //   }
  //   cout << '\n';
  // }
  // int n, m; 
  // cin >> n >> m;
  // int **arr = new int*[n];
  // for (int i = 0; i < n; i++) {
  //   arr[i] = new int[m];
  // }
  // for (int i = 0; i < n; i++){
  //   for (int j = 0; j < m; j++){
  //     arr[i][j] = i * j;
  //   }
  // }
  // for (int i = 0; i < n; i++){
  //   for (int j = 0; j < m; j++){
  //     cout << setw(2) << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int n, m; 
  cin >> n >> m; 
  vector< vector<int> > arr(n, vector<int>(m));
  for (vector<int> &v : arr){
    for (int &x : v) cin >> x;
  }
  for (vector<int> &v : arr){
    for (int &x : v) cout << x << " ";
    cout << endl;
  }
  return 0;
}