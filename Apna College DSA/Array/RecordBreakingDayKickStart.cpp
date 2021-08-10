//Author: Ketan Prakash, Date:
//Program to find number of record breaking days
#include <iostream> 
#include <vector>
#include <climits>
using namespace std; 

int main(){
  int t; 
  cin >> t; 
  for (int k = 1; k <= t; k++){
    int n; 
    int n1 = 0;
    cin >> n; 
    vector<int> v(n); 
    for (int &x : v) cin >> x; 
    int max = INT_MIN;
    for (int i = 0; i < n; i++){
      if (i == n - 1){
        if (v[i] > max){
          n1++;
        }
      }
      else if (v[i] > max && v[i] > v[i + 1]){
        n1++;
      }
      if (v[i] > max) max = v[i];
    }
    cout << "Case#" << k << ": " << n1 << endl;
  }
  return 0;
}