#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void printName5Times(string &name, int n){
  if (n == 0) return;
  cout << name << '\n';
  printName5Times(name, n - 1);
}

int32_t main(){
  // Write your code
  int n;
  string name; 
  cin >> n;
  cin.ignore();
  getline(cin, name); 
  printName5Times(name, n);
}