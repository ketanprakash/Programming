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
  int n;
  cin >> n; 
  int *wt = new int[n];
  int *val = new int[n];
  cout << "Enter Weight of all elements: " << endl;
  for (int i = 0; i < n; i++) cin >> wt[i];
  cout << "Enter value of all elements: " << endl;
  for (int i = 0; i < n; i++) cin >> val[i];
  int W;
  cout << "Enter Knapsack Capacity: " << endl;
  cin >> W;
  cout << knapsack(wt, val, n, W) << endl;
  return 0;
}