//Author: Ketan Prakash, Date:
//Program to print butterfly pattern
#include <iostream> 
using namespace std; 

int main(){
    //to print upper part of butterfly pattern,
    //no of stars = row_no * 2
    //no of spaces = 2 * (total_rows - row_no)
    //total iterations = 2 * total_rows
    //upper part of pattern: 
    int rows; 
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= 2 * rows; j++){
            if (j > i && j < 2 * rows - i + 1){
                cout << "  ";
            }
            else cout << "* ";
        }
        cout << endl;
    }
    for (int i = rows; i >= 1; i--){
        for (int j = 1; j <= 2 * rows; j++){
            if (j > i && j < 2 * rows - i + 1){
                cout << "  ";
            }
            else cout << "* ";
        }
        cout << endl;
    }
    return 0;
}