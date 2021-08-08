//Program to 
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

int size(node* head){
    int c = 0; 
    for (auto i = head; i != NULL; i = i -> next){
        c++;
    }
    return c;
}

node* insertAtHead(node *head, int data){
    node *newnode = new node(data);
    newnode -> next = head;
    head = newnode;
    return head;
}

node* insertAtTail(node *head, int data){
    if (head == NULL){
        head = insertAtHead(head, data);
    }
    else{
        node *temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = new node(data);
    }
    return head;
}

node* insert(node* head, int idx, int data){
    if (idx == 0){
        insertAtHead(head, data);
    }
    else if (idx == size(head)){
        head = insertAtTail(head, data);
    }
    else if (idx < size(head)){
        node *temp = head, *newnode = new node(data);
        for (int i = 0; i < idx - 1; i++){
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
    else {
        cout << "Invalid Index" << endl;
    }
    return head;
}

node* removeHead(node *head){
    if (head != NULL){
        node *oldHead = head; 
        head = head -> next;
        delete oldHead;
    }
    else {
        cout << "No Item in the List" << endl;
    }
    return head;
}

node* removeTail(node *head){
    if (head != NULL){
        node *trav = head; 
        while (trav -> next -> next != NULL){
            trav = trav -> next;
        }
        delete trav -> next; 
        trav -> next = NULL; 
    }
    else {
        cout << "No item in the list" << endl;
    }
    return head;
}

node* remove(node* head, int idx){
    if (head != NULL){
        if (idx == 0){
            head = removeHead(head);
        }
        else if (idx == size(head) - 1){
            head = removeTail(head);
        }
        else {
            node *temp = head;
            for (int i = 0; i < idx - 1; i++){
                temp = temp -> next;
            }
            node* nodeToDelete = temp -> next;
            temp -> next = temp -> next -> next;
            delete nodeToDelete;
        }
    }
    else {
        cout << "No Item in the List" << endl;
    }
    return head;
}

bool search(node *head, int key){
    for (auto i = head; i != NULL; i = i -> next){
        if (key == i -> data) return true;
    }
    return false;
}

void display(node *head){
    for (auto i = head; i != NULL; i = i -> next){
        cout << i -> data << " -> ";
    }
    cout << "NULL" << endl;
}

int32_t main(){
    node* head = NULL;
    int n; 
    cin >> n; 
    int data;
    for (int i = 0; i < n; i++){
        cin >> data; 
        head = insertAtTail(head, data);
    }
    head = insertAtHead(head, 10);
    display(head);
    head = insert(head, 3, 7);
    display(head);
    head = remove(head, 3);
    display(head);
    cout << search(head, 5);
    return 0;
}