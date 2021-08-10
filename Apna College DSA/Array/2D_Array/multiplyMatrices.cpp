//Author: Ketan Prakash, Date:
//Program to multiply two matrices
#include <iostream> 
#include <iomanip>
using namespace std; 

int** multiply(int** arr1, int** arr2, int n1, int n2, int n3){
  int **arr = new int*[n1];
  for (int i = 0; i < n1; i++) arr[i] = new int[n3];
  for (int i = 0; i < n1; i++){
    for (int j = 0; j < n3; j++){
      arr[i][j] = 0;
      for (int k = 0; k < n2; k++){
        arr[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
  return arr;
}
int main(){
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3; 
  int** arr1 = new int*[n1];
  for (int i = 0; i < n1; i++){
    arr1[i] = new int[n2];
  }
  int** arr2 = new int*[n2];
  for (int i = 0; i < n2; i++){
    arr2[i] = new int[n3];
  }
  cout << "Enter first Matrix: " << endl;
  for (int i = 0; i < n1; i++){
    for (int j = 0; j < n2; j++){
      cin >> arr1[i][j];
    }
  }
  cout << "Enter Second Matrix: " << endl;
  for (int i = 0; i < n2; i++){
    for (int j = 0; j < n3; j++){
      cin >> arr2[i][j];
    }
  }
  cout << "Answer: " << endl;
  int **arr = multiply(arr1, arr2, n1, n2, n3);
  for (int i = 0; i < n1; i++){
    for (int j = 0; j < n3; j++){
      cout << setw(3) << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}