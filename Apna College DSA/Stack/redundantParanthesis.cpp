//Program to find if there are redundant paranthesis in a mathematical expression
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool redundant(string s){
  stack<char> st;
  bool flag;
  for (uint i = 0; i < s.size(); i++){
    if (s[i] == ' ') continue;
    else if (s[i] == ')'){
      flag = 1;
      while (!st.empty() && st.top() != '('){
        if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
          flag = 0;
        }
        st.pop();
      }
      st.pop();
      if (flag) return 1;
    }
    else {
      st.push(s[i]);
    }
  }
  return 0;
}

int32_t main(){
  string s; 
  getline(cin, s);
  cout << (redundant(s) ? "Redundant Parenthesis present": "Redundant Parenthesis not present");
  return 0;
}