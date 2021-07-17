//Author: Ketan Prakash, Date:
//Program to print an inverted half pyramid
#include <iostream> 
using namespace std; 

int main(){
    //to print an inverted half pyramid: 
    //no of stars in a row = total_rows - row_no + 1
    int rows; 
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= rows - i + 1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}