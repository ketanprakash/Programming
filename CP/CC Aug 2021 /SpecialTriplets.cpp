#include <bits/stdc++.h> 
using namespace std; 
#define   int       long long int
#define   um        unordered_map
#define   vint      vector<int> 
#define   vvint     vector<vector<int> >
#define   vstring   vector<string> 
#define   vchar     vector<char>
#define   vfloat    vector<double>
#define   sint      set<int>
#define   uint      unordered_map<int, int>
#define   fastio    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define   endl      '\n'
#define   pb        push_back
#define   pushback  push_back

int32_t main(){
  fastio
  int t; 
  cin >> t; 
  while(t--){
    //code start
    int n; 
    cin >> n; 
    int count = 0; 
    vector<pair<int, int> > v; 
    for (int c = 1; c <= n; c++){
      for (int k = 2; k * c <= n; k++){
        // cout << k * c << " " << c << endl;
        v.push_back(pair<int, int>(k * c, c));
      }
    }
    for (auto p : v){
      int c = p.second, b = p.first;
      int m = (n - c) / b;
      count += m + 1;
    }
    cout << count << endl;
    //code end
  }
  return 0;
}

/*
a % b = c
b % c = 0

b = kc
a = mb + c
a = mkc + c
a = (mk + 1)c
*/