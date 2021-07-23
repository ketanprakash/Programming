//Author: Ketan Prakash, Date:
//Program to get a bit
#include <iostream> 
using namespace std; 

bool getBit(int n, int pos){
    return (((1 << pos) & n) >> pos);
}

void setBit(int &n, int pos){
    n = n | (1 << pos);
}

void unsetBit(int &n, int pos){
    n = n & (~(1 << pos));
}

int main(){
    int n, pos; 
    cin >> n >> pos; 
    // cout << getBit(n, pos) << endl;
    // setBit(n, pos);
    unsetBit(n, pos);
    cout << n << endl;
    return 0;
}