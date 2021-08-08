#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void wavesort(int* arr, int n){
    for (int i = 1; i < n; i += 2){
        if (arr[i] > arr[i - 1]){
            swap(arr[i], arr[i - 1]);
        }
        if (i <= n - 2 && arr[i] > arr[i + 1]){
            swap(arr[i], arr[i - 1]);
        }
    }
}

int32_t main(){
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    wavesort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}