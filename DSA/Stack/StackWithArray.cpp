//Author: Ketan Prakash, Date: 2021-07-14
//Program to create stack with array
#include <iostream> 
using namespace std; 

class stack{    
    int* STACK;
    int top;
    int size;
    public:
    stack(){
        STACK = new int[10];
        top = -1;
        this -> size = 10;
    }

    stack(int size){
        STACK = new int[size];
        top = -1;
        this -> size = size;
    }
    
    public:
    bool empty(){
        return top == -1;
    }

    bool full(){
        return top == size - 1;
    }

    void extend(){
        size = 2 * size;
        int* newSTACK = new int[size];
        for (int i = 0; i <= top; i++){
            newSTACK[i] = STACK[i];
        }
        delete [] STACK;
        STACK = newSTACK;
    }

    void push(int value){
        if (full()) extend();
        STACK[++top] = value;
    }

    void pop(){
        if (empty()) return;
        top--;
    }

    int Top(){
        return STACK[top];
    }

    int Size(){
        return top + 1;
    }
};

// int main(){
//     stack stack1(5);
//     for (int i = 0; i < 100; i++){
//         stack1.push(i + 1);
//     }
//     while(!stack1.empty()){
//         cout << stack1.Top() << endl;
//         stack1.pop();
//     }
//     return 0;
// }