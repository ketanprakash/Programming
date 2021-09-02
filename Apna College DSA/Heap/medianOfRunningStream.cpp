//Program to find median of running stream
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  int n, x; 
  cin >> n; 
  priority_queue<int, vector<int> > q1;
  priority_queue<int, vector<int>, greater<int> > q2;
  for (int i = 0; i < n; i++){
    cin >> x; 

    //inserting into queue
    if (q1.empty() || q1.top() > x){
      q1.push(x);
    }
    else q2.push(x);

    if (q1.size() > q2.size() + 1){
      q2.push(q1.top());
      q1.pop();
    }
    else if (q2.size() > q1.size() + 1){
      q1.push(q2.top());
      q2.pop();
    }

    //returing the median
    float med = q1.size() > q2.size() ? q1.top() : q1.size() < q2.size() ? q2.top() : (float)(q1.top() + q2.top())/2;
    cout << med << endl; 
  }
  return 0;
}