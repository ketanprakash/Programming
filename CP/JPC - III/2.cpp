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
    //code start
    vint v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    int x = v[2] - v[0];
    cout << x << endl;
    //code end
    return 0;
}