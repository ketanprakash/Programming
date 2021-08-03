#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

bool checkSorted(int *arr, uint n){
    if (n == 0 || n == 1){
        return true;
    }
    return (arr[n - 1] >= arr[n - 2]) && checkSorted(arr, n - 1); 
}

bool checkSorted1(int *arr, uint n){
    if (n == 0 || n == 1) return true;
    bool restArray = checkSorted1(arr + 1, n - 1);
    return (arr[0] <= arr[1]) && restArray;
}

int32_t main(){
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << (checkSorted1(arr, n) ? "Sorted" : "Not Sorted"); 
    return 0;
}