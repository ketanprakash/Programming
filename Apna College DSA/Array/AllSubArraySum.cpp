//Author: Ketan Prakash, Date:
//Program to find the sum of all subarrays of a given subarray
#include <iostream> 
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++){
        int sum = 0; 
        for (int j = i; j < n; j++){
            sum += arr[j];
            cout << sum << " ";
        }
    }
    return 0;
}