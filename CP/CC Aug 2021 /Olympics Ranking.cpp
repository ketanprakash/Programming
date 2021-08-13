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
    int g1, s1, b1, g2, s2, b2; 
    cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2; 
    cout << ((g1 + s1 + b1) > (g2 + s2 + b2) ? 1 : 2) << endl;
    //code end
  }
  return 0;
}