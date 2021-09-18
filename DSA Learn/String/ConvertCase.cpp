//Author: Ketan Prakash, Date:
//Program to change case 
#include <iostream> 
#include <algorithm>
using namespace std; 

string lowerToUpper(const string &str){
  string s; 
  for (char ch : str){
    if (ch >= 'a' && ch <= 'z'){
      s.push_back(ch - 'a' + 'A');
    }
    else s.push_back(ch);
  }
  return s;
}

string upperToLower(const string &str){
  string s; 
  for (char ch : str){
    if (ch >= 'A' && ch <= 'Z'){
      s.push_back(ch - 'A' + 'a');
    }
    else s.push_back(ch);
  }
return s;
}

int main(){
  string str; 
  getline(cin, str);
  // cout << lowerToUpper(str) << endl;
  // cout << upperToLower(str) << endl;

  //using stl
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  cout << str << endl;
  transform(str.begin(), str.end(), str.begin(), ::toupper);
  cout << str << endl;
  return 0;
}