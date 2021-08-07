#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

int noOfWaysToPairFriends(int n){
    if (n == 0 || n == 1){
        return 1;
    }

    if (n < 0){
        return 0;
    }

    return noOfWaysToPairFriends(n - 1) + (n - 1) * noOfWaysToPairFriends(n - 2);
}

int32_t main(){
    int x; 
    cin >> x; 
    cout << noOfWaysToPairFriends(x) << endl;
    return 0;
}