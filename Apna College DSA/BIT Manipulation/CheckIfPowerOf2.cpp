//Author: Ketan Prakash, Date:
//Program to check if the given number is a power of 2
#include <iostream> 
using namespace std; 

bool powerOf2(int n){
    return n & ((n & (n - 1)) == 0);
}

int main(){
    int n; 
    cin >> n;
    cout << powerOf2(n) << endl;
    return 0;
}