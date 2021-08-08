//Program to count no of count inversions
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int inversion_bf(int* arr, int n){
    //brute force O(n ^ 2)
    int c = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[i]){
                c++;
            }
        }
    }
    return c;
}

int merge(int* arr, int s, int m, int e){
    int inv = 0;
    int n1 = m - s + 1; 
    int n2 = e - m;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];
    for (int i = 0; i < n1; i++){
        arr1[i] = arr[i + s];
    }
    for (int i = 0; i < n2; i++){
        arr2[i] = arr[i + m + 1];
    }
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2){
        if (arr1[i] > arr2[j]){
            arr[k] = arr2[j];
            inv += n1 - i;
            k++; j++;
        }
        else {
            arr[k] = arr1[i];
            k++; i++;
        }
    }
    while (i < n1){
        arr[k] = arr1[i];
        k++; i++;   
    }
    while (j < n2){
        arr[k] = arr2[j];
        k++; j++;
    }
    return inv;
}

int mergesort(int* arr, int s, int e){
    if (s >= e){
        return 0;
    }
    int inv = 0; 
    int m = s + (e - s) / 2;
    inv += mergesort(arr, s, m);
    inv += mergesort(arr, m + 1, e);
    inv += merge(arr, s, m, e);
    return inv;
}

int32_t main(){
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    // cout << inversion_bf(arr, n) << endl;
    int inv = mergesort(arr, 0, n - 1);
    cout << inv << endl;
    return 0;
}