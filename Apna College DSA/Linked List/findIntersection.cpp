//Program to find intersection between two linked lists
#include <bits/stdc++.h>
#include "ll.cpp"  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

node* findIntSTL(node* head1, node* head2){
    node *temp = head1;
    unordered_set<node*> s;
    while (temp -> next != NULL){
        s.insert(temp);
        temp = temp -> next;
    }
    temp = head2;
    while (temp -> next != NULL){
        if (s.find(temp) != s.end()){
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}

void display(node* head){
    for (node* i = head; i != NULL; i = i -> next){
        cout << i -> data << " "; 
    }
    cout << endl;
}

int32_t main(){
    node *head1 = NULL, *head2 = NULL; 
    head1 = new node(1);
    head2 = new node(9);
    head2 -> next = new node(10);
    head1 -> next = new node(2);
    head1 -> next -> next = new node(3);
    head1 -> next -> next -> next = new node(4);
    head2 -> next -> next = head1 -> next -> next -> next -> next = new node(5);
    head1 -> next -> next -> next -> next -> next = new node(6);
    node* intersection = findIntSTL(head1, head2);
    display(head1);
    display(head2);
    if (intersection) {
        cout << intersection << " : " << intersection -> data << endl;
    }
    return 0;
}