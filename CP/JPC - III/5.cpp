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
        int m, n, maxsum;
        cin >> m >> n >> maxsum;
        vint M(m), N(n);
        for (int &x : M) cin >> x; 
        for (int &x : N) cin >> x; 
        int sum = 0; 
        int count1 = 0, count2 = 0, count3 = 0; 
        for (int i = 0; i < n; i++){
            sum += M[i];
            if (sum < maxsum){
                count1++;
            }
        }

        //code end
    }
    return 0;
}