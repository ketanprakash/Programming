#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
using namespace std; 

string reverseStr(string s){
    for (int i = 0, j = s.size() - 1; i < j; i++, j--){
        swap(s[i], s[j]);
    }
    return s;
}

string reverseStrR(string s, string ans){
    if (s.size() == 0){
        return ans;
    }
    ans.insert(ans.begin(), s[0]);
    return reverseStrR(s.substr(1), ans);
}

void rev(string &s){
    for (int i = 0, j = s.size() - 1; i < j; i++, j--){
        swap(s[i], s[j]);
    }
}

int32_t main(){
    string str;
    cin >> ws; 
    getline(cin, str);
    // string s = reverseStr(str);
    // string s = reverseStrR(str, "");
    // cout << s << endl;
    rev(str);
    cout << str << endl;
    return 0;
}