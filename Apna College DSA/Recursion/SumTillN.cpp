#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int sum(int n){
    if (n == 0){
        return 0;
    }
    int prevsum = sum(n - 1);
    return prevsum + n;
}

// int sum(int n){
//     return n * (n + 1) / 2;
// }

int32_t main(){
    int x; 
    cin >> x; 
    cout << sum(x) << endl;
    return 0;
}