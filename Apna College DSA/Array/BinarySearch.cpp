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
    bool lastFlag = false;
    if (arr[e] < key) lastFlag = true;
    while (s < e){
        m = s + (e - s)/2;
        if (key <= arr[m]) e = m;
        else s = m + 1;
    }
    return lastFlag ? s + 1 : s;
}

unsigned int upper_bound(int arr[], int s, int e, int key){
    int m;
    bool lastFlag = false;
    if (arr[e] <= key) lastFlag = true;
    while (s < e){
        m = s + (e - s)/2;
        if (key < arr[m]) e = m;
        else s = m + 1;
    }
    return lastFlag ? s + 1 : s;
}

int main(){
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int key; 
    cin >> key;
    if (binary_search(arr, 0, n - 1, key)) cout << key << " found in the array" << endl;
    // cout << binary_search(arr, 0, n - 1, 13) << endl;
    int upperBound, lowerBound; 
    upperBound = upper_bound(arr, 0, n - 1, key);
    lowerBound = lower_bound(arr, 0, n - 1, key);
    cout << "Lower bound of " << key << " in the array: " << lowerBound << endl;
    cout << "Upper bound of " << key << " in the array: " << upperBound << endl;
    cout << "Count of " << key << " in the array: " << upperBound - lowerBound << endl;
    // cout << lower_bound(arr, arr + n, 13) - arr;
    return 0;
}