//Author: Ketan Prakash, Date:
//Program to print star pattern
#include <iostream> 
using namespace std; 

int main(){
  int rows; 
  cin >> rows;
  for (int i = 1; i <= rows; i++){
    for (int j = 1; j <= rows; j++){
      if (j <= rows - i) cout << " " << " ";
      else cout << "*" << " ";
    }
    for (int k = 2; k <= i; k++){
      cout << "*" << " ";
    }
    cout << endl;
  }
  for (int i = rows; i >= 1; i--){
    for (int j = 1; j <= rows; j++){
      if (j <= rows - i) cout << " " << " ";
      else cout << "*" << " ";
    }
    for (int k = 2; k <= i; k++){
      cout << "*" << " ";
    }
    cout << endl;
  }
  return 0;
}