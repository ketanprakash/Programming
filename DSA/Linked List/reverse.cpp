#include <iostream> 
#include "CreatingLinkedList.cpp"
using namespace std; 

void reverse(linked_list &list){
    linked_list::node *prev = NULL, *curr = list.head, *next = list.head -> next;
    while (curr != NULL){
        curr -> next = prev;
        prev = curr;
        curr = next;
        if (next != NULL) next = next -> next;
    }
    list.head = prev;
}

int main(){
    linked_list list;
    for (int i = 0; i < 10; i++){
        list.insert_tail(i + 1);
    }
    list.print();
    reverse(list);
    list.print();
}
