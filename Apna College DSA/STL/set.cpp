//Program to use set
#include <iostream> 
#include <set>
using namespace std; 

/*
# contains unique elements
# implemented using balanced bsts
# elements are in sorted order
# Random access is not possible
# #include<set> to use set
*/

int main(){
  set<int> s;
  s.insert(1);
  s.insert(1);
  s.insert(1);
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  for (auto i : s) cout << i << endl;
  cout << endl;
  for (auto it = s.begin(); it != s.end(); it++){
    cout << *it << endl;
  }
  //custom comparator
  set<int, greater<int> > s1; 
  s1.insert(1);
  s1.insert(1);
  s1.insert(1);
  s1.insert(1);
  s1.insert(2);
  s1.insert(3);
  s1.insert(4);
  for (auto i : s1) cout << i << endl;
  //lower bound && upper bound
  cout << endl << endl;
  cout << *s.lower_bound(1) << endl;
  cout << *s.upper_bound(1);
  cout << '\n';
  return 0;
}