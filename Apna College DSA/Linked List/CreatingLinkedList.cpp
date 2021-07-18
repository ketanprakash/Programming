//Author: Ketan Prakash, Date: 2021-07-14
//Program to create linked list with its functions
#include <iostream> 
using namespace std;

class linked_list{
    public:
    struct node{
        int data; 
        node* next;
        node(int data){
            this -> data = data;
            next = NULL;
        }
    };
    node* head = NULL;
    void insert_head(int data){
        node* newhead = new node(data);
        newhead -> next = head;
        head = newhead;
    }

    void insert_tail(int data){
        if (head == NULL){
            insert_head(data);
            return;
        }
        node* temp = NULL;
        for (temp = head; temp -> next != NULL; temp = temp -> next){}
        temp -> next = new node(data);
    }

    void insert(int idx, int data){
        if (idx == 0) {
            insert_head(data);
            return;
        }
        else if(head == NULL){
            cout << "Invalid Index" << endl;
            return;
        }
        node* temp = head; 
        for (int i = 0; i < idx - 1; i++){
            if (temp -> next == NULL){
                cout << "Invalid Index" << endl;
                head = head;
            }
            temp = temp -> next;
        }
        node* temp1 = temp -> next;
        temp -> next = new node(data);
        temp -> next -> next = temp1;
    }

    void remove_head(){
        if (head == NULL) return;
        node* temp = head;
        head = head -> next;
        delete temp;
    }

    void remove_tail(){
        if (head == NULL) {
            return;
        }
        else if (head -> next == NULL) {
            remove_head();
            return;
        }
        node* temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }

    void remove(int idx){
        if (head == NULL) return;
        else if (idx == 0) {
            remove_head();
            return;
        }
        node* temp = head;
        for (int i = 0; i < idx - 1; i++){
            if (temp -> next == NULL){
                cout << "Invalid Index" << endl;
                head = head;
            }
            temp = temp -> next;
        }
        node* temp1 = temp -> next -> next;
        delete temp -> next;
        temp -> next = temp1;
    }

    void print(){
        for (node* temp = head; temp != NULL; temp = temp -> next){
            cout << temp -> data << " -> ";
        }
        cout << "NULL" << endl;
    }
};