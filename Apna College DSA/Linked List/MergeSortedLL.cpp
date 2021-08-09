//Program to merge two sorted linked lists
#include <bits/stdc++.h>
#include "ll.cpp"  
#define int long long 
#define uint unsigned long long
#define endl '\n'
using namespace std; 

linked_list mergeWithNewLL(linked_list list1, linked_list list2){
    linked_list list;
    node *temp1 = list1.head, *temp2 = list2.head, *temp = NULL;
    if (temp1 -> data < temp2 -> data){
        list.head = new node(temp1 -> data);
        temp1 = temp1 -> next;
    }
    else {
        list.head = new node(temp2 -> data);
        temp2 = temp2 -> next;
    }
    
    temp = list.head;
    while (temp1 != NULL && temp2 != NULL){
        if (temp1 -> data < temp2 -> data){
        temp -> next = new node(temp1 -> data);
        temp = temp -> next;
        temp1 = temp1 -> next;
        }
        else {
        temp -> next = new node(temp2 -> data);
        temp = temp -> next;
        temp2 = temp2 -> next;
        }
    }
    while (temp1 != NULL){
        temp -> next = new node(temp1 -> data);
        temp = temp -> next;
        temp1 = temp1 -> next;
    }
    while (temp2 != NULL){
        temp -> next = new node(temp2 -> data);
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    return list;
}

linked_list merge(linked_list &l1, linked_list &l2){
    node *dummy = new node(INT_MIN);
    node *temp = dummy, *temp1 = l1.head, *temp2 = l2.head;
    while (temp1 != NULL && temp2 != NULL){
        if (temp1 -> data < temp2 -> data){
        temp -> next = temp1;
        temp1 = temp1 -> next;
        temp -> next -> next = NULL;
        temp = temp -> next;
        }
        else {
        temp -> next = temp2;
        temp2 = temp2 -> next;
        temp -> next -> next = NULL;
        temp = temp -> next;
        }
    }
    while (temp1 != NULL){
        temp -> next = temp1;
        temp1 = temp1 -> next;
        temp -> next -> next = NULL;
        temp = temp -> next;
    }
    while (temp2 != NULL){
        temp -> next = temp2;
        temp2 = temp2 -> next;
        temp -> next -> next = NULL;
        temp = temp -> next;
    }
    linked_list l(dummy -> next);
    delete dummy; l1.head = NULL; l1.size = 0; l2.head = NULL; l2.size = 0;
    return l;
}

int32_t main(){
    int arr1[] = {0, 2, 4, 6, 8};
    int arr2[] = {1, 3, 5, 7, 9};
    linked_list l1(arr1, 5), l2(arr2, 5); 
    l1.display(); l2.display(); 
    linked_list l = merge(l1, l2);
    l1.display();
    l2.display();
    l.display();
    return 0;
}