//Author: Ketan Prakash, Date:
//Program to sort an array using bubble sort algo
#include <iostream> 
using namespace std; 

void bubble_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int n; 
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

/*
5 4 3 2 1

4 5 3 2 1
4 3 5 2 1
4 3 2 5 1
4 3 2 1 5

3 2 1 4 5
*/