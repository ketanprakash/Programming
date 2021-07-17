//Author: Ketan Prakash, Date: 2021-07-15
//Program to print a rectange pattern
#include <iostream> 
using namespace std; 

int main(){
    int rows, columns;
    cin >> rows >> columns;
    //for rectangle pattern, there are 5 rows with 4 stars
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= columns; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}