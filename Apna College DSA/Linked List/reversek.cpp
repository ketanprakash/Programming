//Program to reverse k nodes in a linked list
#include <bits/stdc++.h>  
#include "ll.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

node* reversek(node* head, int k){
    node* temp = head;
    for (int i = 0; i < k; i++){
        temp = temp -> next;
    }
    node *prev = temp, *curr = head, *next = curr -> next;
    while (curr != temp){
        curr -> next = prev;
        prev = curr; 
        curr = next; 
        if (next != temp) next = next -> next;
    }
    if (temp != NULL) head -> next = reversek(head -> next, k);
    return prev;
}

int32_t main(){
    int n, k, x; 
    cin >> n >> k; 
    linked_list l;
    for (int i = 0; i < n; i++){
        cin >> x; 
        l.insertTail(x);
    }
    l.head = reversek(l.head, k);
    l.display();
    return 0;
}