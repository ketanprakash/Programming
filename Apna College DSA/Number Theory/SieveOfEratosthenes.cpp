//Author: Ketan Prakash, Date:
//Program to write sieve of erotesthenes function
#include <iostream> 
using namespace std; 

void primeSieve(int n){
    int *primes = new int[n + 1];
    primes[0] = primes[1] = 0;
    for (int i = 2; i < n; i++){
        primes[i] = 1;
    }
    long long int i = 2; 
    while(i <= n){
        if (primes[i]){
            for (long long int j = i * i; j <= n; j += i){
                if (primes[j]) primes[j] = 0;
            }
        }
        i++;
    }
    for (int i = 2; i <= n; i++){
        if (primes[i]) cout << i << " ";
    }
}

int main(){
    int n; 
    cin >> n;
    primeSieve(n);
    return 0;
}