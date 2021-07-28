//Author: Ketan Prakash, Date:
//Program to prime factor using smallest prime factor (SOE)
#include <iostream>
#include <cmath>
#include <vector> 
#define int long long int
using namespace std; 

vector<int> smallestPrimeFactor(int n){
    vector<int> spf(n + 1, 0);
    vector<bool> primes(n + 1);
    for (int i = 1; i < n + 1; i++){
        spf[i] = i;
    }
    for (int i = 0; i < n + 1; i++){
        primes[i] = 1;
    }
    int i = 2;  
    primes[0] = primes[1] = 0;
    while (i <= n){
        if (!primes[i]) {
            i++;
            continue;
        }
        for (int j = i * i; j <= n; j += i){
            if(primes[j]) {
                primes[j] = 0;
                spf[j] = i; 
            }
        }
        i++;
    }
    return spf;
}

void PrimeFactorization(int n){
    while (n % 2 == 0){
        cout << 2 << " ";
        n /= 2; 
    }
    int i = 3; 
    while (n > 1){
        if (n % i == 0){
            cout << i << " ";
            n /= i; 
        }
        else i += 2;
    }

    if (n > 2) cout << n << " ";
}

int32_t main(){
    int n; 
    // n = __LONG_LONG_MAX__;
    cin >> n; 
    // cin >> n; 
    // vector<int> spf = smallestPrimeFactor(n);
    // while(n > 1){
    //     cout << spf[n] << ' '; 
    //     n = n / spf[n];
    // }
    PrimeFactorization(n);
    return 0;
}