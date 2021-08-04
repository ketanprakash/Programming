#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int tilingways(int n){
    if (n <= 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return tilingways(n - 1) + tilingways(n - 2);
}

int32_t main(){
    int n; 
    cin >> n; 
    cout << tilingways(n);
    return 0;
}