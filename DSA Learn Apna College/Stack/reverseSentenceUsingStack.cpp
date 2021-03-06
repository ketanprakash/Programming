//Program to reverse sentence using stack
#include <bits/stdc++.h>  
#include "stackArr.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  string sentence; 
  getline(cin, sentence);
  string word; 
  stackArr<string> s; 
  int n = sentence.size();
  for (int i = 0; i < n; i++){
    if (sentence[i] == ' '){
      s.push(word);
      word = "";
    }
    else {
      word.push_back(sentence[i]);
    }
  }
  s.push(word);
  sentence = "";
  while (!s.empty()){
    if (sentence != "") sentence.push_back(' ');
    sentence.append(s.top());
    s.pop();
  }
  cout << sentence << endl;
  return 0;
}