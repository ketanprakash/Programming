//Author: Ketan Prakash, Date:
//Program to print floyyd's triangle
#include <iostream> 
using namespace std; 

int main(){
    int count = 0; 
    int rows; 
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= i; j++){
            count++;
            cout << count << " ";
        }
        cout << endl;
    }
    return 0;
}