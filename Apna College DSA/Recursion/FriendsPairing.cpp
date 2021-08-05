#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int noOfWaysToPairFriends(int n){
    if (n < 0){
        return 0;
    }
    if (n == 1 || n == 0){
        return 1; 
    }
    
    return noOfWaysToPairFriends(n - 1) + (n - 1) * noOfWaysToPairFriends(n - 2);
}

int32_t main(){
    int n; 
    cin >> n;
    cout << noOfWaysToPairFriends(n) << endl;
    return 0;
}
