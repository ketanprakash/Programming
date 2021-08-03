#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

uint factorial(uint n){
    if (n == 0){
        return 1;
    }
    return factorial(n - 1) * n;
}

int32_t main(){
    uint x; 
    cin >> x; 
    cout << factorial(x) << endl;
    return 0;
}