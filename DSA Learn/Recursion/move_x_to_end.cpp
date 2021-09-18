#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void move_x_to_end(string s, string xs = ""){
  if (s.size() == 0){
    cout << xs;
    return;
  }
  if (s[0] != 'x'){
    cout << s[0];
  }
  else {
    xs.push_back('x');
  }
  move_x_to_end(s.substr(1), xs);
}

string move_x_to_end1(string s){
  if (s.size() == 0){
    return "";
  }
  string s1 = move_x_to_end1(s.substr(1));
  if (s[0] == 'x'){
    s1.push_back('x');
  }
  else {
    s1.insert(s1.begin(), s[0]);
  }
  return s1;
}

int32_t main(){
  string s; 
  cin >> s;
  // move_x_to_end(s);
  string s1 = move_x_to_end1(s);
  cout << s1 << endl;
  return 0;
}