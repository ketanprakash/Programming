//Program to check balanced paranthesis
#include <bits/stdc++.h>  
#include "stackArr.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

bool checkBalanced(string &s){
  int n = s.size();
  stackArr<char> stack;
  for (int i = 0; i < n; i++){
    if (s[i] == ' ') continue;
    if (s[i] == '(' || s[i] == '{' || s[i] == '['){
      stack.push(s[i]);
    }
    else {
      if ((!stack.empty()) && s[i] == ')' && stack.top() == '('){
        stack.pop();
      }
      else if ((!stack.empty()) && s[i] == '}' && stack.top() == '{'){
        stack.pop();
      }
      else if ((!stack.empty()) && s[i] == ']' && stack.top() == '['){
        stack.pop();
      }
      else{
        return false;
      } 
    }
  }
  return (stack.empty());
}

int32_t main(){
  string exp; 
  getline(cin, exp);
  if (checkBalanced(exp)){
    cout << "Balanced!!" << endl;
  }
  else {
    cout << "Not Balanced!!" << endl;
  }
  return 0;
}