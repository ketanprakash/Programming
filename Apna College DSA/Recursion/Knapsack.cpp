#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int knapsack(int wt[], int val[], int n, int W){
    if (n == 0 || W == 0) return 0;
    if (wt[0] > W) return knapsack(wt + 1, val + 1, n - 1, W);
    int knap =  max(knapsack(wt + 1, val + 1, n - 1, W), val[0] + knapsack(wt + 1, val + 1, n - 1, W - wt[0]));
    return knap;
}
int32_t main(){
    int wt[3] = {10, 20, 30};
    int val[3] = {100, 50, 150};
    int n = 3;
    int W = 50;
    cout << knapsack(wt, val, n, W) << endl;
    return 0;
}