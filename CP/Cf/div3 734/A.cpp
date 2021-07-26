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
        if (n % 3 == 0){
            cout << n/3 << " " << n/3 << endl;
        }
        else if (n % 3 == 1){
            cout << n/3 + 1 << " " << n/3 << endl;
        }
        else {
            cout << n/3 << " " << n/3 + 1<< endl;
        }
        //code end
    }
    return 0;
}