//Author: Ketan Prakash, Date: 2021-07-14
//Program to create a stack with linked list
#include <iostream> 
using namespace std; 

class stack{
    struct node{
        int data;
        node* next;
        node(int data){
            this -> data = data; 
            this -> next = NULL;
        }
    };

    node* top; 
    int size;

    public:
    stack(){
        top = NULL;
        size = 0;
    }

    bool empty(){
        return top == NULL;
    }

    void push(int value){
        node* newTop = new node(value);
        newTop -> next = top;
        top = newTop;
        size++;
    }

    void pop(){
        if (empty()) return;
        node* oldTop = top;
        top = top -> next;
        delete oldTop;
        size--;
    }

    int Top(){
        return top -> data;
    }
};

// int main(){
//     stack stack1;
//     for (int i = 0; i < 10; i++){
//         stack1.push(i);
//     }
//     while(!stack1.empty()){
//         cout << stack1.Top() << endl;
//         stack1.pop();
//     }
//     return 0;
// }