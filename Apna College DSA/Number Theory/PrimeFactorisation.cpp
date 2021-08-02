#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define n 9999999
using namespace std;

//find smallest prime factor of a number using sieve of eratosthenes
vector<int> smallestprime(){
    vector<bool> isprime(n + 1, 1);
    vector<int> spf(n + 1);
    for (uint i = 0; i <= n; i++){
        spf[i] = i;
    }
    isprime[0] = isprime[1] = 0;
    for (uint i = 2; i <= n; i++){
        if (isprime[i]){
            for (uint j = i * i; j <= n; j += i){
                if (isprime[j]){
                    isprime[j] = 0;
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

int32_t main(){
    //smallest prime factor method o(logn) with o(Max ^ 2) preprocessing
    // vector<int> spf = smallestprime();
    // uint x; 
    // cin >> x; 
    // while (x != 1){
    //     cout << spf[x] << " ";
    //     x /= spf[x];
    // }
    //O(sqrt(n)) method
    cout << endl;
    return 0;
}