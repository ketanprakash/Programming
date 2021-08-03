#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

uint fib(uint n){
    if (n == 0 || n == 1){
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int32_t main(){
    uint x; 
    cin >> x; 
    cout << fib(x) << endl;
    return 0;
}