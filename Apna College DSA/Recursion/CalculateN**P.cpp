#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

uint power(uint n, uint p){
    if (p == 0){
        return 1;
    }
    return power(n, p - 1) * n;
}
int32_t main(){
    uint x, p; 
    cin >> x >> p; 
    cout << power(x, p) << endl;
    return 0;
}