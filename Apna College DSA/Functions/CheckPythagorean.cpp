//Author: Ketan Prakash, Date:
//Program to check pythagoream triplets
#include <iostream> 
using namespace std; 

bool checkPyth(int num1, int num2, int num3){
    bool sum1, sum2, sum3; 
    sum1 = num1 * num1 + num2 * num2 == num3 * num3;
    sum2 = num3 * num3 + num2 * num2 == num1 * num1;
    sum3 = num1 * num1 + num3 * num3 == num2 * num2;
    return sum1 || sum2 || sum3;
}

int main(){
    int num1, num2, num3; 
    cin >> num1 >> num2 >> num3;
    if (checkPyth(num1, num2, num3)) cout << "Pythagorean triplet" << endl;
    else cout << "Not Pythagorean triplet" << endl;
    return 0;
}