#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    Node* _next;
}Node;

typedef struct List{
    int size;
    Node* _head;
    Node* _tail;
}List;

List* create(){
    List* list = (List*) malloc(sizeof(List));
    list->size = 0;

    return list;
}

void append(List* list, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if(list->size == 0){
        list->_head = newNode;
        list->_tail = newNode;
    }else{
        list->_tail->_next = newNode;
        list->_tail = newNode;
    }

    list->size++;
}

void prepend(List* list, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if(list->size == 0){
        list->_head = newNode;
        list->_tail = newNode;
    }else{
        newNode->_next = list->_head;
        list->_head = newNode;
    }
    
    list->size++;
}

int main(void){

}