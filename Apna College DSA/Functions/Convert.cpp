//Author: Ketan Prakash, Date:
#include <iostream> 
#include <string>
using namespace std; 

long long BinaryToDecimal(long long int binary){
    int place_value = 1, digit;
    long long int n = binary, decimal = 0;
    while (n){
        digit = n % 10; 
        n /= 10;
        decimal += digit * place_value;
        place_value *= 2;
    }
    return decimal;
}

long long OctalToDecimal(long long int binary){
    int place_value = 1, digit;
    long long int n = binary, decimal = 0;
    while (n){
        digit = n % 10; 
        n /= 10;
        decimal += digit * place_value;
        place_value *= 8;
    }
    return decimal;
}

long long HexToDecimal(string binary){
    int place_value = 1, digit;
    long long decimal = 0;
    for (int i = binary.size() - 1; i >= 0; i--){
        if (binary[i] >= '0' && binary[i] <= '9'){
            digit = binary[i] - '0';
        }
        else if (binary[i] >= 'a' && binary[i] <='f'){
            digit = binary[i] - 'a' + 10;
        }
        else {
            digit = binary[i] - 'A' + 10;
        }
        decimal += digit * place_value;
        place_value *= 16;
    }
    return decimal;
}

long long DecimalToBinary(long long int decimal){
    int place_value = 1, digit;
    long long int n = decimal, binary = 0;
    while (n){
        digit = n % 2; 
        n /= 2;
        binary += digit * place_value;
        place_value *= 10;
    }
    return binary;
}

long long DecimalToOctal(long long int decimal){
    int place_value = 1, digit;
    long long int n = decimal, binary = 0;
    while (n){
        digit = n % 8; 
        n /= 8;
        binary += digit * place_value;
        place_value *= 10;
    }
    return binary;
}

string DecimalToHex(long long int decimal){
    int digit;
    long long int n = decimal;
    string binary = "";
    while (n){
        digit = n % 16; 
        n /= 16;
        char number; 
        if (digit > 9){
            number = (digit) - 10 + 'A';
        }
        else {
            number = digit + '0';
        }
        binary = number + binary;
    }
    return binary;
}

int main(){
    cout << BinaryToDecimal(1111) << endl;
    cout << OctalToDecimal(20) << endl;
    cout << HexToDecimal("a1") << endl;
    cout << DecimalToBinary(10) << endl;
    cout << DecimalToOctal(100) << endl;
    cout << DecimalToHex(100) << endl;
    return 0;
}