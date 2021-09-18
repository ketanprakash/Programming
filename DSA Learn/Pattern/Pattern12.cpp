//Author: Ketan Prakash, Date:
//Program to print number palindromic pattern
#include <iostream> 
using namespace std; 

int main(){
  int rows; 
  cin >> rows; 
  for (int i = 1; i <= rows; i++){
    for (int j = rows; j >= 1; j--){
      if (j <= i){
        cout << j << " "; 
      }
      else cout << " " << " ";
    }
    for (int k = 2; k <= i; k++){
      cout << k << " "; 
    }
    cout << endl;
  }
  return 0;
}