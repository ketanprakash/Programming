//Author: Ketan Prakash, Date:
//Program to find the maximum sum of a subarray
#include <iostream> 
#include <climits>
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    //o(n^3)(brute force) solution: 
    // int maxSum = INT_MIN;
    // for (int i = 0; i < n; i++){
    //     for (int j = i + 1; j < n; j++){
    //         int sum = 0; 
    //         for (int k = i; k <= j; k++){
    //             sum += arr[k];
    //         }
    //         maxSum = max(maxSum, sum);
    //     }
    // }
    //o(n^2) solution: 
    // int maxSum = INT_MIN;
    // int sum;
    // for (int i = 0; i < n; i++){
    //     sum = arr[i]; 
    //     maxSum = max(maxSum, sum);
    //     for (int j = i + 1; j < n; j++){
    //         sum += arr[j];
    //         maxSum = max(maxSum, sum);
    //     }
    // }
    // cout << maxSum;
    //O(n) using kadane's algo
    bool kadaneFlag = 0; 
    int ArrMax = INT_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] >= 0){
            kadaneFlag = 1;
        }
        ArrMax = max(arr[i], ArrMax);
    }
    if (kadaneFlag){
        int sum, maxSum; 
        sum = maxSum = 0; 
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum < 0) sum = 0; 
            maxSum = max(sum, maxSum);
        }
        cout << maxSum << endl;
    }
    else {
        cout << ArrMax << endl;
    }
    return 0;
}