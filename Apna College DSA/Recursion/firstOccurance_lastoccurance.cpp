#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int lastOccurance(int* arr, int n, int k){
    if (n == 0){
        return -1;
    }
    if (arr[n - 1] == k){
        return n - 1;
    }
    return lastOccurance(arr, n - 1, k);
}

int firstOccurance(int* arr, int n, int k){
    if (n == 0){
        return -1;
    }
    int idx = firstOccurance(arr, n - 1, k);
    if (idx == -1 && arr[n - 1] == k){
        return n - 1;
    }
    return idx;
}

int32_t main(){
    uint n; 
    cin >> n; 
    int* arr = new int[n];
    for (uint i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k; 
    cin >> k;
    cout << firstOccurance(arr, n, k) << endl;
    cout << lastOccurance(arr, n, k) << endl;
    return 0;
}