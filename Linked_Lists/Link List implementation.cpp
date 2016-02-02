#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct node {
    int data;
    struct node *next;
}Node;

Node* allocate(){
    Node * head = new(Node);
    head->data = 1;
    head->next = NULL;
    return head;
}

void printList(Node * head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

int main(){
    Node * start = allocate();
    printList(start);
}
