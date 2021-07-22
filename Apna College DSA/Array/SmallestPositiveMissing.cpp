//Author: Ketan Prakash, Date:
//Program to find smallest positive missing number
#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    bool arr1[1000001] = {0};
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    //nlogn soln:
    // sort(arr, arr + n); //nlogn
    // for (int i = 1; i <= 1000000; i++){
    //     if (upper_bound(arr, arr + n, i) - lower_bound(arr, arr + n, i) == 0) {
    //         cout << i << endl;
    //         break;
    //     } 
    // }
    //o(n) soln
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) arr1[arr[i]] = true;
    }
    for (int i = 1; i < 1000001; i++){
        if (arr1[i] == false) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}