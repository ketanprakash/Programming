//Author: Ketan Prakash, Date:
//Program to prime factor using smallest prime factor (SOE)
#include <iostream>
#include <vector> 
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
    long long int i = 2;  
    primes[0] = primes[1] = 0;
    while (i <= n){
        if (!primes[i]) {
            i++;
            continue;
        }
        for (long long int j = i * i; j <= n; j += i){
            if(primes[j]) {
                primes[j] = 0;
                spf[j] = i; 
            }
        }
        i++;
    }
    return spf;
}

int main(){
    int n; 
    cin >> n; 
    vector<int> spf = smallestPrimeFactor(n);
    while(n > 1){
        cout << spf[n] << ' '; 
        n = n / spf[n];
    }
    return 0;
}