//You are given n activities with their start and finish times. Select the mex number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n; 
  cin >> n; 
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++){
    int s, e; 
    cin >> s >> e; 
    v.push_back(pair<int, int>(s, e));
  }
  sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
  });
  int take = 1;
  int end = v[0].second;
  for (int i = 0; i < n; i++){
    if (v[i].first >= end){
      take++;
      end = v[i].second;
    }
  }
  cout << take << endl;
  return 0;
}