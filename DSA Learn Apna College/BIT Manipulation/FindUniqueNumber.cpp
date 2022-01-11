//Author: Ketan Prakash, Date:
//Program to find unique number in which all other elements appear twice
#include <iostream> 
using namespace std; 

int main(){
  int n; 
  cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int x = arr[0];
  for (int i = 1; i < n; i++) x = x ^ arr[i];
  cout << x << endl;
  return 0;
}