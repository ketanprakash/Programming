//Program to reverse a linked list
#include <bits/stdc++.h>  
#include "ll.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void reverse(linked_list &list){
    node *prev = NULL, *curr = list.head, *next = curr -> next;
    while (curr != NULL){
        curr -> next = prev;
        prev = curr; 
        curr = next; 
        if (next != NULL) next = next -> next;
    }
    list.head = prev;
}

node* rev(node* head, node* prev = NULL){
    if (head -> next == NULL) {
        head -> next = prev;
        return head;
    }
    node* temp = rev(head -> next, head);
    head -> next = prev;
    head = temp;
    return head;
}

void reverseR(linked_list &list){
    list.head = rev(list.head);
}

int32_t main(){
    linked_list l; 
    int n; 
    cin >> n;
    int t; 
    for (int i = 0; i < n; i++){
        cin >> t; 
        l.insertTail(t);
    }
    reverseR(l);
    l.display();
    return 0;
}

/*
1 -> 2 -> NULL
NULL <- 1 2 -> NULL
NULL <- 1 <- 2
*/