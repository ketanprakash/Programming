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
    int m, n; 
    cin >> m >> n;
    vint A(n), B(m), C(n);
    for (int i = 0; i < m; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++){
        C[i] = (upper_bound(B.begin(), B.end(), A[i]) - B.begin());
    }
    for (int i = 0; i < n; i++) cout << C[i] << " ";
    cout << endl;
    //code end
    return 0;
}