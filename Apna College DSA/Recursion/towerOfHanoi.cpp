#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void towerOfHanoi(int n, char start, char medium, char end, int &moves){
    if (n == 0) return;
    towerOfHanoi(n - 1, start, end, medium, moves);
    // cout << "Take ring from " << start << " to " << end << endl; 
    moves++;
    towerOfHanoi(n - 1, medium, start, end, moves);
}

int32_t main(){
    //A - start, B - med, C - end
    int n; 
    cin >> n; 
    int moves = 0;
    towerOfHanoi(n, 'A', 'B', 'C', moves);
    cout << "Moves: " << moves << endl;
    return 0;
}

