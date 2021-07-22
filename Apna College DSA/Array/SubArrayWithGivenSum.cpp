//Author: Ketan Prakash, Date:
//Program to find a subarray with given sum
#include <iostream> 
using namespace std; 

int main(){
    int n;  
    cin >> n; 
    int givenSum; 
    cin >> givenSum; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
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
    //optimized
    int a, b; 
    a = b = 0;
    int currSum = arr[0];
    while (a <= b && b <= n - 1){
        if (currSum == givenSum){
            cout << a << " " << b; 
            break;
        }
        else if (currSum < givenSum){
            b++;
            currSum += arr[b];
        }
        else {
            currSum -= arr[a];
            a++;
        }
    }
    return 0;
}