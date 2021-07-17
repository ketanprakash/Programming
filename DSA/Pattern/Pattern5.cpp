//Author: Ketan Prakash, Date:
//Program to print half pyramid using numbers
#include <iostream> 
using namespace std; 

int main(){
    //no of numbers in a row = row_no
    //value of number = row_no
    int rows; 
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}