//Program to detect cycle in linked list
#include <bits/stdc++.h>
#include "ll.cpp"  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

void removeCycle(node* &head){
    unordered_set<node*> s;
    node* temp = head;
    while (temp != NULL){
        s.insert(temp);
        if (s.find(temp -> next) != s.end()){
            temp -> next = NULL;
        }
        temp = temp -> next;
    }
}

bool detectCycle(node* head){
    node *slow = head, *fast = head;
    while (fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next; 
        slow = slow -> next;
        if (fast == slow) return true;
    }
    return false;
}

void removeCycleFW(node* &head){
    node *slow = head, *fast = head;
    do{
        slow = slow -> next;
        fast = fast -> next -> next;
    } while (fast != slow);
    fast = head; 
    while (fast -> next != slow -> next){
        fast = fast -> next; 
        slow = slow -> next;
    }
    slow -> next = NULL;
}

int32_t main(){
    node* head = NULL; 
    node* cycle = NULL;
    head = new node(5);
    head -> next = new node(10);
    head -> next -> next = new node(20);
    cycle = head -> next -> next -> next = new node(30);
    head -> next -> next -> next -> next = new node(40);
    head -> next -> next -> next -> next -> next = new node(50);
    head -> next -> next -> next -> next -> next -> next = cycle;
    node* temp = head; 
    // removeCycle(head);
    if (detectCycle(head)){
        removeCycleFW(head);
    }
    while (temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
    return 0;
}