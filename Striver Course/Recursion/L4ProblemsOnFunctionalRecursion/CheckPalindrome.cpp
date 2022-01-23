#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

//check if a string is a palindrome

bool checkPalindrome(string &str, int i, int n){
  if (i >= n / 2) return true;
  if (str[i] != str[n - 1 - i]) return false;
  return checkPalindrome(str, i + 1, n);
}
int32_t main(){
  // Write your code
  string str;
  cin >> ws;
  getline(cin, str);
  cout << (checkPalindrome(str, 0, str.length()) ? "Palindrome" : "Not palindrome");
}