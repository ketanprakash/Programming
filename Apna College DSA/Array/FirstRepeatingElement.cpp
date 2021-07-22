//Author: Ketan Prakash, Date:
//Given an arr[] of size N. The Task is to find the first repeating element in the array of integers, i.e. an element that occurs more than once and whose index of first occurance is smallest
#include <iostream> 
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int maxn = arr[0]; 
    for (int i = 1; i < n; i++) maxn = max(maxn, arr[i]);
    int *arr1 = new int[maxn + 1];
    for (int i = 0; i < maxn + 1; i++){
        arr1[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        arr1[arr[i]]++;
    }
    for (int i = 0; i < n; i++){
        if (arr1[arr[i]] > 1){
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}