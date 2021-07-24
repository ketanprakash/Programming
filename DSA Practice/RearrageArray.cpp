//Author: Ketan Prakash, Date:
//Program to rearrange array in alternate positive and negative
#include <iostream>
#include <algorithm> 
using namespace std; 

int main(){
    // o(n) solution
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int evenIdx = 0; 
    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            swap(arr[i], arr[evenIdx]);
            evenIdx += 2; 
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}