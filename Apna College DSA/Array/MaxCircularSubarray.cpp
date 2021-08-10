//Author: Ketan Prakash, Date:
//Program to find the sum of the max circular subarray

#include <iostream> 
using namespace std; 

int kadane(int *arr, int n){
  int sum = 0, maxSum = 0;
  for (int i = 0; i < n; i++){
    sum += arr[i];
    if (sum < 0) sum = 0; 
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}

int main(){
  int n; 
  cin >> n; 
  int *arr = new int[n];
  int Sum = 0; 
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    Sum += arr[i];
  }
  int maxLinearSum = kadane(arr, n);
  for (int i = 0; i < n; i++){
    arr[i] = - arr[i];
  }
  int maxCircularSum = Sum + kadane(arr, n);
  cout << max(maxLinearSum, maxCircularSum) << endl;
  return 0;
}
/*
1 23 -2 3 -23 22
-1 -23 2 -3 23 -22
*/

/*
min sum = 0
a (+)b c (+)d e f
b < 0 d < 0
|b| > |c| and |d| > |c|
x > 0, y < 0
x < 0, y > 0
S = x + y
kadane = -y
S = x - kadane
x = S + kadane 
*/