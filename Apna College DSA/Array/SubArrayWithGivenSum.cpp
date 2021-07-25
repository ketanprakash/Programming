//Author: Ketan Prakash, Date:
//Program to find a subarray with given sum 
#include <iostream> 
#include <unordered_map>
using namespace std; 

int main(){
    int n;  
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int givenSum; 
    cin >> givenSum; 
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
    unordered_map<int, int> mp;
    int curr_sum = 0; 
    for (int i = 0; i < n; i++){
        curr_sum += arr[i];
        if (curr_sum == givenSum){
            cout << 0 << " " << i << endl;
            return 0;
        }

        if (mp.find(curr_sum - givenSum) != mp.end()){
            cout << mp[curr_sum - givenSum] + 1 << " " << i << endl;
            return 0;
        }

        mp[curr_sum] = i;
    }
    return 0;
}