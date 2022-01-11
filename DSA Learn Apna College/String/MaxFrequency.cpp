//Author: Ketan Prakash, Date:
//Program to find freq of character having maximum frequency
#include <iostream> 
using namespace std; 

int main(){
  string s;
  getline(cin, s);
  int arr[128] = {0};
  for (char &ch : s){
    if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
    arr[(int)ch]++;
  }    
  int max = -1, max_idx = -1; 
  for (int i = 0; i < 128; i++){
    if (arr[i] > max) {
      max = arr[i];
      max_idx = i;
    }
  }
  cout << (char)(max_idx) << endl;
  return 0;
}