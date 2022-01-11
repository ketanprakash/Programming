//Author: Ketan Prakash, Date:
//Program to find the longest arithmetic subarray
#include <iostream> 
using namespace std; 

int main(){
  int t; 
  cin >> t; 
  while(t--){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 2, lmax = l, d = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++){
      if (d == arr[i + 1] - arr[i]){
        l++;
        lmax = max(l, lmax);
      }
      else {
        lmax = max(l, lmax);
        l = 2; 
        d = arr[i + 1] - arr[i];
      }
    }
    cout << lmax << endl;
  }
  return 0;
}