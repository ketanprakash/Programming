#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

//using recursion
string revString(string s, string ans){
    if (s.size() == 0){
        return ans;
    }
    ans.insert(ans.begin(), s[0]);
    return revString(s.substr(1), ans);
}

string revStringitr(string s){
    uint i = 0, j = s.size() - 1;
    while (i < j){
        swap(s[i], s[j]);
        i++; j--;
    }
    return s;
}

void revStringitrinplace(string &s){
    uint i = 0, j = s.size() - 1;
    while (i < j){
        swap(s[i], s[j]);
        i++; j--;
    }
}

int32_t main(){
    string s; 
    cin >> ws;
    getline(cin, s);
    // string str = revString(s, "");
    // string str = revStringitr(s);
    revStringitrinplace(s);
    cout << s << endl;
    return 0;
}