#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans = ""){
    if (s.size() == 0){
        cout << ans << endl;
        return;
    }
    char c = s[0];
    if (c == ' ') {
        keypad(s.substr(1), ans);
        return;
    }
    string code = keypadArr[c - '0'];
    if (code == "") keypad(s.substr(1), ans);
    for (char ch : code){
        keypad(s.substr(1), ans+ch);
    }
}

int32_t main(){
    string s; 
    getline(cin, s);
    keypad(s);
    return 0;
}