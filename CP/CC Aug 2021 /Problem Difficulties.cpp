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
    vint a(4); 
    cin >> a[0] >> a[1] >> a[2] >> a[3]; 
    uint s; 
    for (int x : a) s[x]++;
    if (s.size() == 4) cout << 2 << endl;
    if (s.size() == 3) cout << 2 << endl;
    if (s.size() == 2) {
      if (s[a[0]] == 2) cout << 2 << endl;
      else cout << 1 << endl;
    }
    if (s.size() == 1) cout << 0 << endl;
    //code end
  }
  return 0;
}