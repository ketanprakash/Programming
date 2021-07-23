//Author: Ketan Prakash, Date:
//Program to sort using count sort
#include <iostream> 
using namespace std; 

void count_sort(int *arr, int n){
    int maxn = arr[0];
    for (int i = 1; i < n; i++){
        maxn = max(maxn, arr[i]);
    }
    int *count = new int[maxn + 1];
    for (int i = 0; i < maxn + 1; i++){
        count[i] = 0; 
    }
    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    int j = 0; 
    for (int i = 0; i < maxn + 1; i++){
        while(count[i]){
            arr[j] = i;
            j++; count[i]--;
        }
    }
}

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    count_sort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}