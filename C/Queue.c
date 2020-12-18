#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    //Any Arbitrary data
    char *name;

} Data;

//Sorted List Node
typedef struct node{
    //The lower the priority the more important the node
    int priority;
    Data* data;
    struct node *ptr;
} node_queue;

//----- LINKED LIST -----
typedef struct Queue {
    int height;
    Queue* head;
    Queue* tail;
} Queue;

Queue* create(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->height = 0;
    
    return queue;
}

int main(void){

}