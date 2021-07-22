//Author: Ketan Prakash, Date:
//Program to find if a pair of numbers exists in an array having sum = k(given)
#include <iostream> 
#include <algorithm>
#include <unordered_map>
using namespace std; 

//brute force
// bool pairSum(int* arr, int n, int k){
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){
//             if (arr[i] + arr[j] == k){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//in o(nlogn)
// bool pairSum(int* arr, int n, int k){
//     sort(arr, arr + n);
//     int s = 0, e = n - 1; 
//     while (s < e){
//         if (arr[s] + arr[e] == k){
//             return true;
//         }
//         else if (arr[s] + arr[e] < k){
//             s++;
//         }
//         else {
//             e--;
//         }
//     }
//     return false;
// }

//O(n + maxn)
// bool pairSum(int* arr, int n, int k){
//     int maxn = arr[0];
//     for (int i = 1; i < n; i++){
//         maxn = max(arr[i], maxn);
//     }
//     bool *arr1 = new bool[maxn + 1];
//     for (int i = 0; i < maxn + 1; i++){
//         arr1[i] = 0;
//     }
//     for (int i = 0; i < n; i++){
//         if (arr1[k - arr[i]]) {
//             return true;
//         }
//         else arr1[arr[i]] = 1;
//     }
//     return false;
// }

//o(n)
bool pairSum(int *arr, int n, int k){
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++){
        if (m[k - arr[i]]) return true;
        else m[arr[i]] = 1; 
    }
    return false;
}

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int k; 
    cin >> k;
    cout << pairSum(arr, n, k) << endl;
    return 0;
}