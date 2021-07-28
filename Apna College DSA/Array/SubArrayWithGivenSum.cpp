//Author: Ketan Prakash, Date:
//Program to find a subarray with given sum 
#include <iostream> 
#include <unordered_map>
using namespace std; 

int main(){
    // int n;  
    // cin >> n; 
    // int *arr = new int[n];
    // for (int i = 0; i < n; i++) cin >> arr[i];
    // int givenSum; 
    // cin >> givenSum; 
    //brute force
    // for (int i = 0; i < n; i++){
    //     int sum = 0; 
    //     for (int j = i; j < n; j++){
    //         sum += arr[j];
    //         if (sum == givenSum){
    //             cout << i << " " << j << endl;
    //             break;
    //         }
    //     }
    // }
    //optimized for non negative integers
    // int a, b; 
    // a = b = 0;
    // int currSum = arr[0];
    // while (b <= n - 1){
    //     if (currSum == givenSum){
    //         cout << a << " " << b; 
    //         break;
    //     }
    //     else if (currSum < givenSum){
    //         b++;
    //         currSum += arr[b];
    //     }
    //     else {
    //         currSum -= arr[a];
    //         if (a == b) {
    //             a++; b++;
    //             currSum = arr[b];
    //         }
    //         else a++;
    //     }
    // }
    //O(n) using unordered_map
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int key; 
    cin >> key;
    unordered_map<int, int> m;
    int curr_sum = 0;
    for (int i = 0; i < n; i++){
        curr_sum += arr[i];
        if (curr_sum == key) {
            cout << 0 << " " << i << endl;
            break;
        }
        if (m.find(curr_sum - key) != m.end()){
            cout << m[curr_sum - key] + 1 << " " << i << endl;
            break;
        }
        m[curr_sum] = i;
    }
    return 0;
}