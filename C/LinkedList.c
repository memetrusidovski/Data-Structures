#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//Adds a value to the end of a list 
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

//Add a value to the front of a list 
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

//Takes a node and removes it from the list in Constant Time
void removeNode(Node* node){
    node->data = node->_next->data;
    node->_next = node->_next->_next;
}

//A linear search function
Node* search(List* list, int find){
    Node* current = (Node*) malloc(sizeof(Node));
    current = list->_head;

    while(current != NULL ){
        if(current->data == find){
            return current;
        }else
        current = current->_next;
    }

    return current;
}

//Checks if a value is contained in the list
bool contains(List* list, int find){
    if(search(list, find) != NULL)
        return true;

    return false;
}

int main(void){

}