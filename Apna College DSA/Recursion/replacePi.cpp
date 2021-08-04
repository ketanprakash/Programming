#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

void replacePi(string s){
    if (s.size() == 0) return;
    if (s.size() == 1){
        cout << s[0];
        return;
    }
    if (s[0] == 'p' && s[1] == 'i'){
        cout << 3.14;
        replacePi(s.substr(2));
        return;
    }
    cout << s[0];
    replacePi(s.substr(1));
}

int32_t main(){
    string str; 
    getline(cin, str);
    replacePi(str);
    return 0;
}