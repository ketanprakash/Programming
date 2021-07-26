#include <bits/stdc++.h> 
using namespace std; 
#define     int         long long int
#define     um          unordered_map
#define     vint        vector<int> 
#define     vvint       vector<vector<int> >
#define     vstring     vector<string> 
#define     vchar       vector<char>
#define     vfloat      vector<double>
#define     sint        set<int>
#define     uint        unordered_map<int, int>
#define     fastio      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define     endl        '\n'
#define     pb          push_back
#define     pushback    push_back

int32_t main(){
    fastio
    int t; 
    cin >> t; 
    while(t--){
        //code start
        int n; 
        cin >> n; 
        vint v(n);
        for (int &x : v) cin >> x; 
        int maxm = v[0], minm = v[0];
        for (int x : v){
            maxm = max(maxm, x);
            minm = min(minm, x); 
        }
        cout << (maxm - minm) * (n - 1) << endl;
        //code end
    }
    return 0;
}

/*
a1, a2, a3, a4, a5, a6 ... an


*/