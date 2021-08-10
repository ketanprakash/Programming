#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void generatePermutations(string s, string ans = ""){
  if (s.size() == 0){
    cout << ans << endl;
  } 
  string ros;
  for (uint i = 0; i < s.size(); i++){
    ros = s.substr(0, i) + s.substr(i + 1);
    generatePermutations(ros, ans + s[i]);
  }
}

int32_t main(){
  string s; 
  cin >> s;
  cout << endl;
  generatePermutations(s);
  return 0;
}