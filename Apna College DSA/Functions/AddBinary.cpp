//Author: Ketan Prakash, Date:
//Program to add two binary numbers
#include <iostream> 
using namespace std; 

string AddBinary(string binary1, string binary2){
    int carry = 0;
    string binarySum = "";
    int time = 32 - binary1.size();
    for (int i = 0; i < time; i++){
        binary1 = "0" + binary1;
    }
    int time1 =  32 - binary2.size(); 
    for (int i = 0; i < time1; i++){
        binary2 = "0" + binary2;
    }
    for (int i = binary1.size() - 1; i >= 0; i--){
        int bin1 = binary1[i] - '0', bin2 = binary2[i] - '0';
        int sum = bin1 ^ bin2 ^ carry;
        carry = (bin1 & bin2) | (bin1 & carry) | (bin2 & carry);
        binarySum = to_string(sum) + binarySum;
    }
    return binarySum;
}

int main(){
    string bin1, bin2; 
    cin >> bin1 >> bin2;
    cout << AddBinary(bin1, bin2) << endl;
    return 0;
}