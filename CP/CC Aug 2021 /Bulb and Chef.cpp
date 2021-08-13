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
    int n, p, k; 
    cin >> n >> p >> k; 
    int r = p % k; 
    if (n % k != 0){
      int r1 = (n - 1) % p; 
      if (r <= r1 + 1){
        cout << r * (n / k + 1) + p / k + 1 << endl;
      }
      else {
        cout << r * (n / k) + r1 + 1 + p / k + 1 << endl;
      }
    }
    else {
      cout << r * (n / k) + p / k + 1 << endl;
    }
    //code
  }
  return 0;
}

/*
2 1 3

0 1

*/