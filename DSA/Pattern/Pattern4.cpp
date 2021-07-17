//Author: Ketan Prakash, Date:
//Program to print mirrored half pyramid
#include <iostream> 
using namespace std; 

int main(){
    //no of spaces in a row = total_rows - row_no
    //no of stars in a row = row_no
    //loop for total rows and print " " if j <= total_row - row_no else print *
    int rows; 
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= rows; j++){
            if (j <= rows - i) cout << "  ";
            else cout << "* ";
        }
        cout << endl;
    }
    return 0;
}