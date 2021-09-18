//Author: Ketan Prakash, Date:
//Program to get all subsets of an array
#include <iostream> 
#include <cmath>
using namespace std; 

bool getBit(int n, int pos){
  return (((1 << pos) & n) >> pos);
}

int main(){
  int n; 
  cin >> n; 
  string arr(n, ' ');
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < pow(2, n); i++){
    cout << i << " : ";
    cout << "{ ";
    for (int j = 0; j < n; j++){
      if (getBit(i, n - j - 1)) cout << arr[j] << ' ';
    }
    cout << '}';
    cout << endl;
  }
  return 0;
}