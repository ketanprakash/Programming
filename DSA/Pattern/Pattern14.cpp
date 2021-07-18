//Author: Ketan Prakash, Date:
//Program to print hollow diamond
#include <iostream> 
using namespace std; 

int main(){
    int rows; 
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= rows; j++){
            if (j == rows - i + 1) cout << "*" << " ";
            else cout << " " << " ";
        }
        for (int k = 2; k <= i; k++){
            if (k == i) cout << "*" << " ";
            else cout << " " << " ";
        }
        cout << endl;
    }
    for (int i = rows; i >= 1; i--){
        for (int j = 1; j <= rows; j++){
            if (j == rows - i + 1) cout << "*" << " ";
            else cout << " " << " ";
        }
        for (int k = 2; k <= i; k++){
            if (k == i) cout << "*" << " ";
            else cout << " " << " ";
        }
        cout << endl;
    }
    return 0;
}