//Program to interconvert infix, postfix, prefix expressions
#include <bits/stdc++.h>  
#include "stackArr.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

unordered_map<char, int> m; 

string rev(string s){
  int i = 0, j = s.size() - 1;
  while (i < j){
    swap(s[i], s[j]);
    i++; j--;
  }
  return s;
}

string infixToPostfix(string infix){
  string s; stackArr<char> st;
  int n = infix.size();
  for (int i = 0; i < n; i++){
    if (infix[i] == ' '){
      continue;
    }
    else if (infix[i] == '('){
      st.push(infix[i]);
    }
    else if (infix[i] == ')'){
      while ((!st.empty()) && st.top() != '('){
        s.push_back(st.top());
        st.pop();
      }
      st.pop();
    }
    else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
      if (st.empty()){
        st.push(infix[i]);
      }
      else {
        while ((!st.empty()) && (m[infix[i]] < m[st.top()])){
          s.push_back(st.top());
          st.pop();
        }
        st.push(infix[i]);
      }
    }
    else {
      s.push_back(infix[i]);
    }
  }
  while (!st.empty()){
    s.push_back(st.top());
    st.pop();
  }
  return s;
}

string infixToPrefix(string &infix){
  return rev(infixToPostfix(rev(infix)));
}

string postfixToInfix(string &postfix){
  stackArr<string> st;
  string a, b, s, s1;
  int n = postfix.size();
  for (int i = 0; i < n; i++){
    if (postfix[i] == ' '){
      continue;
    }
    else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*'){
      b = st.top(); st.pop(); 
      a = st.top(); st.pop();
      s = "(" + a + postfix[i] + b + ")";
      st.push(s);
    }
    else {
      s1 = "";
      s1.push_back(postfix[i]);
      st.push(s1);
    }
  }
  s = st.top();
  st.pop(); 
  return s;
}

string prefixToInfix(string &postfix){
  stackArr<string> st;
  string a, b, s, s1;
  int n = postfix.size();
  for (int i = n - 1; i >= 0; i--){
    if (postfix[i] == ' '){
      continue;
    }
    else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*'){
      a = st.top(); st.pop(); 
      b = st.top(); st.pop();
      s = "(" + a + postfix[i] + b + ")";
      st.push(s);
    }
    else {
      s1 = "";
      s1.push_back(postfix[i]);
      st.push(s1);
    }
  }
  s = st.top();
  st.pop(); 
  return s;
}

int32_t main(){
  m['+'] = m['-'] = 1; m['*'] = m['/'] = 2;
  string prefix, infix, postfix;
  getline(cin, postfix);
  // postfix = infixToPostfix(infix);
  // cout << postfix << endl;
  infix = postfixToInfix(postfix);
  cout << infix << endl;
  return 0;
}

/*
a * b + c

string :
a b * 
stack :
*
*/