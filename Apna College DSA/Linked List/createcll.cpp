//Program to create a circular linked list
#include <bits/stdc++.h>  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

struct node{
    int data; 
    node *next; 
    node(int data){
        this -> data = data; 
        this -> next = NULL;
    }
};

int size(node *head){
    if (head == NULL){
        return 0;
    }
    int c = 1;
    node *temp = head -> next; 
    while (temp != head){
        temp = temp -> next;
        c++; 
    }
    return c;
}

void insert(node* &head, int *arr, int n){
    if (head == NULL){
        head = new node(arr[0]);
        head -> next = head;
        node *temp = head; 
        for (int i = 1; i < n; i++){
            temp -> next = new node(arr[i]);
            temp -> next -> next = head;
            temp = temp -> next; 
        }
    }
    else {
        node *temp = head; 
        while (temp -> next != head){
            temp = temp -> next;
        }
        for (int i = 0; i < n; i++){
            temp -> next = new node(arr[i]);
            temp -> next -> next = head;
            temp = temp -> next;
        }
    }
}

void insertHead(node* &head, int data){
    if (head == NULL){
        head = new node(data);
        head -> next = head;
        return;
    }
    node *newhead = new node(data), *temp = head;
    newhead -> next = head; 
    while (temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newhead;
    head = newhead;
}

void insertTail(node* &head, int data){
    if (head == NULL){
        insertHead(head, data);
    }
    else {
        node *temp = head; 
        while (temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = new node(data);
        temp -> next -> next = head;
    }
}

void insert(node* &head, int idx, int data){
    if (head == NULL || idx == 0){
        insertHead(head, data);
    }
    else if (idx == size(head)){
        insertTail(head, data);
    }
    else{
        node *temp = head, *newnode = new node(data);
        for (int i = 0; i < idx - 1; i++){
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void removeHead(node* &head){
    if (head != NULL){
        node *end = head, *oldhead = head; 
        while (end -> next != head){
            end = end -> next;
        }
        head = head -> next;
        end -> next = head; 
        delete oldhead;   
    }
}

void removeTail(node* &head){
    if (head != NULL){
        if (head -> next == NULL){
            delete head; 
            head = NULL;
        }
        else {
            node* temp = head; 
            while (temp -> next -> next != head){
                temp = temp -> next;
            }
            delete temp -> next; 
            temp -> next = head;
        }
    }
}

void remove(node* &head, int idx){
    if (head != NULL){
        if (idx == 0){
            removeHead(head);
        }
        else if (idx == size(head) - 1){
            removeTail(head);
        }
        else{
            node *temp = head; 
            for (int i = 0; i < idx - 1; i++){
                temp = temp -> next;
            }
            node *toDelete = temp -> next; 
            temp -> next = temp -> next -> next;
            delete toDelete;
        }
    }
}

void display(node *head){
    auto i = head;
    for (i = head; i -> next != head; i = i -> next){
        cout << i -> data << " -> ";
    }
    cout << i -> data << " -> " << i -> next -> data << "(head)";
    cout << endl;
}

int32_t main(){
    node* head = NULL;
    int n; 
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i]; 
    }
    insertHead(head, 0);
    display(head);
    insert(head, arr, n);
    display(head);
    insert(head, 3, 10);
    display(head);
    remove(head, 0);
    display(head);
    return 0;
}