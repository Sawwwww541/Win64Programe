#include<iostream>

void Add_linklist(Node *head,Node *end);
void Print_linklist(Node *head,Node *end);

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

int main(){

    Node *head=(Node*)malloc(sizeof(Node));
    head->prev=nullptr;
    head->next=nullptr;

    Node *end=(Node*)malloc(sizeof(Node));
    end->prev=nullptr;
    end->next=nullptr;

    Add_linklist(head,end);
    Print_linklist(head,end);

    return 0;
    
}

void Add_linklist(Node *head,Node *end){

    Node *temp=nullptr;
    Node *move=(Node*)malloc(sizeof(Node));
    move=head->next;
    while(move->next!=nullptr){
        temp=move;
        move=move->next;
    }
    move->prev=temp;
    move->data=1;
    end=move;

}

void Print_linklist(Node *head,Node *end){

    Node *move=head->next;
    while(move!=nullptr){
        std::cout<<move->data;
        move=move->next;
    }

}