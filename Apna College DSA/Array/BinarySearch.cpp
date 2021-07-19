//Author: Ketan Prakash, Date:
//Program for binary search
#include <iostream> 
using namespace std; 

bool binary_search(int arr[], int s, int e, int key){
    while (s <= e){
        int m = s + (e - s)/2;
        if (key == arr[m]) return true;
        else if (key > arr[m]) s = m + 1;
        else e = m - 1;
    }
    return false;
}

unsigned int lower_bound(int arr[], int s, int e, int key){
    int m;
    while (s < e){
        m = s + (e - s)/2;
        if (key <= arr[m]) e = m;
        else s = m + 1;
    }
    return s;
}

unsigned int upper_bound(int arr[], int s, int e, int key){
    int m;
    while (s < e){
        m = s + (e - s)/2;
        if (key < arr[m]) e = m;
        else s = m + 1;
    }
    return s;
}

int main(){
    int arr[] = {12, 45, 45, 56, 90, 120, 253, 451};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout << binary_search(arr, 0, n - 1, 13) << endl;
    cout << lower_bound(arr, 0, n - 1, 45) << endl;
    cout << upper_bound(arr, 0, n - 1, 45) << endl;
    // cout << lower_bound(arr, arr + n, 13) - arr;
    return 0;
}