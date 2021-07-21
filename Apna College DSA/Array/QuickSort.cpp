//Author: Ketan Prakash, Date:
//Program to sort an array using quicksort 
#include <iostream> 
#include <cstdio>
#include <cstdlib>
using namespace std; 

int partition(int *arr, int s, int e){
    int pivot = arr[e];
    int i = s - 1; 
    for (int j = s; j <= e - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

int partition_random(int *arr, int s, int e){
    srand(time(0));
    int random = s + rand() / RAND_MAX * (e - s);
    swap(arr[random], arr[e]);
    int pivot = arr[e];
    int i = s - 1; 
    for (int j = s; j <= e - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quick_sort(int *arr, int s, int e){
    if (s > e) return;
    // int pi = partition(arr, s, e);
    int pi = partition_random(arr, s, e);
    quick_sort(arr, s, pi - 1);
    quick_sort(arr, pi + 1, e);
}

int main(){
    int n; 
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}