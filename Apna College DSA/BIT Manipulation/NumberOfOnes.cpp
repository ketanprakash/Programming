//Author: Ketan Prakash, Date:
//Program to find number of 1s in the binary rep of a number using bit manipulation
#include <iostream> 
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    int count = 0; 
    while (n){
        n = n & (n - 1);
        count++;
    }
    cout << count;
    cout << '\n';
    return 0;
}