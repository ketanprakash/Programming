#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void generateAllSubstrings(string s, string ans = ""){
  if (s.size() == 0){
    cout << ans << endl;
    return;
  }
  generateAllSubstrings(s.substr(1), ans);
  generateAllSubstrings(s.substr(1), ans+s[0]);
}

void generateAllSubstringsWithAscii(string s, string ans = ""){
  if (s.size() == 0){
    cout << ans << endl;
    return;
  }
  generateAllSubstringsWithAscii(s.substr(1), ans);
  generateAllSubstringsWithAscii(s.substr(1), ans+s[0]);
  generateAllSubstringsWithAscii(s.substr(1), ans+to_string((int)(s[0])));
}

int32_t main(){
  string s; 
  cin >> s; 
  // generateAllSubstrings(s, "");
  generateAllSubstringsWithAscii(s);
  return 0;
}