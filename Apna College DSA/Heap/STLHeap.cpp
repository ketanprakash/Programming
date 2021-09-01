//Program to implement heaps using priority queues in stl
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

int32_t main(){
  priority_queue<int, vector<int> > maxHeap;
  priority_queue<int, vector<int>, greater<int> > minHeap;
  maxHeap.push(2);
  maxHeap.push(3);
  maxHeap.push(4);
  cout << maxHeap.top() << endl;
  minHeap.push(2);
  minHeap.push(3);
  minHeap.push(4);
  cout << minHeap.top() << endl;;
  return 0;
}