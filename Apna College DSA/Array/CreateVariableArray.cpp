//Author: Ketan Prakash, Date: 2021-07-15
//Program to create variable length array(vector)
#include <iostream> 
#include <string>
using namespace std; 
typedef long unsigned int size_t;

template <class T> 
class Array{
    size_t capacity;
    T *array;
    size_t ArraySize;

    public:
    Array(){
        capacity = 10;
        array = new T[capacity];
        ArraySize = 0;
    }
    Array(size_t size){
        capacity = size;
        array = new T[capacity];
        ArraySize = size;
    }

    bool full(){
        return ArraySize == capacity;
    }

    void extend(){
        if (capacity == 0) {
            capacity = 1;
        }
        else {
            capacity *= 2;
        }
        T* newArray = new T[capacity];
        for (size_t i = 0; i < ArraySize; i++){
            newArray[i] = array[i];
        }
        delete [] array;
        array = newArray;
    }

    void push_back(T data){
        if (full()) extend();
        array[ArraySize++] = data; 
    }

    size_t size(){
        return ArraySize;
    }

    T& operator[](size_t idx){
        return array[idx];
    }
};

// int main(){
//     vector<string> arr;
//     for (int i = 0; i < 128; i++){
//         arr.push_back(to_string(i));
//     }
//     for (int i = 0; i < arr.size(); i++){
//         cout << arr[i] << endl;
//     }
//     cout << endl;
//     return 0;
// }