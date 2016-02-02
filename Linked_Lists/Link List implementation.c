typedef struct node {
    int data;
    struct node *next;
}Node;

Node* allocate(){
    Node * head = new(Node);
    head->data;
    head->next = NULL;
}

void printList(Node * head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}
