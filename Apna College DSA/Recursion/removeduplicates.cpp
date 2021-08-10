#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void removeDuplicates(string s){
  if (s.size() == 0 || s.size() == 1){
    cout << s;
    return; 
  }
  if (s[0] != s[1]) cout << s[0];
  removeDuplicates(s.substr(1));
}

string removeDuplicates1(string s){
  if (s.size() == 0){
    return "";
  }
  string rest_no_duplicates = removeDuplicates1(s.substr(1));
  if (s[0] != rest_no_duplicates[0]) {
    rest_no_duplicates.insert(rest_no_duplicates.begin(), s[0]);
  }
  return rest_no_duplicates;
}

int32_t main(){
  string s; 
  cin >> s; 
  // removeDuplicates(s);
  s = removeDuplicates1(s);
  cout << s;
  cout << endl;
  return 0;
}