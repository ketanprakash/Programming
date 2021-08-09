//Program to move last k nodes in the end of a linked list to the beginning
#include <bits/stdc++.h>  
#include "ll.cpp"
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void moveKNodes(node* &head, int size, int k){
    if (head != NULL && size > k){
        node *tail = head, *newtail = NULL; 
        int count = 0; 
        while (tail -> next != NULL){
            if (count == size - k - 1) newtail = tail; 
            tail = tail -> next; 
            count++;
        }
        tail -> next = head; 
        head = newtail -> next;
        newtail -> next = NULL;
    }
}

int32_t main(){
    linked_list l; 
    int n, k; 
    cin >> n; 
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        l.insertTail(x); 
    }
    cin >> k;
    l.display();
    moveKNodes(l.head, n, k);
    l.display();
    return 0;
}