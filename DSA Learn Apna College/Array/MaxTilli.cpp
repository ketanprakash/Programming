//Author: Ketan Prakash, Date:
//Program to find max till i
#include <iostream> 
using namespace std; 

int main(){
  int n; 
  cin >> n; 
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int max = arr[0];
  for (int i = 0; i < n; i++){
    if (arr[i] > max){
      max = arr[i];
    }
    cout << max << " ";
  }
  return 0;
}