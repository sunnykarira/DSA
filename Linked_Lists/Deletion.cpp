#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
# define sf cin
# define pf cout
using namespace std;
typedef struct node {
    int data;
    struct node *next;
}Node;

Node* allocate(){
    Node * head = new(Node);
    int x;
    cout<<"Enter Data";
    sf>> x;
    head->data = x;
    head->next = NULL;
    return head;
}

void printList(Node * head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

void push_front(Node ** head_ref){
    Node* new_node = allocate();
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node *prev_node){
    Node * new_node = allocate();
    if(prev_node == NULL){
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node ** head_ref){
    Node * new_node = allocate();
    Node * last = *head_ref;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void delete_node(Node ** head, int key){
    Node * temp = *head;
    Node *prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int main(){
    Node * first = allocate();
    Node * second = allocate();
    Node * third = allocate();
    first->next = second;
    second->next = third;
    third->next = NULL;
    pf<< "Entering into LL";
    push_front(&first);
    insertAfter(second);
    append(&first);
    printList(first);
    pf<<"Deleting Node";
    delete_node(&first, 2);
    printList(first);
}


