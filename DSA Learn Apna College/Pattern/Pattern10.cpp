//Author: Ketan Prakash, Date:
//Program to print rhombus pattern
#include <iostream> 
using namespace std; 

int main(){
  int rows; 
  cin >> rows;
  for (int i = rows; i >= 1; i--){
    for (int j = 1; j <= i - 1; j++){
      cout << " ";
    }
    for (int k = 1; k <= rows; k++){
      cout << "* ";
    }
    cout << endl;
  }
  return 0;
}