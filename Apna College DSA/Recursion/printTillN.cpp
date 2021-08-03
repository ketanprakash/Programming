#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void inc(int n){
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    inc(n - 1);
    cout << n << endl;
}

void dec(int n){
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    dec(n - 1);
}

int32_t main(){
    int x; 
    cin >> x; 
    inc(x);
    cout << endl;
    dec(x);
    return 0;
}