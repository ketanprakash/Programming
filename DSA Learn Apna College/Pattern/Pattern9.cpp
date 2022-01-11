//Author: Ketan Prakash, Date:
//Program to print a 0-1 pattern
#include <iostream> 
using namespace std; 

int main(){
  // 1
  // 0 1
  // 1 0 1
  // 0 1 0 1
  // 1 0 1 0 1
  int rows; 
  cin >> rows; 
  for (int i = 1; i <= rows; i++){
    bool flag; 
    if (i % 2 == 0) flag = 0;
    else flag = 1;
    for (int j = 1; j <= i; j++){
      cout << flag << " ";
      flag = !flag;
    }
    cout << endl;
  }
  return 0;
}